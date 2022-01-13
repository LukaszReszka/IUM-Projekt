#include "users.h"

#include <fstream>
#include "fileshelp.h"
#include <iostream>

User::User (int usid, std::string n, std::string c, std::string s){
	user_id = usid;
	name = n;
	city = c;
	street = s;
}

void Users::load(std::string filename){
	std::string line = "";
	std::ifstream file (filename);
	if (file.is_open()){

		getline (file,line); //first line is useless
		while ( getline (file,line) ){
			std::vector<std::string> words;
			divideToWords(line, words);
			//std::cout << line ;
			int user_id = std::stoi( words[0] );
			std::string name = words[1];
			std::string city = words[2];
			std::string street = words[3];
			User user(user_id, name, city, street);
			users.push_back(user);
		}

		file.close();
	}
}

void Users::printToFile(std::string file){
   std::ofstream outdata;

   outdata.open(file);

   for (auto it = users.begin(); it != users.end(); ++it){
      outdata
      << it->user_id << ","
      << it->name << ","
      << it->city << ","
      << it->street
      << std::endl;
   }
   outdata.close();

}
