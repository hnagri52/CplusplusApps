/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 03 Assignment: 03
    Filename: lab03_03

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Horoscope calculator
    Purpose: The purpose of this program is to receive input from the user (which enters their birth date), and
             the program will determine their horoscope, as well as give a description of its sign, its compatible
             elements, and its astrological element, as well as its description.

    Due Date:  Friday, September 28, 2018

-----------------------------------------------------------------


    Range of integer values that work for the code:
        Days: 1-31
        Months: 1-12

    Test value: day: 31 month:3
    Result: You are a Aries. One of your strengths is that you optimistic. You are compatible with Libra and Leo. The element associated is Fire which is the only element that shines

    Test value: day: 31 month:5
    Result: You are a Gemini. One of your strengths is that you are affectionate. You are compatible with Aquarius and Sagittarius. The element associated is Air, which is the element that connects all other elements

    Test value: day: 24 month:10
    Result: You are a Scorpio. One of your strengths is that you are brave. You are compatible with Taurus and Cancer. The element associated is Water, which is the element of constant movement.



*/



#include <iostream>
#include <string>

using namespace std;

int main() { //defining the main function
    //defining the variables
    int day, month;
    //defining the strings that contain all the sentences.
    string Aquar = "You are an Aquarius. One of your strengths is that you are independant. You are compatible with Leo and Sagittarius. The element associated is Air, which is the element that connects all other elements.";
    string Pis = "You are a Pisces. One of your strengths is that you are compassionate. You are compatible with Virgo and Taurus. The element associated is Water, which is the element of constant movement.";
    string Ar = "You are a Aries. One of your strengths is that you optimistic. You are compatible with Libra and Leo. The element associated is Fire which is the only element that shines";
    string Taur = "You are a Taurus. One of your strengths is that you are patient. You are compatible with Scorpio and Cancer. The element associated is Earth, whivh represents a basis for our existence.";
    string Gem = "You are a Gemini. One of your strengths is that you are affectionate. You are compatible with Aquarius and Sagittarius. The element associated is Air, which is the element that connects all other elements";
    string Cancer = "You are a Cancer. One of your strengths is that you are loyal. You are compatible with Capricorn and Taurus. The element associated is Water, which is the element of constant movement.";
    string Leo = "You are a Leo. One of your strengths is that you are passionate. You are compatible with Aquarius and Gemini. The element associated is Fire which is the only element that shines";
    string Virg = "You are a Virgo. One of your strengths is that you are analytical. You are compatible with Pisces and Cancer. The element associated is Earth, which represents a basis for our existence.";
    string Lib = "You are a Libra. One of your strengths is that you are diplomatic. You are compatible with Aries and Sagittarius. The element associated is Air, which is the element that connects all other elements";
    string Scorp = "You are a Scorpio. One of your strengths is that you are brave. You are compatible with Taurus and Cancer. The element associated is Water, which is the element of constant movement.";
    string Sagi = "You are a Sagittarius. One of your strengths is that you are idealistic. You are compatible with Gemini and Aries. The element associated is Fire which is the only element that shines";
    string Capri = "You are a Capricorn. One of your strengths is that you are disciplined. You are compatible with Taurus and Cancer.The element associated is Earth, which represents a basis for our existence.";

    //obtaining the user input
    cout << "In numbers, please enter the day of your birthday? " << endl;
    cin >> day;

    cout << "In numbers, please enter the month of your birthday? " << endl;
    cin >> month;

    //checks all of the cases
    if ((month == 1 && day >= 20) ||(month == 2 && day <= 18)) { //days inclusive from jan. 20 - feb. 18
        cout << Aquar << endl;
    }
    else if ((month == 2 && day >= 19 && day <= 28) ||(month == 3 && day <= 20)) { //days inclusive from feb. 19 - mar. 20
        cout << Pis << endl;
    }
    else if ((month == 3 && day >= 21 ) ||(month == 4 && day <= 19)) { //days inclusive from mar. 21 - apr. 19
        cout << Ar << endl;
    }
    else if ((month == 4 && day >= 20 && day <= 30) ||(month == 5 && day <= 20)) { //days inclusive from apr. 20 - may 20
        cout << Taur << endl;
    }
    else if ((month == 5 && day >= 21 ) ||(month == 6 && day <= 20)) { //days inclusive from may 21 - jun. 20
        cout << Gem << endl;
    }
    else if ((month == 6 && day >= 21 && day <= 30) ||(month == 7 && day <= 22)) { //days inclusive from jun. 21 - jul. 22
        cout << Cancer << endl;
    }
    else if ((month == 7 && day >= 23) ||(month == 8 && day <= 22)) { //days inclusive from jul. 23 - aug. 22
        cout << Leo << endl;
    }
    else if ((month == 8 && day >= 23 ) ||(month == 9 && day <= 22)) { //days inclusive from aug. 23 - sept. 22
        cout << Virg << endl;
    }
    else if ((month == 9 && day >= 23 && day <= 30) ||(month == 10 && day <= 22)) { //days inclusive from sept. 23 - oct. 22
        cout << Lib << endl;
    }
    else if ((month == 10 && day >= 23) ||(month == 11 && day <= 21)) { //days inclusive from oct. 23 - nov. 21
        cout << Scorp << endl;
    }
    else if ((month == 11 && day >= 22 && day <= 30) ||(month == 12 && day <= 21)) { //days inclusive from nov. 22 - dec. 21
        cout << Sagi << endl;
    }
    else if ((month == 12 && day >= 22) ||(month == 1 && day <= 19)) { //days inclusive from dec. 22 - jan. 19
        cout << Capri << endl;
    }
    else if (day > 31 || month < 1 || day < 1 || month > 12) { //checks all of the invalid inputs
        cout << "That day/month combo does not exist" << endl;
    }
    //terminate
    return 0;
}
