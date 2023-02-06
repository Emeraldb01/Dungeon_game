#include "Dungeon.h"

/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer(){
    
    string nam;
    char race;
    cout << "Welcome to the dundun...dungeon......" << endl;
    cout << "You're trap, ... what do you expect?" << endl;
    cout << "Now tell me, what's your name " << endl;
    cin >> nam;
    cout << endl << "Aw, " << nam << " so you're very brave, i see";
    sleep(1);
    cout << endl << "What kind of CREATURE... r u?" << endl << " h) human" << endl << " g) goblin" << endl << " e) elf" << endl;
    cin >> race;
    
    vector<Item> a;
    
    if(race == 'h'){
        cout << endl << "Hmmmmm, a human...... ugly human" << endl<< endl;
        player = new Player(nam, 100, 35, 20, 0, a);
    }
    else if(race == 'g'){
        cout << endl << "Oh goblin, my baby precious..." << endl<< endl;
        player = new Player(nam, 130, 30, 25, 1, a);
    }
    else if(race == 'e'){
        cout << endl << "Elf, huh" << endl<< endl;
        player = new Player(nam, 120, 40, 20, 2, a);
    }
    
    else{
        cout << endl << "Wrong! You're a human, i can tell" << endl << endl;
        player = new Player(nam, 100, 45, 20, 0, a );
    }
    sleep(1);
    cout << " ****************************************** " << endl;
    cout << "           R U ready for this???? "           << endl;
    cout << " ****************************************** " << endl;
    sleep(1);
}

/* Create a map, which include several different rooms */
void Dungeon::createMap(){
    
    Item *rainbow = new Item("Super Unicorn Rainbow Sword", 5, 10, 5, 0);
    Item *love = new Item("Fall in love potion", 10, 10, 10, 1);
    Item *hate = new Item("Will hate you potion", 10, 10, 10, 2);
    Item *star = new Item("Mario Star!!!", 10, 15, 5, 0); 
    
    vector<Object*> o0, o1, o2, o3, o4, o5, o6, o7, o8, o9, o10;
    std::vector<Item> ob0, ob1,ob2;
    ob2.push_back(*love);
    ob2.push_back(*hate);
    
    //what's in ob2??
    NPC *wizard = new NPC("Gandolf", "So you've reach this point, now ", ob0, 0);
    NPC *queen = new NPC("Elf Queen", "Handsome young elf, can you do me a favor?", ob1, 1);
    NPC *merchant = new NPC("Despectable merchant", "NOW TRADE!", ob2, 2);
    
    
    Monster *goblin = new Monster("Goblin", 40, 30, 15, 0);
    Monster *travel = new Monster("Time traveler", 50, 35, 10, 0);
    Monster *lil = new Monster("Lil Nas X as SATAN", 100, 40, 15, 1);
    

    list[0] = Room(0, 0, o0);
    list[0].setUpRoom(NULL);
    list[0].setDownRoom(&list[1]);
    list[0].setLeftRoom (NULL);
    list[0].setRightRoom(NULL);
        
    o1.push_back(rainbow);
    list[1] = Room(0, 1, o1);
    list[1].setUpRoom(&list[0]);
    list[1].setDownRoom(&list[2]);
    list[1].setLeftRoom (NULL);
    list[1].setRightRoom(NULL);
      
    o2.push_back(wizard);
    list[2] = Room(0, 2, o2);
    list[2].setUpRoom(&list[1]);
    list[2].setDownRoom(NULL);
    list[2].setLeftRoom (&list[3]);
    list[2].setRightRoom(&list[6]);
            
    
    list[3] = Room(0, 3, o3);
    list[3].setUpRoom(NULL);
    list[3].setDownRoom(&list[4]);
    list[3].setLeftRoom (NULL);
    list[3].setRightRoom(&list[2]);
           
    o4.push_back(goblin);
    list[4] = Room(0, 4, o4);
    list[4].setUpRoom(&list[3]);
    list[4].setDownRoom(NULL);
    list[4].setLeftRoom (NULL);
    list[4].setRightRoom(&list[5]);
           
    o5.push_back(merchant);
    list[5] = Room(0, 5, o5);
    list[5].setUpRoom(NULL);
    list[5].setDownRoom(&list[10]);
    list[5].setLeftRoom (&list[4]);
    list[5].setRightRoom(&list[9]);
            
    o6.push_back(queen);
    list[6] = Room(0, 6, o6);
    list[6].setUpRoom(NULL);
    list[6].setDownRoom(&list[7]);
    list[6].setLeftRoom (&list[2]);
    list[6].setRightRoom(NULL);
            
    list[7] = Room(0, 7, o7);
    list[7].setUpRoom(&list[6]);
    list[7].setDownRoom(&list[9]);
    list[7].setLeftRoom (NULL);
    list[7].setRightRoom(&list[8]);
            
    o8.push_back(star);
    list[8] = Room(0, 8, o8);
    list[8].setUpRoom(NULL);
    list[8].setDownRoom(NULL);
    list[8].setLeftRoom (&list[7]);
    list[8].setRightRoom(NULL);
    
    o9.push_back(travel);
    list[9] = Room(0, 9, o9);
    list[9].setUpRoom(&list[8]);
    list[9].setDownRoom(NULL);
    list[9].setLeftRoom (&list[5]);
    list[9].setRightRoom(NULL);
     
    o10.push_back(lil);
    list[10] = Room(1, 10, o10);
    list[10].setUpRoom(&list[5]);
    list[10].setDownRoom(NULL);
    list[10].setLeftRoom (NULL);
    list[10].setRightRoom(NULL);
   
    player->setCurrentRoom(list);
}



