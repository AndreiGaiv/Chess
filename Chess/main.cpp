//
//  main.cpp
//  Chess
//
//  Created by Гайворонский Андрей on 14/07/2019.
//  Copyright © 2019 agaiv. All rights reserved.
//

#include <iostream>

#include "game.hpp"

int main(int argc, const char * argv[]) {
    
    // Short demo of first to-be-supported game mode
    NGameIO::TChessGame game(NGameIO::EGameMode::PVP, NGameIO::EStartSide::White);
    
    std::string message;
    while (!game.IsGameFinished(message)) {
        std::string command;
        std::cin >> command;
        game.HandleCommand(command);
    }
    std::cout << message << std::endl;
    
    return 0;
}
