#include "fileshelp.h"

void divideToWords(std::string line, std::vector<std::string> & words){
	std::string word = "";
	
	for (int i = 0 ; i < line.size();++i ) {
		if (line[i] == ','){
				words.push_back(word);
		} else {
			word.push_back(line[i]);
		}
	}
	words.push_back(word);
}
