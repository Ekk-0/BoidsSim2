#include "PVector.hpp"


#include <vector>
#include <stdlib.h>
#include <iostream>

#ifndef BOID_HPP
#define BOID_HPP

// The Boid Class
//  @author Eben Vosloo
/*  Attributes
    -bool predator: flag that specifies whether a given boid is a predator.
    -PVector location: Vector that specifies a boid's location.
    -PVector velocity: Vector that specifies a boid's current velocity.
    -PVector acceleration: Vector that specifies a boid's current acceleration.
    -float maxSpeed: Limits magnitude of velocity vector.
    -float maxForce: Limits magnitude of acceleration vector. (F = m*a!)

    Methods
    -applyForce(PVector force): Adds the given vector to acceleration

    -PVector Separation(vector<Boid> Boids): If any other boids are within a
     given distance, Separation computes a a vector that distances the
     current boid from the boids that are too close.

    -PVector Alignment(vector<Boid> Boids): Computes a vector that causes the
     velocity of the current boid to match that of boids that are nearby.

    -PVector Cohesion(vector<Boid> Boids): Computes a vector that causes the
     current boid to seek the center of mass of nearby boids.
*/
class Boid {
public:
    // Logic
    bool predator;
    PVector location;
    PVector velocity;
    PVector acceleration;
    float maxSpeed;
    float maxForce;
    // Constructors
    Boid() {}
    Boid(float x, float y);
    Boid(float x, float y, bool predCheck);
    void applyForce(const PVector& force);

    // Three Laws that boids follow
    PVector Separation(const vector<Boid>& Boids);
    PVector Alignment(const vector<Boid>& Boids);
    PVector Cohesion(const vector<Boid>& Boids);

    //Functions involving SFML and visualisation linking
    PVector seek(const PVector& v);
    void run(const vector<Boid>& v);
    void update();
    void flock(const vector<Boid>& v);
    void borders();
    float angle(const PVector& v);
};

#endif