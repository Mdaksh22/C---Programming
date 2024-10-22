#include<iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next;

    Node(string data) 
    {
        this->data = data;  
        next = NULL;
    }
};

class queue 
{
public:
    Node* front;
    Node* rear;

    queue()
    {
        front = rear = NULL;
    }

    void insert(string data)
     {
        Node* ptr = new Node(data);

        if (front == NULL && rear == NULL) 
        {
            front = rear = ptr;
            return;
        }

        rear->next = ptr;
        rear = ptr;
    }

    void deletee() 
    {
        if (front == NULL)
         {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* p = front;
        string val = front->data;
        front = front->next;

        if (front == NULL)
         {
            rear = NULL;
        }

        cout << "Data dequeued: " << val << endl;
        delete p;
    }

    void display() 
    {
        if (front == NULL) 
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* ptr = front;
     
        while (ptr != NULL)
         {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() 
{
    queue q;
    int x;
    int c;
    string data;

    do {
        cout << "Menu\n1: Add Party to Waitlist\n2: Remove the waitlist id seat allocated\n3: Display the Waitlist\n";
        cin >> x;

        switch (x)
         {
            case 1:
                cout << "Enter the waitlist: ";
                cin >> data;
                q.insert(data);
                break;

            case 2:
                cout << "Removing the waitlist... ";
                q.deletee();
                break;

            case 3:
                cout << "Displaying the current waitlist... ";
                q.display();
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
