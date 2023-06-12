#ifndef Project2_h
#define Project2_h

#include "Vehicle.h"

#include <string>
using namespace std;

class Project2 {
    public:
        Project2(string input, string output);
        void RunSimulation();
    private:
        string inputFile;
        string outputFile;
};

#endif //Project2_h
