#include <stdio.h>
#include <iostream>
#include "system.h"
using namespace std;

int main()
{
    local_queue q1;
    

    q1.add_queue(14);
    q1.add_queue(13);
    q1.add_queue(17);
    q1.add_queue(10);
    q1.add_queue(8);
    q1.add_queue(19);
    q1.add_queue(3);

    q1.change(8,1000);
    
    q1.withdraw(10);
    //cout<<q1.find(19,q1.root)<<endl;

    cout<<q1.remove_min()->id<<endl;
    cout<<q1.remove_min()->id<<endl;    
    cout<<q1.remove_min()->id<<endl; 
    cout<<q1.remove_min()->id<<endl; 
    cout<<q1.remove_min()->id<<endl; 
    cout<<q1.remove_min()->id<<endl; 

}