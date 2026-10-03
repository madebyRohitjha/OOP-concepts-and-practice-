#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author; 
    int year;

public:
    Book() : id(0), title(""), author(""), year(0) {}

    Book(int bookId, const string& bookTitle, const string& bookAuthor, int publicationYear)
        : id(bookId), title(bookTitle), author(bookAuthor), year(publicationYear) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    void setId(int bookId) { id = bookId; }
    void setTitle(const string& bookTitle) { title = bookTitle; }
    void setAuthor(const string& bookAuthor) { author = bookAuthor; }
    void setYear(int publicationYear) { year = publicationYear; }

    void show() const {
        cout << "ID: " << id << " | Title: " << title
             << " | Author: " << author << " | Year: " << year << '\n';
    }
};

class Library {
private:
    static const int CAP = 100;
    Book books[CAP];
    int count;
    int nextId;

    int indexOf(int id) const {
        for (int i = 0; i < count; ++i) {
            if (books[i].getId() == id) return i;
        }
        return -1;
    }

    static int readYear() {
        int year;
        while (true) {
            cout << "Year: ";
            if (cin >> year) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return year;
            }
            cout << "Please enter a valid year.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    Library() : count(0), nextId(1) {}

    void addBook() {
        if (count >= CAP) {
            cout << "The library is full. No more books can be added.\n";
            return;
        }
        string title, author;
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        int year = readYear();

        books[count] = Book(nextId, title, author, year);
        cout << "Book added with ID " << nextId << ".\n";
        ++count;
        ++nextId;
    }

    void listBooks() const {
        if (count == 0) {
            cout << "There are no books in the library.\n";
            return;
        }
        cout << "\nBooks in the library:\n";
        for (int i = 0; i < count; ++i) books[i].show();
    }

    void findById() const {
        int id;
        cout << "Enter book ID: ";
        if (!(cin >> id)) {
            cout << "Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int index = indexOf(id);
        if (index == -1) cout << "Book not found.\n";
        else books[index].show();
    }

    void updateBook() {
        int id;
        cout << "Enter book ID to update: ";
        if (!(cin >> id)) {
            cout << "Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int index = indexOf(id);
        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }
        string title, author;
        cout << "New title: ";
        getline(cin, title);
        cout << "New author: ";
        getline(cin, author);
        int year = readYear();
        books[index].setTitle(title);
        books[index].setAuthor(author);
        books[index].setYear(year);
        cout << "Book updated.\n";
    }

    void deleteBook() {
        int id;
        cout << "Enter book ID to delete: ";
        if (!(cin >> id)) {
            cout << "Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int index = indexOf(id);
        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }
        for (int i = index; i < count - 1; ++i) books[i] = books[i + 1];
        --count;
        cout << "Book deleted.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== Book Management System =====\n"
             << "1. Add Book\n"
             << "2. List Books\n"
             << "3. Search Book\n"
             << "4. Update Book\n"
             << "5. Delete Book\n"
             << "6. Exit\n"
             << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Please enter a number from 1 to 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.listBooks(); break;
            case 3: library.findById(); break;
            case 4: library.updateBook(); break;
            case 5: library.deleteBook(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Choose 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}
