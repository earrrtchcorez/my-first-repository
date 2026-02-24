// Here’s a complete, runnable C++ example demonstrating function templates and class templates with proper input validation and comments.

Cpp#include <iostream>
#include <stdexcept> // For exception handling
using namespace std;     //

// =======================
// Function Template
// =======================
// A generic function to find the maximum of two values
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// =======================
// Class Template
// =======================
// A generic class for a simple pair of values
template <typename T1, typename T2>
class MyPair {
private:
    T1 first;
    T2 second;

public:
    // Constructor
    MyPair(T1 f, T2 s) : first(f), second(s) {}

    // Display the pair
    void display() const {
        cout << "First: " << first << ", Second: " << second << endl;
    }

    // Swap the values (only if types are the same)
    void swapValues() {
        if constexpr (is_same<T1, T2>::value) {
            T1 temp = first;
            first = second;
            second = temp;
        } else {
            throw logic_error("Swap not allowed: types are different.");
        }
    }
};

int main() {
    try {
        // ===== Function Template Example =====
        cout << "Max of 10 and 20: " << getMax(10, 20) << endl;
        cout << "Max of 5.5 and 2.3: " << getMax(5.5, 2.3) << endl;

        // ===== Class Template Example =====
        MyPair<int, int> intPair(3, 7);
        intPair.display();
        intPair.swapValues();
        cout << "After swap: ";
        intPair.display();

        MyPair<string, double> mixedPair("Pi", 3.14159);
        mixedPair.display();
        // mixedPair.swapValues(); // This will throw an exception

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


// How it works//


// Function Template //

//getMax<T> works for any type that supports the > operator.
Automatically deduces the type from the arguments. //



// Class Template //

// MyPair<T1, T2> can store two values of possibly different types.
swapValues() only works if both types are the same (checked at compile time with if constexpr).//



// Error Handling// 

// Throws an exception if swapping is attempted on different types.//




// ✅ This code is self-contained, type-safe, and demonstrates both function and class templates in C++.// 

// If you want, I can also give you an advanced C++ template example using template specialization and concepts (C++20) for even more type safety.
Do you want me to prepare that?  //
