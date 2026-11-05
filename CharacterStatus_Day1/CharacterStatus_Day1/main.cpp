#include <iostream>
#include <vector>
#include "Character.h"

void DisplayAllEnemies(const std::vector<Character>& enemies);
void DamageAllEnemies(std::vector<Character>& enemies, int damage);
void HealAllEnemies(std::vector<Character>& enemies, int healAmount);

using namespace std;

int main() {
	std::vector<Character> enemies;

	enemies.emplace_back("Goblin", 60, 2);
	enemies.emplace_back("Orc", 100, 5);
	enemies.emplace_back("Skeleton", 45, 3);

	int playerChoiceOfEnemy; 
	int playerChoiceOfDamage;
	bool repeatAction = true;
	bool repeatDamage = false;

	while (repeatAction) {
		cout << " === ENEMY TARGETING SYSTEM === " << endl;
		cout << "1." << enemies[0].GetName() << "   | " << enemies[0].GetHealth() << endl;
		cout << "2." << enemies[1].GetName() << "   | " << enemies[1].GetHealth() << endl;
		cout << "3." << enemies[2].GetName() << "   | " << enemies[2].GetHealth() << endl;
		cout << "0. Quit" << endl;

		cout << "Choose an enemy: ";

		if(!(cin >> playerChoiceOfEnemy)) {
			cout << "Invalid input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (playerChoiceOfEnemy == 0) {
			cout << "Exiting the game." << endl;
			repeatAction = false;
			continue;
		}

		if (playerChoiceOfEnemy < 1 || static_cast<std::size_t>(playerChoiceOfEnemy) > enemies.size()) {
			cout << "Invalid choice. Please select a valid enemy." << endl;
			continue;
		}

		int enemyIndex = playerChoiceOfEnemy - 1; // Adjust for zero-based index

		
		

	}

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