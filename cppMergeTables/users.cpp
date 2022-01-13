#include "users.h"

#include <fstream>
#include "fileshelp.h"
#include <Vector>

User::User int usid, std::string n, std::string c, std::string s){
	user_id = usid;
	name = n;
	city = c;
	street = s;
}

void Users::load(std::string filename){
	std::string line;
	ifstream file (filename);
	if (file.is_open()){
		std::vector<std::string> words;
		getline (file,line); //first line is useless
		while ( getline (file,line) ){
			divideToWords(line, words);
			int user_id = std::stoi( words[0] );
			std::string name = words[1];
			std::string city = words[2];
			std::string street = words[3];
			User user(user_id, name, city, street)
			users.push_back(user);
		}
	
		myfile.close();
	}
}