
// DOUBT


#include <iostream>
using namespace std;

class Node 
{
public:
    int coef;  
    int expo;  
    Node* next;


    Node(int n, int p) 
    {
        coef = n;
        expo = p;
        next = NULL;
    }
};

class LinkedList
 {
    Node* head;

public:
   
    LinkedList()
     {
        head = NULL;
    }


    void create(int coef, int expo)
     {
        Node* newNode = new Node(coef, expo);
        if (head == NULL || expo > head->expo) 
        {
            newNode->next = head;
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != NULL && temp->next->expo > expo) 
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void print() 
    {
        if (head == NULL) 
        {
            cout << "Polynomial is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->coef << "x^" << temp->expo;
            if (temp->next != NULL) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

   
    LinkedList addPolynomials(LinkedList& poly2) 
    {
        LinkedList result;
        Node* p1 = head;
        Node* p2 = poly2.head;

        while (p1 != NULL && p2 != NULL)
         {
            if (p1->expo == p2->expo)
             {
                result.create(p1->coef + p2->coef, p1->expo);
                p1 = p1->next;
                p2 = p2->next;
            } 
            else if (p1->expo > p2->expo) 
            {
                result.create(p1->coef, p1->expo);
                p1 = p1->next;
            } 
            else 
            {
                result.create(p2->coef, p2->expo);
                p2 = p2->next;
            }
        }

    
        while (p1 != NULL) 
        {
            result.create(p1->coef, p1->expo);
            p1 = p1->next;
        }

        while (p2 != NULL) 
        {
            result.create(p2->coef, p2->expo);
            p2 = p2->next;
        }

        return result;
    }
};

int main() 
{
    int n, coef, expo;

    LinkedList poly1, poly2, result;

   
    cout << "Enter the number of terms for the first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter the coefficient for term " << i + 1 << ": ";
        cin >> coef;
        cout << "Enter the exponent for term " << i + 1 << ": ";
        cin >> expo;
        poly1.create(coef, expo);
    }

 
    cout << "Enter the number of terms for the second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++)
     {
        cout << "Enter the coefficient for term " << i + 1 << ": ";
        cin >> coef;
        cout << "Enter the exponent for term " << i + 1 << ": ";
        cin >> expo;
        poly2.create(coef, expo);
    }


    cout << "First Polynomial: ";
    poly1.print();

    cout << "Second Polynomial: ";
    poly2.print();

  
    result = poly1.addPolynomials(poly2);


    cout << "Resultant Polynomial after Addition: ";
    result.print();

    return 0;
}
