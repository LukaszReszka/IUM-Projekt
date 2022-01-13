#include "sessions.h"

#include <fstream>
#include "fileshelp.h"


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
	std::ifstream file(filename);
	if (file.is_open()){
		getline (file,line); //first line is useless
		while ( getline (file,line) ){
			std::vector<std::string> words;
			divideToWords(line, words);
			int session_id;
			try {
				session_id = std::stoi(words[0]);
			} catch (...) {
				session_id = -1;
			}
			std::string timestamp = words[1];
			int user_id ;
			try {
				user_id = std::stoi(words[2]);
			} catch (...) {
				user_id = -1;
			}
			int product_id;
			try {
				product_id = std::stoi(words[3]);
		  } catch (...){
				product_id = -1;
			}
			std::string event_type = words[4];
			int offered_discount;

			try {
				offered_discount = std::stoi(words[5]);
			} catch (...){
				offered_discount = -1;
			}

			int purchase_id;
		  try {
				purchase_id = std::stoi(words[6]);
			} catch (...){
				purchase_id = -1;
			}
			Session session(session_id, timestamp, user_id, product_id, event_type, offered_discount, purchase_id);
			sessions.push_back(session);
		}

		file.close();
	}
}
