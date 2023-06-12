//
//  MathVector.h
//

#ifndef MathVector_h
#define MathVector_h

#include <string>
#include <vector>
using namespace std;

class MathVector {
    public:
        MathVector(int numElements);
        ~MathVector() { }
        bool readElements(string str);
        // creates a csv of this vector
        string toString();
    protected:
        int numElements;
        vector<double> elements;
};

#endif /* MathVector_h */
