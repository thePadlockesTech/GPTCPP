#include "Character.h"
#include <algorithm>
#include <iostream>

Character::Character(std::string characterName, int startingHealth, int startingArmor)
	: name(characterName), 
	health(startingHealth), 
	maxHealth(100), 
	armor(startingArmor) {}

Character::Character(const Character& other)
	: name(other.name),
	health(other.health),
	maxHealth(other.maxHealth),
	armor(other.armor) {
std::cout << name << " copied.\n";
}

Character::~Character() {
	//std::cout << name << " destroyed.\n";
}

void Character::TakeDamage(int damage) {
	if (damage < 0) {
		std::cout << "Damage cannot be negative." << std::endl;
		return;
	}
	health = std::max(0, health - std::max(0, damage - armor));
}

void Character::Heal(int amount) {
	if (amount < 0) {
		std::cout << "Heal amount cannot be negative." << std::endl;
		return;
	}
	health = std::min(maxHealth, health + amount);
}

void Character::SetArmor(int newArmor) {
	if (newArmor < 0) {
		std::cout << "Armor cannot be negative." << std::endl;
		return;
	}
	armor = newArmor;
}

int Character::GetHealth() const {
	return health;
}

std::string Character::GetName() const {
	return name;
}