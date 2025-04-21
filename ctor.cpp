#include <iostream>
using namespace std;

class Contained1 {
public:
    Contained1() {
        cout << "Contained1 ctor\n";
    }
};

class Contained2 {
public:
    Contained2() {
        cout << "Contained2 ctor\n";
    }
};

class Contained3 {
public:
    Contained3() {
        cout << "Contained3 ctor\n";
    }
};

class BaseContainer {
    Contained1 c1; // Поле типу Contained1
    Contained2 c2; // Поле типу Contained2
    Contained3 c3; // Поле типу Contained3
public:
    BaseContainer() {
        cout << "BaseContainer ctor\n";
    }
};

int main() {
    BaseContainer bc; // Створення об’єкта BaseContainer
    return 0;
}
