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
	
	do{
	cout<<"write name of movie : ";
	getline(cin, temp);
	}while(temp.find_first_not_of(" ") == string::npos);
	temp = "";
	movieToAdd.setName(temp);
		
	do{
	cout<<"write category of movie : ";
	cin.clear();
	getline(cin, temp);
	}while(temp.find_first_not_of(" ") == string::npos);
	temp = "";
	movieToAdd.setCategory(temp);
	
	do{
	cout<<"write year of movie : ";
	cin.clear();
	getline(cin, temp);
	}while(temp.find_first_not_of(" ") == string::npos);
	temp = "";
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
		cin.ignore();
		cin.get();
		return nullptr;
	}
	
	// temp[0] hidden_normal
	// temp[1] size_name

	char temp[MAX_SIZE];
	memset(temp, 0, MAX_SIZE);

	file.read(temp, 200);
	

	file.read(temp, 3);
	cout<<temp<<endl;


	cin.ignore();	
	cin.get();
	
	
	file.close();

}
