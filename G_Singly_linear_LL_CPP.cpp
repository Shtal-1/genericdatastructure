//Singly LL using Generic
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    private:
        struct node<T> *Head;       //*
        int Count;

    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(int,T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    void Display();
    int CountNode();

};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node <T>*newn = NULL;            //*
    newn = new node<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node <T>*newn = NULL;            //*
    newn = new node<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
      struct node<T> *temp  = Head;
      while(temp -> next !=NULL)
      {
            temp = temp -> next;
      }
      temp -> next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
        cout<<endl;
        cout<<"Elements from LinkedLst are: ";
   struct node<T> *temp  = Head;

    while(temp !=NULL)
      {
           cout<<"|"<<temp->data<<"| ";
            temp = temp -> next;
      }
       cout<<endl;
    }


template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T> :: InsertAtPosition(int pos, T no)
{
    if((Head == NULL) || (pos > CountNode()+1) ||(pos <= 0))
    {
        return ;
    }
    if(pos == 1)
    {
        return (InsertFirst(no));
    }
    else if(pos == (CountNode())+1)
    {
        return InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        struct node <T>* Temp = Head;
        newn = new node<T>;
        if(newn == NULL)
        {
            return;
        }
        newn -> data = no;
        newn -> next = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp = Temp -> next;
        }
        newn -> next = Temp -> next;
        Temp -> next = newn;
    }
        Count++;
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct node<T> *Temp = Head;

    if(Head == NULL)
    {
        return ;
    }
    else
    {
        Head = Head -> next;
        delete(Temp);
    }
    Count--;
}

template<class T>
void SinglyLL<T>:: DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    if(Head -> next == NULL)
    {
        delete Head;
        Head == NULL;
    }
    else
    {
        struct node<T> *Temp1 = Head;
         struct node<T> *Temp2 = NULL;

        while(Temp1 -> next -> next != NULL)
        {
            Temp1 = (Temp1 -> next);
        }
        Temp2 = Temp1 -> next;
        Temp1 -> next = NULL;
        delete Temp2;
    }
    Count--;
}

template<class T>
void SinglyLL<T> :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > CountNode()) ||(pos <= 0))
    {
        return ;
    }
    if(pos == 1)
    {
        return (DeleteFirst());
    }
    else if(pos == (CountNode()))
    {
        return DeleteLast();
    }
    else
    {
        struct node <T>* Temp1 = Head;
        struct node <T>* Temp2 = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp1 = Temp1 -> next;
        }
         Temp2 = Temp1 -> next;
         Temp1 -> next = Temp2 ->next;;
         delete Temp2;
    }
        Count--;
}
int main()
{
    SinglyLL<int>obj1;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertFirst(10);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertAtPosition(3,31);
    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPosition(2);
    obj1.Display();
    cout<<"Number of Nodes are: "<<obj1.CountNode()<<endl;

    SinglyLL<float>obj2;

    obj2.InsertFirst(21.12);
    obj2.InsertFirst(11.36);
    obj2.InsertFirst(10.65);
    obj2.InsertLast(51.4);
    obj2.InsertLast(101.96);
    obj2.InsertLast(111.87);
    obj2.InsertAtPosition(3,31.35);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPosition(2);
    obj2.Display();
    cout<<"Number of Nodes are: "<<obj2.CountNode()<<endl;

      SinglyLL<char>obj3;

     obj3.InsertFirst('B');
     obj3.InsertFirst('A');
     obj3.InsertLast('C');
     obj3.InsertLast('D');
     obj3.InsertLast('E');
     obj3.InsertLast('F');
     obj3.InsertAtPosition(3,'Z');
    obj3.DeleteFirst();
    obj3.DeleteLast();
    obj3.DeleteAtPosition(2);
     obj3.Display();
     cout<<"Number of Nodes are: "<<obj3.CountNode()<<endl;

    return 0;
}