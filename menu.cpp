#include "menu.h"

#define CLEAR "clear"

using namespace std;

Menu::Menu(){
	ofstream file(NAMEFILE, ofstream::app);
}

Menu::~Menu(){
}

void Menu::showMenu(){
	
	char option;
	do {
		system(CLEAR);

		cout<<"Welcome "<<endl<<endl;
		cout<< ADD_MOVIE <<" Add movie"<<endl;
		cout<< SHOW_MOVIES <<" Show movies"<<endl;
		cout<< SEARCH_MOVIE <<" Search movie"<<endl;
		cout<< MODIFY_MOVIE <<" Modify movie"<<endl;
		cout<< DELETE << " Delete movie"<<endl;
		cout<< HIDDEN_MOVIE << " Hide movie"<<endl;
		cout<< RESTORE_MOVIE << " Restore hidden movie"<<endl;
		cout<< EXIT << " exit"<<endl<<endl;
		
		cout<< "chose a option : ";
		cin>>option;

		if(option < ADD_MOVIE or option > EXIT ){
			cout<<option<<" invalid option"<<endl;
			cin.get();
		} 
	}while(option != EXIT);
		
}
