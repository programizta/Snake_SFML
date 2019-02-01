#pragma once
#include <SFML/Graphics.hpp>
//#include <cstdlib>
//#include <ctime>

class Single_Area
{
    bool food; // zmienna logiczna przechowujaca male jedzenie
    bool band; // zmienna logiczna okreslajaca czy jest banda
    bool head; // zmienna logiczna przypisujaca wartosc logiczna czy na danym polu jest glowa weza
    sf::Color food_color; // kolor jedzenia
    sf::Color band_color; // kolor bandy
    sf::Color head_color; // kolor glowy
    sf::Color empty_color; // kolor pustego pola
    sf::RectangleShape square; // deklaracja kwadracika
    sf::RectangleShape background; // deklaracja tla
    sf::RectangleShape start; // deklaracja przycisku start
    sf::RectangleShape exit; // deklaracja przycisku wyjscie
    sf::Font font; // deklaracja czcionki
    sf::Text start_t, exit_t, snake_t; // deklaracja tekstu
    friend class Area_and_Snake;

public:

    Single_Area();
    void place_food(); // metoda umieszczajaca na polu jedzenie
    void place_band(); // metoda umieszczajaca na polu bande
    void place_head(); // metoda umieszczajaca na polu glowe weza
    void remove_head(); // metoda usuwajaca z pola glowe weza
    void remove_food(); // metoda usuwajaca z pola jedzenie
    void setting(int x, int y); //metoda potrzebna do zmiany pozycji pola
    void food_c(); // metoda kolorujaca jedzenie
    void band_c(); // metoda kolorujaca bande
    void head_c(); // metoda kolorujaca glowe weza
    void empty_c(); // metoda kolorujaca puste pole
    void draw_square(sf::RenderWindow & win); // metoda odpowiedzialna za rysowanie pojedynczego pola
    void draw_background(sf::RenderWindow & win); // metoda rysujaca tlo
    void draw_buttons(sf::RenderWindow & win); // metoda rysujaca przyciski
    void draw_text(sf::RenderWindow & win); //metoda rysujaca tekst
    void start_pressed(); // zmiana koloru gdy przycisk START wcisniety
    void exit_pressed(); // zmiana koloru gdy EXIT wvcisniety
};

class Area_and_Snake
{
    Single_Area **T; // utworzenie wskaznika na wskaznik tablicy
    int *tail_x; // sa to utworzone wskazniki, ktore beda dynamicznymi tablicami
    int *tail_y; // przechowujacymi polozenie kazdego elementu ogona weza
    int N;
    int M; // zmienne N, M przechowujace wymiary dynamicznej tablicy dwuwymiarowej
    int x_coordinate; // koordynata X glowy weza
    int y_coordinate; // koordynata Y glowy weza
    int step; // zmienna przechowujaca ile ruchow waz wykonal
    int length; // zmienna przechowujaca dlugosc weza
    int direction; // zmienna przechowujaca kierunek
    friend void play(); // zastosowalem przyjazn klasy z funkcja, by moc sterowac gra

public:

    Area_and_Snake();
    ~Area_and_Snake(); // skorzystanie z destruktora bylo konieczne, pelni funkcje takiego
                       // "Garbage Collectora", czyli dealokuje dynamicznie zajeta pamiec przeze mnie
    void set_food(); // metoda rozmieszczajaca losowo jedzenie na planszy
    void create_borders(); // metoda tworzaca krawedzie
    void increase_length(); // metoda inkrementujaca dlugosc weza
    void if_over(); // metoda sprawdzajaca czy koniec gry
    void if_food(); // metoda sprawdzajaca czy na danym polu gdzie znajduje sie glowa weza jest jedzenie
    void draw_board(sf::RenderWindow & win); // metoda rysujaca cala plansze
};
