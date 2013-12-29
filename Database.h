#include <string.h>
#include <vector>
#include <sqlite3.h>
#include <iostream>

using namespace std;

class Database {
public:
	Database();
    Database(string filename);
    ~Database();

    bool open(string);
    vector<vector<string > > query(string);
    void close();
	string getCurrentDateTime();
private:
    sqlite3* database;
};
