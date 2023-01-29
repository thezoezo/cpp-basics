#include <iostream>
#include "random_value.h"
#include <cstdlib>
#include <ctime>

int getRandomValue() {

	std::srand(std::time(nullptr)); 
     
	const int max_value = 100;
	const int random_value = std::rand() % 100;

	return random_value; 
}