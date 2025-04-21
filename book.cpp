#include <iostream>
s
#include <string>
using namespace std;

// Базовий клас для книги
class Book {
protected:
    string title;
    int year;
public:
    // Звичайний конструктор за замовчуванням
    Book() : title("Unknown"), year(0) {
        cout << "Book default constructor: " << title << endl;
    }

    // Конструктор з параметрами
    Book(string t, int y) : title(t), year(y) {
        cout << "Book parameterized constructor: " << title << ", " << year << endl;
    }

    // Конструктор копіювання
    Book(const Book& other) : title(other.title), year(other.year) {
        cout << "Book copy constructor: " << title << endl;
    }

    // Деструктор
    ~Book() {
        cout << "Book destructor: " << title << endl;
    }

    // Метод для виведення інформації
    void display() const {
        cout << "Book: " << title << ", Year: " << year << endl;
    }
};

// Похідний клас для електронної книги
class EBook : public Book {
private:
    string format; // Формат файлу (наприклад, PDF, EPUB)
public:
    // Успадкування конструкторів базового класу
    using Book::Book;

    // Конструктор з параметрами, включаючи формат
    EBook(string t, int y, string f) : Book(t, y), format(f) {
        cout << "EBook constructor: " << title << ", Format: " << format << endl;
    }

    // Конструктор копіювання
    EBook(const EBook& other) : Book(other), format(other.format) {
        cout << "EBook copy constructor: " << title << ", Format: " << format << endl;
    }

    // Деструктор
    ~EBook() {
        cout << "EBook destructor: " << title << endl;
    }

    // Перевизначений метод виведення
    void display() const {
        cout << "EBook: " << title << ", Year: " << year << ", Format: " << format << endl;
    }
};

// Клас для бібліотеки
class Library {
private:
    Book book1; // Звичайна книга
    EBook ebook1; // Електронна книга
public:
    // Конструктор бібліотеки
    Library() : book1("Default Book", 2000), ebook1("Default EBook", 2020, "PDF") {
        cout << "Library constructor" << endl;
    }

    // Конструктор з параметрами
    Library(Book b, EBook e) : book1(b), ebook1(e) {
        cout << "Library parameterized constructor" << endl;
    }

    // Конструктор копіювання
    Library(const Library& other) : book1(other.book1), ebook1(other.ebook1) {
        cout << "Library copy constructor" << endl;
    }

    // Деструктор
    ~Library() {
        cout << "Library destructor" << endl;
    }

    // Метод для виведення вмісту бібліотеки
    void display() const {
        cout << "Library contents:" << endl;
        book1.display();
        ebook1.display();
    }
};

int main() {
    cout << "=== Creating individual books ===" << endl;
    Book b1; // Виклик конструктора за замовчуванням
    Book b2("C++ Programming", 2023); // Виклик конструктора з параметрами
    Book b3(b2); // Виклик конструктора копіювання

    cout << "\n=== Creating eBooks ===" << endl;
    EBook e1("AI Revolution", 2025, "EPUB"); // Виклик успадкованого конструктора з параметрами
    EBook e2(e1); // Виклик конструктора копіювання

    cout << "\n=== Creating library ===" << endl;
    Library lib(b2, e1); // Виклик конструктора бібліотеки з параметрами
    lib.display();

    cout << "\n=== Copying library ===" << endl;
    Library lib2(lib); // Виклик конструктора копіювання бібліотеки
    lib2.display();

    cout << "\n=== End of program ===" << endl;
    return 0;
}
