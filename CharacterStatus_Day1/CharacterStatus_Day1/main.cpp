#include <iostream>
#include <vector>
#include "Character.h"
#include "Combat.h"

enum class BattleState {
	PlayerTurn,
	EnemyTurn,
	Victory,
	Defeat
};

void DisplayAllEnemies(const std::vector<Character>& enemies);
void DamageAllEnemies(std::vector<Character>& enemies, int damage);
void HealAllEnemies(std::vector<Character>& enemies, int healAmount);



using namespace std;

int main() {
	BattleState currentState = BattleState::PlayerTurn;

	Character player("Hero", 100, 5);

	std::vector<Character> enemies;

	enemies.emplace_back("Goblin", 60, 2);
	enemies.emplace_back("Orc", 100, 5);
	enemies.emplace_back("Skeleton", 45, 3);

	int playerChoiceOfEnemy; 
	bool repeatAction = true;

	while (repeatAction) {
		
		if (currentState == BattleState::PlayerTurn) {
			DisplayEnemies(enemies);

			cout << "Choose an enemy: ";

			if (!(cin >> playerChoiceOfEnemy)) {
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

			if (IsEnemyDefeated(enemies[enemyIndex])) {
				cout << enemies[enemyIndex].GetName() << " is already defeated." << endl;
				continue;
			}
			int playerAttackDamage;
			cout << "Enter damage to deal to " << enemies[enemyIndex].GetName() << ": "; 
			if (!(cin >> playerAttackDamage)) {
				cout << "Invalid input. Please enter a number." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			bool attackSucceeded = ProcessPlayerTurn(enemies, enemyIndex, playerAttackDamage);
			
			if (attackSucceeded) {
				if (AreAllEnemiesDefeated(enemies)) {
					cout << "All enemies have been defeated!" << endl;
					currentState = BattleState::Victory;
					repeatAction = false;
				}
				else {
					currentState = BattleState::EnemyTurn;
				}
			}

		}
		else if (currentState == BattleState::EnemyTurn) {
			cout << "Enemy's turn!" << endl;

			ProcessEnemyTurn(player, enemies);

			if(IsEnemyDefeated(player)) {
				cout << player.GetName() << " has been defeated!" << endl;
				currentState = BattleState::Defeat;
				repeatAction = false;
			}
			else {
				currentState = BattleState::PlayerTurn;
			}
		}

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





