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

class linked_list 
{
    Node *head;

public:
    linked_list() 
    {
        head = NULL;
    }

    // Insert at the start
    void insert_at_start(string d)
    {
        Node *ptr = new Node(d);
        ptr->next = head;
        head = ptr;
    }

    // Insert at the end
    void insert_at_end(string d)
    {
        Node *ptr = new Node(d);
        if (head == NULL) // List is empty
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
    }

    // Insert in between at a given index
    void insert_in_between(string d, int index)
    {
        if (index == 0)
        {
            insert_at_start(d);
            return;
        }

        Node *ptr = new Node(d);
        Node *p = head;

        for (int i = 0; i < index - 1 && p != NULL; i++) 
        {
            p = p->next;
        }

        if (p == NULL) 
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        ptr->next = p->next;
        p->next = ptr;
    }

    // Delete any node by value
    void delete_any_node(string val)
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }

        if (head->data == val)
        {
            delete_first_node();
            return;
        }

        Node *ptr = head;
        Node *p = head->next;

        while (p != NULL && p->data != val)
        {
            ptr = p;
            p = p->next;
        }

        if (p != NULL)
        {
            ptr->next = p->next;
            delete p;
        }
        else
        {
            cout << "Node not found" << endl;
        }
    }

    // Delete the first node
    void delete_first_node()
    {
        if (head == NULL)
        {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node *ptr = head;
        head = head->next;
        delete ptr;
    }

    // Delete the last node
    void delete_last_node()
    {
        if (head == NULL)
        {
            cout << "Deletion cannot be performed, list is empty" << endl;
            return;
        }

        if (head->next == NULL) // Only one node
        {
            delete head;
            head = NULL;
            return;
        }

        Node *ptr = head;
        Node *p = head->next;

        while (p->next != NULL)
        {
            ptr = ptr->next;      // doubt
            p = p->next;
        }

        ptr->next = NULL;
        delete p;
    }

    // Search for a node by value
    void search(string val)
    {
        Node *ptr = head;

        while (ptr != NULL && ptr->data != val)
        {
            ptr = ptr->next;
        }

        if (ptr != NULL)
        {
            cout << "The song is found in the linked list" << endl;
        }
        else
        {
            cout << "The song is not found in the linked list" << endl;
        }
    }

    // Print the entire linked list
    void print() 
    {
        if (head == NULL)
        {
            cout << "The playlist is empty" << endl;
            return;
        }

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
    string song;
    int x, c, index;
    
    do
    {
        cout << "Menu" << endl;
        cout << "1: Add a song at start\n2: Add song at the end\n3: Add a song in between\n4: Delete the first song\n5: Delete the last song\n6: Delete a song by choice\n7: Search for a song\n8: Display the playlist\n";
        cin >> x;

        switch (x)
        {
            case 1:
                cout << "Enter the song to be inserted at start: ";
                cin >> song;
                l.insert_at_start(song);
                l.print();
                break;

            case 2:
                cout << "Enter the song to be inserted at end: ";
                cin >> song;
                l.insert_at_end(song);
                l.print();
                break;

            case 3:
                cout << "Enter the song to be inserted: ";
                cin >> song;
                cout << "Enter the index at which it needs to be inserted: ";
                cin >> index;
                l.insert_in_between(song, index);
                l.print();
                break;

            case 4:
                cout << "Deleting the first node..." << endl;
                l.delete_first_node();
                l.print();
                break;

            case 5:
                cout << "Deleting the last node..." << endl;
                l.delete_last_node();
                l.print();
                break;

            case 6:
                cout << "Enter the song to delete: ";
                cin >> song;
                l.delete_any_node(song);
                l.print();
                break;

            case 7:
                cout << "Enter the song to search: ";
                cin >> song;
                l.search(song);
                break;

            case 8:
                cout << "Displaying the playlist of your favorite songs:" << endl;
                l.print();
                break;

            default:
                cout << "Invalid option" << endl;
        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> c;
    } while (c != 0);

    return 0;
}
