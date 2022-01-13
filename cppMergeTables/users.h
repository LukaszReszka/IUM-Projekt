#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>

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
	void printToFile(std::string file);

};


#endif // USERS_H
