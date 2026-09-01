#pragma once

#include <cstdlib>
#include <string>

class Hero {
private:
	int strength;
	int courage;
	std::string name;

public:
	Hero(std::string n) {
		strength = ((std::rand() % 100) + 1);
		courage = ((std::rand() % 100) + 1);
		name = n;
	}

	int getStrength() {
		return strength;
	}

	int getCourage() {
		return courage;
	}

	void setCourage(int c) {
		courage = c;
	}

};