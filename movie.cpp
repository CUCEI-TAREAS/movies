#include "movie.h"

using namespace std;

Movie::Movie(){
}


Movie::~Movie(){

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

void Movie::setName(string na){
	name = na;
}

void Movie::setCategory(string cate){
	category = cate;
}

void Movie::setYear(string ye){
	year = ye;
}

