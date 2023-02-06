#include "Item.h"


void Item::triggerEvent(Object* player){
    Player* p = dynamic_cast<Player*>(player);
    
    if(type == 0){
        cout << endl << "*There's a " << this->getName() << "*" << endl;
        sleep(1);
        cout << "Do you want to pick it up?" << endl;
        cout << " 1)Yes!" << endl << " 2)Nah" << endl;
        char o;
        cin >> o;
        if(o == '1'){
            cout << endl << "*You picked up " << this->getName() << "*" << endl;
            sleep(1);
            cout << "attack increase " << getAttack() << endl;
            cout << "defense increase " << getDefense() << endl;
            cout << "health increase " << getHealth() << endl;
            p->setAttack(p->getAttack() + getAttack());
            p->setDefense(p->getDefense() + getDefense());
            p->setCurrentHealth(p->getCurrentHealth() + getHealth());
            p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
            
        }
        else{
            cout << "Fine then, carry on"  << endl;
            
        }
    }
    else{
        vector<Item> me;
        me.push_back(*this);
        p->setInventory(me);
    }
    
}

void Item::triggerEvent2(Object* monster){
    Monster* m = dynamic_cast<Monster*>(monster);
    
    if(type == 1){
        sleep(1);
        cout << endl << "*You use the love potion!*" << endl;
        cout << "*Love is the solution to everything on this planet!*" << endl << endl;
        m->setCurrentHealth(0);
        sleep(1);
    }
    else if(type == 2){
        sleep(1);
        cout << endl << "*Hate cannot fix the problem.*" << endl;
        cout << "*But you did some damage to the monster.*" << endl << endl;
        m->setCurrentHealth(m->getCurrentHealth() - 30);
        sleep(1);
    }
    
}
/* Virtual function that you need to complete    */
/* In Item, this function should deal with the   */
/* pick up action. You should add status to the  */
/* player.                                       */

void Item::setHealth(int ch){
    health = ch;
}
void Item::setAttack(int at){
    attack = at;
}
void Item::setDefense(int de){
    defense = de;
}
int Item::getHealth(){
    return health;
}
int Item::getAttack(){
    return attack;
}
int Item::getDefense(){
    return defense;
}

