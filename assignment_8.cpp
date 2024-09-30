#include<iostream>
using namespace std;

class Stack 
{
    string* stk;
    int top;
    int capacity;

public:
    
    Stack(int size) 
    {
        stk = new string[size];
        top = -1;
        capacity = size;
    }

    
    ~Stack() 
    {
        delete[] stk;
    }

    
    void push(char c) 
    {
        if (top < capacity - 1) 
        {
            top++;
            stk[top] = c;
        } 
        else
         {
            cout << "Stack Overflow" << endl;
        }
    }

    
    void pop() 
        {
        if (top == -1) 
        {
            cout << "Stack is empty" << endl;
        } 
        else 
        {
            top--;
        }
    }

    
    char peek() 
       {
        if (top != -1) 
        {
            return stk[top][0];      //imp it return s the top element without deleting it
        } 
        else 
        {
            return '!'; 
        }
    }


    int precedence(char c) 
    {
        if (c == '^') 
        {
            return 3;
        } 
        else if (c == '*' || c == '/') 
        {
            return 2;
        }
         else if (c == '+' || c == '-') 
        {
            return 1;
        } 
        else 
        {
            return -1;
        }
    }
    string infix_to_prefix(string s) 
    {
        string res;
        string finalres;

      
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            char c = s[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
            {
                res += c;
            }
         
            else if (c == ')') 
            {
                push(c);
            }
          
            else if (c == '(') 
            {
                while (peek() != ')' && top != -1) 
                {
                    res += peek();
                    pop();
                }
                pop();  
            }
           
            else 
            {
                while (top != -1 && precedence(peek()) >= precedence(c)) 
                {
                    res += peek();
                    pop();
                }
                push(c);
            }
        }

     
        while (top != -1) 
        {
            res += peek();
            pop();
        }

     
        for (int i = res.length() - 1; i >= 0; i--) 
        {
            finalres += res[i];
        }

       cout << "Prefix expression: " << finalres << endl;
    }

    string infix_to_postfix(string s) 
    {
        string res;
        
        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                res += c;
            }
         
            else if (c == '(') 
            {
                push(c);
            }
       
            else if (c == ')') 
            {
                while (peek() != '(' && top != -1) 
                {
                    res += peek();
                    pop();
                }
                pop();  // to pop ')' closing bracket 
            }
       
            else // this else is for operator
            {
                while (top != -1 && precedence(peek()) >= precedence(c))  // bade pe chota nahi aa sakta hai
                {
                    res += peek();
                    pop();
                }
                push(c);
            }
        }

      
        while (top != -1) 
        {
            res += peek();
            pop();
        }

                    cout << "Postfix expression: " << res << endl;

    }
};

int main() 
{

    int c,x;
 
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    string exp;
    cout << "Enter the infix expression: ";
    cin >> exp;

    Stack st(size);

  
    do
    {
        cout << "Menu" << endl;
        cout << "1: To convert infix to postfix\n2:To convert infix to prefix \n";
        cin >> x;

        switch (x)
        {
            case 1:
            cout<<"converting infix into postfix... "<<endl;
        
             st.infix_to_postfix(exp);

             

            break;
                

            case 2:

            cout<<"converting infix into prefix..."<<endl;

             st.infix_to_prefix(exp);

            
          
            break;

           
            default:
                cout << "Invalid option" << endl;
            

        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> c;
    } while (c != 0);
    

    return 0;
}
