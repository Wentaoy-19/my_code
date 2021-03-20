#include "multiset.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
/* Put your implementation here */
template<class T> MultiSet<T>::MultiSet(int size)
{
    maxsize = size;     //initialize the paramiters here
    if(size < 20)
    {
        minsize = size;
    }
    else 
    {
        minsize = 20;
    }
    numitem = 0;
    reparray = new T[maxsize];  //initialize the set
    multi = new int[maxsize];
}  

template<class T> void MultiSet<T>::allocate()
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    int *newmulti = new int[newsize];       //The same as the AList allocation
    for(int i=0;i<numitem;i++)
    {
        newarray[i] = reparray[i];
        newmulti[i] = multi[i];
    }
    delete[] reparray;
    delete[] multi;
    reparray = newarray;
    multi = newmulti;
    maxsize = newsize;
    return;
}

template<class T> void MultiSet<T>::insertion(T value)
{
    if(numitem+1 >= maxsize)        //Judge if it needs allocation
    {
        allocate();
    }

    int index = binary_search(0,numitem-1,value);   //find the value 
    if(index!=-1)
    {
        this->multi[index]+=1;          // if is in the table, add the multiplicites 
    }
    else
    {
        int j=numitem-1;
        while(this->reparray[j]>value && j>=0)  //insert the value into the table by order, so we get the sorted list
        {
            j--;
        }
        for(int i=numitem-1;i>=j+1;i--)
        {
            this->reparray[i+1]=this->reparray[i];
            this->multi[i+1]=this->multi[i];
        }
        this->reparray[j+1] = value;
        this->multi[j+1]=1;
        numitem++;
    }

}


template<class T> void MultiSet<T>::retrieval(T value)
{
    int index = this->binary_search(0,numitem-1,value);
    if(index < 0)
    {
        cout<<"The element is not in the set"<<endl;        //get the multiplicities if the element is in the set
        return;
    }
    else
    {
        int num = this->multi[index];
        cout<<"The element: "<<value<<" has multiplicities: "<<num<<endl;
        return;
    }
}

template<class T> void MultiSet<T>::deletion(T value)
{
    int index = binary_search(0,numitem-1,value);
    if(index<0)
    {
        return;         // if not in the set, just return 
    }

    if(this->multi[index] > 1)
    {
        this->multi[index]--;  // if the mulitiplicities is more than one, just minus 1 of the multiplicities 
    }
    else
    {
        if((maxsize > minsize) && (numitem == maxsize/4))
        {
            deallocate();       //judge if needs deallocation 
        }
        for(int j=index; j<numitem-1;j++)
        {
            this->reparray[j] = this->reparray[j+1];  //remove the value
            this->multi[j] = this->multi[j+1];
        }
        numitem--;
    }
}

// This is the binary search for the index of the value 
template<class T> int MultiSet<T>::binary_search(int low,int high,T value)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low+high)/2;
    if(this->reparray[mid] == value)
    {
        return mid;
    }
    else if(this->reparray[mid]>value)
    {
        return binary_search(low,mid-1,value);
    }
    else
    {
        return binary_search(mid+1,high,value);
    }
}

// The deallocation function, which is the same as AList 
template<class T> void MultiSet<T>::deallocate()
{
    int newsize = maxsize/2;
    T *newarray = new T[newsize];
    int *newmulti = new int[newsize];
    for(int i=0;i<numitem;i++)
    {
        newarray[i] = reparray[i];
        newmulti[i] = multi[i];
    }
    delete[] reparray;
    delete[] multi;
    maxsize = newsize;
    reparray = newarray;
    multi = newmulti;
}

