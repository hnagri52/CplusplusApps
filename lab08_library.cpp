#include <iostream>
#include <vector>
#include "lab08_library.hpp"
#include "lab08_book.hpp"

using namespace std;
// CONSTRUCTORS
    vector<Book> books;
	// PURPOSE: default/empty constructor
	Library::Library() {}
	// PURPOSE: parametric constructor that takes a new vector instance as input
	Library::Library (vector<Book> new_books) {
	    books = new_books;
	}

	// SERVICE METHODS

	// PURPOSE: prints information for all the books currently stored in the library
	void Library::print() {
	    for(int number=0; number<books.size(); number++) {
            books[number].print();
	    }
	}

	// PURPOSE: inserts a new book into the library
	// INPUTS: new_title, new_authors, new_dop- values for the object that is to be inserted
	// RETURNS: true, if the insertion was succesful; false, otherwise
	bool Library::insert_book(string new_title, string new_authors, string new_dop) {
	    int size_of_book = books.size();
	    for (int number=0; number<=size_of_book; number++) {
            if (size_of_book==0) {
                books.push_back(Book(new_title, new_authors, new_dop));
                cout << "The book insertion is completed successfully. \n";
                return true;
            }
	        else if (number==size_of_book - 1 && books[number].get_title()!= new_title && books[number].get_authors()!=new_authors && books[number].get_dop()!=new_dop) {
                books.push_back(Book(new_title, new_authors, new_dop));
                cout << "The book insertion is completed successfully. \n";
                return true;
	        }
	        else if (books[number].get_title() != new_title && books[number].get_authors() != new_authors && books[number].get_dop()!= new_dop){}
	        else {
                cout << "The book insertion failed because the book already exists within the library. \n";
                return false;
	        }
	    }
	}
	// PURPOSE: inserts a new book into the library
	// INPUTS: new_book - values for the object that is to be inserted
	// RETURNS: true, if the insertion was succesful; false, otherwise
	bool Library::insert_book(Book new_book) {
        int size_of_book = books.size();
        for (int number=0; number<=size_of_book; number++) {
            if (size_of_book==0) {
                books.push_back(new_book);
                cout << "The book insertion is completed successfully. \n";
                return true;
            }
	        else if (number==size_of_book-1 || books[number].get_title()!=new_book.get_title() || books[number].get_authors()!=new_book.get_authors() || books[number].get_dop()!=new_book.get_dop()) {
                books.push_back(new_book);
                cout << "The book insertion is completed successfully. \n";
                return true;
	        }
	        else if (books[number].get_title() != new_book.get_title() && books[number].get_authors() != new_book.get_authors() && books[number].get_dop()!= new_book.get_dop()){}
	        else {
                cout << "The book insertion failed because the book already exists within the library. \n";
                return false;
	        }
	    }
	}
	// PURPOSE: removes a selected book from the library
	// INPUTS: cur_title, cur_authors, cur_dop - values for the object that is to be removed
	// RETURNS: true, if the removal was succesful; false, otherwise
	bool Library::remove_book(string cur_title, string cur_authors, string cur_dop) {
	    for (int number = 0; number <books.size(); number++){
            if (books[number].get_title() == cur_title && books[number].get_authors() == cur_authors && books[number].get_dop() == cur_dop){
                books.erase(books.begin() + number);
                cout << "The book has been erased from the library. \n";
                return true;
            }
            else if (number == books.size() - 1){
                cout << "The book removal failed because the book could not be found. \n";
                return false;
            }
            else{}
	    }
	    return true;
	}
	// PURPOSE: removes a selected book from the library
	// INPUTS: cur_book - values for the object that is to be removed
	// RETURNS: true, if the removal was succesful; false, otherwise
	bool Library::remove_book(Book cur_book) {
	    for (int number = 0; number < books.size(); number++){
            if ( books[number].get_title() == cur_book.get_title() && books[number].get_authors() == cur_book.get_authors() && books[number].get_dop() == cur_book.get_dop()){
                books.erase(books.begin() + number);
                cout << "The book has been erased from the library. \n";
                return true;
            }
            else if ( number == books.size() - 1){
                cout << "The book removal failed because the book does not exist. \n";
                return false;
            }
            else{}
	    }
	    return true;
	}
    // Purpose: Determines the size of the vector
    // Inputs: no inputs
    // Returns: the size of the vector
	int Library::size_of_vector(){
        return books.size();
    }
    // Purpose: determine the number at the index of the vector
    // Input: the index number
    // Returns: the value at the index of the vector
	Book Library::index_of_book(int index){
        return books[index];
	}
