//
//  Input.h
//

#ifndef Input_h
#define Input_h

#include "MathVector.h"
using namespace std;

class Input : public MathVector {
    public:
        Input();
        Input(double v, double delta);
        ~Input() { }
        Input(const Input& other);
        double getV();
        double getDeltaDot();
        void setV(double v);
        void setDeltaDot(double delta);
};

#endif /* Input_h */
