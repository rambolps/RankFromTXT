#include <iostream>
#include <fstream>
#include <string>
#include "RankGame.h"


int main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cout << "Invalid Number Of Arguments!" << std::endl;
		return 1;
	}

	std::fstream fileChoices;

	fileChoices.open(argv[1], std::ios::in);

	int numChoices = 0;

	if (fileChoices.is_open()) {
		std::string line;

		while (std::getline(fileChoices, line))
		{
			if (!line.empty()) {
				numChoices++;
			}
		}

		fileChoices.close();
		std::cout << "Loaded in the following " << numChoices << " choices from " << argv[1] << std::endl;
	} 
	else {
		std::cout << "Error When Trying To Open File!" << std::endl;
	}

	
	std::string* choices = new std::string[numChoices];

	fileChoices.open(argv[1], std::ios::in);

	if (fileChoices.is_open()) {
		std::string line;

		int cCount = 0;
		while (cCount < numChoices)
		{
			std::getline(fileChoices, line);
			if (!line.empty()) {
				choices[cCount] = line;
				cCount++;
			}
		}

		fileChoices.close();
	}

	for (int i = 0; i < numChoices; i++)
	{
		std::cout << (i+1) << ". " << choices[i] << std::endl;
	}

	std::cout << "\nReady To Start Ranking? [Y/n]: ";

	char answer;
	std::cin >> answer;
	std::string* rankedChoices = new std::string[numChoices];

	if (answer == 'y' || answer == 'Y') {
		std::cout << std::endl;
		rankedChoices = rankGame(choices, numChoices);
	}
	else {
		std::cout << "\'Y\' Was Not Pressed. Exiting Program." << std::endl;
		return 1;
	}

	std::cout << "\nThe Following Is Your Ranked Choices Stored In Ranked" << argv[1] << std::endl;

	std::fstream rankedFile;
	std::string rankedFileName = "Ranked_";
	rankedFileName.append(argv[1]);
	rankedFile.open(rankedFileName, std::ios::out);

	if (rankedFile.is_open()) {
		for (int i = 0; i < numChoices; i++)
		{
			std::cout << (i + 1) << ". " << rankedChoices[i] << std::endl;
			rankedFile << (i + 1) << ". " << rankedChoices[i] << std::endl;
		}

		rankedFile.close();
		std::cout << "\nFile Written as " << rankedFileName << std::endl;
	}
	else {
		std::cout << "ERROR: Could Not Write Output File!" << std::endl;
	}

	
} 