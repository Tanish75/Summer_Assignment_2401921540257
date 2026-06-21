#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Base Class
class Compartment 
{
public:
    virtual string notice() = 0;  // Pure virtual function
    virtual ~Compartment() {}
};

// Derived Classes
class FirstClass : public Compartment 
{
public:
    string notice() override {
        return "First Class Compartment";
    }
};

class Ladies : public Compartment 
{
public:
    string notice() override 
{
        return "Ladies Compartment";
    }
};

class General : public Compartment 
{
public:
    string notice() override 
{
        return "General Compartment";
    }
};

class Luggage : public Compartment 
{
public:
    string notice() override 
{
        return "Luggage Compartment";
    }
};

int main() {
    srand(time(0));

    Compartment* arr[10];

    // Create random compartments
    for (int i = 0; i < 10; i++) 
    {
        int r = rand() % 4 + 1;  // Random number 1-4

        switch (r) {
            case 1:
                arr[i] = new FirstClass();
                break;
            case 2:
                arr[i] = new Ladies();
                break;
            case 3:
                arr[i] = new General();
                break;
            case 4:
                arr[i] = new Luggage();
                break;
        }
    }

    // Demonstrate polymorphism
    cout << "Compartment Notices:\n";
    for (int i = 0; i < 10; i++) 
    {
        cout << i + 1 << ". " << arr[i]->notice() << endl;
    }

    // Free memory
    for (int i = 0; i < 10; i++) 
    {
        delete arr[i];
    }

    return 0;
}
