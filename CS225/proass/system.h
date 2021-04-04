#ifndef system_h
#define system_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class person 
{
    public:
        person(int id = -1,int date_birth =-1,int reg_date =-1,int risk=-1,int pro=-1,string name="none",bool reg_again=false,int waiting_time=0, int address = -1);
        person* parent = NULL;
        person* child_left = NULL;
        person* child_right = NULL;
        person* next = NULL;
        person* pre = NULL;
        int treatment_date = -1; // The date that the person receive treatment;


        int id;
        int date_birth; // 1--7, higher number has higher priority
        int reg_date;   // smaller number has higher priority(all negative numbers)
        int risk;       // 0:no risk; 1:low risk; 2:medium; 3:high risk
        int pro;        // 1--8, higher number has higher priority
        string name;
        bool reg_again;
        int waiting_time;   //default 0
        int address;     // The address of the location of this person;
        bool is_delete = false;

    private:
};

class local_queue
{
    public:
        local_queue(void);

        
        person* dummy;
        person* root;
        person* last;

        void add_queue(int id=-1 ,int data_birth=-1 ,int reg_date = -1,int risk = -1,int pro = -1,string name = "",bool reg_again=false,int waiting_time = 0, int address = -1);

        void siftup(person* current);
        void siftdown(person* current);

        void setprofession(int id, int newpro);
        void setrisk(int id,int newrisk);
        void swap(person* a, person* b);
        bool compare(person* xman, person* yman); // True if xman has higher priority to yman 
        bool is_full();
        person* withdraw(int id);
        person* find(int id, person* current);    // The pointer if found, NULL if not found
        person* remove_min();
        person* getlast();

        void change(int id,int newvalue)
        {
            person* current = find(id,this->root);
            if(newvalue > current->id)
            {
                current->id = newvalue;
                this->siftup(current);
            }
            if(newvalue < current->id)
            {
                current->id = newvalue;
                this->siftdown(current);
            }
        }


        int numitem = 0;
        int withdraw_number = 0;

    private:   
};











#endif