#include "movie.h"

Movie::Movie(){
}

Movie::Movie(char na[], char catego[], char ye[]){
	memcpy(name, na, sizeof(na));
	memcpy(category, catego, sizeof(category));
	memcpy(year, ye, sizeof(ye));
}

Movie::~Movie(){

}

char* Movie::getName(){
	return name;
}

char*  Movie::getCategory(){
	return category;
}

char*  Movie::getYear(){
	return year;
}

void Movie::setName(char na[]){
	memcpy(name, na, sizeof(na));
}

void Movie::setCategory(char cate[]){
	memcpy(category, cate, sizeof(cate));
}

void Movie::setYear(char ye[]){
	memcpy(year, ye, sizeof(ye));
}

