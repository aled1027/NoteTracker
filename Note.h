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
    Note(string path);
    ~Note();

    bool open(std::string path); //return false if can't open
    vector<string> read();
    void close();
    void edit();
	string getPath();
	void reopen();
	void addToEnd(string str);
	void updateLine(string, int); // unfinished
private:
    fstream note;
	string file_path;
};

#endif

