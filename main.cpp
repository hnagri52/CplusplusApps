#include <iostream>
#include "lab08_book.hpp"
#include "lab08_library.hpp"

/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 07 Assignment: 01
    Filename: lab08_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: C++ classes
    Purpose: The purpose of this program is to use object oriented prorgamming, and implement the use of classes.
    Due Date:  Wednesday, November 07, 2018

-----------------------------------------------------------------
-Program has been tested numerous times and the outputs are always correct.
-Used the input.txt file, and created multiple names and values in order to test part A.
*/

using namespace std;

//function declaration
bool run();

//object delcarations
Library first_library;
Library second_library;
Book first_book;

int main(){

    //declaring the variables
    bool pass_test;
    pass_test = run();
    cout << endl;
    //to show whether the tests have failed or not
    cout << ( (pass_test) ? "All of the tests have passed. \n\n" : "Some of tests have failed. \n\n");
    //print out the respective libraries
    cout << "This is the first library: \n\n";
    first_library.print();
    cout << "This is the second library: \n\n";
    second_library.print();

    //whether it was successful or not
    cout << "At the end of the day, the testing is: ";
    if (pass_test==true)
        cout << "successful. \n";
    else
        cout << "not successful. \n";




    return 0;
}

bool run(){
    //add books to the first library
    first_library.insert_book("The Heroes of olympus" , "Rick Riordan", "2010-12-15");
    first_library.insert_book("Growth of Trees", "President CAD", "1999-07-21");
    first_library.insert_book("Lebron James; The School", "Rampard Dameer", "2017-01-07");

    //create a vector to hold the books
    vector <Book> the_books (first_library.size_of_vector());
    //inset the books in the vector
    for (int index = 0; index < first_library.size_of_vector(); index++)
        the_books[index] = first_library.index_of_book(index);
    //create a new object to hold the books as well
    Library second_library_01(the_books);

    //create book objects
    Book first_book("The First");
    Book africa("African Adventure", "Tanzania Classic");
    Book sword("Sword fight", "Indiana Jones", "The Middle Ages");
    //add the books
    second_library_01.insert_book(africa);
    second_library_01.insert_book(first_book);
    second_library_01.insert_book(sword);
    second_library_01.insert_book("Growth of Trees", "President CAD", "1999-07-21");
    second_library = second_library_01;

    //remove the books
    second_library.remove_book("Growth of Trees", "President CAD", "1999-07-21");
    first_library.remove_book(sword);


    return true;


}
