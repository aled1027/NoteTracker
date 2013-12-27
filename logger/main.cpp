#include "Logger.h"
#include <iostream>

int main() {
	Logger *l = new Logger("logs.txt");
	l->writeDebug("did I make a mistake?");
	l->writeError("There was an error and I'm recording it here");
	l->writeDebug("starting a counter");
	return 0;
}
