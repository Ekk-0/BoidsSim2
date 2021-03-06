#include <iostream>
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Flock.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Boids.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Pvector.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#ifndef GAME_H
#define GAME_H

// @author Eben Vosloo
// Game handles the instantiation of a flock of boids, game input, asks the
// model to compute the next step in the stimulation, and handles all of the
// program's interaction with SFML. 

class Game {
private:
    sf::RenderWindow window;
    int window_width;
    int window_height;

    Flock flock;
    float boidsSize;
    vector<sf::CircleShape> shapes;

    void Render();
    void HandleInput();

public:
    Game();
    void Run();
};

#endif