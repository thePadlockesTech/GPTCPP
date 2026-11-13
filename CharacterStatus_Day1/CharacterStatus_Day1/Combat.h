#pragma once

#include <vector>
#include "Character.h"

void DisplayEnemies(const std::vector<Character>& enemies);
void ProcessEnemyTurn(
	Character& player,
	const std::vector<Character>& enemies
);
bool ProcessPlayerTurn(
	std::vector<Character>& enemies,
	int targetIndex,
	int damage
);
bool IsEnemyDefeated(const Character& enemy);
bool AreAllEnemiesDefeated(const std::vector<Character>& enemies);
