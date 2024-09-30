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

    Node(string d) {
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
        if (head == NULL) 
        {
            head = ptr;
            return;
        }

        ptr->next = head;
        head->prev = ptr;
        head = ptr;
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
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
    }

 
void insert_in_between(string d,int index)
{
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
        return; 

        Node *ptr = head;
        head = head->next;
        if (head != NULL) 
        {
            head->prev = NULL;
        }
        delete ptr;
}

    void delete_the_end() 
    {
        if (head == NULL) 
        return; 

        Node *ptr = head;
       
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        if (ptr->prev != NULL) 
        {
            ptr->prev->next = NULL;
        } 
        
        else 
        {
            head = NULL; 
        }

        delete ptr;
    }

    void delete_in_between(int index) 
    {
        if (head == NULL) 
        return; 

        Node *p = head;
        Node *q = head->next;
        int i = 0;

        while (i != index-1 && q != NULL) 
        {
            p = p->next;
            q = q->next;
            i++;
        }

        if (q != NULL) 
        {
            p->next = q->next;
            if (q->next != NULL)
             {
                q->next->prev = p;
            }
            delete q;
        }
    }
void search(string val)
    {
        Node *ptr = head;

        while (ptr != NULL && ptr->data != val)
        {
            ptr = ptr->next;
        }

        if (ptr != NULL)
        {
            cout << "The text is found in the linked list" << endl;
        }
        else
        {
            cout << "The text is not found in the linked list" << endl;
        }
    }
void reverse()   
{
    Node *ptr=head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;

    while(ptr->prev!=NULL)
    {
        ptr=ptr->prev;
        cout<<ptr->data<<endl;
    }
   
}   

    void print() 
    {
        Node *p = head;
        while (p != NULL) 
        {
             cout << p->data << endl;
            p = p->next;
        }
    }
};

int main()
 {
   linked_list l;
    string text;
    int x, c, index;

    
    do
    {
        cout << "Menu" << endl;
        cout << "1: Add a text at start\n2: Add text at the end\n3: Add a text in between\n4: Delete the first text\n5: Delete the last text\n6: Delete a text by choice\n7: Search your text\n8: Display the texts\n9: to print the text in reverse \n";
        cin >> x;

        switch (x)
        {
            case 1:
                cout << "Enter the text to be inserted at start: ";
                cin >> text;
                l.insert_at_start(text);
                l.print();
                break;

            case 2:
                cout << "Enter the text to be inserted at end: ";
                cin >> text;
                l.insert_at_end(text);
                l.print();
                break;

            case 3:
                cout << "Enter the text to be inserted: ";
                cin >> text;
                cout << "Enter the index at which it needs to be inserted: ";
                cin >> index;
                l.insert_in_between(text, index);
                l.print();
                break;

            case 4:
                cout << "Deleting the first text..." << endl;
                l.delete_the_start();
                l.print();
                break;

            case 5:
                cout << "Deleting the last text..." << endl;
                l.delete_the_end();
                l.print();
                break;

            case 6:
                cout << "Enter the index of the text to be deleted: ";
                cin >> index;
                l.delete_in_between(index);
                l.print();
                break;

            case 7:
                cout << "Enter the text to search: ";
                cin >> text;
                l.search(text);
                break;

            case 8:
                cout << "Displaying the texts:" << endl;
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
  
