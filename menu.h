#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>

#include "movie.h"

#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN32
    #define CLEAR "cls"
#endif

#define NAMEFILE "movies.txt"
#define NAMEFILE_TEMPORAL "~movies.txt"

#define TITLE_MAIN_MENU     "WELCOME TO MOVIES"

#define TITLE_ADD_MOVIE     " ADD MOVIE"
#define TITLE_SHOW_MOVIES   " SHOW MOVIE"
#define TITLE_SEARCH_MOVIE  " SEARCH MOVIE"
#define TITLE_MODIFY_MOVIE  " MODIFY MOVIE"
#define TITLE_DELETE        " DELETE MOVIE"
#define TITLE_HIDDEN_MOVIE  " HIDDEN MOVIE"
#define TITLE_RESTORE_MOVIE " RESTORE MOVIE"
#define TITLE_EXIT          " EXIT"

#define ADD_MOVIE       '1'
#define SHOW_MOVIES     '2'
#define SEARCH_MOVIE    '3'
#define MODIFY_MOVIE    '4'
#define DELETE          '5'
#define HIDDEN_MOVIE    '6'
#define RESTORE_MOVIE   '7'
#define EXIT            '8'

#define ERROR_FILE_MESSAGE "FILE " NAMEFILE " UNAVAILABLE"
/// max buffer size
#define MAX_SIZE 1024

class Menu {

public:
	Menu();
	~Menu();

	void printMenu(void);
	void doAction(char);
	void mainMenu(void);

	void addMovie(void);
	void showMovies();
	void searchMovie();

/// to manage file directly
	void writeMovie(Movie*);
	Movie* loadMovie();


	Movie captureMovie();
};

#endif // MENU_H_INCLUDED
