#include "Note.h"
#include "Logger.h"
#include "Database.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class Interface {
public:
	Interface();
    Interface(string dbPath);
    ~Interface();
    void printMenu();

private:
	Logger log;
    Database db;
	void gotoNewFile();
	void openFile(string,string);
    void exitInt();
	void fileMenu(Note *file);
	void newFile();
	bool addtoDB(Note *file);
	void practLogs();
    void gotoDB();
	void fileEdit(Note *file);
	void fileRead(Note *file);
	void fileEncrypt(Note *file);
};

