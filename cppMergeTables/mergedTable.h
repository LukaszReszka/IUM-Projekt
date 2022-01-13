#ifndef MERGEDTABLE_H
#define MERGEDTABLE_H

#include <string>
#include <vector>

#include "users.h"
#include "sessions.h"
#include "products.h"

class TableRecord {
	public:
    int client_id;
    std::string city;
    float money_spent;
    int year;
    int month;
    int numberOfProducts;
    int numberOfProductsSeen;
		float money_spent_next_month;
    TableRecord(int clid, std::string c,float m_spent, int y, int m, int n_products, int n_products_seen, float m_spent_next_month);
};

class MergedTable {
	public:
	std::vector<TableRecord> records;

	MergedTable(Users & users, Sessions & sessions, Products & products, int year, int month);

  void printToFile(std::string file);


};


#endif // MERGEDTABLE_H
