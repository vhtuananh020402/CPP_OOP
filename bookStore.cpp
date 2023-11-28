#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Book {
    private:
        int bookId;
        string title;
        string author;
        double price;


    public:
        Book() {
            this->bookId    = 0;
            this->title     = "N/A";
            this->author    = "N/A";
            this->price     = 0.0;
        }

        Book(int bookId, const string &title, const string &author, double price) {
            this->bookId = bookId;
            this->title     = title;
            this->author    = author;
            this->price     = price;
        }

        const string getTitle() {
            return this->title;
        }
};


class Bookstore {
    
};



int main() {
    Book *book1 = new Book();
    cout << book1->getTitle() << endl;    

    delete book1;
    return 0;
}