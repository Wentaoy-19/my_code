//
//  alist.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.h"
using std::cout;
using std::cin;


//
template<class T> void AList<T>::delete_last(int k){
    int newnum=numitems-k;
    if (newnum!=0){
        while((maxsize/2)>=newnum && (maxsize/2)>minsize){
            maxsize=maxsize/2;
        }
    }else{
        maxsize=minsize;
    }
    

    int newsize = maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < newnum; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    numitems=newnum;
    return;    
}


template<class T> void AList<T>::pushback(T x)
{
    if (numitems == maxsize)
    {
        allocate();
    }

    if(end==maxsize-1)
    {
        end=0;
        reprarray[end]=x;
        numitems++;
    }  
    else
    {
        end++;
        reprarray[end]=x;
        numitems++;
    }
      
}

template<class T> void AList<T>::pushfront(T x)
{
    if (numitems == maxsize)
    {
        allocate();
    }
    if(start==0)
    {
        start=maxsize-1;
        reprarray[start]=x;
        numitems++;
    }
    else
    {
        start--;
        reprarray[start]=x;
        numitems++;
    }
    return;
    
    
}


template<class T> T AList<T>::popfront()
{
    T value;
    value=reprarray[start];
    if(numitems==maxsize/4 && maxsize > minsize)
    {
        deallocate();
    }
    if(numitems>0)
    {
        if(start==maxsize-1)
        {
            start=0;
        }
        else
        {
            start++;
        }
        numitems--;
        return value;
    }
    else
    {
        cout<<"error\n";
        exit(EXIT_FAILURE);
    }
    
    
  
}

template<class T> T AList<T>::popback()
{
    T value;
    value=reprarray[end];
    
    if(numitems==maxsize/4 && maxsize > minsize)
    {
        deallocate();
    }

    if(numitems>0)
    {
        if(end==0)
        {
            end=maxsize-1;
        }
        else
        {
            end--;
        }
        numitems--;  
        cout<< "pop value: "<<value<<"\n";
        return value;         
    }
    else
    {
        cout << "error\n";
        exit(EXIT_FAILURE);
    }
    
 
}





template<class T> T AList<T>::src(int start,int end,T e)
{
    if(start==-1)
    {
        return e;
    }
    else
    {
        if(start==end)
        {
            return f(getitem(start));
        }
        else
        {
            return g(src(start,(start+end)/2,e),src((start+end)/2+1,end,e));
        }     
    }    
}

template<class T> T AList<T>::g(T e1,T e2)
{
    return e1+e2;
}

template<class T> T AList<T>::f(T x)
{
    return x+1;
}



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

template<class T> void AList<T>::selection_sort()
{
    T exchange_temp;
    int i,j;
    int temp_max; //index for max
    for(i=0;i<numitems;i++)
    {
        temp_max=i;
        for(j=i;j<numitems;j++)
        {
            if(getitem(j)>getitem(temp_max))
            {
                temp_max=j;
            }
        }
        exchange_temp=getitem(i);
        setitem(i,getitem(temp_max));
        setitem(temp_max,exchange_temp);
    }
}


//


template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index - 1];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index >= 0) && (index < numitems))
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
        if(end>=start)
        {
            return reprarray[index+start];
        }
        else
        {
            if(start+index>maxsize-1)
            {
                return reprarray[0+start+index-(maxsize)];
            }
            else
            {
                return reprarray[start+index];
            }           
        }
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }   

/*
    if ((index >= 0) && (index < numitems))
    {
        return reprarray[index+start];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
*/
}

template<class T> void AList<T>::append(T value)
{
    if(numitems == maxsize)
    {
        allocate();
    }

    if(end==maxsize-1)
    {
        reprarray[0]=value;
        numitems++;
        end=0;
    }
    else if(end==start && numitems==0)
    {   
        reprarray[start] = value;
        numitems++;
        
    }
    else
    {
        reprarray[numitems+start] = value;
        numitems++;
        end++;
    }

    return;
    

    
/*
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
*/
}

template<class T> void AList<T>::insert(int index, T value)
{

    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            if(j+1+start>maxsize-1)
            {
                reprarray[j+1+start-maxsize]=getitem(j);
            }
            else
            {
                reprarray[j+1+start]=getitem(j);
            }            
        }
        if(index+start>maxsize-1)
        {
            reprarray[index+start-maxsize]=value;
        }
        else
        {
            reprarray[index+start]=value;
        }
        end++;
        numitems++;
        return;
    }
    else
    {
        append(value);
        return;
    }
    


/*
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
*/

}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for(int i=0;i<numitems;i++)
    {
        newarray[i]=getitem(i);
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;

    start=0;
    end=numitems-1;

    return;
/*
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
*/
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index < numitems)
    {
        for (int j = index; j < numitems-1; j++)
        {
            reprarray[j] = reprarray[j+1];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize/2;
    T *newarray = new T[newsize];
    for(int i=0;i<getlength();i++)
    {
        newarray[i]=getitem(i);
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    start=0;
    end=numitems-1;
    return;
    /*
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
    */
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
                --i;
    }
    return result;

}