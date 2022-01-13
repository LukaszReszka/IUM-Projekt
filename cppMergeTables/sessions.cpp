#include "sessions.h"

#include <fstream>
#include "fileshelp.h"
#include <Vector>

Session::Session(int sessid, std::string t_stamp, int usid, int prodid, std::string event, int offdisc, int purchid){
	session_id = sessid;
	timestamp = t_stamp;
	user_id = usid;
	product_id = prodid;
	event_type = event;
	offered_discount = offdisc;
	purchase_id = purchid;
	
}

void Sessions::load(std::string filename){
	std::string line;
	ifstream file(filename);
	if (file.is_open()){
		std::vector<std::string> words;
		getline (file,line); //first line is useless
		while ( getline (file,line) ){
			divideToWords(line, words);
			int session_id = std::stoi(words[0]);
			std::string timestamp = words[1];
			int user_id = std::stoi(words[2]);
			int product_id = std::stoi(words[3]);
			std::string event_type = words[4];
			int offered_discount = std::stoi(words[5]);
			int purchase_id = std::stoi(words[6]);
			Session session(session_id, timestamp, user_id, product_id, event_type, offered_discount, purchase_id)
			sessions.push_back(session);
		}
	
		myfile.close();
	}
}