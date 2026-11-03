#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Character {
private:
	std::string name = "Unknown"; 
	int health = 100;
	int maxHealth = 100;
	int armor = 0;

public:
	Character(std::string characterName, int startingHealth, int startingArmor) : 
	name(characterName), 
	health(startingHealth), 
	maxHealth(100), 
	armor(startingArmor) {
	
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

	std::string GetName() const {
		return name;
	}
};

void DisplayAllEnemies(const std::vector<Character>& enemies);
void DamageAllEnemies(std::vector<Character>& enemies, int damage);
void HealAllEnemies(std::vector<Character>& enemies, int healAmount);


int main() {
	std::vector<Character> enemies;

	enemies.emplace_back("Goblin", 60, 2);
	enemies.emplace_back("Orc", 100, 5);
	enemies.emplace_back("Skeleton", 45, 3);

	DisplayAllEnemies(enemies);
	DamageAllEnemies(enemies, 25);
	HealAllEnemies(enemies, 10);
	DisplayAllEnemies(enemies);
}

void DisplayAllEnemies(const std::vector<Character>& enemies) {
	for (const Character& enemy : enemies) {
		std::cout << enemy.GetName() << " - Health: " << enemy.GetHealth() << std::endl;
	}
}

void DamageAllEnemies(std::vector<Character>& enemies, int damage) {
	for (Character& enemy : enemies) {
		enemy.TakeDamage(damage);
	}
}

void HealAllEnemies(std::vector<Character>& enemies, int healAmount) {
	for (Character& enemy : enemies) {
		enemy.Heal(healAmount);
	}
}