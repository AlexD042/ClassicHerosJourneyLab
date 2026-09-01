#include "Hero.hpp"

Hero::Hero(std::string n) {
	strength = ((std::rand() % 100) + 1);
	courage = ((std::rand() % 100) + 1);
	name = n;
}

void Hero::attendTraining(int time) {
	int strengthIncrease = (time * 3);
	strength += strengthIncrease;
	std::cout << "You gained " << strengthIncrease << "strength!\n";
}

void Hero::attendTherapy() {
	int courageIncrease = ((std::rand() % 10) + 1);
	courage += courageIncrease;
	std::cout << "You gained " << courageIncrease << "courage!\n";
}

std::string Hero::getName() {
	return name;
}

int Hero::getStrength() {
	return strength;
}

int Hero::getCourage() {
	return courage;
}

void Hero::setCourage(int c) {
	courage = c;
}