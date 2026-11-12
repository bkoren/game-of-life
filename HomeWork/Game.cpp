#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

void Game::net(RenderWindow& window)
{
    for (int i = 0; i <= rows; ++i) {
        Vertex line[] = {
            Vertex(Vector2f(0, i * space)),
            Vertex(Vector2f(cols * space, i * space))
        };
        window.draw(line, 2, Lines);
    }

    for (int i = 0; i <= cols; ++i) {
        Vertex line[] = {
            Vertex(Vector2f(i * space, 0)),
            Vertex(Vector2f(i * space, rows * space))
        };
        window.draw(line, 2, Lines);
    }
}

void Game::set_color(int c_0, int c_1, int c_2)
{
    this->c_0 = c_0;
    this->c_1 = c_1;
    this->c_2 = c_2;
}

void Game::set_numberOfCells(int length)
{
    this->length = length;
}

void Game::checkStatus()
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            countNeighbour(i, j);
        }
    }
}

void Game::countNeighbour(int x, int y)
{
    Position checkPoint;

    checkPoint.set_x(x);
    checkPoint.set_y(y);

    int numberNeighbour = 0;
    alive = false;
    for (int i = 0; i < pastPosition.size(); i++)
    {
        Position firstPoint = pastPosition[i];

        isAlive(checkPoint, firstPoint);

        int distance = sqrt(pow(firstPoint.get_x() - checkPoint.get_x(), 2) + pow(firstPoint.get_y() - checkPoint.get_y(), 2));
        if (distance == 1)
        {
            numberNeighbour++;
        }
    }
    nextGeneration(checkPoint, numberNeighbour);
}

void Game::isAlive(Position& checkPoint, Position& firstPoint)
{
    if ((checkPoint.get_x() == firstPoint.get_x()) && (checkPoint.get_y() == firstPoint.get_y()))
    {
        alive = true;
    }
}

void Game::nextGeneration(Position& checkPoint, int numberNeighbour)
{
    if (!alive && numberNeighbour == 3)
    {
        nextPosition.push_back(checkPoint);
    }
    
    if (alive && (numberNeighbour == 2 || numberNeighbour == 3))
    {
        nextPosition.push_back(checkPoint);
    }
    //cout << boolalpha << alive << endl;
}

void Game::set_startCells()
{
    srand(time(0));
    
    pastPosition.resize(length);

    for (int i = 0; i < length; i++)
    {
        int temp_a = rand() % cols;
        int temp_b = rand() % rows;
        
        pastPosition[i].set_x(temp_a);
        pastPosition[i].set_y(temp_b);
        
    }
}

void Game::set_Coordinates()
{ 
    Coordinates.resize(1280);

    int temp_x = 0;
    for (int i = 0; i < cols; i++)
    {
        Coordinates[i].set_x(temp_x);
        temp_x += 20;
    }

    int temp_y = 0;
    for (int i = 0; i < rows; i++)
    {
        Coordinates[i].set_y(temp_y);
        temp_y += 20;
    }
}

void Game::generate(RenderWindow& window)
{
    for (int i = 0; i < pastPosition.size(); i++)
    {
        RectangleShape shape(Vector2f(20, 20));
        shape.setFillColor(Color(c_0, c_1, c_2));
        shape.setPosition(Coordinates[pastPosition[i].get_x()].get_x(), Coordinates[pastPosition[i].get_y()].get_y());

        window.draw(shape);
    }
}

void Game::swap()
{  
    pastPosition = nextPosition;
    nextPosition.clear();
}
