#ifndef SESSIONS_H
#define SESSIONS_H

#include <cstring>

class Session {
	public:
	int session_id;
	std::string timestamp;
	int user_id;
	int product_id;
	std::string event_type;
	int offered_discount;
	int purchase_id;
	
	Session(int sessid, std::string t_stamp, int usid, int prodid, std::string event, int offdisc, int purchid);
};

class Sessions {
	public:
	std::vector<Session> sessions;
	
	void load(std::string filename);
};


#endif // SESSIONS_H