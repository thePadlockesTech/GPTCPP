#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Character {
private:
	std::string name = "Unknown"; 
	int health = 100;
	int maxHealth = 100;
	int armor = 0;

public:
	Character(std::string characterName, int startingHealth, int startingArmor) : 
	name(characterName), health(startingHealth), maxHealth(100), armor(startingArmor) {
	
	}

	void TakeDamage(int damage) {
		if (damage < 0) {
			std::cout << "Damage cannot be negative." << std::endl;
			return;
		}

		health -= (std::max(0, damage - armor));
		if (health < 0) {
			health = 0;
		}
	}

	void Heal(int healAmount) {
		if (healAmount < 0) {
			std::cout << "Heal amount cannot be negative." << std::endl;
			return;
		}
		health += healAmount;
		if (health > maxHealth) {
			health = maxHealth;
		}
	}

	int GetHealth() const {
		return health;
	}

	void SetArmor(int armorValue) {
		if (armorValue < 0) {
			std::cout << "Armor cannot be negative." << std::endl;
			return;
		}
		armor = armorValue;
	}

	const std::string& GetName() {
		return name;
	}
};


int main() {
	Character Goblin("Goblin", 60, 2);
	Character Orc("Orc", 100, 5);
	Character Skeleton("Skeleton", 45, 3);

	cout << Goblin.GetName() << endl;
	cout << Orc.GetName() << endl;
	cout << Skeleton.GetName() << endl;
	cout << Goblin.GetHealth() << endl;
	cout << Orc.GetHealth() << endl;
	cout << Skeleton.GetHealth() << endl;

	Goblin.TakeDamage(20);
	Orc.TakeDamage(20);
	Skeleton.TakeDamage(20);

	cout << Goblin.GetHealth() << endl;
	cout << Orc.GetHealth() << endl;
	cout << Skeleton.GetHealth() << endl;

	Skeleton.Heal(30);
	cout << Skeleton.GetHealth() << endl;



}
