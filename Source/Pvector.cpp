#include <math.h>
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/PVector.hpp"

// ===================================================== //
// ======== PVector Functions from PVector.hpp ========= //
// ===================================================== //

#define PI 3.141592635

// Sets values of x and y for PVector
void PVector::set(float i, float o)
{
    x = i;
    y = o;
}

void PVector::addVector(const PVector& v)
{
    x += v.x;
    y += v.y;
}

// Adds to a PVector by a constant number
void PVector::addScalar(float s)
{
    x += s;
    y += s;
}

// Subtracts 2 vectors
void PVector::subVector(const PVector& v)
{
    x -= v.x;
    y -= v.y;
}

// Subtracts two vectors and returns the difference as a vector
PVector PVector::subTwoVector(const PVector& v, const PVector& v2)
{
    PVector tmp(v.x - v2.x, v.y - v2.y);
    return std::move(tmp);
}

// Adds to a PVector by a constant number
void PVector::subScalar(float s)
{
    x -= s;
    y -= s;
}

// Multiplies 2 vectors
void PVector::mulVector(const PVector& v)
{
    x *= v.x;
    y *= v.y;
}

// Adds to a PVector by a constant number
void PVector::mulScalar(float s)
{
    x *= s;
    y *= s;
}

// Divides 2 vectors
void PVector::divVector(const PVector& v)
{
    x /= v.x;
    y /= v.y;
}

// Adds to a PVector by a constant number
void PVector::divScalar(float s)
{
    x /= s;
    y /= s;
}

void PVector::limit(double max)
{
    double size = magnitude();

    if (size > max) {
        set(x / size, y / size);
    }
}

// Calculates the distance between the first PVector and second PVector
float PVector::distance(const PVector& v)
{
    float dx = x - v.x;
    float dy = y - v.y;
    float dist = sqrt(dx*dx + dy*dy);
    return dist;
}

// Calculates the dot product of a vector
float PVector::dotProduct(const PVector& v)
{
    float dot = x * v.x + y * v.y;
    return dot;
}

// Calculates magnitude of referenced object
float PVector::magnitude()
{
    return sqrt(x*x + y*y);
}

void PVector::setMagnitude(float x)
{
    normalize();
    mulScalar(x);
}

// Calculate the angle between PVector 1 and PVector 2
float PVector::angleBetween(const PVector& v)
{
    if (x == 0 && y == 0) return 0.0f;
    if (v.x == 0 && v.y == 0) return 0.0f;

    double dot = x * v.x + y * v.y;
    double v1mag = sqrt(x * x + y * y);
    double v2mag = sqrt(v.x * v.x + v.y * v.y);
    double amt = dot / (v1mag * v2mag); //Based of definition of dot product
    //dot product / product of magnitudes gives amt
    if (amt <= -1) {
        return PI;
    } else if (amt >= 1) {
        return 0;
    }
    float tmp = acos(amt);
    return tmp;
}

// normalize divides x and y by magnitude if it has a magnitude.
void PVector::normalize()
{
    float m = magnitude();

    if (m > 0) {
        set(x / m, y / m);
    } else {
        set(x, y);
    }
}

// Creates and returns a copy of the PVector used as a parameter
PVector PVector::copy(const PVector& v)
{
    PVector copy(v.x, v.y);
    return copy;
}