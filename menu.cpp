#include "menu.h"

using namespace std;

Menu::Menu() {

}

Menu::~Menu() {
}

void Menu::printMenu() {

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

void Menu::doAction(char option) {

	switch(option) {
	case ADD_MOVIE :
		addMovie();
		break;
	case SHOW_MOVIES :
		showMovies();
		break;
	case SEARCH_MOVIE :
		searchMovie();
		break;
	case MODIFY_MOVIE :
		modifyMovie();
		break;
	case DELETE :
		break;
	case HIDDEN_MOVIE :
		break;
	case RESTORE_MOVIE :
		break;
	case EXIT :
		break;
	}
}

void Menu::mainMenu() {

	char option;
	do {
		system(CLEAR);
		cin.clear();
		printMenu();

		cout<< "chose a option : ";
		cin>>option;

		if(option < ADD_MOVIE or option > EXIT ) {
			cout<<option<<" invalid option"<<endl;
			cin.ignore();
			cin.clear();
			cin.get();
		}
		doAction(option);
	} while(option != EXIT);
}

/// search the NAME movie in the file [duplicate()] []
/// if name movie dont exist, is posibnle write...
/// else, throw exception ¡is duplicate!
void Menu::addMovie() {
	system(CLEAR);
	cout<<TITLE_ADD_MOVIE<<endl<<endl;

	ifstream file(NAMEFILE, std::ifstream::ate | ifstream::binary);

	if(!file) {
/// throw exception
		cout<<ERROR_FILE_MESSAGE<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	Movie * movieToAdd = nullptr, * tempMovie = nullptr;
	movieToAdd = captureMovie();

	/// SEARCH FOR DUPLICATED NAME IN FILE EXIST

	tempMovie =  searchMovie(&file, movieToAdd->getName());

	file.close();
	if(tempMovie != nullptr) {

		cout<<MESSAGE_MOVIE_FOUND<<endl<<endl;
		cout<<MESSAGE_MOVIE_DUPLICATED<<endl<<endl;

		PRINT_TITLES_MOVIES
		cout<<tempMovie->getName();
		cout<<"\t\t\t"<<tempMovie->getCategory();
		cout<<"\t\t\t"<<tempMovie->getYear()<<endl;

	} else {

		ofstream file(NAMEFILE, ofstream::app);
		writeMovie(&file, movieToAdd);
		cout<<"\n"<<MOVIE_ADDED_SUCCESSFULLY<<endl;
        file.close();

	}
	tempMovie = movieToAdd = nullptr;
	delete tempMovie;
	delete movieToAdd;

	cin.ignore();
	cin.get();
}

// show all movies except status movies
void Menu::showMovies() {
	system(CLEAR);
	cout<<TITLE_SHOW_MOVIES<<endl<<endl;

	ifstream file(NAMEFILE, std::ifstream::ate | ifstream::binary);

	if(!file) {
/// throw exception
		cout<<endl<<ERROR_FILE_MESSAGE<<endl;
		cin.ignore();
		cin.get();
		return;
	}

	unsigned long fileSize = (unsigned long )file.tellg(); /// cast for streampos is returned
	unsigned long* positionMovie = new unsigned long(START_FIRST_MOVIE);
	Movie* tempMovie = nullptr;

	PRINT_TITLES_MOVIES
	tempMovie = loadMovie(&file, positionMovie, &fileSize);
	while(tempMovie != nullptr) {
		cout<<tempMovie->getName();
		cout<<"\t\t\t"<<tempMovie->getCategory();
		cout<<"\t\t\t"<<tempMovie->getYear()<<endl;
		tempMovie = nullptr;
		tempMovie = loadMovie(&file, positionMovie, &fileSize);
	}

	cin.ignore();
	cin.get();

	file.close();
}

void Menu::searchMovie() {
	system(CLEAR);
	cout<<TITLE_SEARCH_MOVIE<<endl<<endl;

	cin.ignore();
	cin.clear();
	string temp;
//Movie* movieToAdd = new Movie();

	do {
		cout<<"write name of movie : ";
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);

	cout<<"\n searching ...."<<endl<<endl;

	ifstream file(NAMEFILE, std::ifstream::ate | ifstream::binary);

	if(!file) {
/// throw exception
		cout<<endl<<ERROR_FILE_MESSAGE<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	Movie* tempMovie =  searchMovie(&file, temp);

	if(tempMovie != nullptr) {

		cout<<MESSAGE_MOVIE_FOUND<<endl<<endl;

		PRINT_TITLES_MOVIES
		cout<<tempMovie->getName();
		cout<<"\t\t\t"<<tempMovie->getCategory();
		cout<<"\t\t\t"<<tempMovie->getYear()<<endl;

	} else cout<<MESSAGE_MOVIE_NOT_FOUND;


	cin.ignore();
	cin.get();

	file.close();
}

void Menu::modifyMovie() {
	system(CLEAR);
	cout<<TITLE_SEARCH_MOVIE<<endl<<endl;

	cin.ignore();
	cin.clear();
	string temp;

	do {
		cout<<"write name of movie : ";
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);

	cout<<"\n searching ...."<<endl<<endl;

	ifstream file(NAMEFILE, std::ifstream::ate | ifstream::binary);

	if(!file) {
/// throw exception
		cout<<endl<<ERROR_FILE_MESSAGE<<endl;
		cin.ignore();
		cin.get();
		return;
	}
	Movie* tempMovie =  searchMovie(&file, temp);

	if(tempMovie != nullptr) {

		cout<<MESSAGE_MOVIE_FOUND<<endl<<endl;

		PRINT_TITLES_MOVIES
		cout<<tempMovie->getName();
		cout<<"\t\t\t"<<tempMovie->getCategory();
		cout<<"\t\t\t"<<tempMovie->getYear()<<endl;



	} else cout<<MESSAGE_MOVIE_NOT_FOUND;


	cin.ignore();
	cin.get();

	file.close();

}


Movie* Menu::captureMovie() {

	cin.ignore();
	cin.clear();

	string temp;
	Movie* movieToAdd = new Movie();

	do {
		cout<<"write name of movie : ";
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setName(temp);
	temp = "";

	do {
		cout<<"write category of movie : ";
		cin.clear();
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setCategory(temp);
	temp = "";

	do {
		cout<<"write year of movie : ";
		cin.clear();
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setYear(temp);
	temp = "";

	return movieToAdd;
}

void  Menu::writeMovie(ofstream* file, Movie* toAdd) {

	char sizeName, sizeCate, sizeYear, statusM;

	statusM = toAdd->getStatus();
	sizeName = toAdd->getName().length();
	sizeCate = toAdd->getCategory().length();
	sizeYear = toAdd->getYear().length();
// flags to hide 0
// by default 1
	file->write(&statusM, SIZE_DIMENSION_FILE);

// movie data
	file->write(&sizeName, SIZE_DIMENSION_FILE);
	file->write(toAdd->getName().c_str(), sizeName);

	file->write(&sizeCate, SIZE_DIMENSION_FILE);
	file->write(toAdd->getCategory().c_str(), sizeCate);

	file->write(&sizeYear, SIZE_DIMENSION_FILE);
	file->write(toAdd->getYear().c_str(), sizeYear);

}

Movie* Menu::loadMovie(std::ifstream* file, unsigned long* position, unsigned long* fileSize) {

// file->tellg() IMPROVE...
// VALIDATION EACH CALL

	if(*position == *fileSize)
		return nullptr;

	string temp;
	unsigned long tempDimension;
	char tempSource[*fileSize];
	memset(tempSource, 0, *fileSize);
	Movie* myMovie = nullptr;

// temp[0] hidden_normal status
	file->seekg(*position);
	file->read(tempSource, SIZE_DIMENSION_FILE);

/// validation if return nullptr

	myMovie = new Movie();
	myMovie->setStatus(tempSource[0]);

// temp[1] size_name (long)
	memset(tempSource, 0, *fileSize);
	file->seekg(file->tellg());
	file->read(tempSource, SIZE_DIMENSION_FILE);

	tempDimension =(long)tempSource[0];

	memset(tempSource, 0, *fileSize);
	file->read(tempSource, tempDimension);

	temp = tempSource;
	myMovie->setName(temp);

// temp[2] size_category (long)
	memset(tempSource, 0, *fileSize);
	file->seekg(file->tellg());
	file->read(tempSource, SIZE_DIMENSION_FILE);

	tempDimension =(long)tempSource[0];

	memset(tempSource, 0, *fileSize);
	file->read(tempSource, tempDimension);

	temp = tempSource;
	myMovie->setCategory(temp);

// temp[3] size_year (long)
	memset(tempSource, 0, *fileSize);
	file->seekg(file->tellg());
	file->read(tempSource, SIZE_DIMENSION_FILE);

	tempDimension =(long)tempSource[0];

	memset(tempSource, 0, *fileSize);
	file->read(tempSource, tempDimension);

	temp = tempSource;
	myMovie->setYear(temp);

	*position = file->tellg();

	return myMovie;
}

/// if exist return it
/// else return nullptr
Movie* Menu::searchMovie(ifstream *file, string name) {

	unsigned long fileSize = (unsigned long )file->tellg(); /// cast for streampos is returned
	unsigned long* positionMovie = new unsigned long(START_FIRST_MOVIE);
	Movie* tempMovie = nullptr;

	tempMovie = loadMovie(file, positionMovie, &fileSize);
	while(tempMovie != nullptr) {
		if (tempMovie->getName() == name )
			return tempMovie;

		tempMovie = nullptr;
		tempMovie = loadMovie(file, positionMovie, &fileSize);
	}

    positionMovie = nullptr;
    delete positionMovie;

	return tempMovie;
}

Movie* Menu::searchMovie(ifstream *file, string name, unsigned long* position) {

	unsigned long fileSize = (unsigned long )file->tellg(); /// cast for streampos is returned
	unsigned long* positionMovie = new unsigned long(START_FIRST_MOVIE);
	Movie* tempMovie = nullptr;

	tempMovie = loadMovie(file, positionMovie, &fileSize);
	while(tempMovie != nullptr) {
		if (tempMovie->getName() == name )
			return tempMovie;

		tempMovie = nullptr;
		tempMovie = loadMovie(file, positionMovie, &fileSize);
	}

    positionMovie = nullptr;
    delete positionMovie;

	return tempMovie;
}
