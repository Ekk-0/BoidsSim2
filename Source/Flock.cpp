#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Boids.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Flock.hpp"

// ================================================= //
// ======== Flock Functions from Flock.hpp ========= //
// ================================================= //

int Flock::getSize()
{
    return flock.size();
}

//Read only method that returns a copy of the Boid.
Boid Flock::getBoid(int i)
{
    return flock[i];
}

//Read/write method that returns a reference of the Boid.
// Boid &Flock::getBoid(int i)
// {
//     return flock[i];
// }

void Flock::addBoid(const Boid& b)
{
    flock.push_back(std::move(b));
}

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking() 
{
    for (int i = 0; i < flock.size(); i++)
        flock[i].run(flock);
}