/* Deal with player's moveing action */
void Dungeon::handleMovement(){
    sleep(1);
    cout << endl << "You can go " << endl;
    if(player->getCurrentRoom()->getUpRoom() != NULL){
        cout << " u) to the upper room" << endl;
        
    }
    if(player->getCurrentRoom()->getDownRoom() != NULL){
        cout << " d) to the bottom room" << endl;
        
    }
    if(player->getCurrentRoom()->getLeftRoom() != NULL){
        cout << " l) to the left room" << endl;
        
    }
    if(player->getCurrentRoom()->getRightRoom() != NULL){
        cout << " r) to the right room" << endl;
        
    }
    cout << endl << "Where do you want to go?" << endl;
    
    char d;
    cin >> d;
    
        if(d == 'u' && player->getCurrentRoom()->getUpRoom() != NULL){
            player->changeRoom(player->getCurrentRoom()->getUpRoom() );
        
        }
        else if(d == 'd' && player->getCurrentRoom()->getDownRoom() != NULL){
            player->changeRoom(player->getCurrentRoom()->getDownRoom());
        
        }
        else if(d == 'l' && player->getCurrentRoom()->getLeftRoom() != NULL){
            player->changeRoom(player->getCurrentRoom()->getLeftRoom());
            
        }
        else if(d == 'r' && player->getCurrentRoom()->getRightRoom() != NULL){
            player->changeRoom(player->getCurrentRoom()->getRightRoom());
        
        }
    else{
        cout << "*wrong input*" << endl;
    }
}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object*){};

/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame(){};

/* Deal with the player's action     */
/* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(Object* player){
    Player* p = dynamic_cast<Player*>(player);
    
    cout << endl << "Choose action: " << endl << " 1) Move" << endl << " 2) Check Status" << endl << " 3) Save to File" << endl;
    char op;
    cin >> op;
    
    if(op == '2'){
        cout << "Your state: " << endl;
        cout << "Health: " << p->getCurrentHealth() << " / " << p->getMaxHealth() << endl;
        cout << "Attack: " << p->getAttack() << endl << "Defense: " << p->getDefense() << endl;
        cout << "Inventory: ";
        for(int i = 0; i < p->getInventory().size(); i++){
            cout << p->getInventory()[i].getName() << " ";
        }
        cout << endl;
      
    }
    
    else if(op == '3'){
        //save file
    }
    
    else{
        if((p->getCurrentRoom()->getObjects().size()== 0 || p->getCurrentHealth() >= 0) && p->end != 1){
            handleMovement();
        }
    }
    
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic(){
    if(player->getCurrentHealth() <= 0 || list[10].getObjects().size() == 0 || player->end == 1){
        return 1;
    }
    else
        return 0;
}

/* Deal with the whole game process */
void Dungeon::runDungeon(){
    cout <<  "Welcome to Dungeon by B.Emerald..." << endl;
    sleep(1);
    cout << " 1) New game" << endl << " 2) Load previous file" << endl ;
    char g;
    cin >> g;
    if(g == '2'){
        
    }
    else{
        cout << endl;
        createPlayer();
        createMap();
        while(checkGameLogic() != 1){
            cout << endl << "*You're at room " << player->getCurrentRoom()->getIndex() << "*" << endl << endl;
            
            cout << "Your state: " << endl;
            cout << "Health: " << player->getCurrentHealth() << " / " << player->getMaxHealth() << endl;
            cout << "Attack: " << player->getAttack() << endl << "Defense: " << player->getDefense() << endl ;
            cout << "Inventory: ";
            for(int i = 0; i < player->getInventory().size(); i++){
                cout << player->getInventory()[i].getName() << " ";
            }
            cout << endl;
        
            if(player->getCurrentRoom()->getObjects().size() != 0){
                player->getCurrentRoom()->getObjects()[0]->triggerEvent(player);
            }
            if(checkGameLogic() == 0){
                chooseAction(player);
            }
            cout << endl << " ****************************************** " << endl;
            
        
        }
        if(checkGameLogic() == 1){
            if(player->getCurrentHealth() <= 0){
                cout << endl << "You die, now you're trap forever..." << endl;
            }
            else{
                cout << endl << "You made it out of the dungeon!!!" << endl << "Or have you....." << endl;
            }
        }
    }
}
