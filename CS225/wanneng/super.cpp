#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "super.h"
using std::cout;
using std::cin;
using std::endl;

template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index >= 0) && (index <numitems))
    {
        reprarray[index] = value;
        return;
    }
    else
        cout << "Index error: index out or range\n";
}

template<class T> T AList<T>::getitem(int index)
{
    if ((index >= 0) && (index < numitems))
    {
        return reprarray[index];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void AList<T>::append(T value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
}

template<class T> void AList<T>::insert(int index, T value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            reprarray[j+1] = reprarray[j];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index < numitems)
    {
        for (int j = index; j < numitems; ++j)
        {
            reprarray[j-1] = reprarray[j];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::concat(AList<T> &list)
{
    int length = list.getlength();
    for (int i = 1; i <= length; ++i)
    {
        append(list[i]);
    }
    return;
}

template<class T> bool AList<T>::member(T value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
}

template<class T> bool AList<T>::equal(AList<T> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}

template<class T> bool AList<T>::sublist(AList<T> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 1, j = 0; (i <= length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                ++j;
    }
    return result;
}

// Added codes here

template<class T> void AList<T>::bubble_alist()
{
    int i,j;
    T temp;
    for(i=numitems;i>0;i--)
    {
        for(j=0;j<i-1;j++)
        {
            if(getitem(j)>getitem(j+1))
            {
                temp=getitem(j);
                setitem(j,getitem(j+1));
                setitem(j+1,temp);
            }
        }

    }
}







//build the max heap using elements in the input array.
template<class T> void MaxHeap<T>::build_heap(void){
    //put your code below
    for(int i=this->getlength()/2-1;i>=0;i--)
    {
        sift_down(i,this->getlength());
    }

}

//sift down the element with index i within the first num_elements elements.
template<class T> void MaxHeap<T>::sift_down(int i, int num_elements){
    //put your code below
    int largest = i;
    if(2*i+1<=num_elements && this->getitem(2*i+1)>this->getitem(i))
    {
        this->swap(i,2*i+1);
        largest = 2*i+1;
    }
    if(2*i+2<= num_elements && this->getitem(2*i+2)> this->getitem(i))
    {
        this->swap(i,2*i+2);
        largest=2*i+2;
    }

    if(largest!=i)
    {
        sift_down(largest,num_elements);
    }


}

//sort the input array using max heap.
template<class T> void MaxHeap<T>::heap_sort(void){
    //put your code below
    build_heap();
    int total_number = this->getlength()-1;
    while(total_number >= 0)
    {
        swap(0,total_number);
        total_number-=1;
        sift_down(0,total_number);
    }
}

//swap elements with indices i and j.
template<class T> void MaxHeap<T>::swap(int i, int j){
    //put your code below   
    T temp=this->getitem(i);
    this->setitem(i,this->getitem(j));
    this->setitem(j,temp);

}

//return the root element. 
template<class T> T MaxHeap<T>::max(){
    return this->getitem(0);
    //put your code below
}

//print all elements in the heap in sequential order.
template<class T> void MaxHeap<T>::print_elements(){

    int n = this->getlength();
    for (int i=0; i<n; i++){
        cout << this->getitem(i) << "\n";
    }

}
///my codes 
template<class T> void MaxHeap<T>::insert_k(int k,T arr[])
{
    int i;
    int start_point = this->getlength();
    for(i=0;i<k;i++)
    {
        this->append(arr[i]);
    }
    int end_point = this->getlength()-1;
    
    for(i=end_point;i>=start_point;i--)
    {
        adjust_heap(i);
    }
    
}

template<class T> void MaxHeap<T>::adjust_heap(int position)
{
    int current=position;
    int parent;
    T parent_value,current_value;
    while(current>0)
    {   
        parent=(current-1)/2;
        parent_value=this->getitem(parent);
        current_value=this->getitem(current);

        if(parent_value<current_value)
        {
            swap(parent,current);
            current=parent;
        }  
        else
        {
            break;
        }
    }

}

template<class T> void AList<T>::swap(int i,int j)
{
    T temp=getitem(i);
    setitem(i,getitem(j));
    setitem(j,temp);
}


// Here comes the main function
int main(){
    MaxHeap<int> test_array = MaxHeap<int>();
    test_array.append(10);
    test_array.append(5);
    test_array.append(7);
    test_array.append(1);
    test_array.append(12);
    test_array.append(3);
    test_array.append(20);
    test_array.heap_sort();
    test_array.print_elements();
}
