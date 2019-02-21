/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 04 Assignment: 01
    Filename: lab04_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Soccer Game Commentary
    Purpose: The purpose of this program is to output the commentary of a soccer game.
    Due Date:  Monday, October 15, 2018

-----------------------------------------------------------------


Program has been tested numerous times and stats have been correct. */

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <string.h>
#include <iomanip>
#include <windows.h>

using namespace std;


int event_amount();
//purpose: generate the amount of events from 1-15
//input: no input
//output: random number from 1-15

int type_of_event();
//purpose: generate the type of event
//input: no input
//output: random number from 1-6


bool obj_1(int type, int& goals_A, int& target_a, int& offtarget_a, int& blocked_a);
//purpose: display and update gameplay
//input: a random number from 1-4 or 1-3 based on the scenario
//output: commentary in regards to the type of event occuring
bool foul(int& fouls, int& yellow, int& red);
//purpose: display and update foul outcomes
//input: random number from 0-2
//output: commentary in regards to the foul outcome
bool stats (int& goals_A,int& goals_B,int& target_a,int& target_b,int& offtarget_a,int& offtarget_b,int& blocked_a,int& blocked_b,int& red_a,int& red_b,int& yellow_a,int& yellow_b,int& fouls_a,int& fouls_b);
//purpose: display the game statistics
//input: the variables needed to be output
//output: game statistics for each team

bool game_half(int& halfcounter, int& goals_A, int& goals_B);
//purpose: display which team won (if needed) and what half it is
//input: a counter to tell what half it is
//output: the winning team (if needed), and whether it is the first or second half

int main(){
    //declaring variables
    srand(time(NULL)); //obtains a random number completely
    int event_specific, counter = 0, goals_A = 0, goals_B = 0, fouls_a =0, fouls_b = 0, yellow_a = 0, yellow_b = 0, red_a = 0, red_b = 0;
    int target_a = 0, target_b = 0, offtarget_a = 0, offtarget_b = 0, blocked_a = 0, blocked_b = 0, halfcounter=0;
    //obtain the amount of events
    int event = event_amount();
    //to run the code 2 times (each half)
    while (halfcounter<=1){
    //runs until the number of events are completed
        while (counter < event){
            //generates a number from 1-6 to determine the event type
            int event_type = type_of_event();
            //calls the appropriate functions based on the generated number
            if (event_type == 1){
                cout << "\nBarcelona: ";
                obj_1(1, goals_A, target_a, offtarget_a, blocked_a);
            }
            else if (event_type == 2){
                cout << "\nManchester United: ";
                obj_1(1, goals_B, target_b, offtarget_b, blocked_b);
            }
            else if (event_type == 3){
                cout << "\nManchester United has commited a foul, Barcelona is shooting a free kick: ";
                obj_1(1, goals_A, target_a, offtarget_a, blocked_a);
                foul(fouls_b, yellow_b, red_b);
            }
            else if (event_type == 4){
                cout << "\nBarcelona has commited a foul, Manchester United is shooting a free kick: ";
                obj_1(1, goals_B, target_b, offtarget_b, blocked_b);
                foul(fouls_a, yellow_a, red_a);
            }
            else if (event_type == 5){
                cout << "\nManchester United has commited a foul close to the net which resulted in a penality. Barcelona: ";
                obj_1(2, goals_A, target_a, offtarget_a, blocked_a);
                foul(fouls_b, yellow_b, red_b);
            }
            else if (event_type == 6){
                 cout << "\nBarcelona has commited a foul close to the net which resulted in a penality. Manchester United: ";
                 obj_1(2, goals_B, target_b, offtarget_b, blocked_b);
                 foul(fouls_a, yellow_a, red_a);
            }
            //increases the counter so that the loope will end
            counter++;
            Sleep(1000);
        }
        //prints out the stats
        game_half(halfcounter, goals_A, goals_B);
        stats (goals_A, goals_B, target_a, target_b, offtarget_a, offtarget_b, blocked_a, blocked_b, red_a, red_b, yellow_a, yellow_b, fouls_a, fouls_b);
        //generates a random number of events again, increases the halfcounter, and resets the main counter
        event = event_amount();
        halfcounter++;
        counter = 0;
    }
    //terminate the function
    return 0;
}


int event_amount(){
    int events = rand()%15 + 1;//generate random number from 1-15
    return events;
}
int type_of_event(){
    int events = rand()%6 + 1; //generate random number from 1-6
    return events;
}

bool obj_1(int type, int& goals, int& target, int& offtarget, int& blocked){
         int event_specific = 0;
          //either obtains a random number form 1-4 or 1-3 depending on the situation
          if (type == 1)
            event_specific = rand()%4;
          else
            event_specific = rand()%3;
            //outputs the appropriate text based on the event, and updates the variable counter
            if (event_specific == 0){
                cout << "Has scored a goal. What a goal!";
                goals++;}
            else if (event_specific == 1){
                cout << "Made a shot on goal. The goalie/last defender made an amazing save!";
                target++;}
            else if  (event_specific == 2){
                cout << "Made shot off goal. Horrible Aim!";
                offtarget++;}
            else{
                cout << "Shot blocked by person who is not the last defender. Great defence!";
                blocked++;
        }
        return true;
    }

bool foul(int& fouls, int& yellow, int& red){
    int foul_type = rand()%3;
        //display appropriate text based on number generated
        if (foul_type == 0)
            cout << " It was a fair play. No card was given.";
        else if (foul_type == 1){
            cout << " That was rough. Yellow Card was given.";
            yellow++;}
        else{
            cout << " That was unfair and too rough. Red card was given.";
            red++;}
        fouls++;
     return true;
}

bool stats (int& goals_A,int& goals_B,int& target_a,int& target_b,int& offtarget_a,int& offtarget_b,int& blocked_a,int& blocked_b,int& red_a,int& red_b,int& yellow_a,int& yellow_b,int& fouls_a,int& fouls_b){

        //displays statics
        cout << "\nScore: " << goals_A << ":" << goals_B << "\n\n";
        cout << setw(30) << "Barcelona" << setw(30) << "Manchester United\n" << endl;
        cout << "Goals: \t\t" << setw(11) << goals_A << setw(30) << goals_B << endl;
        cout << "Shots on goal: \t" << setw(11) << target_a << setw(30) << target_b << endl;
        cout << "Shots off goal:\t" << setw(11) << offtarget_a << setw(30) << offtarget_b << endl;
        cout << "Shots blocked: \t" << setw(11) << blocked_a << setw(30) << blocked_b << endl;
        cout << "Fouls: \t\t" << setw(11) << fouls_a << setw(30) << fouls_b << endl;
        cout << "Yellow cards: \t" << setw(11) << yellow_a << setw(30) << yellow_a << endl;
        cout << "Red cards: \t" << setw(11) << red_a << setw(30) << red_a << endl << endl;
        cout << "\n-------------------------------------------------------------\n" << endl;

        return true;
}

bool game_half(int& halfcounter, int& goals_A, int& goals_B){
       //displays the appropriate text based on the outcome
        if (halfcounter==0) {
            cout << "\nHalf-Time Stats: \n\n";
        }
        else {
            cout << "\nEnd-Game Stats: \n\n";

            cout << "Result: ";
            if(goals_A>goals_B) {
                cout << "Barcelona wins!" << endl;
            }
            else if(goals_A<goals_B) {
                cout << "Manchester United wins!" << endl;
            }
            else {
                cout << "Tied" << endl;
            }
        }
        return true;
}
