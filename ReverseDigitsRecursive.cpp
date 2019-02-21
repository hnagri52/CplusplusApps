#include <iostream>

using namespace std;


void reverse_digits (int value);
//purpose: reverses and prints the digits of the inputted value
// Inputs: value - the input that needs to be reversed
//Outputs: returns nothing

int main (){


    reverse_digits (143);



    return 0;
}

void reverse_digits ( int value){

    if (value <10){
        cout << value;
    }
    else {

        cout << value % 10;
        reverse_digits (value / 10);


    }

}
