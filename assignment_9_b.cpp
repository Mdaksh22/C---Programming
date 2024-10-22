#include<iostream>
using namespace std;

class Node 
{
public:
    string data;
    Node *next;

    Node() 
    {
        data = " ";
        next = NULL;
    }

    Node(string d) 
    {
        data = d;
        next = NULL;
    }
};

class CircularQueue 
{
    Node *front;
    Node *rear;

public:
    CircularQueue() 
    {
        front = rear = NULL;
    }

    //  Insert at the rear of the queue
    void insert(string d) 
    {
        Node *ptr = new Node(d);
        if (front == NULL) 
        {
            front = rear = ptr;
            rear->next = front;  // Point to front to make it circular
        } 
        else 
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = front;  // Maintain circular property
        }
    }

    //  Remove from the front of the queue
    void Delete() 
    {
        if (front == NULL) 
        {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear) 
        {  
            
            delete front;
            front = rear = NULL;
        } 
        else 
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;  // Maintain circular property
            delete temp;
        }
    }

    void counter()
    {
        if (front == NULL) 
        {
            cout << "checkout counter is closed \n";
            return;
        }
        else
        {
            cout<<"customers are waiting in the queue you cannot close the counter !\n";
        }
    }


    void print() 
    {
        if (front == NULL) 
        {
            cout << "checkout counter is closed \n";
            return;
        }
        Node *ptr = front;
        cout << "Customer queue: "<<endl;;
        do 
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        } 
        while (ptr != front);
    }
};

int main() 
{
    CircularQueue q;
   
    int x;
    int c;
    string data;

    do {
        cout << "Menu\n1: Customer arrival \n2: Customer checkout\n3: View customer\n4: Close the checkout counter\n";
        cin >> x;

        switch (x)
         {
            case 1:
            cout<<"enter the customer name: ";
            cin>>data;
                q.insert(data);
                break;

            case 2:
                q.Delete();
                q.print();

                break;

            case 3:
                q.print();
                break;

            case 4:
            q.counter();
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