

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.cpp"

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    /*
    int i;
    DList<int> list2=DList<int>();
    list2.append(9);
    list2.append(3);
    list2.append(6);
    list2.append(7);
    list2.append(5);
    list2.append(8);
    list2.bubble_dlist();
    for(i=0;i<6;i++)
    {
        cout<<list2.getitem(i)<<endl;
    }
*/

    int e=1;
    int size=5;
    int i;
    AList<int> list1=AList<int>(size);
    list1.append(1);
    list1.append(5);
    list1.append(3);
    list1.append(8);
    list1.append(7);


    int return_value;
/*  
    list1.bubble_alist();
    for(i=0;i<5;i++)
    {
        cout << list1.getitem(i)<<endl;
    }
*/  if(list1.getlength()==0)
    {
        return_value=list1.src(-1,-1,1);
    }
    else
    {
        return_value=list1.src(0,list1.getlength()-1,1);       
    }
    
    cout << return_value<<endl;
    

    //cout <<"test\n"<<list1.getitem(1)<<"\n";
    


    return 0;
}


