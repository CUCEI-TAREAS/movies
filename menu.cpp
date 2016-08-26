#include "menu.h"

using namespace std;

Menu::Menu(){
	ofstream file(NAMEFILE, ofstream::app);
}

Menu::~Menu(){
}

void Menu::printMenu(){

	cout<< TITLE_MAIN_MENU<<endl<<endl;
	cout<< ADD_MOVIE   << TITLE_ADD_MOVIE <<endl;
	cout<< SHOW_MOVIES << TITLE_SHOW_MOVIES<<endl;
	cout<< SEARCH_MOVIE <<TITLE_SEARCH_MOVIE<<endl;
	cout<< MODIFY_MOVIE <<TITLE_MODIFY_MOVIE<<endl;
	cout<< DELETE << TITLE_DELETE<<endl;
	cout<< HIDDEN_MOVIE << TITLE_HIDDEN_MOVIE<<endl;
	cout<< RESTORE_MOVIE << TITLE_RESTORE_MOVIE<<endl;
	cout<< EXIT << TITLE_EXIT<<endl<<endl;
}

void Menu::doAction(char option){

	switch(option){
		case ADD_MOVIE : addMovie(); break;
		case SHOW_MOVIES : addMovie(); break;
		case SEARCH_MOVIE : addMovie(); break;
		case MODIFY_MOVIE : addMovie(); break;
		case DELETE : addMovie(); break;
		case HIDDEN_MOVIE : addMovie(); break;
		case RESTORE_MOVIE : addMovie(); break;
		case EXIT : addMovie(); break;
	}
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

/// search the NAME movie in the file [duplicate()] []
/// if name movie dont exist, is posibnle write...
/// else, message is show that is duplicate
void Menu::addMovie(){
    system(CLEAR);
    cout<<TITLE_ADD_MOVIE<<endl<<endl;

    Movie movieToAdd = captureMovie();

    // if (movieToAdd == nullptr)
    //    return;
}

Movie Menu::captureMovie(){
    char temp[50];
    cout<<"write name of movie : ";
    ///FIX : how to read directly ?
    /// search in the file if is duplicated by name
    ///

    Movie movieToAdd;
//    movieToAdd.setName(temp.c_str());

    cout<<"write category of movie : ";
    cin>>temp;
//    movieToAdd.setCategory(temp.c_str());

    cout<<"write year of movie : ";
    cin>>temp;


}
