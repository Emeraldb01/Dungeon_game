#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item> commodity;
    int kind;
public:
    NPC(){};
    NPC(string n, string sc, vector<Item> inventory, int k){
        Object::setName(n);
        script = sc;
        commodity = inventory;
        kind = k;
    }
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    void triggerEvent(Object*);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item>);
    string getScript();
    vector<Item> getCommodity();
};


#endif // NPC_H_INCLUDED
