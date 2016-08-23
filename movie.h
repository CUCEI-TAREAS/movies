#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define NAMEFILE "movies.txt"

#define ADD_MOVIE 	1
#define SHOW_MOVIES	2
#define SEARCH_MOVIE	3
#define MODIFY_MOVIE	4
#define DELETE		5
#define HIDDEN_MOVIE	6
#define RESTORE_MOVIE	7
#define EXIT		8

// SEARCH FOR NAME

class Movie {	
private:
	char name[50];
	char category[50];
	char year[10];

public:
	
	Movie();
	Movie(char*, char*, char*);
	~Movie();

	void getName(char*);
	void getCategory(char*);
	void getYear(char*);

	void setName(char*);
	void setCategory(char*);
	void setYear(char*);

};

#endif MOVIE_H_INCLUDED
