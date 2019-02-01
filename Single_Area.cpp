#include <SFML/Graphics.hpp>
#include "Snake.h"

Single_Area::Single_Area()
{
    food = false;
    band = false;
    head = false;

    food_color = sf::Color::Green; // jedzonko ma kolor zielony
    band_color = sf::Color::Black; // krawedz to kolor czarny
    head_color = sf::Color::Blue; // glowa weza ma kolor Magenta
    empty_color = sf::Color::Magenta; // jesli puste to kolor bialy
    square.setSize(sf::Vector2f(20, 20)); // pojedyncze pole ma rozmiary 20x20 pikseli

    background.setSize(sf::Vector2f(600, 370)); // wymiary tla
    background.setFillColor(sf::Color::Green);

    start.setSize(sf::Vector2f(150, 80)); // przycisk start ma rozmiary 200x100 pikseli
    start.setPosition(90, 200); // pozycja przycisku inicjujacego gre
    start.setFillColor(sf::Color::Yellow); // poczatkowy kolor startu to zielony

    exit.setSize(sf::Vector2f(150, 80));
    exit.setPosition(350, 200);
    exit.setFillColor(sf::Color::Yellow);

    font.loadFromFile("Font/arial.ttf");

    snake_t.setFont(font);
    snake_t.setString("SNAKE");
    snake_t.setPosition(180, 40);
    snake_t.setColor(sf::Color::Black);
    snake_t.setCharacterSize(70);

    start_t.setFont(font);
    start_t.setString("Start!");
    start_t.setPosition(100, 205);
    start_t.setColor(sf::Color::Black);
    start_t.setCharacterSize(50);

    exit_t.setFont(font);
    exit_t.setString("Exit");
    exit_t.setPosition(380, 205);
    exit_t.setColor(sf::Color::Black);
    exit_t.setCharacterSize(50);
}

void Single_Area::place_food()
{
    food = true;
}

void Single_Area::place_band()
{
    band = true;
}

void Single_Area::place_head()
{
    head = true;
}

void Single_Area::remove_head()
{
    head = false;
}

void Single_Area::remove_food()
{
    food = false;
}

void Single_Area::setting(int x, int y)
{
	square.setPosition(x, y);
}

void Single_Area::draw_square(sf::RenderWindow & win)
{
    win.draw(square);
}

void Single_Area::food_c()
{
    square.setFillColor(food_color);
}

void Single_Area::band_c()
{
    square.setFillColor(band_color);
}

void Single_Area::head_c()
{
    square.setFillColor(head_color);
}

void Single_Area::empty_c()
{
    square.setFillColor(empty_color);
}

void Single_Area::draw_background(sf::RenderWindow & win)
{
    win.draw(background);
}

void Single_Area::draw_buttons(sf::RenderWindow & win)
{
    win.draw(start);
    win.draw(exit);
}

void Single_Area::draw_text(sf::RenderWindow & win)
{
    win.draw(start_t);
    win.draw(exit_t);
}

void Single_Area::start_pressed()
{
    start.setFillColor(sf::Color::Cyan);
}

void Single_Area::exit_pressed()
{
    exit.setFillColor(sf::Color::Cyan);
}
