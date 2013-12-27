#include "Note.h"
#include "Logger.h"
#include <iostream>
#include <vector>
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

	void practLogs();
private:
	Logger log;
    Note db;
	void fileEdit(Note *file);
	void fileRead(Note *file);
	void fileEncrypt(Note *file);
	void addtoDB(string path);
};

