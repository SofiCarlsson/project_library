// Header file
#include <string>
#include <vector>

#ifndef HEADER_H
#define HEADER_H

// Class Book
class Book
{
    private: 
        std::string title;
        std::string author;
        bool borrowed;
    
    public:

        // Constructor for creating a new book
        Book(std::string input_title, std::string input_author, bool input_borrowed = false);
        
        // Getter
        std::string get_title() const;
        std::string get_author() const;
        bool get_borrowed() const;

        // Setter
        void set_borrowed(bool input_borrowed);

        // Functions Book
        void display_book() const;

        // Do not pass a parameter
        void borrow_book();
        void return_book();

}; 
class Library
{
    public:
        std::vector<Book> books_vector;

    // Functions Library
    void add_new_book_to_library();

    void add_book_to_library(Book input_book);
    
    void display_available_books();

    void borrow_book_library(); 
    
    void return_book_library(); 
    
}; 

#endif