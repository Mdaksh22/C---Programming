#include<iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next;
    Node *prev;

    Node() 
    {
        data = " ";
        next = NULL;
        prev = NULL;
    }

    Node(string d) 
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class linked_list 
{
    Node *head;
public:
    linked_list() 
    {
        head = NULL;
    }

    void insert_at_start(string d)
    {
        Node *ptr = new Node(d);
        Node *p=head;
        if (head == NULL) 
        {
            head=ptr;
            ptr->next=head;
        }
        else
       { 

        while(p->next!=head)
        {
            p=p->next;
        }
        
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        p->next=ptr;
        }
    

    }

    void insert_at_end(string d) 
    {
        Node *ptr = new Node(d);
        if (head == NULL) 
        {
            head = ptr;
            return;
        }

        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next=head;
    }

 
void insert_in_between(string d,int index)
{
    if (index == 0) 
        {
            insert_at_start(d);
            return;
        }

    Node *ptr=new Node(d);
    Node *p=head;
    Node *q=head->next;

    int i=0;

    while(i != index-1 && q != NULL)
    {
        p=p->next;
        q=q->next;
        i++;

    }

   p->next=ptr;
   ptr->next=q;
    if (q != NULL)
     {
            q->prev = ptr;
     }
        
   ptr->prev=p;

}

void delete_the_start() 
{
        if (head == NULL) 
        {
           cout<<"linked list is empty "<<endl;
        }
        if (head->next == head) 
        {  // Only one node
            delete head;
            head = NULL;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }

            Node *p=head;
            head=head->next;

            ptr->next=head;

            delete p;
}
}

   void delete_last_node()
{
    if (head == NULL) 
        {
            cout << "List is empty\n";
            return;
        }
        if (head->next == head) 
        {  // Only one node
            delete head;
            head = NULL;
        }
        else
        {
            Node *ptr=head;
            Node *p=head->next;

            while(p->next!=head)
            {
                ptr=ptr->next;
                p=p->next;
            }
        
        ptr->next=head;

        delete p;



        }
} 

    void delete_any_node(string val)
{
    Node *ptr=head;
    Node *p=head->next;

   if (head == NULL) 
        {
            cout << "List is empty\n";
            return;
        }
    if (head->data == val) 
        {
            delete_the_start();
            return;
        }
    while (p != head && p->data != val) {
            p->next = ptr->next;
            ptr = ptr->next;
        }

        if (p == head) 
        {
            cout << "Value not found\n";
        } 
        else 
        {
            ptr->next = p->next;
            delete p;
        }

}
void search(string val) 
{
    
    if (head == nullptr) 
    {
        cout << "The list is empty" << endl;
        return;
    }

Node *ptr = head;

    do 
    {
        if (ptr->data == val) 
        {
            cout << "The text is found in the linked list" << endl;
            return;
        }
        ptr = ptr->next;  
    } while (ptr != head);  


    cout << "The text is not found in the linked list" << endl;
}

void reverse()   
{
    Node *ptr=head;

    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;

    while(ptr->prev!=head)
    {
        ptr=ptr->prev;
        cout<<ptr->data<<endl;
    }
    cout<<ptr->prev->data;
   
}   

 void print() 
    {
        cout<<head->data<<endl;
        Node *p = head->next;
        while (p != head) 
        {
             cout << p->data << endl;
            p = p->next;
        }
    }
};


int main()
 {
   linked_list l;
    string text,route;
    int x, c, index;

    
    do
    {
        cout << "Menu" << endl;
        cout << "1: Add a route at start\n2: Add a route at the end\n3: Add a route in between\n4: Delete the first route\n5: Delete the last route\n6: Delete a route by choice\n7: Search your route\n8: Display the route\n9: to print the route in reverse \n";
        cin >> x;

        switch (x)
        {
            case 1:
                cout << "Enter the route to be inserted at start: ";
                cin >> text;
                l.insert_at_start(text);
                l.print();
                break;

            case 2:
                cout << "Enter the route to be inserted at end: ";
                cin >> text;
                l.insert_at_end(text);
                l.print();
                break;

            case 3:
                cout << "Enter the route to be inserted: ";
                cin >> text;
                cout << "Enter the index at which it needs to be inserted: ";
                cin >> index;
                l.insert_in_between(text, index);
                l.print();
                break;

            case 4:
                cout << "Deleting the first route..." << endl;
                l.delete_the_start();
                l.print();
                break;

            case 5:
                cout << "Deleting the last route..." << endl;
                l.delete_last_node();
                l.print();
                break;

            case 6:
                cout << "Enter the route to be deleted: ";
                cin >> route;
                l.delete_any_node(route);
                l.print();
                break;

            case 7:
                cout << "Enter the route to search: ";
                cin >> text;
                l.search(text);
                break;

            case 8:
                cout << "Displaying the route:" << endl;
                l.print();
                break;

            case 9:
              
              l.reverse();
              
              break;
            

            default:
                cout << "Invalid option" << endl;
        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> c;
    } while (c != 0);

    return 0;
}
  
