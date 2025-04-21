#include <iostream>
using namespace std;

class Base {
protected:
    int num;
    char letter;
public:
    // Конструктор за замовчуванням
    Base() {
        cout << "Base()\n";
    }

    // Конструктор копіювання
    Base(const Base& other) {
        num = other.num;
        letter = other.letter;
        cout << "Base(Base&)\n";
    }

    // Конструктор з параметром int
    explicit Base(int i) : num(i) {
        cout << "Base(int)\n";
    }

    // Конструктор з параметром char
    explicit Base(char c) : letter(c) {
        cout << "Base(char)\n";
    }
};

class Derived : public Base {
public:
    using Base::Base; // Успадкування всіх конструкторів Base
private:
    int newMember{ 0 }; // Нове поле з ініціалізацією
};

int main() {
    cout << "Derived d1(5) calls: ";
    Derived d1(5); // Виклик Base(int)

    cout << "Derived d2('c') calls: ";
    Derived d2('c'); // Виклик Base(char)

    cout << "Derived d3 = d2 calls: ";
    Derived d3 = d2; // Виклик Base(Base&)

    cout << "Derived d4 calls: ";
    Derived d4; // Виклик Base()

    return 0;
}
