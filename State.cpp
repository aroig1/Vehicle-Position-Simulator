#include <iostream>
using namespace std;

#include "State.h"

State::State() : MathVector(4) {
    elements.at(0) = 0;
    elements.at(1) = 0;
    elements.at(2) = 0;
    elements.at(3) = 0;
}

State::State(double x, double y, double delta, double theta) : MathVector(4) {
    elements.at(0) = x;
    elements.at(1) = y;
    elements.at(2) = delta;
    elements.at(3) = theta;
}

State::State(const State& other) : MathVector(other) {
    setX(other.elements.at(0));
    setY(other.elements.at(1));
    setDelta(other.elements.at(2));
    setTheta(other.elements.at(3));
}

double State::getX() {
    return elements.at(0);
}

double State::getY(){
    return elements.at(1);
}

double State::getDelta() {
    return elements.at(2);
}

double State::getTheta() {
    return elements.at(3);
}

void State::setX(double newX) {
    elements.at(0) = newX;
}

void State::setY(double newY) {
    elements.at(1) = newY;
}

void State::setDelta(double newDelta) {
    elements.at(2) = newDelta;
}

void State::setTheta(double newTheta) {
    elements.at(3) = newTheta;
}