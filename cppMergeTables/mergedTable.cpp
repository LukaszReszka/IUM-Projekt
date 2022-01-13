#include "mergedTable.h"
#include <fstream>

#include "fileshelp.h"

TableRecord::TableRecord(int clid, std::string c, float m_spent, int y, int m, int n_products, int n_products_seen, float m_spent_next_month){
  client_id = clid;
  city = c;
  money_spent = m_spent;
  year = y;
  month = m;
  numberOfProducts = n_products;
  numberOfProductsSeen = n_products_seen;
  money_spent_next_month = m_spent_next_month;

}

MergedTable::MergedTable(Users & u, Sessions & s, Products & p, int year, int month){
  int client_id;
  std::string city;
  float money_spent;
  int numberOfProducts;
  int numberOfProductsSeen;
  float money_spent_next_month;
  int next_months_year;
  int next_month;
  if (month == 12){
    next_month = 1;
    next_months_year = year+1;
  } else{
    next_month = month+1;
    next_months_year = year;
  }

  for (auto itu = u.users.begin(); itu != u.users.end(); ++itu){
      client_id = itu->user_id;
      city = itu->city;

      money_spent = 0;
      numberOfProducts = 0;
      numberOfProductsSeen = 0;
      money_spent_next_month = 0;
      for (auto its = s.sessions.begin(); its != s.sessions.end(); ++its){
          if (its->user_id == client_id ){
              int y;
              int m;
              getMonthAndYear(its->timestamp, y, m);
              if (y == year && m == month){
                if (its->event_type == "BUY_PRODUCT"){
                  ++numberOfProducts;
                  for (auto itp = p.products.begin(); itp != p.products.end(); ++itp){
                    if (itp->product_id == its->product_id){
                      if (itp->price > 0){
                        money_spent += itp->price - ((float)its->offered_discount)/100 * itp->price;
                      }
                    }
                  }
                } else if (its->event_type == "VIEW_PRODUCT"){
                  ++numberOfProductsSeen;
                }
              } else if (y == next_months_year && m == next_month){
                if (its->event_type == "BUY_PRODUCT"){
                  for (auto itp = p.products.begin(); itp != p.products.end(); ++itp){
                    if (itp->product_id == its->product_id){
                      if (itp->price > 0){
                        money_spent_next_month += itp->price - ((float)its->offered_discount)/100 * itp->price;
                      }
                    }
                  }
                }
              }
          }
      }

      if (numberOfProducts != 0 || numberOfProductsSeen != 0 || money_spent_next_month != 0 ){
        TableRecord record(client_id, city, money_spent, year, month, numberOfProducts, numberOfProductsSeen, money_spent_next_month);
        records.push_back(record);
      }
  }
}


void MergedTable::printToFile(std::string file){
   std::ofstream outdata;

   outdata.open(file, std::ios_base::app);
   /*outdata << "client_id" << ","
   << "city" << ","
   << "money_spent" << ","
   << "year" << ","
   << "month" << ","
   << "numberOfProducts" << ","
   << "numberOfProductsSeen"
   << std::endl;*/
   for (auto it = records.begin(); it != records.end(); ++it){
      outdata << it->client_id << ","
      << it->city << ","
      << it->money_spent << ","
      << it->year << ","
      << it->month << ","
      << it->numberOfProducts << ","
      << it->numberOfProductsSeen << ","
	<< it->money_spent_next_month
      << std::endl;
   }
   outdata.close();

}
