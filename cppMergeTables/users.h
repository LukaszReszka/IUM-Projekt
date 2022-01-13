#ifndef USERS_H
#define USERS_H

#include <cstring>
#include <Vector>

class User {
	public:
	int user_id;
	std::string name;
	std::string city;
	std::string street;
	
	User (int usid, std::string n, std::string c, std::string s);
};

class Users {
	public:
	std::vector<User> users;
	
	void load(std::string filename);
	
	
};


#endif // USERS_H