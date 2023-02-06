#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Object.h"
#include "Player.h"
#include "Monster.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense;
public:
    Item(){};
    Item(string n, int h, int a, int d , int t){
        setName(n);
        health = h;
        attack = a;
        defense = d;
        type = t;
    }
    
    int type;
    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    void triggerEvent(Object* player);
    void triggerEvent2(Object* monster);


    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    void setHealth(int ch);
    void setAttack(int at);
    void setDefense(int de);
};

#endif // ITEM_H_INCLUDED
