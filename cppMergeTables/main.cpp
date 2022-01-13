#include <iostream>

#include "users.h"
#include "sessions.h"
#include "products.h"
#include "mergedTable.h"


int main(){
	Users users;
	Sessions sessions;
	Products products;
	users.load("csvfiles/users.csv");
	sessions.load("csvfiles/sessions.csv");
	products.load("csvfiles/products.csv");

	for (int i = 10; i <= 12; ++i){
		MergedTable mergedTable(users, sessions, products, 2020, i);
		mergedTable.printToFile("merged.csv");
	}

	for (int i = 1; i < 12; ++i){
		MergedTable mergedTable(users, sessions, products, 2021, i);
		mergedTable.printToFile("merged.csv");
	}

	

	return 0;
}
