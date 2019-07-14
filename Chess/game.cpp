//
//  game.cpp
//  Chess
//
//  Created by Гайворонский Андрей on 14/07/2019.
//  Copyright © 2019 agaiv. All rights reserved.
//

#include "game.hpp"

#include <iostream>

namespace NGameIO {
    
    TChessGame::TChessGame(EGameMode mode, EStartSide side) {
        // TODO
    }
    
    void TChessGame::HandleCommand(const std::string& command) {
        if (command == "help") {
            PrintHelp();
        } else if (command == "quit") {
            // TODO quit
        } else if (!State.MakeMove(command)){
            std::cout << "Invalid move!\n";
        }
    }
    
    bool TChessGame::IsGameFinished(std::string& message) {
        if (State.IsCheckmate()) {
            if (State.IsWhiteMove()) {
                message = "Black pieces win!\n";
                return true;
            } else {
                message = "White pieces win!\n";
                return true;
            }
        }
        return false;
    }
    
    void TChessGame::PrintHelp() {
        std::cout << "Available options are: \n";
        std::cout << "help -- print this message and continue\n";
        std::cout << "quit -- terminate game and exit\n";
        std::cout << "valid move, either in form E2E4, O-O, or O-O-O\n";
    }
}
