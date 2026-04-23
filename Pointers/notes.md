🔹 1. What is a Pointer?
A pointer is a variable that stores the address of another variable
Declared using *
int x = 10;
int *p = &x;
p → stores address of x
*p → gives value at that address (10)
🔹 2. Pointer Size (VERY IMPORTANT 🔥)
Key Rule:

Pointer size depends on system architecture, NOT data type

Example:
int *p1;
float *p2;
double *p3;
char *p4;

👉 All pointers take:

8 bytes (64-bit system)
4 bytes (32-bit system)
Why?
Pointer stores address, not data
Important Insight:

Data type is used for pointer arithmetic, not size

🔹 3. Declaration vs Initialization
✔️ Declaration:
int *p;
✔️ Initialization:
int x = 10;
p = &x;
✔️ Combined:
int *p = &x;
🔹 4. Dereferencing

Accessing value at the address stored in pointer

int x = 10;
int *p = &x;

cout << *p;  // 10
🔹 5. Stack vs Heap Memory
🟦 Stack
Stores local variables
Automatic allocation & deallocation
Fast
Limited size
int a = 10;
int arr[5];
🟥 Heap
Dynamic memory allocation
Manual management
Large memory
int *p = new int[5];
🔹 6. Dynamic Memory (Heap)
Allocation:
int *p = new int[5];
Deallocation:
delete[] p;
🔹 7. Memory Leak

Memory allocated but not freed

int *p = new int[5];
p = nullptr;   // ❌ memory lost

👉 Problem:

Memory still in heap
No pointer to access → waste
🔹 8. Dangling Pointer

Pointer pointing to deleted memory

int *p = new int[5];
delete[] p;

p; // ❌ dangling pointer
Fix:
p = nullptr;
🔹 9. NULL vs nullptr
NULL
Value = 0
Old C-style
nullptr (Modern C++ ✅)
Keyword
Type-safe
Preferred
int *p = nullptr;
🔹 10. Pointer Arithmetic
int arr[5] = {1,2,3,4,5};
int *p = arr;

p++;  // moves to next element

👉 Moves by:

sizeof(data type) (not 1 byte)
🔹 11. Arrays & Pointers
Key Rule:

Array name = base address

int A[5] = {2,4,6,8,10};

int *p = A;      // ✅ valid
int *q = &A[0];  // ✅ same
Invalid:
p = &A;  // ❌
🔹 12. Accessing Array via Pointer
p[2] = 15;

Same as:

*(p + 2) = 15;
🔹 13. r-value vs l-value
int x = 10;
x = 20;   // x → l-value (address used)

int y = x; // x → r-value (value used)
🔹 14. Why Pointers Are Used
Dynamic memory allocation
Efficient data passing
Modify original data
Build data structures (LL, Trees, Graphs)
Low-level memory access
🔹 15. Real-world Example (Chrome)
Tabs opened dynamically
Memory allocated in heap
Closed tabs → memory freed

👉 If not freed → Memory Leak

🔹 16. Smart Pointers (Modern C++)
Types:
unique_ptr → single owner
shared_ptr → multiple owners
weak_ptr → avoids circular dependency

👉 Automatic memory management

🔹 17. Vector (Modern C++)
std::vector<int> v = {1,2,3};
Features:
Dynamic size
Safe
.size() available
No manual delete


🔹 18. What is a Vector?

👉 std::vector

A vector is a dynamic array provided by C++ Standard Library.

✔️ Example:
#include <vector>

std::vector<int> v = {1,2,3,4,5};
✔️ Features:
Dynamic size (can grow/shrink)
Automatic memory management
Safe (no manual delete)
Stores elements in contiguous memory (like array)
✔️ Common Operations:
v.push_back(10);   // add element
v.pop_back();      // remove last
v.size();          // get size
v[0];              // access
❗ Why vector over array?
Feature	Array	Vector ✅
Size	Fixed	Dynamic
Memory	Manual	Automatic
Safety	Low	High
Size access	No direct method	.size()
🔹 19. What are Smart Pointers?

👉 Provided by C++ Standard Library

Smart pointers are wrapper objects that manage raw pointers automatically.

✔️ Why needed?

Problem with raw pointers:

Manual delete
Memory leaks
Dangling pointers
Hard to manage

👉 Smart pointers solve all this

🔹 20. Types of Smart Pointers
🟢 1. unique_ptr (Most Important ⭐)
#include <memory>

std::unique_ptr<int> p = std::make_unique<int>(10);
✔️ Features:
Only one owner
Cannot be copied
Automatically deleted
🟡 2. shared_ptr
std::shared_ptr<int> p1 = std::make_shared<int>(10);
std::shared_ptr<int> p2 = p1;
✔️ Features:
Multiple owners
Uses reference counting
Deleted when last owner is gone
🔵 3. weak_ptr
Works with shared_ptr
Prevents memory issues (circular reference)
🔥 21. Why Smart Pointers over Raw Pointers?
Feature	Raw Pointer ❌	Smart Pointer ✅
Memory cleanup	Manual	Automatic
Safety	Low	High
Leak risk	High	Very low
Ease of use	Hard	Easy

🔹 22. What is RAII? (VERY IMPORTANT 🔥)

👉 RAII = Resource Acquisition Is Initialization

✔️ Definition:

Resource is acquired when object is created and released when object is destroyed

✔️ Simple Meaning:
Constructor → allocate resource
Destructor → free resource
✔️ Example (Smart Pointer):
{
    std::unique_ptr<int> p = std::make_unique<int>(10);
} // memory automatically freed here

👉 When p goes out of scope → memory freed

✔️ Example (Vector):
{
    std::vector<int> v = {1,2,3};
} // memory automatically freed
🔥 Why RAII is Powerful?
No manual delete
No memory leaks
Exception safe
Clean and maintainable code

🔹 23. RAII vs Manual Memory
Feature	Manual (Raw Pointer) ❌	RAII (Modern C++) ✅
Memory handling	Manual	Automatic
Safety	Low	High
Leak risk	High	Very low
🔹 24. When to Use What?
✔️ Use Vector:
Arrays
DSA problems
Default choice
✔️ Use Smart Pointers:
Objects in heap
Complex systems
Ownership management
✔️ Use Raw Pointer:
Rare cases
Low-level programming
Performance-critical code