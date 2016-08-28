#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <string.h>
#include <string>

class Movie {
private:
	std::string name;
	std::string category;
	std::string year;

public:

	Movie();
	~Movie();

	std::string getName();
	std::string getCategory();
	std::string getYear();

	void setName(std::string);
	void setCategory(std::string);
	void setYear(std::string);

};

#endif // MOVIE_H_INCLUDED
