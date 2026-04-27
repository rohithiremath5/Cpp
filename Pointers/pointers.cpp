#include <iostream>
using namespace std;

int main()
{

    int x = 20; // actual variable declaration.
    int *p;     // pointer variable declaration.

    p = &x; // store address of x in pointer variable

    cout << "Value of x is: " << x << endl;
    cout << "Address of x is: " << &x << endl;
    cout << "Value of p is: " << p << endl;
    cout << "Address of p is: " << &p << endl;
    cout << "Value pointed to by p is: " << *p << endl; // Dereferencing the pointer variable p.

    // Dynamic memory allocation using pointers (i., in heap memory)

    int *p0 = new int[5]{1, 2, 3, 4}; // Allocating memory for 5 integers in heap and storing the address in pointer variable p0.

    cout << "Size of p0" << sizeof(p0) << " bytes" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Value at index " << i << " is: " << p0[i] << endl;
    }

    // Deallocate the memory after use
    delete[] p0;

    p0 = nullptr;

    // Note: Always remember to deallocate memory allocated with new to prevent memory leaks.

    // Case 2:  If array size need to increase or decrease during runtime, we can use dynamic memory allocation with pointers.

    int *p1 = new int[10]; // Allocating memory for 10 integers in heap.
    delete[] p1;

    p1 = new int[20]; // Reallocating memory for 20 integers in heap.
    delete[] p1;      // Deallocating the memory after use.
    p1 = nullptr;

    // Pointer arithmetic:

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointing to the first element of the array

    cout << "First element: " << *ptr << "Address: " << ptr << endl;  // Output: 10
    ptr++;                                                            // Move to the next element
    cout << "Second element: " << *ptr << "Address: " << ptr << endl; // Output: 20

    // Reference variables:
    int a = 10;
    int &ref = a; // ref is a reference to variable a

    cout << "Value of a: " << a << endl;
    a++;
    ref++;
    cout << "Value of a: " << a << endl;     // Output: 12
    cout << "Value of ref: " << ref << endl; // Output: 12
    cout << "Address of a: " << &a << " and " << &ref << endl;

    return 0;
}