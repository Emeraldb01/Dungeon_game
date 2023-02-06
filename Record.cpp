#include "Record.h"

void Record::savePlayer(Player* m, ofstream& savefile){
    /*savefile.open ("save.txt");
    savefile << m->getName() << m->getCurrentHealth() << m->getMaxHealth() << m->getDefense() << m->getAttack() << m->race;
    for(int i = 0; i <m->getInventory().size() ; i++){
        savefile << m->getInventory()[0].getName() << m->getInventory()[0].getHealth() << m->getInventory()[0].getAttack() << m->getInventory()[0].getDefense() << m->getInventory()[0].type;
    }
    savefile << m->getCurrentRoom() << m->getPreviousRoom();
    savefile.close();*/
}

void Record::saveRooms(vector<Room>& r, ofstream& savefile){
    
    
    
}
void Record::loadPlayer(Player* m, ifstream& savefile){
    
}
void Record::loadRooms(vector<Room>& r, ifstream& savefile){
    
}


void Record::saveToFile(Player* m, vector<Room>& r){
    /*savePlayer(m, <#ofstream &#>);
    saveRooms(r, <#ofstream &#>)*/
}
void Record::loadFromFile(Player*, vector<Room>&){
    
}
