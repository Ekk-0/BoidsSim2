#include <iostream>
#include <vector>
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Boids.hpp"

#ifndef FLOCK_HPP
#define FLOCK_HPP

/*
    @author Eben Vosloo
    Brief description of Flock Class:
    This file contains the class needed to create a flock of boids. It utilizes
    the boids class and initializes boid flocks with parameters that can be
    specified. This class will be utilized in main.
*/

class Flock {
public:
    //Constructors
    Flock() {}

    // Accessor functions
    int getSize();

    //Read only and read/write methods.
    Boid getBoid(int i);
    //Boid &getBoid(int i);

    // Mutator Functions
    void addBoid(const Boid& b);
    void flocking();
private:
    vector<Boid> flock;  
};

#endif