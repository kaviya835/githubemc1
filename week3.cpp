#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

// Template class for book management
template <typename T>
class Library {
    vector<shared_ptr<T>> books;
    string file_name = "books.txt";

public:
    void add_book(shared_ptr<T> book) {
        books.push_back(book);
        save_books();
        cout << "Book Added Successfully!\n";
    }

    void search_book(const string &title) {
        for (const auto &book : books) {
            if (book->get_title() == title) {
                book->display();
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void delete_book(const string &title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->get_title() == title) {
                books.erase(it);
                save_books();
                cout << "Book Deleted Successfully!\n";
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void load_books() {
        ifstream file(file_name);
        if (!file) return;
        string title, author;
        int id;
        while (file >> id >> ws && getline(file, title) && getline(file, author)) {
            books.push_back(make_shared<T>(id, title, author));
        }
    }

    void save_books() {
        ofstream file(file_name);
        for (const auto &book : books) file << book->to_string() << endl;
    }
};

// Book class
class Book {
    int id;
    string title, author;

public:
    Book(int i, string t, string a) : id(i), title(t), author(a) {}
    string get_title() const { return title; }
    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
    string to_string() const {
        return std::to_string(id) + "\n" + title + "\n" + author;
    }
};

int main() {
    Library<Book> lib;
    lib.load_books();
    int choice;
    do {
        cout << "\nLibrary Management System\n1. Add Book\n2. Search Book\n3. Delete Book\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            lib.add_book(make_shared<Book>(id, title, author));
        } else if (choice == 2) {
            string title;
            cout << "Enter Book Title: "; getline(cin, title);
            lib.search_book(title);
        } else if (choice == 3) {
            string title;
            cout << "Enter Book Title: "; getline(cin, title);
            lib.delete_book(title);
        }
    } while (choice != 4);
    return 0;
}
