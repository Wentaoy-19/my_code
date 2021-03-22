#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef system_h
#define system_h

class person 
{
    public:
        person();
        int id;
        int date_birth; //The same meaning as age
        int reg_time;
        int risk;
        int pro;
        string name;
        bool reg_again;
        
};

class local_queue
{

};

class central_queue
{

};

class treat_center
{

};


#endif