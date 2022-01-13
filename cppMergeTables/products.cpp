#include "products.h"

#include <fstream>
#include "fileshelp.h"

Product::Product(int proid, std::string proname, std::string catpath, float p){
	product_id = proid;
	product_name = proname;
	category_path = catpath;
	price = p;
}

void Products::load(std::string filename){
	std::string line;
	std::ifstream file(filename);
	if (file.is_open()){
		getline (file,line); //first line is useless
		while ( getline (file,line) ){
			std::vector<std::string> words;
			divideToWords(line, words);
			int product_id = std::stoi(words[0]);
			std::string product_name = words[1];
			std::string category_path = words[2];
			float price = std::stof(words[3]);
			Product product(product_id, product_name, category_path, price);
			products.push_back(product);
		}

		file.close();
	}
}
