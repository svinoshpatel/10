#include <iostream>
#include <stdlib.h>
using namespace std;

class Array1 {
    int* Arr_Ptr; // Вказівник на динамічний масив
    int size;     // Розмір масиву
public:
    // Звичайний конструктор
    Array1(int sz) {
        Arr_Ptr = new int[sz];
        if (!Arr_Ptr) exit(1);
        size = sz;
        for (int i = 0; i < size; i++) {
            Arr_Ptr[i] = i; // Ініціалізація масиву значеннями
        }
        cout << "Ordinary constructor\n";
    }

    // Конструктор копіювання
    Array1(const Array1& a) {
        size = a.size;
        Arr_Ptr = new int[size];
        if (!Arr_Ptr) exit(1);
        for (int i = 0; i < size; i++) {
            Arr_Ptr[i] = a.Arr_Ptr[i]; // Копіювання вмісту масиву
        }
        cout << "Copy constructor\n";
    }

    // Деструктор
    ~Array1() {
        delete[] Arr_Ptr;
    }

    // Метод для виведення масиву
    void Print() const {
        for (int i = 0; i < size; i++) {
            cout << Arr_Ptr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array1 a(5); // Створення масиву розміром 5
    cout << "Array a: ";
    a.Print();

    Array1 b(a); // Створення копії масиву
    cout << "Array b: ";
    b.Print();

    return 0;
}
