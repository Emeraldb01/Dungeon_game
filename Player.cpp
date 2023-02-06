#include "Player.h"

void Player::addItem(Item i){
    inventory.push_back(i);
}
void Player::increaseStates(int ch,int a,int d){
    setCurrentHealth(getCurrentHealth() + ch);
    setAttack(getAttack() + a);
    setDefense(getDefense() + d);
}

void Player::changeRoom(Room* next){
    
    setPreviousRoom(getCurrentRoom());
    setCurrentRoom(next);
    cout << "current room: " << getCurrentRoom()->getIndex() << endl;
    
}

/* Virtual function that you need to complete   */
/* In Player, this function should show the     */
/* status of player.                            */
void Player::triggerEvent(Object* o){
    cout << "Health: " << getCurrentHealth() << " / " << getMaxHealth() << endl;
    cout << "Attack: " << getAttack() << endl << "Defense: " << getDefense() << endl;
    
}

/* Set & Get function*/
void Player::setCurrentRoom(Room* cr){
    currentRoom = cr;
}
void Player::setPreviousRoom(Room* pr){
    previousRoom = pr;
}
void setInventory(vector<Item>);


Room* Player::getCurrentRoom(){
    return currentRoom;
}
Room* Player::getPreviousRoom(){
    return previousRoom;
}


vector<Item> Player::getInventory(){
    return inventory;
}
