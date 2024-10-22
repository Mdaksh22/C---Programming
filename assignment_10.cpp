#include <iostream>
using namespace std;

class Node 
{
public:
    string data;
    int prio;
    Node* next;
    Node* prev;

    
    Node(string val, int priority)
{ 
    data = val;
    prio = priority;
    next = NULL;
    prev = NULL;
}
};
           

class Deque 
{
public:
    Node* front;
    Node* rear;


    Deque() 
    {
        front =NULL; 
        rear = NULL;
    }
    
void insert(string data, int prio)
{
    Node* p = new Node(data, prio);
    
    if (front == NULL || prio > front->prio)
    {
       
        if (front == nullptr) 
        {
            front = rear = p;
        }
        else 
        {
            p->next = front;
            front->prev = p;
            front = p;
        }
    }
    else
    {
        Node* q = front;
        
        
        while (q->next != NULL &&  q->next->prio    >    prio)
        {
            q = q->next;
        }
        
      
        p->next = q->next;
        p->prev = q;

        if (q->next != NULL)
        {
            q->next->prev = p;
        }
        else  // means last node
        {
            rear = p;
        }

        q->next = p;
    }
}


    

    void delete_front() 
    {
        if (front == nullptr) 
        {
            cout << "Deque is empty! Cannot delete from front." << endl;
            return;
        }

        cout << "Element " << front->data << " removed from front." << endl;
        Node* temp = front;

        if (front == rear) 
        {
            front = rear = nullptr;
        }
        else 
        {
            front = front->next;
            front->prev = nullptr; 
        }

        delete temp;
    }

    void delete_rear() 
    {
        if (rear == nullptr) 
        {
            cout << "Deque is empty! Cannot delete from rear." << endl;
            return;
        }

        cout << "Element " << rear->data << " removed from rear." << endl;
        Node* temp = rear;

        if (front == rear) 
        {
            front = rear = nullptr;
        }
        else 
        {
            rear = rear->prev;
            rear->next = nullptr; 
        }

        delete temp;
    }
   
   void search(string val)
   {
    Node *ptr=front;

    while(ptr)
    {
        if(ptr->data==val)
        {
            cout<<" Job "<<ptr->data<<" found! \n";
            return;
        }
        ptr=ptr->next;
            

        
        cout<<" Job not found! \n";
    }
   }
   
   void print()
{
cout<<"Displaying the Jobs\n";
  Node *temp;
  temp=front;

  if(front==NULL)
  {
    cout<<"queue is empty\n";

  }

  else
  {
    while(temp!=NULL)
    {
        cout<<temp->data<<" "<<temp->prio<<"\n";
        temp=temp->next;
    }
       

  }

}
    ~Deque() 
    {
        while (front != nullptr) 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() 
{
    Deque dq;
    int x;
    int c;
    string data;
    int priority;
    int choice;

    do {
        cout << "Menu\n1: Add Job \n2: Remove Job \n3: Display Job\n4: Search Job\n";
        cout<<"Enter your choice: " ;
        cin >> x;

        switch (x)
         {
            case 1:
            cout<<"Enter Job Name: ";
            cin>>data;
            cout<<"Enter the priority for the Job entered: ";
            cin>>priority;
            dq.insert(data,priority);

            break;

            case 2:
             
            cout<<"enter 1 to remove highest priority Job \nenter 2 to remove lowest priority job\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
                 dq.delete_front();
                
                break;
            
            case 2:
                 dq.delete_rear();
                
                break;
            
            default:
                break;
            }
                
                break;


            case 3:
              dq.print();
                
                break;

            case 4:
            cout<<"Enter the Job to be searched: ";
            cin>>data;
            dq.search(data);
            break;


            default:
                cout << "Invalid option" << endl;
        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> c;
    } 
    while (c != 0);



    

    return 0;
}
