#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"


using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room(){};
    Room(bool exit, int ind, vector<Object*> listobj){
        setIsExit(exit);
        setIndex(ind);
        setObjects(listobj);
    }
    
    void popObject(vector<Object*> del){
        vector<Object*> tem;
        tem = del;
        tem.pop_back();
        setObjects(tem);
    } /*pop out the specific object, used when the interaction is done*/

    
    void setUpRoom(Room* up);
    void setDownRoom(Room* down);
    void setLeftRoom(Room* left);
    void setRightRoom(Room* right);
    
    void setIsExit(bool is); 
    
    void setIndex(int n);
    void setObjects(vector<Object*> obj);
    
    
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    

};

#endif // ROOM_H_INCLUDED
