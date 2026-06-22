// Functions
#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

// Print the menu
void print_out_menu()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                          SOFI'S LIBRARY" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "Choose an option by pressing 1, 2, 3, 4 or 5" << endl;

    cout << "1: Add a new book"<< endl;
    cout << "2: Borrow book"<< endl;
    cout << "3: Return book"<< endl;
    cout << "4: View available books"<< endl;
    cout << "5: Exit the program"<< endl;
}

// Functions for Book class
// Constructor
Book::Book(string input_title, string input_author, bool input_borrowed)
        {
            title = input_title;
            author = input_author;
            borrowed = input_borrowed;
        }

//Getters Book
string Book::get_title() const {return title;}
string Book::get_author() const {return author;}
bool Book::get_borrowed() const {return borrowed;}

// Setter for Book borrowed
void Book::set_borrowed(bool input_borrowed)
{
    borrowed = input_borrowed;
}

void Book::display_book() const
{
    cout << "Title: " << get_title() << endl;
    cout << "Author: " << get_author() << endl;
    cout << "Borrowed: " << boolalpha << get_borrowed() << endl; 
    cout << "______________________________________________________________________"<< endl;
}

// For borrowing a book
// Should take a book object and only if it is not already borrowed
void Book::borrow_book()
        {
            if (get_borrowed() == false)
            {
                set_borrowed(true);
                cout << "The book is now borrowed" << endl;
            }
            else
            {
                cout << "The book is not availble" << endl;
            }
        }

// For returning a book
void Book::return_book()
{
    {
        if (get_borrowed() == true)
        {
            set_borrowed(false);
            cout << "The book is returned" << endl;
        }
        else
        {
            cout << "The book is already returned" << endl;
        }
    }
}

// Functions for the Library class 

// Create and add a new book to the library by asking for a title and a author
void Library::add_new_book_to_library()
{
    string new_name;
    string new_author;
    cout << "Add a new book by entering the name of the book first, then the author's name." << endl;
    
    cout << "Name: ";
    cin.ignore(10000, '\n');
    getline(cin, new_name);
    cout << "Author: ";
    getline(cin, new_author);

    Book new_book(new_name, new_author);
    books_vector.push_back(new_book);
}

// Adds an already created book to the library
void Library::add_book_to_library(Book input_book)
{
    books_vector.push_back(input_book);
}

// Borrow a book by inputing the title
void Library:: borrow_book_library()
{
    string input_title;
    cout << "Input the title of the book you want to borrow: ";
    cin.ignore(10000, '\n');
    getline(cin, input_title);

    // If the book is not borrowed then borrow it
    // Iterate by reference
    for (Book &book: books_vector)
    {
        // The book exists
        if (book.get_title() == input_title)
        {
            // Look if it is avalible
            if (book.get_borrowed() == false)
            {
                book.borrow_book();
            }
            else
            {
                cout << "The book is not avalible" << endl;
                break;
            }
        }  
    } 
}

// Return book
void Library::return_book_library()
{
    string input_title;
    cout << "Input the title of the book you want to return: ";
    cin.ignore(10000, '\n');
    getline(cin, input_title);

    // If the book is not already returned, then return the book.
    for (Book &book: books_vector)
    {
        // The book exists
        if (book.get_title() == input_title)
        {
            // Look if it is borrowed
            if (book.get_borrowed() == true)
            {
                book.return_book();
            }
            else
            {
                cout << "The book is already returned" << endl;
            }
            break;
        }  
    } 
}

// Display available books
void Library::display_available_books()
{
    for(Book book: books_vector)
    {
        if (book.get_borrowed() == false)
        {
            book.display_book();
        }  
    }
}