template<class T> MultiSet<T> MultiSet<T>::intersection(MultiSet<T> set)
{
   
    MultiSet<T> newset = MultiSet<T>();
    int i = 0;
    int j = 0;
    while(i<this->numitem && j<set.numitem)             // Since the two sets are all sorted, so we have the similar method as merge
    {
        if(this->reparray[i]==set.reparray[j])
        {
            newset.insertion(this->reparray[i]);
            if(this->multi[i]>=set.multi[j])
            {
                newset.multi[newset.binary_search(0,newset.numitem-1,this->reparray[i])] = set.multi[j];        //assign the one with smaller multiplicities
            }
            else
            {
                newset.multi[newset.binary_search(0,newset.numitem-1,this->reparray[i])] = this->multi[i];
            }
            i++;
            j++;
        }
        else if(this->reparray[i] > set.reparray[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }


    
    return newset;
}

template<class T> MultiSet<T> MultiSet<T>::setunion(MultiSet<T> set)
{
    MultiSet<T> newset;
    newset = *this;
    int index;
    // search for all the element in the added set
    for(int i=0;i<set.numitem;i++)
    {
        index = newset.binary_search(0,newset.numitem-1,set.reparray[i]);
        if(index<0)
        {
            newset.insertion(set.reparray[i]);  
            newset.multi[newset.binary_search(0,newset.numitem-1,set.reparray[i])] = set.multi[i];  //using binary search to find the index 
        }
        else
        {
            if(newset.multi[index] < set.multi[i])
            {
                newset.multi[index] = set.multi[i]; //judge the multiplicities, and choose the bigger one 
            }
        }
    }
    return newset;
}

template<class T> void MultiSet<T>::display()
{
    for(int i=0;i<numitem;i++)
    {
        cout<<this->reparray[i]<<" "<<this->multi[i]<<endl;
    }
}

template<class T> MultiSet<T> MultiSet<T>::difference(MultiSet<T> set)
{
    int tempdiff;
    MultiSet<T> newset = MultiSet<T>();

    for(int i=0;i<this->numitem;i++)
    {
        if(set.binary_search(0,set.numitem-1,this->reparray[i]) < 0)    // if no element in the minused set, just assign the element into the new set
        {
            newset.insertion(this->reparray[i]);
            newset.multi[newset.binary_search(0,newset.numitem,this->reparray[i])] = this->multi[i];
        }
        else    // if the element is in the minused set, calculate the difference of them 
        {
            tempdiff = this->multi[i] - set.multi[set.binary_search(0,set.numitem-1,this->reparray[i])];
            if(tempdiff > 0)        // if smaller than 0, which means all excluded
            {
                newset.insertion(this->reparray[i]);
                newset.multi[newset.binary_search(0,newset.numitem-1,this->reparray[i])] = tempdiff;
            }
        }
    }
    return newset;
}


// chaining



template<class T> MultiSet_Chaining<T>::MultiSet_Chaining(int size)
{
    maxsize = size;
    minsize = size;
    numitem = 0;
    reparray = new node<T>[maxsize];  // initialize the parameters and the representing array
}

// The rehashing function for the case that the factor of load is too large 
template<class T> void MultiSet_Chaining<T>::allocate()
{
    MultiSet_Chaining<T> tempset = *this;       // The similar way as the Alist
    int newsize = 2*maxsize;
    int maxsize1 = maxsize;
    this->maxsize = newsize;

    this->reparray = new node<T>[newsize];

    for(int i=0;i<maxsize1;i++)         //using the new size to calculate the hashing value , and calculate the new location
    {
        node<T>* temp = &tempset.reparray[i];
        if(temp->pt_next!=0)
        {
            node<T>* temp2 = temp;
            while(temp2->pt_next!=0)
            {
                temp2=temp2->pt_next;
                int num = tempset.find(temp2->dataitem);
                for(int j=0;j<num;j++)
                {
                    this->insertion(temp2->dataitem);
                }
            }
        }
    }

}

template<class T> void MultiSet_Chaining<T>::insertion(T value)
{
    if(numitem == 2*maxsize)
    {
        this->allocate();       //judge if needs rehashing 
    }    

    int index = value % maxsize;
    node<T>* newnode = new node<T>;
    node<T>* temp = &reparray[index];
    newnode->dataitem = value;

    while(temp->pt_next!=0)     //firstly find the elements through the chaining of different elements 
    {
        temp=temp->pt_next;
        if(temp->dataitem == value)
        {
            node<T>* temp2 = temp;
            while(temp2->value_next!=0)     // then find through the chain with the same elements 
            {
                temp2 = temp2->value_next;
            }
            temp2->value_next = newnode;
            newnode->value_previous = temp2;
            this->numitem++;
            return;
        }        
    }
    temp->pt_next = newnode;
    newnode->pt_previous = temp;    //upgrade the parameters
    this->numitem++;
}

template<class T> void MultiSet_Chaining<T>::retrieval(T value)
{
    int index = value % maxsize;
    node<T>* temp = &this->reparray[index];
    while(temp->pt_next!=0)
    {
        temp=temp->pt_next;
        if(temp->dataitem == value)
        {
            int num = 1;
            node<T>* temp2 = temp;
            while(temp2->value_next != 0)       //locate the chain of the same element and count the number of it.
            {
                temp2=temp2->value_next;
                num++;
            }
            cout<<"The element: "<<value<<" has multiplicities: "<<num<<endl;
            return;
        }
    }
    cout<<"The element is not in the set"<<endl;
    return;
}

template<class T> void MultiSet_Chaining<T>::deletion(T value)
{
    int index = value % maxsize;
    node<T>* temp = &this->reparray[index];
    while(temp->pt_next!=0)
    {
        temp = temp->pt_next;
        if(temp->dataitem == value)
        {
            if(temp->value_next!=0)     //if the element only has a chain, we remove the first of it 
            {
                temp->pt_previous->pt_next = temp->value_next;
                temp->value_next->pt_previous = temp->pt_previous;
                temp->value_next->pt_next = temp->pt_next;
                temp->value_next->value_previous = 0;
                if(temp->pt_next!=0)
                {
                    temp->pt_next->pt_previous = temp->value_next;
                }
                free(temp);
                this->numitem--;
                return;
            }
            else
            {                   // if the element only has one, just remove it by the method of linked list
                temp->pt_previous->pt_next = temp->pt_next;
                if(temp->pt_next!=0)
                {
                    temp->pt_next->pt_previous = temp->pt_previous;
                }
                free(temp);
                this->numitem--;
                return;
            }
        }
    }
    return;
}

//This is the function to find the mulitiplicities of the element
template<class T> int MultiSet_Chaining<T>::find(T value)
{
    int num = 0;
    int index = value % maxsize;
    node<T>* temp = &this->reparray[index];
    while(temp->pt_next!=0)
    {
        temp=temp->pt_next;
        if(temp->dataitem == value)
        {
            num =1;
            node<T>* temp2 = temp;
            while(temp2->value_next != 0)
            {
                temp2=temp2->value_next;
                num++;
            }
            return num;
        }
    }
    return num;
}

template<class T> MultiSet_Chaining<T> MultiSet_Chaining<T>::setunion(MultiSet_Chaining<T> set)
{
    MultiSet_Chaining<T> newset = *this;    //let the newset be a copy of current set
    node<T>* temp;
    for(int i=0;i<set.maxsize;i++)      //loop all the elements in the added set
    {
        temp = &set.reparray[i];
        if(temp->pt_next!=0)
        {
            node<T>* temp2 = temp;      //if we find that the element is not in the current set, add it
            while(temp2->pt_next!=0)
            {
                temp2=temp2->pt_next;
                int number1 = newset.find(temp2->dataitem);
                int number2 = set.find(temp2->dataitem);
                if(number2>number1)
                {
                    for(int j=0;j<number2-number1;j++)      // We choose the larger mulitiplicities and add the element in time of the offset to the largest number
                    {
                        newset.insertion(temp2->dataitem);
                    }
                }
                
            }
            
        }
    }
    return newset;
}   

template<class T> MultiSet_Chaining<T> MultiSet_Chaining<T>::intersection(MultiSet_Chaining<T> set)
{
    MultiSet_Chaining<T> newset;        //initialize a new set
    node<T>* temp;   
    for(int i=0;i<set.maxsize;i++)
    {
        temp = &set.reparray[i];
        if(temp->pt_next!=0)
        {
            node<T>* temp2 = temp;
            while(temp2->pt_next!=0)        // loop the chain 
            {
                temp2=temp2->pt_next;
                int number1 = this->find(temp2->dataitem);  //find the number 
                if(number1>0)
                {
                    int number2 = set.find(temp2->dataitem);
                    if(number2 >= number1)      // using the smaller number for insertion 
                    {
                        for(int j=0;j<number1;j++)
                        {
                            newset.insertion(temp2->dataitem);
                        }
                    }
                    else
                    {
                        for(int j=0;j<number2;j++)
                        {
                            newset.insertion(temp2->dataitem);
                        }
                    }
                }
            }
        }
    }
    return newset;
}

template<class T> MultiSet_Chaining<T> MultiSet_Chaining<T>::difference(MultiSet_Chaining<T> set)
{
    MultiSet_Chaining<T> newset;
    node<T>* temp; 
    for(int i=0;i<this->maxsize;i++)
    {
        temp = &this->reparray[i];
        if(temp->pt_next!=0)        
        {
            node<T>* temp2 = temp;
            while(temp2->pt_next!=0)
            {
                temp2=temp2->pt_next;   //just calculate the number of elements in the minused set, and calculate the offset
                int diff = this->find(temp2->dataitem) - set.find(temp2->dataitem); 
                if(diff<0)
                {
                    diff = 0;
                }
                for(int j=0;j<diff;j++)     //The offset of it is the number for insertion to the new set
                {
                    newset.insertion(temp2->dataitem);
                }
            }
        }      
    }   
    return newset;

}
