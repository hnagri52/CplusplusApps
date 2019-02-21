/*
    Student Name: Hussein Nagri
    Student Number: 20784178
    SYDE 121 Lab: 05 Assignment: 01
    Filename: lab05_01

    I hereby declare that this code, submitted for credit for the course
    SYDE121, is a product of my own efforts.  This coded solution has
    not been plagiarized from other sources and has not been knowingly
    plagiarized by others.

    Project: Fun with scalable vector graphics
    Purpose: The purpose of this program is to obtain input from a text file and display it visually.
    Due Date:  Wednesday, November 07, 2018

-----------------------------------------------------------------
-Program has been tested numerous times and the outputs are always correct.
-Used the input.txt file, and created multiple names and values in order to test part A.
*/



#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//function declaration
void part_a();
//purpose: obtain information from the text file and display it on the graph
//inputs: the inputs come from the text file, which is where it obtains its values
//outputs: displays a bar graph
void part_b();
//purpose: to create a SYDE logo using c++ graphics
//input: none
//output: the SYDE logo

int main() {
    //function calling
   part_a();
   part_b();
   return 0;
}

void part_b() {
    ofstream logo;
    logo.open("syde_logo_username.svg");


    if (!logo.fail()) {
        logo << "<?xml version=\"1.0\"?>\n";
        logo << "<!DOCTYPE svg PUBLIC \"-//W3c//DTD SVG 1.1//EN\" ";
        logo << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        logo << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\">\n";
        //text
        logo << "<style> \n\t.heavy { font: 100px arial; }\n</style>\n";
        logo << "<text x=\"65\" y=\"200\" class=\"heavy\">SYDE</text>\n";
        logo << "<text x=\"65\" y=\"300\" class=\"heavy\">2023</text>\n";
        //horizontal lines
        logo << "<line x1=\"25\" y1=\"100\" x2=\"375\" y2=\"100\" style=\"stroke:green;stroke-width:10\"/>\n";
        logo << "<line x1=\"25\" y1=\"325\" x2=\"375\" y2=\"325\" style=\"stroke:green;stroke-width:10\"/>\n";
        //vertical lines
        logo << "<line x1=\"25\" y1=\"95\" x2=\"25\" y2=\"330\" style=\"stroke:green;stroke-width:10\"/>\n";
        logo << "<line x1=\"375\" y1=\"95\" x2=\"375\" y2=\"330\" style=\"stroke:green;stroke-width:10\"/>\n";
        //exclamation marks
        logo << "<circle cx=\"350\" cy=\"300\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"red\"/>\n";
        logo << "<circle cx=\"325\" cy=\"300\" r=\"5\" stroke=\"black\" stroke-width=\"2\" fill=\"red\"/>\n";
        logo << "<line x1=\"325\" y1=\"225\" x2=\"325\" y2=\"280\" style=\"stroke:red;stroke-width:10\"/>\n";
        logo << "<line x1=\"350\" y1=\"225\" x2=\"350\" y2=\"280\" style=\"stroke:red;stroke-width:10\"/>\n";


        logo << "</svg>\n";
        logo.close();

    }
}

void part_a() {

    //variable declaration
    string current;
    vector<string> names;
    vector<int> values;

    int counter = 0, first = 20, lines = 0;

    //open file
    ifstream pairs;
    pairs.open("input.txt");
    //checks to see the amount of lines on the input document
    while (getline(pairs, current)) {
        lines++;
    }


    pairs.close();
    pairs.open("input.txt");
    //obtains the name and value, and stores it in 2 separate vectors
    for (int index = 0; index < lines; index++) {
        getline(pairs, current);
        names.push_back(current.substr(0, current.find(',', 0)));
        values.push_back(stoi(current.substr(current.find(',', 0) + 2)));
    }
    //prints out the names and their respective values
    for (int index = 0; index < lines; index++) {
        cout << "Name: " << names[index] << '\t' << "Values: " << values[index] << endl;
        counter++;
    }

    pairs.close();
    //opens a file to graph the data
    ofstream picture;
    picture.open("PART_A.svg");
    //diplays the graph
    if (!picture.fail()) {
        picture << "<?xml version=\"1.0\"?>\n";
        picture << "<!DOCTYPE svg PUBLIC \"-//W3c//DTD SVG 1.1//EN\" ";
        picture << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        picture << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"600\" height=\"600\">\n";
        //prints out the values according to the number of values there are on the input file
        for (int start = 0; start <= counter; start++) {
            picture << "<rect x=\"" << first << "\" y=\"" << 300 - values[start] << "\" width=\"20\" height=\"" << values[start] << "\" style=\"fill:green;\"/>\n";
            first += 40;
        }

        picture << "<line x1=\"10\" y1=\"0\" x2=\"10\" y2=\"300\" style=\"stroke:black;stroke-width:5\"/>\n";
        picture << "<line x1=\"10\" y1=\"300\" x2=\"300\" y2=\"300\" style=\"stroke:black;stroke-width:5\"/>\n";
        picture << "</svg>\n";
        picture.close();
    }
}
