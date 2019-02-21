/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 04 Assignment: 02
    Filename: lab05_02

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Stat calculator
    Purpose: The purpose of this program is to operate a stat calculator program to
    calculate the minimum,  maximum,  mean,  and population standard deviation values.
    This program is also able to replace a number and recalculate the stats.
-----------------------------------------------------------------
Program has been tested numerous times and the outputs are always correct.
*/



#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int get_input(double arr[], int arr_size);
//purpose: Obtain the user input
//inputs: What the user inputs
//outputs: The inputs are stored in the array
void out_stats(double arr[], int arr_size);
//purpose: Obtain the user input
//inputs: What the user inputs
//outputs: The inputs are stored in the array


int main(){
    //declare variables
    double store_num[20] = {0};
    int length =0;
    //obtain input
    length = get_input(store_num, 20);
    //output stats
    out_stats(store_num, length);

    return 0;
}
int get_input(double input[], int input_size){
    //define a variable
    int length =0;
    //obtain user input
        for (int i = 0; i < input_size; i++){
            string user_input = "";
            cout << "\nPlease enter a number to be stored in space " << i+1 << "(type done or d when finished): " << "\n";
            cin >> user_input;
            if (user_input == "done" || user_input == "d")
                break;
            //store the input in the array
            else{
                input[i] = stod(user_input);
                length++;
            }
        }
        return length;
}
void out_stats(double arr[], int length){
   //declare variables
    double sum =0, maxi = arr[0], mini = arr[0], mean = 0, standard_dev = 0, sum_all =0, replacement = 0;
    int index =0;
    string index_num = "";

    do{
        for (int i = 0; i< length ; i++){
            //calculate the stats
            sum += arr[i];

            (maxi>arr[i]? maxi=maxi : maxi = arr[i]);
            (mini<arr[i]? mini=mini : mini = arr[i]);
            cout << "\n"  << arr[i];
            }
        mean = sum / length;

        for (int i =0; i<length ; i++){
            sum_all += (pow((arr[i] - mean) , 2) );
            }

        standard_dev = pow ((sum_all/length), 0.5);
            //output the stats
        cout << "\nThe statistics are: ";
        cout << "\n\nThe sum is: " << sum;
        cout << "\nThe maximum is: " << maxi;
        cout << "\nThe minimum is: " << mini;
        cout << "\nThe mean is: " << mean;
        cout << "\nThe standard deviation is: " << standard_dev << endl;


        cout << "  Index | Value  ";
        cout << "\n--------|--------\n";

        for (int i =0; i<length ; i++){
            cout << "  " << setw(2) <<i << "    |  " << setw(2) <<arr[i] << endl;
            }
        cout << "Which index would you like to replace? (enter q or quit to exit) ";
        cin >> index_num;
         if (index_num =="quit" || index_num == "q")
            return ;

        index = stoi(index_num);
        while (index<0 || index >= length){
            cout << "Invalid index. Try again: ";
            cin >> index;
            }
        cout << "\nWhat would you like to replace it with? ";
        cin >> replacement;

        arr[index] = replacement;
        sum =0, maxi = arr[0], mini = arr[0], mean = 0, standard_dev = 0, sum_all =0;
        }while(true);

}
