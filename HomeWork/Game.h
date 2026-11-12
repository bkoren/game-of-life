#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Game
{
private:

	class Position
	{
	private:
		int x;
		int y;
	public:
		int get_x() { return x; }
		int get_y() { return y; }
		void set_x(int x) { this->x = x; }
		void set_y(int y) { this->y = y; }
	};

	vector<Position> Coordinates;

	vector<Position> pastPosition;
	vector<Position> nextPosition;

	int c_0, c_1, c_2;
	int index_x, index_y;
	int length;

	const int rows = 40;
	const int cols = 50;
	const int space = 20;

	bool alive;

public:
	void set_Coordinates();
	void nextGeneration(Position& checkPoint, int numberNeighbour);
	void isAlive(Position& checkPoint, Position& firstPoint);
	void swap();
	void checkStatus();
	void countNeighbour(int x, int y);
	void set_startCells();
	void set_color(int c_0, int c_1, int c_2);
	void set_numberOfCells(int length);
	void net(RenderWindow& window);
	void generate(RenderWindow& window);
};

