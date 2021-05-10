#include <iostream>
#include <conio.h>

using namespace std;

struct Book {
    string name;
    string author;
    int id;
    float cost;
    string category;
};

typedef struct Book Book;

const int n = 50;
int d = 0; // deleted books

Book books[n];

Book getBook() {
    cout << "Enter the book information: [name, author, id, cost, category]" << endl;
    
    Book book;
    cin >> book.name;
    cin >> book.author;
    cin >> book.id;
    cin >> book.cost;
    cin >> book.category;

    return book;
}

void show_book(Book book) {
    cout << "=== name: " << book.name << endl;
    cout << "\tauthor: " << book.author << endl;
    cout << "\tcategory: " << book.category << endl;
    cout << "\ncost: " << book.cost << endl;
    cout << "==" << endl;
}

int findBook(string book_name) {
    for(int i = 0; i < n - d; i++) {
        if (books[i].name == book_name) return i;
    }
    return -1;
}

void deleteBook(string book_name) {
    int p = findBook(book_name);

    if (p != -1) {
        d++;

        for(int i = p; i < n-1; i++) {
            books[i] = books[i+1];
        }
        cout << "The book has been deleted." << endl;
    } else {
        cout << "No book found with this name." << endl;
    }
}

void sort_books() {
    for(int i = 0; i < n-d-1; i++) {
        for(int j = 0; j < n-d-i-1; j++) {
            if (books[j].cost > books[j+1].cost) {
                Book b = books[j];
                books[j] = books[j+1];
                books[j+1] = b;
            }
        }
    }
    cout << "Book have been ordered by their cost increasingly..." << endl;
}

void show_all() {
    for(int i = 0; i < n-d; i++) {
        show_book(books[i]);
    }
}

void show_books_with(string catageroy) {
    int c = 0;
    for(int i = 0; i < n-d; i++) {
        if (books[i].category == catageroy) {
            if (c == 0) {
                cout << "+ Available books with this category:" << endl;
            }
            show_book(books[i]);
            c++;
        }
    }
    if (c == 0) {
        cout << "No books with this category exist." << endl;
    }
}

int main() {
    cout << "At the beggining enter " << n << " information according the books in this library." << endl;

    for(int i = 0; i < n; i++) {
        books[i] = getBook();
    }

    while(true) {
        string cmd;
        
        cout << "Now you can use the library functions: " << endl;
        cout << "/find <book_name>" << endl;
        cout << "\tSearch in the library and return the index of the book with specified name. (-1 if not exists)" << endl;
        cout << "/delete <book_name>" << endl;
        cout << "\tDelete a book from the library" << endl;
        cout << "/sort" << endl;
        cout << "\tSort books according to their costs" << endl;
        cout << "/category <category_name>" << endl;
        cout << "\tShow all books with the given category" << endl;
        cout << "/all" << endl;
        cout << "\tShow all books" << endl;
        cout << "/exit" << endl;
        cout << "\tExit from the program" << endl;

        cin >> cmd;

        if (cmd == "/find") {
            cin >> cmd;
            int r = findBook(cmd);
            if (r == -1) {
                cout << "Not found" << endl;
            } else {
                cout << "Book found at index: " << r << endl;
            }
        } else if (cmd == "/delete") {
            cin >> cmd;
            deleteBook(cmd);
        } else if (cmd == "/sort") {
            sort_books();
        } else if (cmd == "/category") {
            cin >> cmd;
            show_books_with(cmd);
        } else if (cmd == "/all") {
            show_all();
        } else if (cmd == "/exit") {
            break;
        } else {
            cout << "Unkown command." << endl;
        }

        cout << "Press any key to continue ..." << endl;
        getch();
    }
}