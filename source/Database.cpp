#include "Database.h"
#include <iostream>

using namespace std;

// to complile: g++ db-pract.cpp -lsqlite3 -Wno-write-strings
// Database is simply an object to work with sqlite3 in c++
// I used http://www.dreamincode.net/forums/topic/122300-sqlite-in-c/

// All sqlite3 functions require c, hence the use char* instead of strings


/*

	Database *db = new Database("sqldb.db");
	// can do any query
	vector<vector<string> > vvs = db->query("SELECT * from tbl1;");
	db->close();
*/

Database::Database() {
	//does nothing
	return;
}

Database::Database(string filename) {
	open(filename);
}

Database::~Database() {
}

bool Database::open(string filename) {
	if (sqlite3_open(filename.c_str(), &database) == SQLITE_OK) {
		return true;
	}
	return false;
}

vector<vector<string> > Database::query(string q) {
	// the outside vector refers to each object in table
	// the inside vector is for each column of each object. 
	// eg: the pieces of data for the 3rd object in a table of 2 columns is
	// results[2][0] and results[2][1]

	// if error, returns results[0][0] with the error message. 
	
	char *query = (char*)q.c_str();
	sqlite3_stmt* stmt;
	vector<vector<string > > results;

	if(sqlite3_prepare_v2(database, query, -1, &stmt, 0) == SQLITE_OK) {
		int cols = sqlite3_column_count(stmt);
		int result = 0;

		while (true) {
			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW) {
				vector<string> values;
				for (int col=0; col < cols; col++) {
					values.push_back((char *)sqlite3_column_text(stmt, col));
				}
				results.push_back(values);
			}
			else break;
		}
		sqlite3_finalize(stmt);
	}
	string error = sqlite3_errmsg(database);
	if (error != "not an error") {
		vector<string> vs;
		vs.push_back(q + " : " + error);
		results.push_back(vs);
	}
	return results;
}

string Database::getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
	

void Database::close() {
	sqlite3_close(database);
}
