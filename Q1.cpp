#include <iostream>
using namespace std;

class Book{
public:
    string title;
    string author;
    int publishedYear;
};

int main(){
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];

    for (int i = 0; i < n; i++){
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << endl;
        cout << "\nEnter details for Book " << i + 1 << ":\n";

        cout << "Title: ";
        cin >> books[i].title;

        cout << "Author: ";
        cin >> books[i].author;

        cout << "Published Year: ";
        cin >> books[i].publishedYear;
    }

    cout << "\n--- Book Details ---\n";

    for (int i = 0; i < n; i++){
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << endl;
        cout << "\nBook " << i + 1 << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Published Year: " << books[i].publishedYear << endl;
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << endl;
    }
    return 0;
}