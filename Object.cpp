#include "Object.h"

void Object::setName(string n){
    name = n;
}
void Object::setTag(string t){
    tag = t;
}
string Object::getName(){
    return name;
}
string Object::getTag(){
    return tag;
}
