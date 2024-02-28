#pragma once


struct Cell {
    Cell();
    bool visited;
    bool topWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;
    bool isCorrDir;
};