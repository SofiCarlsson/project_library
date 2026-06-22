// The library project
#include <iostream>
#include "header.h"
#include <sstream> 
#include <fstream>
using namespace std;
#include <vector>

void print_out_menu();

int main()
{
    Library my_library;

    // To read from the txt file
    ifstream in_file {"books.txt"};

    string line, title, author, borrowed;
    bool borrowed_bool;

    // If the txt file can not be opened, exit the program and return 1.
    if (!in_file)
    {
        cout << "The file books.txt could not be opened" << endl;
        return 1;
    }

    // Go through the txt file while there are lines (books) to read
    while (getline(in_file, line))
    {   
        // To store the values in a string stream called line_stringstream
        stringstream line_stringstream(line);

        // Split the line that holds all the information of one book at the "," and store it in the variables
         getline(line_stringstream, title, ',');
         getline(line_stringstream, author, ',');
         getline(line_stringstream, borrowed, ',');
         
         // Change the string variable "borrowed" to an bool in order to add it as an book object later
         if (borrowed == "1")
         {
            borrowed_bool = true;
         }
         else if (borrowed == "0")
         {
            borrowed_bool = false;
         }
         else
         {
            cout << "Wrong input for borrowed in the txt-file" << endl;
         }
         
         // Create a new book
         Book new_book(title, author, borrowed_bool);
         
         // Add the new book to the library
         my_library.add_book_to_library(new_book);
    }

    // Close for reading
    in_file.close();


    // The menu options
    bool want_to_exit = false;

    while (want_to_exit == false)
    {
        print_out_menu();
        int user_choice;
        cout << "Menu choice: ";
        cin >> user_choice;

        switch (user_choice)
        {
            // Add a new book
            case 1:
                my_library.add_new_book_to_library();
                break;

            // Borrow book
            case 2:
                my_library.borrow_book_library();

                break;

            // Return book
            case 3:
                my_library.return_book_library(); 
                break;

            // View available books
            case 4:
                cout << endl;
                cout << "The available books are: " << endl;
                my_library.display_available_books();
                break;

            // Exit the program and write all the books back to the file
            case 5:
                cout << "Goodbye and thank you for using the library!" << endl;
                want_to_exit = true;
                break;

            default:
                cout << "You have to choose a valid menu option (1-5)" << endl;
                break;
            }
    }

    // To write to the txt file
    ofstream out_file{"books.txt"};

    if (!out_file)
    {
        cout << "The file books.txt could not be opened" << endl;
        return 1;
    }

    if(out_file.is_open())
    {
        for(Book one_book : my_library.books_vector)
        {
            out_file << one_book.get_title() << "," << one_book.get_author() << "," << one_book.get_borrowed() << endl;
        }
    
    // Close for writing
    out_file.close();
    }

    return 0;
}
