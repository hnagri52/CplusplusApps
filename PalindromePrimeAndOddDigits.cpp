/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 03 Assignment: 01
    Filename: lab03_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Prime Number Calculator
    Purpose: The purpose of this program is to output all of the prime numbers from 2-100000. If the prime numbers are less than 10,000
             it will also depict whether it is a palindromic prime number or not. Finally, if it is less than 100, 000, it will calculate
             whether the sum of all of its digits is odd.
    Due Date:  Friday, September 28, 2018

-----------------------------------------------------------------


    Range of integer values that work for the code:
        0-100,000


    Test value: 5
    Result: 2 is a palindromic prime number
            3 is a palindromic prime number
            5 is a palindromic prime number 19-20 seconds: 191.230

    Test value: 3
    Result: 2 is a palindromic prime number
            3 is a palindromic prime number

    Test value: 11
    Result: 2 is a palindromic prime number
            3 is a palindromic prime number
            5 is a palindromic prime number
            7 is a palindromic prime number
            11 is a prime number. It is also a palindromic prime number.
*/

#include <iostream>

using namespace std;

int main (){
    //defining the variable
    int num, ans, counter=0, d1, d2, d3, d4, d5;

    //asking user for their input
    cout << "Please enter a number you want to check for prime: \n";
    cin >> num;

    //to make sure the user does not enter a number lower than or equal to 1
    while (num<=1){
        cout << "Please re-enter as this is not a valid entry: \n";
         cin >> num;
    }
    //to check whether if the number is a prime number or not
    for (int x=2; x<=num; x++){

            for (int i=2; i<x; i++){
                if (x%i !=0)
                    counter=0;
                else
                    counter++;
            }
    //if its a prime number, output it
     if (counter == 0){
            //if the number has 5 digits, obtain each digit
             if (x > 9999 && x < 100000){
                d1 = x / 10000;
                d2 = (x / 1000) % 10;
                d3 = (x / 100) % 10;
                d4 = (x / 10) % 10;
                d5 =  x % 10;

                cout << endl << x <<" is a prime number.";
                //checks to see if digits added up is odd
                if ((d1+d2+d3+d4+d5)%2!=0)
                    cout << " The sum of its digits is odd.";
             }
             //if the number has 4 digits
            if (x > 999 && x < 10000){
                d1 = x / 1000;
                d2 = (x / 100) % 10;
                d3 = (x / 10) % 10;
                d4 = (x % 10);

                cout << endl << x <<" is a prime number.";
                //checks to see if digits added up is odd
                if ((d1+d2+d3+d4)%2!=0)
                    cout << " The sum of its digits is odd.";
            }
            //when the number has three digits
            if (x > 99 && x < 1000){
                d1 = x / 100;
                d2 = (x / 10) % 10;
                d3 = (x % 10);

                cout << endl << x <<" is a prime number.";
                //check if it is palindromic
                if (d1==d3){
                    cout << " It is also a palindromic prime number.";
                }
                //checks to see if digits added up is odd
                if ((d1+d2+d3)%2!=0){
                    cout << " The sum of its digits is odd.";
                }
            }
            //for 2 digits numbers
            if (x > 9 && x < 100){
                d1 = x / 10;
                d2 = (x % 10);

                cout << endl << x <<" is a prime number.";
                //determine if it is palindromic
                if (d1==d2){
                    cout << " It is also a palindromic prime number.";
                }
                //checks to see if digits added up is odd
                if ((d1+d2)%2!=0){
                    cout  << " The sum of its digits is odd.";
                }
            }
            //if it is a single digit, it is automatically a palindromic prime number
            if (x < 10){
                cout << endl << x << " is a palindromic prime number";
            }

     }
     //reset the variables
     counter = 0;
     d1 = 0;
     d2 = 0;
     d3 = 0;
     d4 = 0;
     d5 = 0;
    }
    //terminate
    return 0;
    }
