

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
    int i;
    int j;
    AList<int> list2=AList<int>();
    list2.append(1);
    list2.append(5);
    list2.append(7);
    list2.append(2);
    list2.append(3); 

    j=list2.popback();  
    cout << j<<endl;

    for(i=0;i<list2.getlength();i++)
    {
        cout<<list2.getitem(i)<<endl;
    }
  
    
}


