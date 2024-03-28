#pragma once

#include <iostream>
#include <vector>
#include <set>
#include "cell.h"

class Labyrinth {
public:
    Labyrinth(int w, int h);
    void generateLabyrinth(int x, int y);
    bool checkDir(const int& newX, const int& newY, const int& oldX, const int& oldY);
    bool recFindPath(int x, int y);
    void printLabyrinth();
    void removeWalls(int x, int y, int newX, int newY);

private:
    std::set<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> path;
    int width, height;
    std::vector<std::vector<Cell>> matrixLabyrinth;

    void randomShuffle(std::vector<std::pair<int, int>>& directions);
};