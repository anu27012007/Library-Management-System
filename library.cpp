#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------- Book Class ---------------------
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

// ------------------- Member Class -------------------
class Member {
public:
    int memberId;
    string name;

    Member(int memberId, string name) {
        this->memberId = memberId;
        this->name = name;
    }
};

// ------------------- Library Class -------------------
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Add Book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // Add Member
    void addMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    // Issue Book
    void issueBook(int bookId) {
        for (auto &b : books) {
            if (b.id == bookId) {
                if (!b.isIssued) {
                    b.isIssued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Return Book
    void returnBook(int bookId) {
        for (auto &b : books) {
            if (b.id == bookId) {
                if (b.isIssued) {
                    b.isIssued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Search by Title
    void searchByTitle(string title) {
        for (auto &b : books) {
            if (b.title == title) {
                cout << "Book Found → ID: " << b.id << ", Title: " << b.title
                     << ", Author: " << b.author 
                     << ", Issued: " << (b.isIssued ? "Yes" : "No") << endl;
                return;
            }
        }
        cout << "No book found with given title.\n";
    }

    // Search by Author
    void searchByAuthor(string author) {
        for (auto &b : books) {
            if (b.author == author) {
                cout << "Book Found → ID: " << b.id << ", Title: " << b.title
                     << ", Author: " << b.author 
                     << ", Issued: " << (b.isIssued ? "Yes" : "No") << endl;
                return;
            }
        }
        cout << "No book found with the author.\n";
    }

    // Display All Books
    void displayBooks() {
        cout << "\n--- Book List ---\n";
        for (auto &b : books) {
            cout << "ID: " << b.id << " | Title: " << b.title
                 << " | Author: " << b.author
                 << " | Issued: " << (b.isIssued ? "Yes" : "No") << endl;
        }
    }

    // Display All Members
    void displayMembers() {
        cout << "\n--- Member List ---\n";
        for (auto &m : members) {
            cout << "Member ID: " << m.memberId 
                 << " | Name: " << m.name << endl;
        }
    }
};

// ------------------- Main Program -------------------
int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n2. Add Member\n3. Issue Book\n4. Return Book\n";
        cout << "5. Search Book by Title\n6. Search Book by Author\n";
        cout << "7. Display All Books\n8. Display All Members\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            lib.addBook(id, title, author);
        } 
        else if (choice == 2) {
            int id;
            string name;
            cout << "Enter Member ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Member Name: "; getline(cin, name);
            lib.addMember(id, name);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;
            lib.issueBook(id);
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;
            lib.returnBook(id);
        }
        else if (choice == 5) {
            string title;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            lib.searchByTitle(title);
        }
        else if (choice == 6) {
            string author;
            cin.ignore();
            cout << "Enter Author: ";
            getline(cin, author);
            lib.searchByAuthor(author);
        }
        else if (choice == 7) {
            lib.displayBooks();
        }
        else if (choice == 8) {
            lib.displayMembers();
        }
        else if (choice == 9) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}