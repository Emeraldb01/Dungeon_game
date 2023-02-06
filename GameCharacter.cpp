#include "GameCharacter.h"

void GameCharacter::setMaxHealth(int mh){
    maxHealth = mh;
}
void GameCharacter::setCurrentHealth(int ch){
    currentHealth = ch;
}
void GameCharacter::setAttack(int at){
    attack = at;
}
void GameCharacter::setDefense(int de){
    defense = de;
}
int GameCharacter::getMaxHealth(){
    return maxHealth;
}
int GameCharacter::getCurrentHealth(){
    return currentHealth;
}
int GameCharacter::getAttack(){
    return attack;
}
int GameCharacter::getDefense(){
    return defense;
}

