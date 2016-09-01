#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <string.h>
#include <string>

class Movie {
private:
	char status;
	std::string name;
	std::string category;
	std::string year;

public:

	Movie();
	~Movie();

    	char getStatus();
	std::string getName();
	std::string getCategory();
	std::string getYear();

    	void setStatus(char);
	void setName(std::string);
	void setCategory(std::string);
	void setYear(std::string);
};

#endif // MOVIE_H_INCLUDED
