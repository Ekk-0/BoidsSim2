#include <iostream>

using namespace std;

#ifndef PVector_HPP
#define PVector_HPP

// The PVector class implements Euclidian vectors -- that is, each vector has
// both a magnitude and a direction. We use PVectors for implementing movement
// and the three Boid rules -- cohesion, separation, and matching velocity
// through the use of acceleration, force, and velocity vectors.

class PVector {

public:
    float x;
    float y;

    //Constructors
    PVector() {}

    PVector(float xComp, float yComp)
    {
        x = xComp;
        y = yComp;
    }

    //Mutator Functions
    void set(float x, float y);

    //Scalar functions scale a vector by a float
    void addVector(const PVector& v);
    void addScalar(float x);

    void subVector(const PVector& v);
    PVector subTwoVector(const PVector& v, const PVector& v2);
    void subScalar(float x);

    void mulVector(const PVector& v);
    void mulScalar(float x);

    void divVector(const PVector& v);
    void divScalar(float x);

    void limit(double max);

    //Calculating Functions
    float distance(const PVector& v);
    float dotProduct(const PVector& v);
    float magnitude();
    void setMagnitude(float x);
    float angleBetween(const PVector& v);
    void normalize();

    PVector copy(const PVector& v);
};

#endif