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

const std::string Logger::getTime() {
	time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

void Logger::write(std::string str) {
	str = getTime() + "\t" + str;
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
