#include <iostream>

#include "users.h"
#include "sessions.h"
#include "products.h"


int main(){
	Users users;
	Sessions sessions;
	Products products;
	users.load("csvfiles\\users.csv");
	sessions.load("csvfiles\\sessions.csv");
	products.load("csvfiles\\products.csv");
	return 0;
}