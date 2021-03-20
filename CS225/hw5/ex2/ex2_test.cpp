#include "multiset_f.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

int main()
{

    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */

    //The test case for all operations are written below

    int input1[] = {1, 1, 1, 5, 2};
    int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};

    MultiSet<int> test1, test2;
    MultiSet<int> m_union,m_diff,m_ins;
    MultiSet_Chaining<int> test3,test4;
    MultiSet_Chaining<int> c_union,c_diff,c_ins;
    for(int i=0;i<5;i++)
    {
        test1.insertion(input1[i]);
        test3.insertion(input1[i]);
    }
    for(int i=0;i<11;i++)
    {
        test2.insertion(input2[i]);
        test4.insertion(input2[i]);
    }

    cout<<endl;
    cout<<"==========retrieval and insertion test for multiset 01=========="<<endl;
    test1.retrieval(1);
    test1.retrieval(5);    
    test1.retrieval(2);
    cout<<endl;
    cout<<"==========retrieval and insertion test for multiset 02=========="<<endl;
    test2.retrieval(0);
    test2.retrieval(2);    
    test2.retrieval(3);   
    test2.retrieval(4);
    test2.retrieval(5);
    test2.retrieval(12);
    test2.retrieval(42);
    cout<<endl;
    cout<<"==========retrieval and insertion test for multiset_chaining=========="<<endl;    
    test3.retrieval(1);
    test3.retrieval(5);    
    test3.retrieval(2);
    cout<<endl;
    cout<<"==========retrieval and insertion test for multiset_chaining 02=========="<<endl;
    test4.retrieval(0);
    test4.retrieval(2);    
    test4.retrieval(3);   
    test4.retrieval(4);
    test4.retrieval(5);
    test4.retrieval(12);
    test4.retrieval(42); 

    cout<<endl;
    cout<<"==========difference test for multiset=========="<<endl;
    m_diff = test2.difference(test1);
    m_diff.retrieval(0); 
    m_diff.retrieval(3); 
    m_diff.retrieval(4); 
    m_diff.retrieval(5); 
    m_diff.retrieval(12);
    m_diff.retrieval(42); 

    cout<<endl;
    cout<<"==========difference test for multiset_chaining=========="<<endl;    
    c_diff = test4.difference(test3);
    c_diff.retrieval(0);
    c_diff.retrieval(3); 
    c_diff.retrieval(4);
    c_diff.retrieval(5);
    c_diff.retrieval(12);
    c_diff.retrieval(42);


    cout<<endl;
    cout<<"==========intersection test for multiset=========="<<endl;        
    m_ins = test2.intersection(test1);
    m_ins.retrieval(2);
    m_ins.retrieval(5);

    cout<<endl;
    cout<<"==========intersection test for multiset_chaining=========="<<endl; 
    c_ins = test3.intersection(test4);
    c_ins.retrieval(2);
    c_ins.retrieval(5);


    cout<<endl;
    cout<<"==========setunion test for multiset=========="<<endl;    
    m_union = test1.setunion(test2);
    m_union.retrieval(0);
    m_union.retrieval(1);    
    m_union.retrieval(2);    
    m_union.retrieval(3);   
    m_union.retrieval(4);
    m_union.retrieval(5);
    m_union.retrieval(12);
    m_union.retrieval(42);     
    cout<<endl;

    cout<<"==========setunion test for multiset_chaining=========="<<endl; 
    c_union = test3.setunion(test4);
    c_union.retrieval(0);
    c_union.retrieval(1);    
    c_union.retrieval(2);    
    c_union.retrieval(3);   
    c_union.retrieval(4);
    c_union.retrieval(5);
    c_union.retrieval(12);
    c_union.retrieval(42);  



    return 0;
}