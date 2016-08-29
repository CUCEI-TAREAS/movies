#include "menu.h"

using namespace std;

Menu::Menu(){

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
		case SHOW_MOVIES : showMovies(); break;
		case SEARCH_MOVIE : break;
		case MODIFY_MOVIE : break;
		case DELETE : break;
		case HIDDEN_MOVIE : break;
		case RESTORE_MOVIE :break;
		case EXIT : break;
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
	writeMovie(&movieToAdd);
	cout<<"\nMOVIE ADDED SUCCESS!"<<endl;
	cin.get();
}

// show all movies except status movies
void Menu::showMovies(){
	loadMovie();

}
/// FIX: how to read directly ?
/// search in the file if is duplicated by 
Movie Menu::captureMovie(){
	
	cin.ignore();
	cin.clear();

	string temp;
	Movie movieToAdd;

	cout<<"write name of movie : ";
	getline(cin, temp);
	movieToAdd.setName(temp);

	cout<<"write category of movie : ";
	cin.clear();
	getline(cin, temp);
	movieToAdd.setCategory(temp);

	cout<<"write year of movie : ";
	cin.clear();
	getline(cin, temp);	
	movieToAdd.setYear(temp);

	return movieToAdd;
}

void  Menu::writeMovie(Movie* toAdd){		

	ofstream file(NAMEFILE, ofstream::app);

	if(!file){
		/// throw exception
		cout<<ERROR_FILE_MESSAGE<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	
	char sizeName, sizeCate, sizeYear;

	sizeName = toAdd->getName().length();
	sizeCate = toAdd->getCategory().length();
	sizeYear = toAdd->getYear().length();

	// flags to hide 0
	// by default 1 
	file.write("1", 1);
	
	// movie data
	file.write(&sizeName, 1);
	file.write(toAdd->getName().c_str(), sizeName);

	file.write(&sizeCate, 1);
	file.write(toAdd->getCategory().c_str(), sizeCate);

	file.write(&sizeYear, 1);
	file.write(toAdd->getYear().c_str(), sizeYear);

	file.close();

}

Movie* Menu::loadMovie(){

	ifstream file(NAMEFILE, ifstream::binary);

	if(!file){
		/// throw exception
		cout<<endl<<ERROR_FILE_MESSAGE<<endl;
		cin.clear();
		cin.ignore();
		cin.get();
		return nullptr;
	}
	
	char title = 0;

	while(!file.eof()){
		
		/// first character -> status : 0 hidden / 1 normal
		/// second character -> sizeName
		/// name
		///


		/// first movie
		char x;
		unsigned char statusRead, status = file.read(&x, 1);
		long temp = 0;

		/*
		switch (statusRead){			
		}
		name
		*/

		if(status == '1'){
			
		/// second character -> sizeName
			temp = (long)file.get();

			if(title == 0)
				cout<<"NAME\t\t"<<"CATEGORY\t\t"<<"YEAR\t\t"<<endl<<endl;			
		
		} else if(status == '0'){
			/// second character -> sizeName
			file.ignore(file.get());	
		} 

		cout<<"size of name "<<temp<<endl<<endl;
		
		while(temp--)
			cout<<"value temp "<<temp<<" "<<(char)file.get()<<endl;

		// size category of movie		
		temp = (long)file.get();
		cout<<"size of category "<<temp<<endl<<endl;

		while(temp--)
			cout<<"value temp "<<temp<<" "<<(char)file.get()<<endl;


		// size year of movie		
		temp = (long)file.get();
		cout<<"size of year "<<temp<<endl<<endl;

		while(temp--)
			cout<<"value temp "<<temp<<" "<<(char)file.get()<<endl;

	}
			file.close();

}
