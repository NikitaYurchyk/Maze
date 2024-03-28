#include <iostream>

#include <string>

#include "game.h"
#include "maze.h"

Game::Game()= default;

void Game::startGame() {
    bool isGameOn = true;
    srand(42);
    while(isGameOn) {
        std::cout << "Choose a command:" << '\n';
        std::cout << "1: Create labyrinth" << '\n';
        std::cout << "2: Specify seed" << '\n';
        std::cout << "3: Exit" << '\n';
        try {
            int seedNumber = 5;
            std::string command = "";
            std::cin >> command;
            int numOfCommand = stoi(command);
            switch (numOfCommand) {
                case 1: {
                    std::string width = "";
                    std::string height = "";
                    std::cout << "Enter: width and height" << '\n';
                    std::cin >> width >> height;
                    Labyrinth labyrinth(stoi(width), stoi(height));
                    labyrinth.printLabyrinth();
                    bool isPrintLabyrOn = true;
                    while(isPrintLabyrOn) {
                        std::cout << "Do you want to find the path to the end of the labyrinth" << '\n';
                        std::cout << "1.Yes" << '\n' << "2.No" << '\n';
                        std::string innerCmd = "";
                        std::cin >> innerCmd;
                        numOfCommand = std::stoi(innerCmd);
                        switch (numOfCommand) {
                            case 1: {
                                labyrinth.recFindPath(0, 0);
                                labyrinth.printLabyrinth();
                                isPrintLabyrOn = false;
                                break;
                            }
                            case 2: {
                                isPrintLabyrOn = false;
                                break;
                            }
                            default: {
                                std::cout << "Invalid command." << std::endl;
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter the seed number: " << '\n';
                    std::string strSeedNumber = "";
                    std::cin >> strSeedNumber;
                    srand(seedNumber);
                    break;
                }
                case 3: {
                    isGameOn = false;
                    std::cout << "Bye" << std::endl;
                    break;
                }
                default:
                    std::cout << "Invalid command." << std::endl;
            }
        } catch (std::invalid_argument &e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            return;
        }
    }
}