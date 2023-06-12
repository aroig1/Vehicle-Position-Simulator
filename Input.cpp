#include <iostream>
using namespace std;

#include "Input.h"

Input::Input() : MathVector(2) {
    elements.at(0) = 0;
    elements.at(1) = 0;
}

Input::Input(double v, double delta) : MathVector(2) {
    elements.at(0) = v;
    elements.at(1) = delta;
}

Input::Input(const Input& other) : MathVector(other) {
    setV(other.elements.at(0));
    setDeltaDot(other.elements.at(1));
}

double Input::getV() {
    return elements.at(0);
}

double Input::getDeltaDot() {
    return elements.at(1);
}

void Input::setV(double v) {
    elements.at(0) = v;
}

void Input::setDeltaDot(double delta) {
    elements.at(1) = delta;
}