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
    void gotoDB();
    void gotoNewFile();
	void openFile(string path);
    void exitInt();
	void fileMenu(Note *file);
	void newFile();
	void addtoDB(Note *file);
	void practLogs();
private:
	Logger log;
	Database db;
	void fileEdit(Note *file);
	void fileRead(Note *file);
	void fileEncrypt(Note *file);
};

