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