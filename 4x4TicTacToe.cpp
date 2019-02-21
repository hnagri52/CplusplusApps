/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 04 Assignment: 01
    Filename: lab05_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Tic-Tac-Toe game
    Purpose: The purpose of this program is to operate a 4x4 Tic-Tax-Toe game.
    Due Date:  Friday, October 26, 2018

-----------------------------------------------------------------
Program has been tested numerous times and the outputs are always correct.
*/



#include <iostream>

using namespace std;

void change_x(int& user_input, char my_array[][4], int array_size);
//purpose: Change the user value to X
//inputs: what number the user wants to change
//outputs: replaces the value with an X
void change_o(int& user_input, char my_array[][4], int array_size);
//purpose: Change the user value to O
//inputs: what number the user wants to change
//outputs: replaces the value with an O
void print_table(char my_array[][4], int array_size);
//purpose: print the table for the user
//inputs: the array
//outputs: the 4x4 table
bool check_for_win(char my_array[][4], int array_size, int& counter_x, int& counter_o);
//purpose: to check if a player has won
//inputs: the array values
//outputs: checks if the win conditions are true
void stats (int& x, int& o, int& x_counter , int& o_counter);
//purpose: display the winner
//inputs: the counter to see if the condition is met
//outputs: the winner of the game
void final_stats (int x_counter, int o_counter);
//purpose: display the overall winner
//inputs: the win counters
//outputs: the overall winner of all of the games


int main(){
    //define variables
    char gameboard[4][4] = {{1,2,3,4} ,{5, 6, 7, 8}, {9, 10, 11, 12},  {13, 14, 15, 16}};
    int p_x, p_o, x_win = 0, o_win = 0, x_count = 0, o_count = 0, play_again =0, game_number = 0;
    bool game_checker = false, whose_turn = false;
    //print the table
    print_table(gameboard, 4);

    cout << "Hello! Would you like to play? (1 for yes, 0 for no) ";
    cin >> play_again;
    //keep running the game until the people want to stop
    while (play_again == 1){
            char gameboard[4][4] = {{1,2,3,4} ,{5, 6, 7, 8}, {9, 10, 11, 12},  {13, 14, 15, 16}};
            //determine which player goes first
            if (game_number % 2 == 0)
                whose_turn = false;
            else if (game_number % 2 != 0)
                whose_turn = true;

            //keep running until there is a tie or a winner in the game
            while (game_checker == false){

                //X goes first
                if (whose_turn == false){
                    //asks user which number to replace
                    cout << "Player X: enter which number you would like to place an x over: " ;
                    cin >> p_x;
                    cout << "\n\n";
                    //changes it, and prints the table again
                    change_x(p_x, gameboard, 4);
                    print_table(gameboard, 4);
                    cout << "\n\n";
                    //checks for a winner
                    if (check_for_win(gameboard, 4, x_win, o_win) == true){
                        game_checker = true;
                        break;}
                    whose_turn = true;
                    }
                //O goes first
                if (whose_turn == true){
                    cout << "Player O: enter which number you would like to place an o over:" ;
                    cin >> p_o;
                    cout << "\n\n";

                    change_o(p_o, gameboard, 4);
                    print_table(gameboard, 4);
                    cout << "\n\n";
                    if (check_for_win(gameboard, 4, x_win, o_win) == true){
                        game_checker = true;
                        break;}
                    whose_turn = false;
                    }
                }
                //prints out the stats of the game
                stats(x_win, o_win, x_count, o_count);

                cout << "Would you like to play again? (1 for yes, 0 for no) ";
                cin >> play_again;
                game_checker = false;
                game_number++;
                x_win =0;
                o_win = 0;
                }
            //prints out the overall stats
            final_stats(x_count, o_count);
    return 0;
}

void print_table(char my_array[][4], int array_size){

    for (int i = 0; i<4 ; i++){
        for (int j = 0; j<4 ; j++){
            //prints out the X's appropriately
            if (my_array[i][j] == 'X'){
                cout << my_array[i][j] << "\t";
            }
            //prints out the O's appropriately
            else if (my_array[i][j] == 'O')
                cout << my_array[i][j] << "\t";
            //prints out the numbers
            else
                cout << static_cast<int>(my_array[i][j]) << "\t";
            }
        cout << endl;
        }
}
void change_x(int& user_input, char my_array[][4], int array_size){
      int row = (user_input - 1) / 4;
      int coloum = (user_input - 1) % 4;

     while ((my_array[row][coloum] == 'X') || (my_array[row][coloum] == 'O') ||(user_input < 1) || (user_input >16) ){
        cout << "Please enter a valid input player X:\n\n";
        cin >> user_input;
        row = (user_input - 1) / 4;
        coloum = (user_input - 1) % 4;
       }

       my_array[row][coloum] = 'X';

}
void change_o(int& user_input, char my_array[][4], int array_size){
      int row = (user_input - 1) / 4;
      int coloum = (user_input - 1) % 4;
        //checks for valid input
     while ((my_array[row][coloum] == 'X') || (my_array[row][coloum] == 'O')){
        cout << "Please enter a valid input player O:\n\n";
        cin >> user_input;
        row = (user_input - 1) / 4;
        coloum = (user_input - 1) % 4;
       }
        //changes the value
       my_array[row][coloum] = 'O';
}
bool check_for_win(char my_array[][4], int array_size, int& counter_x, int& counter_o){
    //checks the rows
    for (int i = 0; i < array_size; i++){
        for (int j = 0; j < 4; j++){
            if (my_array[i][j] == 'X')
                counter_x++;
            else if (my_array[i][j] == 'O')
                counter_o++;
    }
    if ((counter_x == 4) || (counter_o ==4))
        return true;
    else{
        counter_x = 0;
        counter_o = 0;
        }
    }
    //checks the column
    for (int i = 0; i < array_size; i++){
        for (int j = 0; j < 4; j++){
            if (my_array[j][i] == 'X')
                counter_x++;
            else if (my_array[j][i] == 'O')
                counter_o++;
        }
        if ((counter_x == 4) || (counter_o ==4))
            return true;
        else{
            counter_x = 0;
            counter_o = 0;
        }
    }
    //checks diagonals
    if((my_array[0][0] == 'X') && (my_array[1][1] == 'X') && (my_array[2][2] == 'X') && (my_array[3][3] == 'X')){
        counter_x = 4;
        return true;}
    else if((my_array[0][0] == 'O') && (my_array[1][1] == 'O') && (my_array[2][2] == 'O') && (my_array[3][3] == 'O')){
        counter_o = 4;
        return true;}
    else
        return false;
    }
void stats (int& x, int& o, int& x_counter , int& o_counter){

    //prints out the according stats
    if (x==4){
        cout << "Player X has won the game! ";
        x_counter++;}
    else if (o==4){
        cout << "Player O has won the game! ";
        o_counter++;}
    else
        cout << "Tie game! Try again to see who is the better player! ";
}
void final_stats (int x_counter, int o_counter){
    //prints out the stats once the players are finished playing
    cout << "Congratulations! The game has now ended!! \n"
         << "Player X has won " << x_counter << " times!\n"
         << "Player O has won " << o_counter << " times!\n";
    if (x_counter>o_counter)
        cout << "Player X has won more than player O";
    else if (x_counter< o_counter)
        cout << "Player O has won more than player X";
    else
        cout << "You guys both won the game " << x_counter << " times! Good job!";
}
