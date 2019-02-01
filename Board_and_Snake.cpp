#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Snake.h"

Area_and_Snake::Area_and_Snake()
{
    length = 0;
    step = 0;

    T = new Single_Area *[30]; // dynamiczne utworzenie wierszy tablicy

    for(int i = 0; i < 30; i++) // dynamiczne utworzenie kolumn tablicy
    {
        T[i] = new Single_Area [20];
    }

    tail_x = new int [10000]; // alokacja dwoch tablic dla przechowywania polozenia ogona weza
    tail_y = new int [10000]; // musza miec duzy rozmiar bo nie wiemy ile ruchow wykona waz

    x_coordinate = 10;
    y_coordinate = 10;
    T[x_coordinate][y_coordinate].place_head();

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            T[i][j].setting(i*21, j*21);
        }
    }
}

Area_and_Snake::~Area_and_Snake()
{
    for(int i = 0; i < 30; i++)
    {
        delete [] T[i];
    }

    delete [] T;
    delete [] tail_x;
    delete [] tail_y;
    T = NULL;
    tail_x = NULL;
    tail_y = NULL; // od teraz tablice za zdealokowane i wskazuja nigdzie
}

void Area_and_Snake::set_food()
{
    int n, m;
    srand(time(NULL));
    n = 1 + rand()%(30 - 2 - 1 + 1); // losowanie liczby z przedzialu [1, 28] dla wiersza (pierwszy i ostatni element to krawedzie)
    m = 1 + rand()%(20 - 2 - 1 + 1); // losowanie liczby z przedzialu [1, 18] dla kolumny (pierwszy i ostatni element to krawedzie)

    T[n][m].place_food();
}


void Area_and_Snake::create_borders()
{
    for (int i = 0; i < 30; i++)
    {
        T[i][0].place_band();
        T[i][20 - 1].place_band();
    }
    for (int i = 1; i < 20; i++)
    {
        T[0][i].place_band();
        T[30 - 1][i].place_band();
    }
}

void Area_and_Snake::increase_length()
{
    length++;
}

void Area_and_Snake::draw_board(sf::RenderWindow & win)
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            T[i][j].draw_square(win);
            if(T[i][j].food) T[i][j].food_c();
            else if(T[i][j].band) T[i][j].band_c();
            else if(T[i][j].head) T[i][j].head_c();
            else T[i][j].empty_c();
        }
    }
}

void Area_and_Snake::if_over()
{
    if(T[y_coordinate][x_coordinate].band)
    {
        exit(0);
    }
    else return;
}

void Area_and_Snake::if_food()
{
    if(T[y_coordinate][x_coordinate].food)
    {
        T[y_coordinate][x_coordinate].remove_food();
        increase_length();
        set_food();
    }
}
