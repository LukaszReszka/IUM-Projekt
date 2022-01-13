#ifndef FILESHELP_H
#define FILESHELP_H

#include <vector>
#include <string>

void divideToWords(std::string line, std::vector<std::string> & words);
void getMonthAndYear(std::string timestamp, int & year, int & month);

#endif // FILESHELP_H
