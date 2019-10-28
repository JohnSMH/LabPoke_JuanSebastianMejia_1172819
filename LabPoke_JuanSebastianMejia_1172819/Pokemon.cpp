#include "Pokemon.h"

Pokemon::Pokemon(char nomb[], int gen, int natnum) {
	Nombre = nomb;
	this->natnum = natnum;
	gennum = gen;
}

Pokemon::Pokemon()
{
}


Pokemon::~Pokemon()
{
}
