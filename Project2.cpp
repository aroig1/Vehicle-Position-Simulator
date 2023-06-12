#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Project2.h"

Project2::Project2(string input, string output) {
    inputFile = input;
    outputFile = output;
}

void Project2::RunSimulation() {
    State state;
    Input input;
    double wheelbase;
    ifstream inFS;
    ofstream outFS;
    double ts;
    double time = 0.0;
    string str;
    string temp;

    inFS.open(inputFile);
    outFS.open(outputFile);

    inFS >> temp >> wheelbase;
    inFS >> temp >> str;
    state.readElements(str);
    outFS << fixed << setprecision(3);
    Vehicle miata(state, wheelbase);
    inFS >> temp >> ts;
    inFS.ignore();
    getline(inFS, str);
    input.readElements(str);
    while (!inFS.eof()) {
        outFS << time << "," << miata.getState()->toString() << "," << input.toString() << endl;
        miata.update(&input, ts);
        getline(inFS, str);
        input.readElements(str);
        time += ts;
    }
    outFS << time << "," << miata.getState()->toString() << endl;

    inFS.close();
    outFS.close();
}