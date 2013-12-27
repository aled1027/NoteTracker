#include <iostream>
#include <fstream>

class Logger{
public:
	Logger();
	Logger(std::string);
	~Logger();

	bool open(std::string);
	void write(std::string);
	void writeLocation(std::string);
	void writeDebug(std::string);
	void writeError(std::string);
	bool close();

private:
	std::fstream logStream;
};
