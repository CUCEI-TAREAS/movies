#include <iostream>
#include <cstdlib>

#include "menu.h"
#include "movie.h"

#define CLEAR clear

using namespace std;

int main () {

	Menu myMenu;
	myMenu.showMenu();
	
	cout<<"all is well"<<endl;
	
	return 0;
}
