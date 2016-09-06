#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "movie.h"

#ifdef __linux__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

using namespace std;

int main () {

	system(CLEAR);

	Menu myMenu;
	myMenu.mainMenu();

	return 0;
}
