#include <iostream>
using namespace std;

// Printing all elements of the array:
int printArray(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Printing all elements of the array using for each loop:
// Note: This function will not work as expected because the size of the array is not passed, and it will decay to a pointer.
int printArrayForEach(int arr[])
{
    cout << "Array elements: ";
    // for (int x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    return 0;
}

int main()
{

    // Array declaration syntax:
    // data_type array_name[array_size];
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing array elements:
    cout << "First element: " << arr[0] << endl; // Output: 1

    // Modifying array elements:
    arr[2] = 10; // Changing the value at index 2 to 10
    cout << "Modified third element: " << arr[2] << endl;

    printArray(arr, 5);

    int arr1[5] = {1, 2, 3}; // Remaining elements will be initialized to 0
    printArray(arr1, 5);

    int arr3[] = {1, 2, 3, 4, 5}; // Size is inferred from the initializer list
    // printArrayForEach(arr3);
    for (int x : arr3)
    {
        cout << x << " ";
    }

    float arr4[5] = {1.1, 2.2, 3.3, 9, 10}; // Array of floats
    cout << "\nFloat array elements: ";
    // auto will deduce the type of x as float in this loop
    for (auto x : arr4)
    {
        cout << x << " ";
    }

    // Char array:
    char arr5[6] = {'A', 66, 'C', 'D'};
    cout << "\nChar array elements: ";
    for (auto x : arr5)
    {
        cout << x << " ";
    }
    // for loop with char array:
    cout << "\nChar array elements using for loop: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr5[i] << " ";
    }
    // printing char array values as to their ASCII values:
    cout << "\nChar array elements as ASCII values: ";
    for (int i = 0; i < 6; i++)
    {
        cout << (int)arr5[i] << " ";
    }

    for (int x : arr5)
    {
        cout << (int)x << " ";
    }

        // Get size of the array:
    int arr6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "\nSize of arr6: " << size6 << " elements" << endl;
    return 0;
}