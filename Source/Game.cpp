#include <iostream>
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Flock.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Boids.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Pvector.hpp"
#include "/Users/eavosloo/Programming/C++/sfml_projects/BoidsSim2/Header/Game.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

// Construct window using SFML
Game::Game()
{
    this->boidsSize = 4.0;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window_height = desktop.height;
    this->window_width  = desktop.width;
    this->window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Boids Simulation 2");
    
    // Try to achieve 60 FPS.
    window.setFramerateLimit(60);
}

// Run the simulation. Run creates the boids that we'll display, checks for user
// input, and updates the view
void Game::Run()
{
    for (int i = 0; i < 1000; i++) {
        Boid b(window_width / 3, window_height / 3); // Starts all boids in the center of the screen
        sf::CircleShape shape(8, 3);

        // Changing the Visual Properties of the shape
        // shape.setPosition(b.location.x, b.location.y); // Sets position of shape to random location that boid was set to.
        shape.setPosition(window_width, window_height); // Testing purposes, starts all shapes in the center of screen.
        shape.setFillColor(sf::Color::Blue);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(1);
        shape.setRadius(boidsSize);

        // Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
        flock.addBoid(b);
        shapes.push_back(shape);
    }
    while (window.isOpen()) {
        HandleInput();
        Render();
    }
}

void Game::HandleInput()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        // "close requested" event: we close the window
        // Implemented alternate ways to close the window. (Pressing the escape, X, and BackSpace key also close the program.)
        if ((event.type == sf::Event::Closed) ||
            (event.type == sf::Event::KeyPressed &&
             event.key.code == sf::Keyboard::Escape) ||
            (event.type == sf::Event::KeyPressed &&
             event.key.code == sf::Keyboard::BackSpace) ||
            (event.type == sf::Event::KeyPressed &&
             event.key.code == sf::Keyboard::X))
             {
            window.close();
        }
    }

    // Check for mouse click, draws and adds boid to flock if so.
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Gets mouse coordinates, sets that as the location of the boid and the shape
        sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
        Boid b(mouseCoords.x, mouseCoords.y, false);
        sf::CircleShape shape(10,3);

        // Changing visual properties of newly created boid
        shape.setPosition(mouseCoords.x, mouseCoords.y);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineColor(sf::Color::Blue);
        shape.setOutlineThickness(1);
        shape.setRadius(boidsSize);

        // Adds newly created boid and shape to their respective data structure
        flock.addBoid(b);
        shapes.push_back(shape);

        // New Shape is drawn
        window.draw(shapes[shapes.size()-1]);
    }
}

void Game::Render()
{
    window.clear();

    // Draws all of the Boids out, and applies functions that are needed to update.
    for (int i = 0; i < shapes.size(); i++) {
        window.draw(shapes[i]);

        //cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
        //cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

        // Matches up the location of the shape to the boid
        shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

        // Calculates the angle where the velocity is pointing so that the triangle turns towards it.
        float theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
        shapes[i].setRotation(theta);

        // Prevent boids from moving off the screen through wrapping
        // If boid exits right boundary
        if (shapes[i].getPosition().x > window_width)
            shapes[i].setPosition(shapes[i].getPosition().x - window_width, shapes[i].getPosition().y);
        // If boid exits bottom boundary
        if (shapes[i].getPosition().y > window_height)
            shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - window_height);
        // If boid exits left boundary
        if (shapes[i].getPosition().x < 0)
            shapes[i].setPosition(shapes[i].getPosition().x + window_width, shapes[i].getPosition().y);
        // If boid exits top boundary
        if (shapes[i].getPosition().y < 0)
            shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + window_height);
    }

    // Applies the three rules to each boid in the flock and changes them accordingly.
    flock.flocking();

    window.display();
}
