/*
#include <stdio.h>
#include <iostream>
#include <string>
*/
#include "system.h"
using namespace std;



person::person(int id,int date_birth,int reg_date,int risk,int pro,string name,bool reg_again,int waiting_time, int address)
{
    this->id = id;
}

local_queue::local_queue(void)
{
    dummy = new person;
    this->numitem = 0;
    this->withdraw_number = 0;
    this->last = dummy;
    this->root = NULL;
}


void local_queue::add_queue(int id,int date_birth,int reg_date,int risk,int pro,string name,bool reg_again,int waiting_time, int address)
{
    person* newperson = new person(id,date_birth,reg_date,risk,pro,name,reg_again,waiting_time,address);
    if(this->last == dummy)
    {
        newperson->parent = dummy;
        dummy->child_left = newperson;
        dummy->child_right = newperson;
        this->last = newperson;
        this->root = newperson;
        this->numitem++;
        return;
    }
    else
    {
        if(is_full())
        {
            person* temp = this->last;
            while(temp->pre!=NULL)
            {
                temp=temp->pre;
            }

            temp->child_left = newperson;
            newperson->parent=temp;
            this->last = newperson;
            this->siftup(newperson);
            numitem++;
            return;
            
        }
        else if(last->parent->child_right==NULL)
        {
            last->parent->child_right = newperson;
            last->next=newperson;
            newperson->pre = last;
            newperson->parent = last->parent;
            
            this->last = newperson;
            this->siftup(newperson);
            this->numitem++;
            return;
        }
        else
        {
            last->parent->next->child_left = newperson;
            last->next = newperson;
            newperson->pre = last;
            newperson->parent = last->parent->next;

            this->last = newperson;
            this->siftup(newperson);
            this->numitem++;
            return;
        }

    }    

}

bool local_queue::is_full()
{
    if(last->parent->child_right==NULL)
    {
        return false;
    }
    else if(last->parent->next!=NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void local_queue::swap(person* a,person* b)
{
    int id1 = a->id;
    int date_birth1 = a->date_birth; 
    int reg_date1 = a->reg_date;
    int risk1 = a->risk;
    int pro1 = a->pro;
    string name1 = a->name;
    bool reg_again1 =a->reg_again;
    int waiting_time1 = a->waiting_time;
    int address1 = a->address;
    int treatment_date1 = a->treatment_date;
    bool is_delete1 = a->is_delete;

    a->id = b->id;
    a->date_birth = b->date_birth;
    a->reg_date = b->reg_date;
    a->risk = b->risk;
    a->pro = b->pro;
    a->name = b->name;
    a->reg_again = b->reg_again;
    a->waiting_time = b->waiting_time;
    a->address = b->address;
    a->treatment_date = b->treatment_date;
    a->is_delete = b->is_delete;

    b->id = id1;
    b->date_birth = date_birth1;
    b->reg_date = reg_date1;
    b->risk = risk1;
    b->pro = pro1;
    b->name = name1;
    b->reg_again = reg_again1;  
    b->waiting_time = waiting_time1;
    b->address = address1;
    b->treatment_date = treatment_date1;
    b->is_delete = is_delete1;

    return;  
}



void local_queue::siftup(person* current)
{
    person* parent = current->parent;
    if(current->parent == dummy)
    {
        return;
    }
    if(this->compare(current,parent))
    {
        swap(current,parent);
        siftup(parent);
    }
    return;
}

void local_queue::siftdown(person* current)
{
    person* temp = current;
    if(current->child_left!=NULL && compare(current->child_left,temp))
    {
        temp = current->child_left;
    }
    if(current->child_right!=NULL && compare(current->child_right,temp))
    {
        temp = current->child_right;
    }
    if(temp!=current)
    {
        this->swap(temp,current);
        this->siftdown(temp);
    }
}

void local_queue::setprofession(int id,int newpro)
{
    person* current = this->find(id,this->root);
    if(newpro > current->pro)
    {
        current->pro = newpro;
        siftup(current);
    }
    if(newpro < current->pro)
    {
        current->pro = newpro;
        siftdown(current);
    }
}

void local_queue::setrisk(int id,int newrisk)
{
    person* current = this->find(id,this->root);
    if(newrisk < current->risk)
    {
        current->risk = newrisk;
        siftup(current);
    }
    if(newrisk > current->risk)
    {
        current->risk = newrisk;
        siftdown(current);
    }
}

person* local_queue::find(int id, person* current)
{
    if(current->id == id)
    {
        return current;
    }
    if(current->child_left!=NULL)
    {
        if(find(id,current->child_left)!=NULL)
        {
            return find(id,current->child_left);
        }
    }
    if(current->child_left!=NULL)
    {
        if(find(id,current->child_right)!=NULL)
        {
            return find(id,current->child_right);
        }
    }
    return NULL;   
}

person* local_queue::remove_min()
{
    if(this->numitem<=0)
    {
        return NULL;
    }

    if(this->numitem == 1)
    {
        this->dummy->child_left = NULL;
        this->dummy->child_right = NULL;

        person* result = new person;
        *result = *this->root;
        
        free(this->root);
        this->root = NULL;
        this->last = this->dummy;
        this->numitem--;
        return result;
    }

    person* min = new person;
    *min = *root;
    this->swap(this->root,this->last);
    if(this->last->parent->child_right==this->last)
    {
        this->last->parent->child_right=NULL;
    }
    if(this->last->parent->child_left==this->last)
    {
        this->last->parent->child_left=NULL;
    }


    if(last->pre == NULL)
    {
        person* temp = last->parent;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        last->parent = NULL;
        free(last);
        last = temp;
    }
    else
    {
        person* temp2 = last->pre;
        last->parent = NULL;
        free(last);
        last = temp2;
        last->next = NULL;
    }
    this->siftdown(this->root);
    this->numitem--;
    return min;
}

person* local_queue::getlast()
{
    return this->last;
}

bool local_queue::compare(person* xman,person* yman)
{
/*
    if(xman->is_delete == true)
    {
        return true;
    }
    if(yman->risk>=2)
    {
        return true;
    }
    else if(yman->waiting_time>0 && xman->risk<2)
    {
        return true;
    }
    else if(xman->pro>=yman->pro)
    {
        return true;
    }    
    else if(xman->date_birth >= yman->date_birth)
    {
        return true;
    }
    else if(xman->reg_date <= yman->reg_date)
    {
        return true;
    }
    else 
    {
        return false;
    }

*/

    if(xman->id > yman->id)
    {
        return true;
    }
    else
    {
        return false;
    }

}

person* local_queue::withdraw(int id)
{
    person* current = this->find(id,this->root);
    current->id = 1000000;
    current->is_delete = true;
    this->siftup(current);
    return this->remove_min();
}





