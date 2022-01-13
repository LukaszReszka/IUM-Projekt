#include "fileshelp.h"


void divideToWords(std::string line, std::vector<std::string> & words){
	std::string word = "";
	for (int i = 0 ; i < line.size();++i ) {
		if (line[i] == ','){
				words.push_back(word);
				word = "";
		} else {
			word.push_back(line[i]);
		}
	}
	words.push_back(word);
}


void getMonthAndYear(std::string timestamp, int & year, int & month){
	std::string word = "";
	std::vector<std::string> words;
	for (int i = 0 ; i < timestamp.size();++i ) {
		if (timestamp[i] == '-'){
				words.push_back(word);
				word = "";
		} else {
				word.push_back(timestamp[i]);
		}
	}
	words.push_back(word);

	year = std::stoi(words[0]);
	month = std::stoi(words[1]);

}
