#pragma once

#include <string>

class Character {
private:
	std::string name;
	int health;
	int maxHealth;
	int armor;

public:
	Character(std::string characterName, int startingHealth, int startingArmor);
	Character(const Character& other);
	~Character();
	
	void TakeDamage(int damage);
	void Heal(int healAmount);
	void SetArmor(int armorValue);
	
	int GetHealth() const;
	int GetArmor() const;
	std::string GetName() const;



};