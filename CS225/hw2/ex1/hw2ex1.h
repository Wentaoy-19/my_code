/*
 * @ Author     : 
 * 
 * @ File       : 
 * 
 * @ Purpose    : 
 * 
 * @ Usage      : 
 * 
 * @ Description: 
 * 
 * @ Input      : 
 * 
 * @ Output     : 
 * 
 */
#ifndef ex1
#define ex1
#define MAXFLOAT 3.40282347e+38F
#include <iostream>
#include <vector>
#include<ctime>
#include <math.h>
using namespace std;

// You may modify the decleration and definenation by yourself, add help function etc.
template <class T> class Solution {
    public:
        Solution(vector<T> input){
            data = input;
        };

        vector<T> MergeSort_k(vector<T> lst, unsigned k);
        vector<T> MergeSort_t(vector<T> lst, int t);
        vector<T> SelfSort(vector<T> lst);
        vector<T> merge(vector<T> temp[],int k,int total_size);
        vector<T> get_data(vector<T> lst,unsigned start, unsigned end);
        
        void vec_print(vector<T> vec);
        vector<T> data;
        void test(int k, int t);
    private:
        
};

// Modify the following to finish ex1.1
template <class T> vector<T> Solution<T>::MergeSort_k(vector<T> lst, unsigned k)
{
    if(lst.size()<k)
    {
        return SelfSort(lst);   //if the number of elements in the array is less than k, it means that we can not divide the list into k sublists, so we use selfsort to sort the array 
    }
    else
    {
        vector<T> vector_array[k];      //create vector array to store the k splited array 
        vector<T> temp;

        unsigned i;
        int step=lst.size()/k;  



        for(i=0;i<k-1;i++)
        {
            temp=get_data(lst,0+i*step,0 + step*(i+1)); //using for loop to split the array into k parts 
            vector_array[i]=MergeSort_k(temp,k);        //recursive sort each part 
        }


        temp=get_data(lst,0 + (k-1)*step,lst.size());
        vector_array[k-1]=MergeSort_k(temp,k);
        return merge(vector_array,k,lst.size());        //merge the k splited parts 
    }
    
};

template <class T> vector<T> Solution<T>::merge(vector<T> temp[],int k,int total_size)
{
    //cout<<"dd\n";

    int i,j;
    vector<T> merged_array;
    vector<T> temp_array;
    for(i=0;i<total_size;i++)
    {
        
        float min=MAXFLOAT;         //define the maximum float 
        int min_index=total_size;   //initialize the minimum index 
        for(j=0;j<k;j++)
        {
            temp_array=temp[j];
            if(!temp_array.empty())
            {
                if(temp_array[0]<min)
                {
                    min=temp_array[0];  //find the current mimnimum number in the splited array 
                    min_index=j;        //update minimum index 
                }
            }

        }
        merged_array.push_back(min);    //push back the current minimum number  
        temp[min_index].erase(temp[min_index].begin());     //get rid of the minimum number 
        
        
    }


    return merged_array;
}

// this is the heaper function to get data from vector array
template <class T> vector<T> Solution<T>::get_data(vector<T> lst,unsigned start,unsigned end)
{
    vector<T>  result;
    unsigned i;
    for(i=start;i<end;i++)
    {
        result.push_back(lst[i]);   // copy each number to the returned array 
    }
    return result;
}




// Modify the following to finish ex1.2
template<class T> vector<T> Solution<T>::MergeSort_t(vector<T> lst, int t)
{
    if((long)lst.size()<t)      //if the size is smaller than t, using self sort    
    {
        return SelfSort(lst);  
    }
    else
    {
        //revised from k-merge sort, set k=2 
        vector<T> vector_array[2];  
        vector<T> temp;

        unsigned i;
        int step=lst.size()/2;

        for(i=0;i<1;i++)
        {
            temp=get_data(lst,0+i*step,0 + step*(i+1)); //divide the array into two sublist 
            vector_array[i]=MergeSort_t(temp,t);        //using merge sort     
        }


        temp=get_data(lst,0 + 1*step,lst.size());
        vector_array[1]=MergeSort_t(temp,t);            //merge the two array 
        return merge(vector_array,2,lst.size());        //return the merged array
    }
  

}

// You could implement either bubble sort, insert sort or selection sort
//we choose bubble sort 
template<class T> vector<T> Solution<T>::SelfSort(vector<T> lst){
    vector<T> sorted_vector;
    int i,j;
    T temp;
    for(i=lst.size()-1;i>0;i--) //loop from the end to start 
    {
        for(j=0;j<i;j++)        //loop start from the current end 
        {
            if(lst[j]>lst[j+1]) //making judgement 
            {
                temp=lst[j];
                lst[j]=lst[j+1];    //exchange number 
                lst[j+1]=temp;
            }
        }
    }
    return lst;
    
}

// DO NOT modify the following
// This is to view the vector
template<class T> void Solution<T>::vec_print(vector<T> vec){
    for (T i: vec){
        cout << i << "  ";
    }
    cout << endl;
    return ;
}

// This is for testing.
template <class T> void Solution<T>::test(int k, int t){
    cout << "Self-implemented Sort:          ";
    vec_print(SelfSort(data));
    cout << "Merge Sort with K sublist:      ";
    vec_print(MergeSort_k(data, k));
    cout << "Merge Sort with Insertion Sort: ";
    vec_print(MergeSort_t(data, t));
}
#endif 

