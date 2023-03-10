#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object(){};
    Object(string n,string t){
        name = n;
        tag = t;
    }

    /* pure virtual function */
    virtual void triggerEvent(Object*) = 0;

    /* Set & Get function*/
    void setName(string n);
    void setTag(string t);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
