#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

class Hero {
private:
	int strength;
	int courage;
	std::string name;

public:
	// Constructor
	Hero(std::string n);

	// Methods
	void attendTraining(int time);
	void attendTherapy();

	// Getters & Setters
	std::string getName();
	int getStrength();
	int getCourage();
	void setCourage(int c);

};