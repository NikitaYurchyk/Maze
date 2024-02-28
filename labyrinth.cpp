#include "Labyrinth.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

Labyrinth::Labyrinth(int w, int h) : width(w), height(h), matrixLabyrinth(h, std::vector<Cell>(w)) {
    srand(static_cast<unsigned int>(time(nullptr)));
    generateLabyrinth(0, 0);
}

void Labyrinth::generateLabyrinth(int x, int y) {
    matrixLabyrinth.at(x).at(y).visited = true;
    std::vector<std::pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}};
    randomShuffle(directions);
    for (auto dir : directions) {
        int newX = x + dir.first, newY = y + dir.second;
        if (newY >= 0 && newY < height && newX >= 0 && newX < width && !matrixLabyrinth.at(newX).at(newY).visited) {
            removeWalls(x, y, newX, newY);
            generateLabyrinth(newX, newY);
        }
    }
}

bool Labyrinth::checkDir(const int& newX, const int& newY, const int& oldX, const int& oldY) {
    int changeInX = newX - oldX;
    int changeInY = newY - oldY;
    if(changeInX == 1) return !matrixLabyrinth.at(oldY).at(oldX).rightWall;
    if(changeInX == -1) return !matrixLabyrinth.at(oldY).at(oldX).leftWall;
    if(changeInY == 1) return !matrixLabyrinth.at(oldY).at(oldX).bottomWall;
    if(changeInY == -1) return !matrixLabyrinth.at(oldY).at(oldX).topWall;
    return false;
}

bool Labyrinth::recFindPath(int x, int y) {
    if (x == width - 1 && y == height - 1) {
        matrixLabyrinth.at(y).at(x).isCorrDir = true;
        return true;
    }

    visited.insert({x, y});
    matrixLabyrinth.at(y).at(x).visited = true;
    std::vector<std::pair<int, int>> directions = {{1,  0},
                                                   {-1, 0},
                                                   {0,  1},
                                                   {0,  -1}};
    for (const auto &dir: directions) {
        int newX = x + dir.first, newY = y + dir.second;
        if (newY >= 0 && newY < height && newX >= 0 && newX < width &&
            !visited.contains({newX, newY}) && checkDir(newX, newY, x, y)) {
            if (recFindPath(newX, newY)) {
                matrixLabyrinth.at(y).at(x).isCorrDir = true;
                return true;
            }
        }
    }
    return false;
}


void Labyrinth::printLabyrinth() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << "+";
            if (matrixLabyrinth.at(y).at(x).topWall) std::cout << "---";
            else std::cout << "   ";
        }
        std::cout << "+" << '\n';
        for (int x = 0; x < width; ++x) {
            if (matrixLabyrinth.at(y).at(x).leftWall) std::cout << "|";
            else std::cout << " ";
            if (matrixLabyrinth.at(y).at(x).isCorrDir) std::cout << " O ";
            else std::cout << "   ";
        }
        std::cout << "|" << '\n';
    }

    for (int x = 0; x < width; ++x) {
        std::cout << "+---";
    }
    std::cout << "+" << '\n';

}

void Labyrinth::removeWalls(int x, int y, int newX, int newY) {
    if (x == newX) {
        if (y < newY) {
            matrixLabyrinth.at(y).at(x).bottomWall = false;
            matrixLabyrinth.at(newY).at(newX).topWall = false;
        } else {
            matrixLabyrinth.at(y).at(x).topWall = false;
            matrixLabyrinth.at(newY).at(newX).bottomWall = false;
        }
    } else if (y == newY) {
        if (x < newX) {
            matrixLabyrinth.at(y).at(x).rightWall = false;
            matrixLabyrinth.at(newY).at(newX).leftWall = false;
        } else {
            matrixLabyrinth.at(y).at(x).leftWall = false;
            matrixLabyrinth.at(newY).at(newX).rightWall = false;
        }
    }
}

void Labyrinth::randomShuffle(std::vector<std::pair<int, int>>& directions) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(directions.begin(), directions.end(), g);
}