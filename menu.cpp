/** : completed -> search () return movie found or null to avoid duplicate code in modify()
search() modify()
bug when file is has created yet and seek movie
should print message as showMovie() "unavailable file"

*/

/** to fix -> with new algorithms
modify() :246 :
modifyMovie(file, nameMovie, *movieToAdd, )
create a temporal, copy every movie seeking for name and then rename namefile, adding all movies with new modify movie

*/

/** completed -> modify search through search, and avoid overwrite code
search() modify()
comparate new algorithms

*/

/**
change name variables through defines to make generic

*/

/**
print only movies unhidden

*/

/**
#1
Bug OS Win : loadMovie() when the field dimension indicate 10 [ Ten ] its interpretated like \r when is \n
*/

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

void Menu::addMovie() {
	system(CLEAR);
	cout<<TITLE_ADD_MOVIE<<endl<<endl;

	Movie * movieToAdd = nullptr;

	ifstream* fileRead = alreadyExistFile(NAMEFILE, "");
	if (fileRead == nullptr) {

		movieToAdd = captureMovie();
		ofstream file(NAMEFILE, ofstream::app);
		writeMovie(&file, movieToAdd);
		cout<<endl<<endl<<CREATING_FILE;
		cout<<endl<<MOVIE_ADDED_SUCCESSFULLY<<endl;
		file.close();

	} else {
		cin.clear();
		cin.ignore();
		string tempName;
		do {
			cout<<GET_NAME_MOVIE;
			getline(cin, tempName);
		} while(tempName.find_first_not_of(" ") == string::npos);

		movieToAdd =  searchMovie(fileRead, tempName);

		fileRead->close();
		if(movieToAdd != nullptr) {

			cout<<endl<<endl;
			cout<<MESSAGE_MOVIE_DUPLICATED<<endl<<endl;

			printTitles();
			printMovie(movieToAdd);

		} else {
			movieToAdd = captureMovieWithoutName();
			movieToAdd->setName(tempName);
			ofstream file(NAMEFILE, ofstream::app);
			writeMovie(&file, movieToAdd);
			cout<<"\n"<<MOVIE_ADDED_SUCCESSFULLY<<endl;
			file.close();
		}
	}

	movieToAdd = nullptr;
	delete movieToAdd;

	cin.ignore();
	cin.get();
}

void Menu::showMovies() {
	system(CLEAR);
	cout<<TITLE_SHOW_MOVIES<<endl<<endl;

	ifstream* file = alreadyExistFile(NAMEFILE, ERROR_FILE_MESSAGE);
	if (file != nullptr) {
		unsigned long fileSize = (unsigned long )file->tellg(); /// cast for streampos is returned
		unsigned long* positionMovie = new unsigned long(START_FIRST_MOVIE);
		Movie* tempMovie = nullptr;

		printTitles();
		tempMovie = loadMovie(file, positionMovie, &fileSize);
		while(tempMovie != nullptr) {
			printMovie(tempMovie);
			tempMovie = nullptr;
			tempMovie = loadMovie(file, positionMovie, &fileSize);
		}
		file->close();
	}
	cin.ignore();
	cin.get();

	file = nullptr;
	delete file;
}

Movie* Menu::searchMovie() {
	system(CLEAR);
	cout<<TITLE_SEARCH_MOVIE<<endl<<endl;

	Movie* tempMovie = nullptr;
	cin.clear();

	ifstream* file = alreadyExistFile(NAMEFILE, ERROR_FILE_MESSAGE);
	if (file != nullptr) {
		string temp;
		cin.ignore();
		do {
			cout<<GET_NAME_MOVIE;
			getline(cin, temp);
		} while(temp.find_first_not_of(" ") == string::npos);


		tempMovie =  searchMovie(file, temp);

		if(tempMovie != nullptr) {
			printTitles();
			printMovie(tempMovie);
		} else cout<<MESSAGE_MOVIE_NOT_FOUND;

		file->close();
	}

	cin.get();
	cin.ignore();

	file = nullptr;
	delete file;

	return tempMovie;
}

