#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "movie.h"

#define NAMEFILE "movies.txt"
#define NAMEFILE_TEMPORAL "~movies.txt"

#define ADD_MOVIE '1'
#define SHOW_MOVIES '2'
#define SEARCH_MOVIE '3'
#define MODIFY_MOVIE '4'
#define DELETE '5'
#define HIDDEN_MOVIE '6'
#define RESTORE_MOVIE '7'
#define EXIT '8'

class Menu {

private:
	std::ofstream file();

public:	
	Menu();
	~Menu();
	
	void printMenu(void);
	void doAction(char);
	void mainMenu(void);

	void addMovie(void);
	void showMovies();
	void searchMovie();

	void writeMovie();
	void readMovie();


	void captureMovie();
};

#endif // MENU_H_INCLUDED
