#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Vehicle.h"
#include "Project2.h"

int main(int argc, char* argv[]) { // delete parameters if not using command line
    ifstream inFS;
    ofstream outFS;
    string inFileName;
    string outFileName;
    string test;

    if(argc != 3) {
        cout << "./project2 inputFile outputFile" << endl;
        return 0;
    }

    inFileName = argv[1]; // delete if not using command line
    outFileName = argv[2]; // delete if not using command line

//    cout << "Enter input file name: "; // use if not using command line
//    cin >> inFileName; // use if not using command line
//    cout << "Opening file " << inFileName << endl; // use if not using command line

    inFS.open(inFileName);
    if (!inFS.is_open()) {
        cout << "Could not open output file " << inFileName << endl;
        return -1;
    }
    //inFS.close();
    outFS.open(outFileName);
    if (!outFS.is_open()) {
        cout << "Could not open input file " << inFileName << endl;
        return -1;
    }
    outFS.close();
//    cout << "Enter output file name: "; // use if not using command line
//    cin >> outFileName; // use if not using command line

    getline(inFS, test); // to check for empty input file

    if (!inFS.eof()) { // runs if input file is not empty
        inFS.close();
        Project2 elCrapo(inFileName, outFileName);
        elCrapo.RunSimulation();
    }



    return 0;
}