void Menu::modifyMovie() {

	Movie* temp = searchMovie();

	if (temp != nullptr) {
		system(CLEAR);
		cout<<TITLE_MODIFY_MOVIE<<endl<<endl;

		printTitles();
		printMovie(temp);

		cout<<endl<<endl;
		cout<<"INSERT NEW MOVIE :"<<endl<<endl;


		cin.clear();
		cin.ignore();
		string tempName;
		do {
			cout<<GET_NAME_MOVIE;
			getline(cin, tempName);
		} while(tempName.find_first_not_of(" ") == string::npos);

		ifstream* fileRead = alreadyExistFile(NAMEFILE, ERROR_FILE_MESSAGE);
        /// fleWrite
		Movie* movieToAdd =  searchMovie(fileRead, tempName);

		fileRead->close();
		if(movieToAdd != nullptr) {

			cout<<endl<<endl;
			cout<<MESSAGE_MOVIE_DUPLICATED<<endl<<endl;

			printTitles();
			printMovie(movieToAdd);

		} else {

			/// pendig
			///fileWrite NAMEFILE & NAMEFILE_TEMP
			/// loadFirstMovie -> to recorre file...
            /// while loadFirstMovie != temp
                /// write loadFirstmovie in temp file
            /// if loadFirstMovie == temp
                /// write movieToAdd in temp file

                /// reaname different files....
                /// branch to use ffstream pointer as member class
                ///solution


			movieToAdd = captureMovieWithoutName();
			movieToAdd->setName(tempName);
			ofstream file(NAMEFILE, ofstream::app);
			writeMovie(&file, movieToAdd);
			cout<<"\n"<<MOVIE_ADDED_SUCCESSFULLY<<endl;
			file.close();
		}

	} else {
		return;
	}

	cin.ignore();
	cin.get();
}


Movie* Menu::captureMovie() {

	cin.ignore();
	cin.clear();

	string temp = "";
	Movie* movieToAdd = new Movie();

	do {
		cout<<GET_NAME_MOVIE;
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setName(temp);
	temp = "";

	do {
		cout<<GET_CATEGORY_MOVIE;
		cin.clear();
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setCategory(temp);
	temp = "";

	do {
		cout<<GET_YEAR_MOVIE;
		cin.clear();
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setYear(temp);
	temp = "";

	return movieToAdd;
}

Movie* Menu::captureMovieWithoutName() {

	cin.clear();

	string temp = "";
	Movie* movieToAdd = new Movie();

	do {
		cout<<GET_CATEGORY_MOVIE;
		cin.clear();
		getline(cin, temp);
	} while(temp.find_first_not_of(" ") == string::npos);
	movieToAdd->setCategory(temp);
	temp = "";

	do {
		cout<<GET_YEAR_MOVIE;
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

	if(*position == *fileSize)
		return nullptr;

	string temp = "";
	unsigned long tempDimension = 0;
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
/// bug :  TO:FIX #1
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

Movie* Menu::searchMovie(ifstream *file, string name, unsigned long* positionMovie) {

	unsigned long fileSize = (unsigned long )file->tellg(); /// cast for streampos is returned
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

void Menu::modifyMovie(ifstream* file, string name, Movie* movieToAdd) {

}

ifstream* Menu::alreadyExistFile(string name,  string message) {

	ifstream* file = nullptr;
	file = new ifstream(name, std::ifstream::ate | ifstream::binary);

	if(!*file) {
/// throw exception
		cout<<endl<<message<<endl;
		file = nullptr;
		delete file;
		return nullptr;
	}
	return file;
}

void Menu::printMovie(Movie* toPrint) {

	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left <<toPrint->getName();
	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left <<toPrint->getCategory();
	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left<<toPrint->getYear();
	cout<<endl;

}

void Menu::printTitles() {
	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left <<"NAME";
	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left <<"CATEGORY";
	std::cout.fill(' ');
	std::cout.width(MAX_CHARACTER_FOR_MOVIE);
	std::cout << std::left<<"YEAR";
	cout<<endl;

}

Movie* findDuplicateForName() {

}
