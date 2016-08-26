#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "movie.h"

#define CLEAR "clear"

using namespace std;

int main () {

	system(CLEAR);	

	Menu myMenu;
	myMenu.mainMenu();

	return 0;
}
