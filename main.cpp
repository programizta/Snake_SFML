#include "Snake.h"
#include <SFML/Graphics.hpp>

void play() // funkcja sterujaca cala gra
{
    while(true)
    {
        Area_and_Snake board;
        Single_Area button;
        sf::RenderWindow menu(sf::VideoMode(600, 370), "Main menu");
        button.draw_background(menu);
        button.draw_buttons(menu);
        button.draw_text(menu);
        menu.display();

        while(menu.isOpen())
        {
            sf::Event event;

            while (menu.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    menu.close();
                    exit(0);
                }
                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left && sf::Mouse::getPosition(menu).x <= 500 && sf::Mouse::getPosition(menu).x >= 350 && sf::Mouse::getPosition(menu).y <= 280 && sf::Mouse::getPosition(menu).y >= 200)
                    {
                        button.exit_pressed();
                        menu.clear();
                        button.draw_background(menu);
                        button.draw_buttons(menu);
                        button.draw_text(menu);
                        menu.display();
                        menu.close();
                        exit(0);
                    }
                    if(event.mouseButton.button == sf::Mouse::Left && sf::Mouse::getPosition(menu).x <= 240 && sf::Mouse::getPosition(menu).x >= 90 && sf::Mouse::getPosition(menu).y <= 280 && sf::Mouse::getPosition(menu).y >= 200)
                    {
                        button.start_pressed();
                        menu.clear();
                        button.draw_background(menu);
                        button.draw_buttons(menu);
                        button.draw_text(menu);
                        menu.display();
                        menu.close();

                        board.create_borders();
                        sf::RenderWindow game(sf::VideoMode(630, 420), "Rozgrywka");
                        game.setFramerateLimit(30);
                        board.set_food();
                        board.draw_board(game);


                        while(game.isOpen())
                        {
                            sf::Event event;

                            while (game.pollEvent(event))
                            {
                                if(event.type == sf::Event::Closed) game.close();
                                if(event.type == sf::Event::KeyPressed &&(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right))
                                {
                                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                                    {
                                        board.direction = 1;
                                    }
                                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                                    {
                                        board.direction = 2;
                                    }
                                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                                    {
                                        board.direction = 3;
                                    }
                                    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                                    {
                                        board.direction = 4;
                                    }

                                    board.step++;
                                    board.tail_x[board.step] = board.x_coordinate;
                                    board.tail_y[board.step] = board.y_coordinate;

                                    if(board.direction == 3)
                                    {
                                        board.y_coordinate--;
                                        board.T[board.tail_y[board.step - board.length]][board.tail_x[board.step - board.length]].remove_head();
                                        board.T[board.y_coordinate][board.x_coordinate].place_head();
                                    }

                                    else if(board.direction == 1)
                                    {
                                        board.x_coordinate--;
                                        board.T[board.tail_y[board.step - board.length]][board.tail_x[board.step - board.length]].remove_head();
                                        board.T[board.y_coordinate][board.x_coordinate].place_head();
                                    }
                                    else if(board.direction == 2)
                                    {
                                        board.x_coordinate++;
                                        board.T[board.tail_y[board.step - board.length]][board.tail_x[board.step - board.length]].remove_head();
                                        board.T[board.y_coordinate][board.x_coordinate].place_head();
                                    }
                                    else
                                    {
                                        board.y_coordinate++;
                                        board.T[board.tail_y[board.step - board.length]][board.tail_x[board.step - board.length]].remove_head();
                                        board.T[board.y_coordinate][board.x_coordinate].place_head();
                                    }
                                }
                                board.if_food();
                                board.if_over();
                            }
                            game.clear();
                            board.draw_board(game);
                            game.display();
                        }
                    }
                }
            }
        }
    }


}

int main()
{
    play();
    return 0;
}
