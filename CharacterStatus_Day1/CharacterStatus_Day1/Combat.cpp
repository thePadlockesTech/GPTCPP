#include "Combat.h"
#include <iostream>

using namespace std;

void DisplayEnemies(const std::vector<Character>& enemies) {
	std::cout << "=== ENEMY TARGETING SYSTEM ===" << std::endl;
	for (std::size_t i = 0; i < enemies.size(); i++)
	{
		std::cout << i + 1 << ". " << enemies[i].GetName() << " - Health: " << enemies[i].GetHealth() << std::endl;
	}
	std::cout << "0. Quit" << std::endl;
}

void ProcessEnemyTurn(
	Character& player,
	const std::vector<Character>& enemies
) {
	for (const Character& enemy : enemies) {
		if (!IsEnemyDefeated(enemy)) {
			int playerHealthBeforeDamage = player.GetHealth();
			player.TakeDamage(12);
			int playerHealthAfterDamage = player.GetHealth();
			cout << enemy.GetName() << " attacks! " << player.GetName() << " took " << playerHealthBeforeDamage - playerHealthAfterDamage << " damage. Remaining health: " << player.GetHealth() << endl;
			break;
		}
	}
}

bool ProcessPlayerTurn(
	std::vector<Character>& enemies,
	int targetIndex,
	int damage)
{
	if (targetIndex >= 0 && static_cast<std::size_t>(targetIndex) < enemies.size() && damage >= 0 && !IsEnemyDefeated(enemies[targetIndex])) {
		int healthBeforeDamage = enemies[targetIndex].GetHealth();
		enemies[targetIndex].TakeDamage(damage);
		int healthAfterDamage = enemies[targetIndex].GetHealth();
		cout << enemies[targetIndex].GetName() << " took " << healthBeforeDamage - healthAfterDamage << " damage. Remaining health: " << enemies[targetIndex].GetHealth() << endl;
		return true;
	}
	else {
		cout << "Invalid target or damage amount." << endl;
		return false;
	}
}

bool IsEnemyDefeated(const Character& enemy) {
	return enemy.GetHealth() <= 0;
}

bool AreAllEnemiesDefeated(const std::vector<Character>& enemies) {
	for (const Character& enemy : enemies) {
		if (!IsEnemyDefeated(enemy)) {
			return false;
		}
	}
	return true;
}

