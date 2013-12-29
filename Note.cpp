#include "Note.h"
#include <iostream>
using namespace std;

Note::Note() {
}

Note::Note(string pathX, string nameX) {
	path = pathX;
	name = nameX;
	open(path);
}
Note::~Note() {
	close();
}

bool Note::open(string path) {
	//works for both relative and absolute paths
	note.open (path.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
	if (note.is_open()) {
		return true;
	}
	return false;
}

vector<string> Note::read() {
	vector<string> retVect;
	if (note.is_open());
	else {
		cout << "note is not open" << endl;
		return retVect;
	}

	string line;
	note.clear();
    note.seekg(0, ios::beg);
	while (getline(note, line)) {
		retVect.push_back(line);
	}
	note.clear();
	return retVect;
}

void Note::close() {
	note.close();
}

string Note::getPath() {
	return path;
}

string Note::getName() {
	return name;
}

void Note::reopen() {
	close();
	open(getPath());
}

void Note::addToEnd(string str) {
	note << str << endl;	
}

