#include "movie.h"

using namespace std;

Movie::Movie(){
    status =  1;
}


Movie::~Movie(){
}

char Movie::getStatus(){
    return status;
}

string Movie::getName(){
	return name;
}

string  Movie::getCategory(){
	return category;
}

string Movie::getYear(){
	return year;
}
void Movie::setSatus(char s){
    status = s;
}

void Movie::setName(string na){
	name = na;
}

void Movie::setCategory(string cate){
	category = cate;
}

void Movie::setYear(string ye){
	year = ye;
}

