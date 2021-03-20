/* Put your decleration here */
#ifndef multiset_h
#define multiset_h

template<class T> class node
{
public:
    node(node<T> *pt_n = 0,node<T> *value_n = 0, node<T>* pt_p = 0, node<T>* value_p = 0);
    T dataitem;
    node<T> *pt_next;
    node<T> *value_next;
    node<T> *pt_previous;
    node<T> *value_previous;
private:

};

template<class T> node<T>::node(node<T> *pt_n,node<T> *value_n, node<T>* pt_p, node<T>* value_p )
{
    pt_next = pt_n;
    value_next = value_n;
    pt_previous = pt_p;
    value_previous = value_p;
}


template<class T> class MultiSet{
    public:
        MultiSet(int size=20);
        /* You should add other functions to make the structure work  */


        /* The following is required for this assignment */
        /* It is not complete, you should design the APIs by yourself */
        void insertion(T value);
        void deletion(T value);
        void retrieval(T value);
        MultiSet<T> setunion(MultiSet<T> set);
        MultiSet<T> intersection(MultiSet<T> set);
        MultiSet<T> difference(MultiSet<T> set);

        int binary_search(int low,int high,T value);
        void display();
        void allocate();
        void deallocate();


        T *reparray; // using two array, one record the elemeent, another one record the multiplicities of elements.
        int* multi;
        int maxsize;
        int minsize;
        int numitem;
    private:     
};


template<class T> class MultiSet_Chaining{
    public:
        MultiSet_Chaining(int size = 5); // we use the similar way as hashing with chain

        void allocate();                // there is one pointer added in the class of node to record the next same element
        void insertion(T value);
        node<T> *reparray;
        void deletion(T value);
        void retrieval(T value);

        int find(T value);


        MultiSet_Chaining<T> setunion(MultiSet_Chaining<T> set);
        MultiSet_Chaining<T> intersection(MultiSet_Chaining<T> set);
        MultiSet_Chaining<T> difference(MultiSet_Chaining<T> set);


        int maxsize;
        int minsize;
        int numitem;
    private:

};






#endif