#include <iostream>
using namespace std;

class Myc1 {
    int* p; // Вказівник на ціле число
public:
    // Конструктор з параметром
    Myc1(int x) {
        p = new int(x);
    }

    // Конструктор копіювання
    Myc1(const Myc1& a) {
        p = new int(*a.p); // Глибоке копіювання
    }

    // Деструктор
    ~Myc1() {
        delete p;
    }

    // Метод для отримання значення
    int Get() const {
        return *p;
    }

    // Метод для встановлення значення
    void Set(int x) {
        *p = x;
    }
};

int main() {
    int x = 5;
    Myc1 a(x); // Створення об’єкта a зі значенням 5
    cout << "a.p => " << a.Get() << endl;

    Myc1 b(a); // Створення об’єкта b як копії a
    cout << "b.p => " << b.Get() << endl;

    a.Set(7); // Зміна значення в об’єкті a
    cout << "b.p => " << b.Get() << endl; // Перевірка, чи змінилося значення в b

    return 0;
}
