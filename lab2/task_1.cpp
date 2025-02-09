#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string bookTitle;
    string authorName;
    int publicationYear;
} Book;

void getBookData(Book books[], int n);
void displayBooksPublishedAfterYear(Book books[], int n);

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    Book bookData[numBooks]; 
    getBookData(bookData, numBooks);
    displayBooksPublishedAfterYear(bookData, numBooks);

    return 0;
}

void getBookData(Book books[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter title for book " << i + 1 << ": ";
        cin >> books[i].bookTitle;
        cout << "Enter author name of book " << i + 1 << ": ";
        cin >> books[i].authorName;
        cout << "Enter published year of book " << i + 1 << ": ";
        cin >> books[i].publicationYear;
    }
}

void displayBooksPublishedAfterYear(Book books[], int n) {
    int targetYear;
    cout << "Enter the specific year: ";
    cin >> targetYear;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (targetYear < books[i].publicationYear) {
            found = true;
            cout << "The Book " << i + 1 << " with title " << books[i].bookTitle 
                 << " wrote by " << books[i].authorName 
                 << " and published in year: " << books[i].publicationYear << endl;
        }
    }
    if (!found) {
        cout << "None of the books are published after " << targetYear << "!" << endl;
    }
}