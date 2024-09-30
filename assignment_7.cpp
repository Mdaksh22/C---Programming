#include <iostream> 
using namespace std;
class Stack 
{
  private:
    string * array; 
    int top; 
    int capacity; 

  public:
    
    Stack(int size) 
    {
      capacity = size;
      array = new string[capacity]; 
      top = -1; 
    }

   
    ~Stack() 
    {
      delete[] array;
    }

    
    void push(string text) 
    {
      if (top == capacity - 1) 
      { 
        cout << "Stack Overflow. Cannot push element: " << text << endl;
        return;
      }
      top++;
      array[top]=text; 
      cout << "Browsing history : " << text << endl; 
    }

   

       void pop() 
   {

        if (top== -1)
        {
            cout << " Stack is Empty!";

        }
        else 
        {
            //cout<<"popping the element: "<<array[top]<<endl;
            top--;
            cout<<"Navigating back: ";
            if(top==-1)
            {
              cout<<"no history beyond this.."<<endl;
            }
            else{
            cout<<array[top]<<endl;
            }
        }
    }


    void view_current_page()
    {
        if(top==-1)
        {
            cout << " Stack is Empty!"<<endl;

        }
        else
        {

          cout<<"viewing the current page: ";
          cout<<array[top]<<endl;
        }
    }


    void empty()
     {
        if(top==-1)
        {
            cout<<" browsing history is empty! "<<endl;
        }
        else
        {
          cout<<"browsing history not empty!"<<endl;
        }
     }

    void show()
    {
      if(top==-1)
      {
        cout<<"history is empty..."<<endl;
      }
        // cout << "Display :" << endl;
        for(int i =0; i <= top-1; i++)
        {
            cout << array[i] << endl;
        }


     }
};

int main() 
{
   int c;
   int n;
cout<<"enter the size of the stack: ";
cin>>n;
int x;
string text;
Stack s(n);
  
    do
    {
        cout << "Menu" << endl;
        cout << "1: Add visited page\n2: Navigate back \n3: View current page\n4:To check if history is empty or not\n";
        cin >> x;

        switch (x)
        {
            case 1:
            cout<<"enter the visited page: "<<endl;
            cin>>text;
            s.push(text);
            s.show();
            break;
                

            case 2:

            cout<<"Navigating back..."<<endl;
            s.pop();
            s.show();
                
                break;

            case 3:

           
            s.view_current_page();
            
                
                break;

            case 4:
              cout<<"checking if history is empty or not..."<<endl;
              s.empty();
                break;
            

            default:
                cout << "Invalid option" << endl;
        }

        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> c;
    } while (c != 0);
    

return 0;
}
