#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    //string name;
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
public:
    GameCharacter(){};
    GameCharacter(string n,string s,int h,int a ,int d){
        setName(n);
        setTag(s);
        setAttack(a);
        setMaxHealth(h);
        setCurrentHealth(h);
        setDefense(d);
    }
    bool checkIsDead(){
        if(currentHealth <= 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int takeDamage(int hurt){
        currentHealth = currentHealth - hurt;
        return currentHealth;
    }

    /* Set & Get function*/
    void setMaxHealth(int mh);
    void setCurrentHealth(int ch);
    void setAttack(int at);
    void setDefense(int de);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
};
#endif // GAMECHARACTER_H_INCLUDED
