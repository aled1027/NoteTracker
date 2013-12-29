// consider renaming note to file
#ifndef __NOTE_H__
#define __NOTE_H__

#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

class Note {
public:
	Note();
    Note(string, string);
    ~Note();

    bool open(std::string path); //return false if can't open
    vector<string> read();
    void close();
	string getPath();
	string getName();
	void reopen();
	void addToEnd(string str);
	
private:
    fstream note;
	string path;
	string name;
};

#endif

