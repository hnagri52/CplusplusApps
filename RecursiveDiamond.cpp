/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 06 Assignment: 01
    Filename: lab07_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Diamond Star pattern
    Purpose: The purpose of this program is to obtain input from the user, and print out the correct diamond pattern accordingly.
    Due Date:  Wednesday, November 14, 2018

-----------------------------------------------------------------
-Program has been tested numerous times and the outputs are always correct.
ex:

input  = 5,
     *
    * *
   * * *
  * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
*/

#include <iostream>
using namespace std;


//define functions
void printer_upperhalf (int value, int row);
void printer_lowerhalf (int value, int row);


int main(){
    //define variables
    int user_input;
    const int row_start = 1;
    //receive user input for the amount of rows
    cout << "Please enter the amount of rows you would like: " ;
    cin >> user_input;
    //call functions
    printer_upperhalf (user_input, row_start);
    printer_lowerhalf(user_input, row_start);

    return 0;
}

void printer_upperhalf (int value, int row){
    //declare variable to count the amount of spaces
    int space = value - 1;
    //if the user enters 0, return nothing
    if (value == 0)
        return;
    //recursive case
    else{
    //print the number of spaces
            for (int j = 1; j<=space+1; j++)
                cout<<" ";
    //print out the amount of stars and spaces accordingly
            for (int k = 1; k<= row; k++)
                cout<<"*" << " " ;
    //print out the leftover spaces
            for (int j = 1; j<=space-1; j++)
                cout<<" ";
    //enter a new line
            cout<<"\n";


    //recursive function call
        printer_upperhalf (value-1, ++row);

    }


}


void printer_lowerhalf (int value, int row){
    //declar variable
    int space = row +1;
    //if value is 0, return nothing
    if (value == 0)
        return;
    //recursive case
    else{
        //print out the amount of spaces
        for (int i = 1; i< space+1; i++)
            cout<<" ";
        //print out the stars accordingly
        for (int k = 1 ; k< value; k++)
            cout<<"*" << " " ;
        //print out the spaces after acordingly
        for (int i = 1; i<= space-1; i++)
            cout<<" ";

        cout<<"\n";

        //recursive function call
        printer_lowerhalf (value-1, ++row);
    }

}
