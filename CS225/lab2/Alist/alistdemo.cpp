

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
    AList<int> list1=AList<int>(4);
    list1.append(1);
    list1.append(5);
    list1.append(3);
    list1.append(8);
    list1.append(9);
    list1.append(10);
    list1.pushback(1000);

    list1.bubble_alist();

    for(i=0;i<7;i++)
    {
        cout << list1.getitem(i)<<" start:"<<list1.start<<" end:"<<list1.end<<" numitems:"<<list1.getlength()<<endl;
    }


    return 0;
}


