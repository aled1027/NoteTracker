#include "Logger.h"

Logger::Logger() {
}

Logger::Logger(std::string path) {
	open(path);
}

Logger::~Logger() {
	close();
}

bool Logger::open(std::string logPath) {
    logStream.open(logPath.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
	if (!logStream.is_open()) {
		return false;
	}
	return true;
}

void Logger::write(std::string str) {
	//add line#, date, 
	std::cout << "in logger::write(std::string str)" << std::endl;
	str = "DATE HERE\t" + str;
	logStream << str << std::endl;	
}

void Logger::writeLocation(std::string str) {
	return;
}
void Logger::writeDebug(std::string str) {
	str = "DEBUG:\t" + str;
	write(str);
	return;
}
void Logger::writeError(std::string str) {
	str = "ERROR:\t" + str;
	write(str);
	return;
}

bool Logger::close() {
	logStream.close();
	return true;
}
