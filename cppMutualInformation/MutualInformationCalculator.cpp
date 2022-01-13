#include "MutualInformationCalculator.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

void divideToWords(std::string line, std::vector<std::string>& words) {
	std::string word = "";
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == ',') {
			words.push_back(word);
			word = "";
		}
		else {
			word.push_back(line[i]);
		}
	}
	words.push_back(word);
}

void MutualInformationCalculator::updateUniqueValues(int value, std::vector<std::pair<int, int>> & valueCountPairs) {
	for (auto it = valueCountPairs.begin(); it != valueCountPairs.end(); ++it) {
		if (it->first == value) {
			++it->second;
			return ;
		}
	}	
	valueCountPairs.push_back(std::pair<int, int>(value, 1));
}

void MutualInformationCalculator::loadDataFromCsvFile(std::string fileName){
	std::string line;
	std::ifstream file(fileName);
	if (file.is_open()) {
		std::vector<std::string> words;
		getline(file, line);
		divideToWords(line, words);
		int attrNum = words.size();
		for (int i = 0; i < attrNum; ++i) {
			std::vector<int> attrData;
			data.push_back(attrData);
		}
		while (getline(file, line)) {
			words.clear();
			divideToWords(line, words);
			for (int i = 0; i < attrNum; ++i) {
				data[i].push_back(std::stoi(words[i]));
			}
		}
		

		file.close();
	}
}

void MutualInformationCalculator::createUniqueValues(){
	for (auto it = data.begin(); it != data.end(); ++it){
		std::vector<std::pair<int, int>> valueCountPairs;
		for (auto attrIt = it->begin(); attrIt != it->end(); ++attrIt) {
			updateUniqueValues(*attrIt, valueCountPairs);
		}
		uniqueValues.push_back(valueCountPairs);
	}
}

void MutualInformationCalculator::calculateMutualInformations(){
	results.clear();
	uniqueValues.clear();
	createUniqueValues();
	for (int i = 0; i < data.size(); ++i) {
		for (int j = i + 1; j < data.size(); ++j) {
			Result result;
			result.firstAttributeIndex = i;
			result.secondAttributeIndex = j;
			result.mutualInformation = calculateMutualInformation(i, j);
			results.push_back(result);
		}
	}
}

float MutualInformationCalculator::calculateMutualInformation(int firstAttrIndex, int secondAttrIndex)
{
	std::vector<std::pair<std::pair<int, int>, int>> uniquePairsList;
	createUniquePairsList(uniquePairsList, data[firstAttrIndex], data[secondAttrIndex]);
	float mutualInformation = 0;
	for (auto it = uniquePairsList.begin(); it != uniquePairsList.end(); ++it) {
		int dataRowsNum = data[0].size();
		float pairProb = ((float)it->second) / ((float)dataRowsNum);
		float firstProb = ((float)getUniqueValueCount(it->first.first, firstAttrIndex)) / (float)dataRowsNum;
		float secondProb = ((float)getUniqueValueCount(it->first.second, secondAttrIndex)) / (float)dataRowsNum;
		mutualInformation += pairProb * log(pairProb / (firstProb * secondProb));
	}
	return mutualInformation;
}

void MutualInformationCalculator::createUniquePairsList(std::vector<std::pair<std::pair<int, int>, int>>& uniquePairsList, std::vector<int> attr1, std::vector<int> attr2){
	for (int i = 0; i < attr1.size(); ++i) {
		updateUniquePairsList(uniquePairsList, std::pair<int, int>(attr1[i], attr2[i]));
	}
}

void MutualInformationCalculator::updateUniquePairsList(std::vector<std::pair<std::pair<int, int>, int>> & uniquePairsList, std::pair<int, int> pair){
	for (auto it = uniquePairsList.begin(); it != uniquePairsList.end(); ++it) {
		if (it->first == pair) {
			++it->second;
			return;
		}
	}
	uniquePairsList.push_back(std::pair<std::pair<int, int>, int>(pair, 1));
}

int MutualInformationCalculator::getUniqueValueCount(int value, int attrIndex){
	for (auto it = uniqueValues[attrIndex].begin(); it != uniqueValues[attrIndex].end(); ++it) {
		if (it->first == value) {
			return it->second;
		}
	}
	return -1;
}

void MutualInformationCalculator::printResultsToFile(std::string fileName){
	std::ofstream outdata;
	outdata.open(fileName, std::ios_base::app);

	for (auto it = results.begin(); it != results.end(); ++it) {
		outdata << it->firstAttributeIndex << " " << it->secondAttributeIndex << " " << it->mutualInformation << std::endl;
	}
	outdata.close();
}

void MutualInformationCalculator::mixData(){
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, data[0].size()-1); // define the range
	for (int i = 0; i < data.size(); ++i){
		for (int j = 0; j < data[i].size() * 3; ++j) {
			int idx1 = distr(gen);
			int idx2 = distr(gen);
			int buffer = data[i][idx1];
			data[i][idx1] = data[i][idx2];
			data[i][idx2] = buffer;
		}
	}
}
