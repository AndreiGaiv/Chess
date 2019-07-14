//
//  game.hpp
//  Chess
//
//  Created by Гайворонский Андрей on 14/07/2019.
//  Copyright © 2019 agaiv. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <string>
#include "board.hpp"

namespace NGameIO {
    
    enum class EGameMode {
        PVP,
        PVC
    };
    
    enum class EStartSide {
        Black,
        White,
        Random
    };

    class TChessGame {
    public:
        TChessGame(EGameMode mode, EStartSide side);
        
        void HandleCommand(const std::string& command);
        
        bool IsGameFinished(std::string& message);
        
    private:
        void PrintHelp();
        
        TBoardState State;
    };
    
}

#endif /* game_hpp */
