#include "hw2ex1.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>

int main(){

    // ============ test 1 ==============
    Solution<int> test1 = Solution<int>(vector<int>({1, 3, 2,8, 0, 10, 4, 100, 90}));
    cout << "Test 1:" << endl << "Input: ";
    test1.vec_print(test1.data);
    cout << "Gold Output:" << "0  1  2  3  4  8  10  90  100" << endl << endl; 
    test1.test(4, 2);

    // ============ test 2 ==============
    Solution<float> test2 = Solution<float>(vector<float>({2.5, 3.4, 1.9, 7.8, 3.9, 1, 9, 0, -1.7}));
    cout << "\n \n Test 2:" << endl << "Input:         ";
    test2.vec_print(test2.data);
    cout << "Gold Output:        " << " -1.7  0  1  1.9  2.5  3.4  3.9  7.8  9" << endl << "--------------" << endl; 
    test2.test(4, 4);
    // You could add your own test example

    // ============ test 3 ==============
    Solution<float> test3 = Solution<float>(vector<float>({31.1,-0.1,30,0,1.2,17.9,1.9,11.8,2.9,4.6}));
    cout << "\n \n Test 3:" << endl << "Input:         ";
    test3.vec_print(test3.data);
    cout << "Gold Output:        " << " -0.1  0  1.2  1.9  2.9  4.6  11.8  17.9  30  31.1" << endl << "--------------" << endl; 
    test3.test(4, 4);



    // ============ find experimental value of t ============

    cout<<endl<<endl<<"================== experiment for value of t =================="<<endl;
    for(int j=1;j<=50;j++)
    {
        clock_t start_time1,end_time1,start_time2,end_time2;
        int num=j*100;          //step:100 numbers
        vector<float> array;
        for(int i=0;i<num;i++)
        {
            array.push_back((float)(rand()) / RAND_MAX * 100000);   //creating random float array
        }
        
        

        Solution<float> test1 = Solution<float>(array);
        start_time1=clock();
        test1.MergeSort_k(test1.data,2);    //record the operating time for merge sort
        end_time1=clock();
    
        Solution<float> test2 = Solution<float>(array); //record the operating time for self sort(bubble sort)
        start_time2=clock();
        test2.SelfSort(test2.data);
        end_time2=clock();

        cout << "Quantity:"<< num << " \t  The run time of merge-sort is: " << (double)(end_time1-start_time1)/CLOCKS_PER_SEC  << "   \t The run time of self-sort is: "<< (double)(end_time2-start_time2)/CLOCKS_PER_SEC <<endl; 
    }
    return 0;
}