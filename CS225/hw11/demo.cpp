

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
    int result_int,result_double,result_popback,result_popfront;
    cout<<"\nunsorted test list for integer is 3, 9, 6, 7, 5, 8, 1, 10, 8, 0\n";
    cout<<"\nunsorted test list for double is 3.2, 1.4, 3.5, 7.2, 8.3, 8.1, 0.3, 4.5, 4.9, 0.1, 9.2\n";

    DList<int> list_Di=DList<int>();
    list_Di.append(3);
    list_Di.append(9);
    list_Di.append(6);
    list_Di.append(7);
    list_Di.append(5);
    list_Di.append(8);
    list_Di.append(1);
    list_Di.append(10);
    list_Di.append(8);
    list_Di.append(0);//create the test list for integer in Dlist

    DList<double> list_Dd=DList<double>();
    list_Dd.append(3.2);
    list_Dd.append(1.4);
    list_Dd.append(3.5);
    list_Dd.append(7.2);
    list_Dd.append(8.3);
    list_Dd.append(8.1);
    list_Dd.append(0.3);
    list_Dd.append(4.5);
    list_Dd.append(4.9);
    list_Dd.append(0.1);
    list_Dd.append(9.2);//create the test list for double in Dlist
 
    AList<int> list_Ai=AList<int>();
    list_Ai.append(3);
    list_Ai.append(9);
    list_Ai.append(6);
    list_Ai.append(7);
    list_Ai.append(5);
    list_Ai.append(8);
    list_Ai.append(1);
    list_Ai.append(10);
    list_Ai.append(8);
    list_Ai.append(0);//create the test list for integer in Alist

    AList<double> list_Ad=AList<double>();
    list_Ad.append(3.2);
    list_Ad.append(1.4);
    list_Ad.append(3.5);
    list_Ad.append(7.2);
    list_Ad.append(8.3);
    list_Ad.append(8.1);
    list_Ad.append(0.3);
    list_Ad.append(4.5);
    list_Ad.append(4.9);
    list_Ad.append(0.1);
    list_Ad.append(9.2);//create the test list for double in Alist


    cout<<"\n---Ex.2 test for structual recursion---\nWe implement the algorithm to determine the length of a list\n";
    
    result_int =list_Ai.src(0,list_Ai.getlength()-1,0); 
    result_double =list_Ad.src(0,list_Ad.getlength()-1,0);  //use the structural recursion 
    
    cout<<"The length of integer list is "<<result_int<<"\n";
    cout<<"The length of double list is "<<result_double<<"\n";

    cout<<"\n---Ex.3 test list is 6 ,1, 5, 7, 2, 3\n";
    AList<int> list_op=AList<int>();    // test list for ex3
    list_op.append(1);
    list_op.append(5);
    list_op.append(7);
    list_op.append(2);
    list_op.append(3);
/*    
    cout<<"\n---Ex.3 test for pushback---\n";
    list_op.pushback(4);
    cout<<"after pushback(4) is ";
    for (int i = 0; i < list_op.getlength(); i++)
    {
        cout<<list_op.getitem(i)<<", ";
    }
    
    cout<<"\n---Ex.3 test for pushfront---\n";
    list_op.pushfront(6);
    cout<<"after pushfront(6) is ";
    for (int i = 0; i < list_op.getlength(); i++)
    {
        cout<<list_op.getitem(i)<<", ";
    }
*/


    list_op.pushfront(6);
    //cout<<"\n\n\n\n"<<list_op.getitem(list_op.getlength()-1)<<" start: "<<list_op.start<<" end: "<<list_op.end<<"\n";
    cout<<"\n---Ex.3 test for popback---\n";
    result_popback=list_op.popback();
    //cout<<"pop value is "<<result_popback;
    cout<<"after popback is ";
    for (int i = 0; i < list_op.getlength(); i++)
    {
        cout<<list_op.getitem(i)<<", ";
    }

/*
    cout<<"\n---Ex.3 test for popfront---\n";
    result_popfront=list_op.popfront();
    cout<<"after popfornt is ";
    for (int i = 0; i < list_op.getlength(); i++)
    {
        cout<<list_op.getitem(i)<<", ";
    }
    cout<<"pop value is "<<result_popback;

    cout<<"\n---Ex.4 test for SelectionSort using Alist---\n";
    
    cout<<"The sorted integer list is ";
    list_Ai.selection_sort();   // use SelectionSort
    for (int i = 0; i < list_Ai.getlength(); i++)
    {
        cout<<list_Ai.getitem(i)<<", ";
    }
    
    cout<<"The sorted double list is ";
    list_Ad.selection_sort();// use SelectionSort
    for (int i = 0; i < list_Ad.getlength(); i++)
    {
        cout<<list_Ad.getitem(i)<<", ";
    }
    
    cout<<"\n---Ex.4 test for InsertionSort using Dlist---\n";
    
    cout<<"The sorted integer list is ";
    list_Di.insertion_sort();// use InsertionSort
    for (int i = 0; i < list_Di.getlength(); i++)
    {
        cout<<list_Di.getitem(i)<<", ";
    }
    
    cout<<"The sorted double list is ";
    list_Dd.insertion_sort();// use InsertionSort
    for (int i = 0; i < list_Dd.getlength(); i++)
    {
        cout<<list_Dd.getitem(i)<<", ";
    }
    
    cout<<"\n---Ex.4 test for BubbleSort using Alist---\n";
    
    cout<<"The sorted integer list is ";
    list_Ai.bubble_alist();// use BubbleSort
    for (int i = 0; i < list_Ai.getlength(); i++)
    {
        cout<<list_Ai.getitem(i)<<", ";
    }
    
    cout<<"The sorted double list is ";
    list_Ad.bubble_alist();// use BubbleSort
    for (int i = 0; i < list_Ad.getlength(); i++)
    {
        cout<<list_Ad.getitem(i)<<", ";
    }

    cout<<"\n---Ex.4 test for BubbleSort using Dlist---\n";
    
    cout<<"The sorted integer list is ";
    list_Di.bubble_dlist();// use BubbleSort
    for (int i = 0; i < list_Di.getlength(); i++)
    {
        cout<<list_Di.getitem(i)<<", ";
    }
    
    cout<<"The sorted double list is ";
    list_Dd.bubble_dlist();// use BubbleSort
    for (int i = 0; i < list_Dd.getlength(); i++)
    {
        cout<<list_Dd.getitem(i)<<", ";
    }
*/
    return 0;
}


