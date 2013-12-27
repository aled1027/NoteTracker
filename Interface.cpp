#include <iostream>
#include "Interface.h"

using namespace std;

Interface::Interface() {
}

Interface::Interface(string dbPath) {
	
	log.open("logs.txt");
	db.open(dbPath.c_str());
	log.writeDebug("Booting up the interface");
}

Interface::~Interface() {
	db.close();
}

void Interface::printMenu() {
    cout << endl;
    cout << endl;
    cout << "Welcome to notetaker. Notetaker will encrypt and store your text files in a database." << endl;
    cout << "How would you like to proceed?" << endl;
    // print menu and figure out what the user wants to do. 
    int inp;
    bool run = true;
    while (run) {
		log.writeDebug("printing menu");
        cout << "1: access old files" << endl;
        cout << "2: save a new text file" << endl;
        cout << "3: exit" << endl;
        string input;
		cout << "?";
		try {
			log.writeDebug("getting menu input");
        	getline(cin, input);
			if (input == "1") {
				log.writeDebug("input=1. Calling gotoDB()");
				gotoDB();
				run = false; //should probably just change to return; 
			} else if (input == "2") {
				log.writeDebug("input=2. Calling newFile()");
				newFile();	
				run = false;
			} else if (input == "3") {
				log.writeDebug("input=3. Calling exitInt()");
				exitInt();
                run = false;
			} else {
				log.writeError("invalid input. retrying to get menu input");
                cout << endl;
                cout << "----- Invalid input. Try again" << endl;
			}
		}
		catch (exception &e) {
			log.writeError("Caught invalid menu input. Retrying to get menu input");
			cout << "Invalid input." << endl;
	       }
    }
}

void Interface::gotoDB() {
	log.writeDebug("Accessing db");
	bool run = true;
	int counter = 0;
	int inp = -1;
	vector<string> dbText = db.read();
	log.writeDebug("Starting loop to print contents of db");
	for (vector<string>::iterator it = dbText.begin(); it != dbText.end(); it++) {
		unsigned pos = it->find(";");
		cout << counter << ": " << it->substr(0, pos) << endl;
		counter++;
	}
	log.writeDebug("Ending loop to print contents of db");

	string input;
	while(run) {
		log.writeDebug("Getting input for accessing db");
		cout << "Pick a file to access or type menu to go to the main menu." << endl;
		cout << "?";
		getline(cin, input);
		try {
			if (input == "menu") {
				printMenu();
			}
			inp = atoi(input.c_str());
			if ((inp > -1) && (inp < (counter+1))) {
				unsigned pos = dbText[inp].find(";");
				openFile(dbText[inp].substr(0, pos), inp);
			}
			run = false;
		} catch(exception &e) {
			cout << "Invalid input." << endl;
		}
	}
}

void Interface::openFile(string path) {
	Note * file = new Note(path);
	fileMenu(file);
	updateDB(file, 
}

void Interface::updateDB(Note *file, int line_number) {
	log.writeDebug("Updating database on line " + line_number + "and file " + file->getPath());
	//now update the database

}

void Interface::fileMenu(Note *file) {
	bool run = true;
	string input;
	while(run) {
		cout << "You are accessing " << file->getPath() << endl;
		cout << "What would you like to do with this file?" << endl;
		cout << "Your options are: edit, read, encrypt, menu" << endl;
		cout << "?";
		getline(cin, input);
		try {
			if (input == "edit") {
				fileEdit(file);
				return;
			} else if (input == "read") {
				fileRead(file);
				return;
			} else if (input == "encrypt") {
				fileEncrypt(file);
				return;
			} else if (input == "menu") {
				printMenu();
				delete file; // I don't know if this is ever called. Have to check in pract file. 
				return;	
			} else {
				throw "bad input";
			run = false;
				// not sure if this hits run = false;
			}
		} catch (exception &e) {
			cout << "Invalid input." << endl;
		}	
	}
	delete file;
	return;
}

void Interface::newFile() {
	log.writeDebug("Asking for new path for file");
	cout << "What is the path of the new file?" << endl;
	string path;
	while (true) {
		cin.clear();
		getline(cin, path);
		//check if path is valid
		fstream file(path.c_str());
		if (!file.is_open()) {
			log.writeError("Path wasn't valid");
			cout << "That path isn't valid. Please enter a new path." << endl;
		}
		else break;
	}
	// add to database
	addtoDB(path);
	// Create a new note with this path
	Note *file = new Note(path);
	// Now work with this path. 
	log.writeDebug("finished adding file to db. Going to fileMenu for path");
	fileMenu(file);
	delete file;
	return;
}

void Interface::fileEdit(Note *file) {
	// finish this. 
	
	log.writeDebug("About to edit " + file->getPath());
	string command = "vim " + file->getPath();
	system(command.c_str());
	file->reopen();
	log.writeDebug("Finished editing");
	fileMenu(file); // these are redundant. 
	return;
}

void Interface::fileRead(Note *file) {
	log.writeDebug("About to read " + file->getPath());
	vector<string> v = file->read();
	cout << "----------------------" << endl;
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) << endl;
	}
	cout << "----------------------" << endl;
	log.writeDebug("Finished reading");
	fileMenu(file); // these are redundant. 
	return;
}

void Interface::fileEncrypt(Note *file) {
	// Not finished
	log.writeDebug("About to encrypt " + file->getPath());
	cout << "You are in file encyrpt." << endl;
	log.writeDebug("Finished encrypting");
	fileMenu(file); //these are redundant. 
	return;
}	
void Interface::exitInt() {
	log.writeDebug("exiting Interface");
	cout << endl;
	cout << "Thanks for using the app. Have a good day.";
	cout << endl << endl;
}

void Interface::addtoDB(string path) {
	// change this to generate the absolute path. Can use system("pwd") to get path of program.
	log.writeDebug("adding path to db " + path);
	string str = path + ";";
	db.addToEnd(str);
	log.writeDebug("Finished adding to db");
}

