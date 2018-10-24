#include <iostream>
#include <SFML/Graphics.hpp>
#include "myMath.h"
#include <cmath>

/**
 * \brief main
 * @return int return status. 0 indicates normal return.
 *
 *    Driver that draws a math function. As an illustration, it shows how to draw
 *    sin curve based on my sin function (red color) and system sin function (green color)
 */
int main() {
    // draw Canvas to the window!
    sf::RenderWindow window(sf::VideoMode(800,600), "Sin curve with SFML VertexArray");
    sf::VertexArray m_points; // Chapter 7 arrays and vectors
    sf::VertexArray c_points; // Chapter 7 arrays and vectors

    unsigned canvas_width = window.getSize().x;
    unsigned canvas_height = window.getSize().y-100;

    const double step = 0.01;
    for (double x = 0.0; x < canvas_width*0.2; x = x + step) {
        double y = mySin(x);
        m_points.append(sf::Vertex(sf::Vector2f(x*20,canvas_height/2-y*80), sf::Color::Red));
    }

    for (double x = 0.0; x < canvas_width*0.2; x = x + step) {
        double y = sin(x);
        c_points.append(sf::Vertex(sf::Vector2f(x*20+4,canvas_height/2-y*80), sf::Color::Green));
    }

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(m_points);
        window.draw(c_points);
        window.display();
    }
    return 0;
}