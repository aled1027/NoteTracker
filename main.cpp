// main.cpp
#include <iostream>
#include <stdlib.h>
#include "Interface.h"

using namespace std;

int main(int argc, char* argv[]) {

	Interface *i = new Interface("db.txt");
	i->printMenu();
	return 0;

}
