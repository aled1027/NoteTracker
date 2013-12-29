// main.cpp
#include <iostream>
#include <stdlib.h>
#include "Interface.h"
//change

using namespace std;

int main(int argc, char* argv[]) {

	Interface *i = new Interface("sqldb.db");
	i->printMenu();
	return 0;

}
