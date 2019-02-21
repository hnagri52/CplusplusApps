/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 06 Assignment: 01
    Filename: lab07_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Substring checker
    Purpose: The purpose of this program is to obtain input from the user of a string and a substring, and see if the substring is within the big string.
    Due Date:  Wednesday, November 14, 2018

-----------------------------------------------------------------
-Program has been tested numerous times and the outputs are always correct.
-I like java:
    The small string that you wanted to check is inside the large string.

*/




#include<iostream>
using namespace std;

bool check_if_contains(string target, string substr);
//purpose: will check if there is an occurance of the little string in the big string
//input: obtains the big string and the substring to be checked
//output: true or false based on if the substring is contained in the big string

string remove_letter(string target);
//purpose: will remove the first element, and shift the indexes of the elements down by 1 each time
//input: the target is the big string that the user enters
//output: it will return a string with the first element removed

bool check_strings(string target, string substr);
//purpose: compares both strings to see if there is an occurance of the little string in the big string
//input: obtains the input for the long string, and the substring input
//output: returns true or false based on if the substring matches the big string


int main(){
    //derfine variables
    string large_string, small_string;
    //obtain user input
    cout << "Please enter the large string: ";
    getline(cin, large_string);
    cout << "Please enter the small string: ";
    getline (cin, small_string);

    //depending on if the substring is within the big string, it will print out the appropriate message
    if (check_if_contains(large_string, small_string)){
        cout << "The small string that you wanted to check is inside the large string. ";
    }else{
        cout << "The small string that you entered is not inside the large string. ";
    }
    return 0;
}

bool check_if_contains(string target, string substr){
    if (target[0] == '\0') // if after all the letters have either been removed, if the remaining are \0 then it is not true
        return false;
    else if (check_strings(target, substr)) // it calls the other function and checks to see if the substring is within the big string
        return true;
    else //removes a letter if it does not match with the substring, and calls the function over again
        return check_if_contains(remove_letter(target), substr);
}

string remove_letter(string target){
    //t will change the index's of the elements accordingly
    for (int index = 0; index < target.size() - 1 ; index++){
        target[index] = target [index + 1];
    }
    //make sure that the last element is still a null
    target[target.size() - 1] = '\0';
    return target;
}
bool check_strings(string target, string substr){
    //checks to see if there is a difference between the string and substring, and will exit if there is
    for (int index = 0; index < substr.size(); index++){
        if (target[index] != substr [index])
            return false;
    }
    //if there are no
    return true;
}
