#include <iostream>
using namespace std;

class employee 
{
    string name;
    int id;
    int salary;

public:
    void input();
    int partition(employee arr[], int low, int high);
    void quicksort(employee arr[], int low, int high);
    void mergesort(employee arr[], int low, int high);
    void merge(employee arr[], int low, int mid, int high);
    void show();
};

void employee::input() {
    cout << "Enter the employee name: ";
    cin >> name;
    cout << "Enter the employee id: ";
    cin >> id;
    cout << "Enter the employee salary: ";
    cin >> salary;
}

int employee::partition(employee arr[], int low, int high) {
    int pivot = arr[low].id;  // Choose the first element as the pivot
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i].id <= pivot && i < high)
            i++;
        while (arr[j].id > pivot && j > low)
            j--;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);  // Place the pivot in the correct position
    return j;  // Return the partition index
}

void employee::quicksort(employee arr[], int low, int high) {
    if (low < high) {
        int pindex = partition(arr, low, high);  // Partition the array
        quicksort(arr, low, pindex - 1);         // Sort the left part
        quicksort(arr, pindex + 1, high);        // Sort the right part
    }
}

void employee::merge(employee arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    employee arr1[100];

    while (i <= mid && j <= high) {
        if (arr[i].name < arr[j].name) {
            arr1[k++] = arr[i++];
        } else {
            arr1[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        arr1[k++] = arr[i++];
    }

    while (j <= high) {
        arr1[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = arr1[i];
    }
}

void employee::mergesort(employee arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void employee::show() {
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Employee Salary: " << salary << endl;
}

int main() {
    employee x, *arr;
    int a, b, c;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enter employee details" << endl;
        cout << "2. Display employee details" << endl;
        cout << "3. Sort employee details by id (quick sort)" << endl;
        cout << "4. Sort employee details by alphabet (merge sort)" << endl;
        cout << "Enter your choice: ";
        cin >> a;

        switch (a) {
        case 1:
            cout << "Enter the number of employees: ";
            cin >> b;
            arr = new employee[b];
            for (int i = 0; i < b; i++) {
                arr[i].input();
            }
            break;

        case 2:
            cout << "The details entered are:" << endl;
            for (int i = 0; i < b; i++) {
                arr[i].show();
            }
            break;

        case 3:
            cout << "The sorted details for employee by ID are: " << endl;
            x.quicksort(arr, 0, b - 1);
            for (int i = 0; i < b; i++) {
                arr[i].show();
            }
            break;

        case 4:
            cout << "The sorted details for employee by name are: " << endl;
            x.mergesort(arr, 0, b - 1);
            for (int i = 0; i < b; i++) {
                arr[i].show();
            }
            break;

        default:
            break;
        }

        cout << "Do you want to continue? (1 for yes and 0 for no): ";
        cin >> c;
        if (c == 0) {
            delete[] arr;
        }
    } while (c != 0);

    return 0;
}

// we cannot use an int array in place of an employee array in the main function because the quicksort, partition, and show functions all operate on objects of type employee. The employee class contains multiple data members like name, id, and salary, and these functions are designed to work specifically with employee objects.