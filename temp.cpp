#include <iostream>
#include <cstring>

class Person {
private:
    char* name;

public:
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy constructor for shallow copying
    Person(const Person& other) {
        name = other.name; // Shallow copy of the pointer
    }

    // Copy constructor for deep copying
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name); // Deep copy of the name string
    }

    ~Person() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }
};

int main() {
    Person person1("John");

    // Shallow copy
    Person person2(person1);
    std::cout << "Person 2 (Shallow Copy): " << person2.getName() << std::endl;

    // Deep copy
    Person person3 = person1; // Using the copy constructor
    std::cout << "Person 3 (Deep Copy): " << person3.getName() << std::endl;

    return 0;
}
