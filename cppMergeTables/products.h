#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>
#include <vector>

class Product {
	public:
	int product_id;
	std::string product_name;
	std::string category_path;
	float price;

	Product(int proid, std::string proname, std::string catpath, float p);
};

class Products {
	public:
	std::vector<Product> products;

	void load(std::string filename);

};


#endif // PRODUCTS_H
