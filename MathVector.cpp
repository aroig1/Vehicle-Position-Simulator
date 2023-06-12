#include <iostream>
#include <iomanip>
using namespace std;

#include "MathVector.h"

MathVector::MathVector(int numElements) {
    this->numElements = numElements;
    elements.resize(numElements);
}

bool MathVector::readElements(string str) {
    // creates a csv of this vector
    istringstream inSS;
    vector <double> values;
    double temp;
    int i = 1;
    char comma;

    inSS.clear();
    inSS.str(str);

    inSS >> temp;
    values.push_back(temp);
    if (!inSS.good()) {
        cout << "Unable to read element 0 of [" << str << "] ";
        cout << "(expected " << numElements << " elements)" << endl;
        return false;
    }
    while (!inSS.eof()) {
        if (!inSS.good()) {
            cout << "Unable to read element " << i - 1 << " of [" << str << "] ";
            cout << "(expected " << numElements << " elements)" << endl;
            return false;
        }
        inSS >> comma >> temp;
        values.push_back(temp);
        ++i;
    }
    if (values.size() > numElements) {
        cout << "Unable to read line [" << str << "] ";
        cout << "(more than " << numElements << " elements)" << endl;
        return false;
    }
    if (values.size() < numElements) {
        cout << "Unable to read element " << i << " of [" << str << "] ";
        cout << "(expected " << numElements << " elements)" << endl;
        return false;
    }

    for (i = 0; i < numElements; ++i) {
        elements.at(i) = values.at(i);
    }
    return true;
}

string MathVector::toString() {
    stringstream stream;
    string str;

    stream << fixed << setprecision(3) << elements.at(0);
    str = stream.str();
    for (int i = 1; i < numElements; ++i) {
        stream.clear();
        stream << "," << elements.at(i);
    }
    str = stream.str();

    return str;
}