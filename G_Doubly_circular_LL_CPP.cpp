// Doubly circular linkedlist (C++) Generic Programming
#include<iostream>
using namespace std;

template<class T>
struct node
{
    int data;
    struct node *next;
    struct node* prev;
};

template<class T>
class DoublyCLL
{
    private:        // characteristics
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

    public:         // Behaviours
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int CountNode();
};
    template<class T>
    DoublyCLL<T> :: DoublyCLL()
     {
         Head = NULL;
         Tail = NULL;
         Count = 0;
     }

   template<class T>
   void DoublyCLL<T> :: InsertFirst(T no)
    {
        struct node <T>* newn = NULL;
        newn  = new node<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Head -> prev = newn;
            newn -> next = Head;
            Head = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void DoublyCLL<T> :: InsertLast(T no)
    {
        struct node<T> *newn = NULL;
        newn  = new node<T>;

        newn -> data = no;
        newn -> next = NULL;
       newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail -> next = newn;
            newn -> prev = Tail;
            Tail = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void DoublyCLL<T> :: InsertAtPos(T no, int ipos)
    {
        int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize+1))
        {
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iSize +1)
        {
            InsertLast(no);
        }
        else
        {
          struct node <T>* newn = NULL;
          newn  = new node<T>;

          newn -> data = no;
          newn -> next = NULL;
         newn -> prev = NULL;

        struct node <T> *temp = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        }
        Count++;
    }

    template<class T>
    void DoublyCLL<T> :: DeleteFirst()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Head = Head -> next;
            Head -> prev = Tail;
            delete Tail-> next;
        }
        Tail -> next = Head;
        Count--;
    }

     template<class T>
    void DoublyCLL<T> :: DeleteLast()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            struct node <T> *temp = Head;

            while(temp-> next != Tail)
             {
                temp = temp -> next;
             }
             delete temp -> next; // delete Tail;
             Tail = temp;
             Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count--;
    }

    template<class T>
    void DoublyCLL<T> :: DeleteAtPos(int ipos)
    {
         int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize))
        {
            cout<<"Invalid Position";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iSize)
        {
            DeleteLast();
        }
        else
        {
          struct node <T> *temp1 = Head;
          int iCnt = 0;

          for(iCnt = 1; iCnt < ipos -1; iCnt++)
          {
              temp1 = temp1 -> next;
          }
            struct node <T> *temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            delete temp2;
            temp1 -> next -> prev = temp1;
        }
        Count--;
    }
    template<class T>
    void DoublyCLL<T> :: Display()
    {
        struct node <T> *temp = Head;

        if(Head == NULL && Tail ==NULL)
        {
            return;
        }

       do
        {
            cout<<" |"<<temp-> data<<"|";
            temp = temp -> next;
        } while(temp != Tail->next);   //(temp != Head);

        cout<<endl;
    }

    template<class T>
    int DoublyCLL<T> :: CountNode()
    {
        return Count;
    }

int main()
    {
        DoublyCLL<int> obj;

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.InsertFirst(1);
        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        cout<<" number of nodes are:"<<obj.CountNode()<<endl<<endl;

        obj.InsertAtPos(75,5);
        obj.Display();
        cout<<" number of nodes are:"<<obj.CountNode()<<endl<<endl;

        obj.DeleteFirst();
        obj.Display();
        cout<<" number of nodes are:"<<obj.CountNode()<<endl<<endl;

        obj.DeleteLast();
        obj.Display();
        cout<<" number of nodes are:"<<obj.CountNode()<<endl<<endl;

        obj.DeleteAtPos(2);
        obj.Display();
        cout<<" number of nodes are:"<<obj.CountNode()<<endl<<endl;

        return 0;
    }