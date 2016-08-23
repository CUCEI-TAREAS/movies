#include "movie.h"

Movie::Movie(){
	memcpy(name, 0, sizeof(name));	
	memcpy(category, 0, sizeof(name));
	memcpy(year, 0, sizeof(name));
}

Movie::Movie(char &na, char &catego, char &ye){
	memcpy(name, na, sizeof(na));
	memcpy(category, catego, sizeof(category));
	memcpy(year, ye, sizeof(ye));
}

Movie::getName(char &na){
	memcpy(na, name, sizeof(name));
}

Movie::getCategory(char &cate){
	memcpy(cate, category, sizeof(category));
}

Movie::getYear(char &ye){
	memcpy(ye, year, sizeof(year));
}

Movie::setName(char &na){
	memcpy(name, na, sizeof(na));
}

Movie::setCategory(char &cate){
	memcpy(category, cate, sizeof(cate));
}

Movie::setYear(char &ye){
	memcpy(year, ye, sizeof(ye));
}

