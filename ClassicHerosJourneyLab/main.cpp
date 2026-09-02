#include <ctime>

#include "Hero.hpp"

void goOnQuest(Hero& h);

int main() {
	//seed random function
	std::srand(std::time(nullptr));

	Hero hero1("Sir Awesome");
	Hero hero2("John Vyk");
	Hero hero3("Peta Griffers");
	Hero hero4("Satoru Gojo");

	std::cout << hero1.getName() << "'s Strength: " << hero1.getStrength() << '\n';
	std::cout << hero2.getName() << "'s Strength: " << hero2.getStrength() << '\n';
	std::cout << hero3.getName() << "'s Strength: " << hero3.getStrength() << '\n';
	std::cout << hero4.getName() << "'s Strength: " << hero4.getStrength() << "\n\n";

	std::cout << hero1.getName() << "'s Courage: " << hero1.getCourage() << '\n';
	std::cout << hero2.getName() << "'s Courage: " << hero2.getCourage() << '\n';
	std::cout << hero3.getName() << "'s Courage: " << hero3.getCourage() << '\n';
	std::cout << hero4.getName() << "'s Courage: " << hero4.getCourage() << "\n\n";

	goOnQuest(hero1);
	goOnQuest(hero2);
	goOnQuest(hero3);
	goOnQuest(hero4);
	
	std::cout << '\n';

	std::cout << hero1.getName() << "'s Courage: " << hero1.getCourage() << '\n';
	std::cout << hero2.getName() << "'s Courage: " << hero2.getCourage() << '\n';
	std::cout << hero3.getName() << "'s Courage: " << hero3.getCourage() << '\n';
	std::cout << hero4.getName() << "'s Courage: " << hero4.getCourage() << "\n\n";

	hero1.attendTraining(10);
	hero1.attendTherapy();
	std::cout << hero1.getName() << "'s Strength: " << hero1.getStrength() << '\n';

	std::cout << '\n';

	goOnQuest(hero1);

	return 0;
}

void goOnQuest(Hero& h) {
	// Damage is set to 2 times the strength value of the hero so a hero with higher strength will be more likely to succeed
	int damage = h.getStrength() * 2;
	int enemy1Health = ((std::rand() % 51) + 50);
	enemy1Health -= damage;
	int enemy2Health = ((std::rand() % 51) + 50);
	enemy2Health -= damage;
	
	// SUCCESS
	if (enemy1Health <= 0 && enemy2Health <= 0) {
		std::cout << "The quest was a success! Congratulations " << h.getName() << "!\n";
	}
	// NEUTRAL
	else if ((enemy1Health > 0 && enemy2Health <= 0) || (enemy1Health <= 0 && enemy2Health > 0)) {
		std::cout << "You were not able to defeat all enemies. At least you escaped alive, " << h.getName() << "!\n";
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
		std::cout << "The quest failed. You were not able to defeat either enemy. Good luck next time, " << h.getName() << ".\n";
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