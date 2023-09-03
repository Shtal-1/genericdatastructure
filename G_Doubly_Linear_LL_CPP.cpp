// Doubly Linear LinlkedList in C++.
#include<iostream>

using namespace std;

template<class T>
struct node
{
    T Data;
    struct node* Next;
    struct node* Prev;
};

template<class T>
class Doubly_linkedList
{
    private:
        struct node<T> *Head;
        int Count;

    public:
        Doubly_linkedList();
        ~Doubly_linkedList();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        inline void Display();
        inline int CountNode();
        void DeleteFirst();
        void DeleteAtPosition(int);
        void DeleteLast();
};

template<class T>
Doubly_linkedList<T> :: Doubly_linkedList()
{
    Head = NULL;
    Count = 0;
}

template<class T>
Doubly_linkedList<T> :: ~Doubly_linkedList()
{
    struct node <T>*Temp = Head;

    if(Head != NULL)
    {
        while(Head != NULL)
        {
            Head = Head -> Next;
            delete Temp;
            Temp = Head;
        }
    }
}

 template<class T>
 void Doubly_linkedList<T> :: InsertFirst(T no)
{
    struct node <T>* newn = NULL;

    newn = new node<T>;

    if(newn == NULL)
    {
        return;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> Next = Head;
        Head -> Prev = newn;
        Head = newn;
    }
    Count++;
}

 template<class T>
 void Doubly_linkedList<T> :: InsertLast(T no)
 {
    struct node <T>* newn = NULL;
     struct node <T>*Temp = Head;

    newn = new node<T>;

    if(newn == NULL)
    {
        return;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = newn;
        newn -> Prev = Temp;
    }
    Count++;
 }

template<class T>
void Doubly_linkedList<T> :: InsertAtPosition(T no, int pos)
{
    if((Head == NULL) || (pos > CountNode()+1) || (pos <= 0))
    {
        return;
    }
    if(pos ==1 )
    {
        return(InsertFirst(no));
    }
    else if(pos == CountNode()+1)
    {
        return(InsertLast(no));
    }
    else
    {
        struct node<T> *newn = NULL;
         struct node<T> *Temp = Head;

        newn = new node<T>;

        if(newn == NULL)
        {
            return;
        }

        newn -> Data = no;
        newn -> Next = NULL;
        newn -> Prev = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp = Temp -> Next;
        }
        newn -> Next = Temp -> Next;
        Temp -> Next -> Prev = newn;
        newn -> Prev = Temp;
        Temp -> Next = newn;
    }
    Count++;
}

template<class T>
void Doubly_linkedList<T> :: DeleteFirst()
{
    struct node<T> *Temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head -> Next;
        Head -> Prev = NULL;

        delete Temp;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: DeleteLast()
{
    struct node<T> *Temp = Head;

    if(Head == NULL)
    {
        return;
    }
   if(Head -> Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        while((Temp -> Next) != NULL)  // while(Temp1 -> Next -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
                                        //Temp2 = Temp1 -> Next;
        Temp -> Prev -> Next = NULL;   // Temp1 -> Next = NULL;
        delete Temp;                   // delete Temp2;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > CountNode()) || (pos <= 0))
    {
        return;
    }
    if(pos ==1 )
    {
        return(DeleteFirst());
    }
    else if(pos == CountNode()+1)
    {
        return(DeleteLast());
    }
    else
    {
        struct node<T> * Temp = Head;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = Temp -> Next -> Next;
        delete (Temp -> Next -> Prev);
        Temp -> Next -> Prev = Temp;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: Display()
{
    struct node<T> * Temp = Head;
    cout<<"\nList of Nodes are:\n";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp-> Data<<"|->";
        Temp = Temp -> Next;
    }
    cout<< "NULL\n";
}

template<class T>
int Doubly_linkedList<T> :: CountNode()
{
    return Count;
}

int main()
{
    Doubly_linkedList<int> obj1;  // Static object
    Doubly_linkedList<int> *obj2 = new Doubly_linkedList<int>();  // Dynamic memory

// Function call by Static object
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();
    cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

     obj1.InsertLast(101);
     obj1.InsertLast(111);
     obj1.Display();
    cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

    obj1.InsertAtPosition(75,4);
    obj1.InsertAtPosition(85,4);
    obj1.Display();
    cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

     obj1.DeleteLast();
     obj1.Display();
     cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

     obj1.DeleteAtPosition(2);
     obj1.Display();
     cout<<"\nNumber of Nodes : "<< obj1.CountNode()<<"\n";

// Function call by Pointer
    obj2 -> InsertFirst(501);
    obj2 -> InsertFirst(511);
    obj2 -> InsertFirst(521);

    obj2 -> Display();

    obj2 -> InsertLast(551);
    obj2 -> InsertAtPosition(601,3);

    obj2 -> Display();

     cout<<"\nNumber of Nodes : "<< obj2 -> CountNode()<<"\n";

     delete obj2;

     return 0;
}







