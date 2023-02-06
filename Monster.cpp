#include "Monster.h"

void Monster::triggerEvent(Object* player){
    //retreat or fight
    Player* p = dynamic_cast<Player*>(player);
    
    cout << endl << "You've encountered " << getName() << endl;
    while(getCurrentHealth() > 0 && p->getCurrentHealth() > 0){
        
        cout << "Monster Health: " << getCurrentHealth() << " / " << getMaxHealth() << endl;
        cout << "Monster Attack: " << getAttack() << endl << "Monster Defence: " << getDefense() << endl;
        cout << " 1) Retreat" << endl << " 2) Fight!" << endl << " 3) Use Item!" << endl;;
        int act;
        cin >> act;
        if(act == 1 && getCurrentHealth() >= 0){
            p->changeRoom(p->getPreviousRoom());
            break;
        }
        else if(act == 2 && getCurrentHealth() >= 0){
            cout << endl << "You choose fight!!!" << endl;
            sleep(1);
            cout << "*You attack!*" << endl;
            setCurrentHealth(getCurrentHealth() - p->getAttack() + getDefense());
            sleep(1);
            if(getCurrentHealth() >= 0){
                p->setCurrentHealth(p->getCurrentHealth() - getAttack() + p->getDefense());
                cout << "*You were attacked, minus " << getAttack() - p->getDefense() << " health*" <<endl << endl;
                if(p->getCurrentHealth() > 0){
                    sleep(1);
                    cout << "Your state: " << endl;
                    cout << "Health: " << p->getCurrentHealth() << " / " << p->getMaxHealth() << endl;
                    cout << "Attack: " << p->getAttack() << endl << "Defense: " << p->getDefense() << endl;
                    cout << "Inventory: ";
                    for(int i = 0; i < p->getInventory().size(); i++){
                        cout << p->getInventory()[i].getName() << " ";
                    }
                    cout << endl << endl;
                }
                else{
                    p->end = 1;
                    break;
                }
                
            }
        }
        else if (act == 3 && getCurrentHealth() >= 0){
            cout << "Do you want to...";
            cout << endl << " 1) Don't use anything";
            for(int i = 0; i < p->getInventory().size(); i++){
                cout << endl << " " << i + 2 << ") Use " << p->getInventory()[i].getName() << endl;
            }
            
            int act;
            cin >> act;
            for(int i = 0; i < p->getInventory().size(); i++){
                if(act == i+2){
                    p->getInventory()[i].triggerEvent2(this);
                    vector<Item> tem;
                    tem = p->getInventory();
                    tem.pop_back();
                    p->setInventory(tem);
                     
                }
            }
        }
        else{
            cout << "*wrong input!!*" << endl;
        }
        if((getCurrentHealth() <= (getMaxHealth()/2)) && type == 1){
            cout << endl << "*Lil Nas x enter INSANE mode*" << endl;
            cout << "Monster attack increase 20" << endl << "Monster defense increase 20" << endl;
            setAttack(getAttack() + 20);
            setDefense(getDefense() + 20);
            type = 0;
        }
    }
    if(p->getCurrentHealth() >  0 && getCurrentHealth() <= 0){//undone
    cout << "*The monster dissapear*" << endl << "*You can now carry on*" << endl;
        p->getCurrentRoom()->popObject(p->getCurrentRoom()->getObjects());
        if(p->getCurrentRoom()->getIndex() == 10){
            p->end = 1;
        }
    }
    
}

/* Virtual function that you need to complete   */
/* In Monster, this function should deal with   */
/* the combat system.*/
