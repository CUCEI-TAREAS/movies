#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <string.h>
// SEARCH FOR NAME

class Movie {
private:
	char name[50];
	char category[50];
	char year[10];

public:

	Movie();
	Movie(char[], char[], char[]);
	~Movie();

	char* getName();
	char* getCategory();
	char* getYear();

	void setName(char[]);
	void setCategory(char[]);
	void setYear(char[]);

};

#endif // MOVIE_H_INCLUDED
