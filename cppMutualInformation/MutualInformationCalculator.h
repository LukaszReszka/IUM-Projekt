#pragma once

#include <vector>
#include <string>

class Result {
public:
	int firstAttributeIndex;
	int secondAttributeIndex;
	float mutualInformation;
};



class MutualInformationCalculator{
public:

	std::vector<std::vector<int>> data;

	std::vector<std::vector<std::pair<int, int>>> uniqueValues;


	std::vector<Result> results;

	void updateUniqueValues(int value, std::vector<std::pair<int, int>>& valueCountPairs);

	void loadDataFromCsvFile(std::string fileName);

	void createUniqueValues();

	void calculateMutualInformations();

	float calculateMutualInformation(int firstAttrIndex, int secondAttrIndex);

	void createUniquePairsList(std::vector<std::pair<std::pair<int, int>, int>> & uniquePairsList, std::vector<int> attr1, std::vector<int> attr2);

	void updateUniquePairsList(std::vector<std::pair<std::pair<int, int>, int>> & uniquePairsList, std::pair<int, int> pair);

	int getUniqueValueCount(int value, int attrIndex);

	void printResultsToFile(std::string fileName);

	void mixData();
};

