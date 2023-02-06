#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    
public:
    Player(){};
    int race;
    bool end;
    Player(string nam,int mh,int a,int d, int r, vector<Item> ob){
        Object::setName(nam);
        setMaxHealth(mh);
        setCurrentHealth(mh);
        setAttack(a);
        setDefense(d);
        race = r;
        inventory = ob;
        end = 0;
    }
    void addItem(Item);
    void increaseStates(int ch,int a ,int d);
    void changeRoom(Room* next);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    void triggerEvent(Object* o);

    /* Set & Get function*/
    void setCurrentRoom(Room* cr);
    void setPreviousRoom(Room* pr);
    void setInventory(vector<Item> n){
        inventory = n;
    }
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
   
};

#endif // PLAYER_H_INCLUDED
