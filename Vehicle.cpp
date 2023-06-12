#include <iostream>
using namespace std;

#include "Vehicle.h"

// vehicle should start at 0, 0, 0, 0 if nothing is passed in. It should
// allocate a default value of State of 0, 0, 0, 0
Vehicle::Vehicle() {
    state = new State();
    wheelbase = 0.0;
}

// vehicle should make a copy of the data in x0 and allocate new memory
// to hold its state value
Vehicle::Vehicle(State x0, double wheelbase) {
    state = new State(x0);
    this->wheelbase = wheelbase;
}

// implementation should delete the state variable data
Vehicle::~Vehicle() {
    delete state;
}

// return the wheelbase value
double Vehicle::getWheelbase() {
    return wheelbase;
}

// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it
State* Vehicle::update(Input* u, double ts) {
    double newX, newY, newDelta, newTheta;

    newX = state->getX() + (ts * u->getV() * cos(state->getDelta()) * cos(state->getTheta()));
    newY = state->getY() + (ts * u->getV() * cos(state->getDelta()) * sin(state->getTheta()));
    newDelta = state->getDelta() + (ts * u->getDeltaDot());
    newTheta = state->getTheta() + (ts * u->getV() * (1.0 / wheelbase) * sin(state->getDelta()));

    if (newDelta > DELTA_MAX) {
        newDelta = DELTA_MAX;
    }
    else if (newDelta < DELTA_MIN) {
        newDelta = DELTA_MIN;
    }
    if (newTheta > HEADING_MAX) {
        newTheta -= HEADING_MAX;
    }
    else if (newTheta < 0) {
        newTheta += HEADING_MAX;
    }

    state->setX(newX);
    state->setY(newY);
    state->setDelta(newDelta);
    state->setTheta(newTheta);
}

// returns a pointer to the current state. The calling object should make
// a deep copy of the data if it wants to keep it
State* Vehicle::getState() {
    return state;
}