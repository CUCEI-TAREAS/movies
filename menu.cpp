#include "menu.h"

using namespace std;

Menu::Menu(){
	ofstream file(NAMEFILE, ofstream::app);
}

Menu::~Menu(){
}


void Menu::showMenu(){
	char option;

	do {
		cout<<"Welcome "<<endl<<endl;
		cout<< ADD_MOVIE <<" Add movie"<<endl;
		cout<< SHOW_MOVIES <<" Show movies"<<endl;
		cout<< SEARCH_MOVIE <<" Seach movie"<<endl;
		cout<< MODIFY_MOVIE <<" Modify movie"<<endl;
		cout<< DELETE << " Delete movie"<<endl;

		cin.get();

	}while(option == EXIT);
	
	
}
