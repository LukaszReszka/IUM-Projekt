#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <cstring>

class Product {
	public:
	int product_id;
	std::string product_name;
	std::string category_path;
	int price;
	
	Product(int proid, std::string proname, std::string catpath, int p);
};

class Products {
	public:
	std::vector<Product> products;
	
	void load(std::string filename);
	
};


#endif // PRODUCTS_H