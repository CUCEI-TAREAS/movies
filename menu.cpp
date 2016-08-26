#include "menu.h"

#define CLEAR "clear"

using namespace std;

Menu::Menu(){
	ofstream file(NAMEFILE, ofstream::app);
}

Menu::~Menu(){
}

void Menu::printMenu(){

	cout<<"Welcome "<<endl<<endl;
	cout<< ADD_MOVIE <<" Add movie"<<endl;
	cout<< SHOW_MOVIES <<" Show movies"<<endl;
	cout<< SEARCH_MOVIE <<" Search movie"<<endl;
	cout<< MODIFY_MOVIE <<" Modify movie"<<endl;
	cout<< DELETE << " Delete movie"<<endl;
	cout<< HIDDEN_MOVIE << " Hide movie"<<endl;
	cout<< RESTORE_MOVIE << " Restore hidden movie"<<endl;
	cout<< EXIT << " exit"<<endl<<endl;

}

void Menu::doAction(char option){

/*
	switch(option){
		case ADD_MOVIE : 
		break;
	}
*/
}


void Menu::mainMenu(){
	
	char option;
	do {
		system(CLEAR);
		cin.clear();
		printMenu();
		
		cout<< "chose a option : ";
		cin>>option;

		if(option < ADD_MOVIE or option > EXIT ){
			cout<<option<<" invalid option"<<endl;
			
			cin.ignore();			
			cin.get();

		} 

		doAction(option);

	}while(option != EXIT);
		
}

/// search the movie in the file [duplicate()] []
/// if movie dont exist, is write...
// else, message is show that is duplicate
void Menu::addMovie(){

}
