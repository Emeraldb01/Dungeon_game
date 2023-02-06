#include "Room.h"

void Room::setUpRoom(Room* up){
    upRoom = up;
}
void Room::setDownRoom(Room* down){
    downRoom = down;
}
void Room::setLeftRoom(Room* left){
    leftRoom = left;
}
void Room::setRightRoom(Room* right){
    rightRoom = right;
}

void Room::setIsExit(bool is){
    isExit = is;
} 

void Room::setIndex(int n){
    index = n;
}

void Room::setObjects(vector<Object*> obj){
    objects = obj;
}


bool Room::getIsExit(){
    return isExit;
}
int Room::getIndex(){
    return index;
}
vector<Object*> Room::getObjects(){
    return objects;
}
Room* Room::getUpRoom(){
    return upRoom;
}
Room* Room::getDownRoom(){
    return downRoom;
}
Room* Room::getLeftRoom(){
    return leftRoom;
}
Room* Room::getRightRoom(){
    return rightRoom;
}


