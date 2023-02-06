#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
public:
    Monster(){};
    Monster(string n,int mh,int a,int d, int t){
        setName(n);
        setAttack(a);
        setMaxHealth(mh);
        setCurrentHealth(mh);
        setDefense(d);
        type = t;
    }
    int type;
    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    void triggerEvent(Object* player);
};


#endif // ENEMY_H_INCLUDED
