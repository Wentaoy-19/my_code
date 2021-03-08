//
//  alist.h
//  
//
//  Created by KD on 14.01.21.
//

#ifndef alist_h 
#define alist_h

template<class T> class AList
{
public:
    AList(int size = 20);
//    virtual ~AList();
    T &operator[](int index);
    int getlength(void);
    void setitem(int index, T value);
    T getitem(int index);
    void append(T value);
    void insert(int index, T value);
    void remove(int index);
    void concat(AList<T> &list);
    bool member(T value);
    bool equal(AList<T> &list);
    bool sublist(AList<T> &list);

//  for sort
    void selection_sort();
    void bubble_alist();
    T f(T x);
    T g(T e1,T e2);
    T src(int start,int end,T e);

//   

private:
    int maxsize, minsize;
    int numitems;
    T *reprarray;
    void allocate(void);
    void deallocate(void);
};

template<class T> AList<T>::AList(int size)
{
    maxsize = size;
    if (size < 20)
        minsize = size;
    else
        minsize = 20;
    numitems = 0;
    reprarray = new T[maxsize];
}

/*
class Rlist:public AList<int>
{
    public:
        Rlist(int num=10)
        {
            id=num;
        }

        int id;
        char* name;
};

*/




//template<class T> AList<T>::~AList()
//{
//    delete[] reprarray;
//}

#endif /* alist_h */