NoteTracker is a c++ application for keeping track of *.txt files located in various places on your computer. To add a note, the user enters the path of the text file (either relative or absolute path) and the nickname they want to give the file. This information is stored in sqlite3 database for easy access and use. 

To use:
	make
	./noteTracker

Known bugs:
	- If you enter relative paths, then move the exectuable, the program will be unable to fetch the file.

Things to add:
	- ability to remove notes from database
	- Work with absolute paths, in case the location of the executable changes. 
	- Better interface in general. 
	- A search feature
	- Tags or descriptors for notes

Things that I might add later but probably won't
	- A gui
	- Link it with an app or put online. 
