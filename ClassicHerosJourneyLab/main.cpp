#include <ctime>

#include "Hero.hpp"

void goOnQuest(Hero h);

int main() {
	//seed random function
	std::srand(std::time(nullptr));

	Hero hero1("Sir Awesome");
	Hero hero2("John Vyk");
	Hero hero3("Peter Griffin");


	return 0;
}

void goOnQuest(Hero h) {
	// Damage is set to 3 times the strength value of the hero so a hero with higher strength will be more likely to succeed
	int damage = h.getStrength() * 3;
	int enemy1Health = ((std::rand() % 100) + 1);
	enemy1Health -= damage;
	int enemy2Health = ((std::rand() % 100) + 1);
	enemy2Health -= damage;
	
	// SUCCESS
	if (enemy1Health <= 0 && enemy2Health <= 0) {
		std::cout << "The quest was a success! Congratulations " << h.getName() << '\n';
	}
	// NEUTRAL
	else if ((enemy1Health > 0 && enemy2Health <= 0) || (enemy1Health <= 0 && enemy2Health > 0)) {
		std::cout << "You were not able to defeat all enemies. At least you escaped alive, " << h.getName() << '\n';
		int heroCourage = h.getCourage();
		heroCourage -= 10;
		if (heroCourage < 0) {
			h.setCourage(0);
		}
		else {
			h.setCourage(heroCourage);
		}
	}
	// FAILURE
	else {
		std::cout << "The quest failed. You were not able to defeat either enemy. Good luck next time, " << h.getName() << '\n';
		int heroCourage = h.getCourage();
		heroCourage -= 25;
		if (heroCourage < 0) {
			h.setCourage(0);
		}
		else {
			h.setCourage(heroCourage);
		}
	}
}