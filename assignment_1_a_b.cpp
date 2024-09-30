#include<iostream>
using namespace std;
class student
{
    int roll;
    string name;
    float cgpa;
    public:
    void input();
    void output();
static void insertion_sort(student s[],int n);     
static void shell_sort(student s[],int n);     
};

void student::input()
{
    cout<<"enter the student name"<<endl;
    cin>>name;
    cout<<"enter the student roll"<<endl;
    cin>>roll;
    cout<<"enter the student cgpa"<<endl;
    cin>>cgpa;

}

void student::output() {
    cout << "Name: " << name << endl;
    cout << "Roll: " << roll << endl;
    cout << "CGPA: " << cgpa << endl;
}

void student::insertion_sort(student s[],int n)  // imp 
{
    for (int i = 1; i < n; i++) {
        student val = s[i];   //as s[i] is stored in the data type student we cannot declare it as int  
        int j = i - 1;
        while (j >= 0 && s[j].roll > val.roll) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = val;
    }
}

void student::shell_sort(student s[], int n) {
    int gap = n / 2;
    while (gap >= 1) {
        for (int j = gap; j < n; j++) {
            for (int i = j - gap; i >= 0; i -= gap) {
                if (s[i].name > s[i + gap].name) {
                    
                    student temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                } else {
                    break;
                }
            }
        }
        gap /= 2;
    }
}


int main()
{
    student s[100],l; 
    
    // student here acts as a datatype for the array 

    // here we are storing the info i.e student database in student data type so we have declared student as its data type



    int a,x,c;
    do{
    cout << "Menu:" << endl;
        cout << "1. Enter student details" << endl;
        cout << "2. Display student details" << endl;
        cout << "3. Sort student details by roll number by insertion sort: " << endl;
        cout << "4. Sort student details by name number by shell sort: " << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
            cout<<"enter the number of students"<<endl;
            cin>>x;
            for(int i=0;i<x;i++)
            {
                s[i].input();
            }
            break;

        case 2:
        cout<<"the details entered are"<<endl;
        for(int i=0;i<x;i++)
            {
                s[i].output();
            }
            break;

        case 3:
                cout << "The sorted details for roll number are: " << endl;
                l.insertion_sort(s, x);   
                for (int i = 0; i <x; i++) 
                {
                    s[i].output();
                }
                break;
        case 4:
               cout<<"the sorted details for name is: "<<endl;
               l.shell_sort(s,x);
               for(int i=0;i<x;i++)
               {
                     s[i].output();
               }

        default:
            break;
        }
        cout<<"Do you want to continue? (1 for yes and 0 for no): ";
        cin>>c;
    }
        while (c!=0);
        return 0;

}

// The sort function doesn't need to access or modify any instance variables (name, roll, cgpa) of the student class itself. Instead, it works on an array of student objects passed as an argument.

// Since it does not rely on any specific instance of the class, making it static indicates this independence.