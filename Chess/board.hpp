//
//  board.hpp
//  Chess
//
//  Created by Гайворонский Андрей on 14/07/2019.
//  Copyright © 2019 agaiv. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <array>
#include <vector>

namespace NGameIO {
    
    class TBoardState;
    
    using TPosition = std::pair<int, int>;
    
    enum class ENoMoveReason {
        Unknown = 0,
        IllegalMove = 1,
        Occupied = 2,
        Blocked = 3,
        Checked = 4,
        OpensCheck = 5
    };
    
    enum class EPieceType {
        Pawn,
        Khight,
        Bishop,
        Rook,
        Queen,
        King
    };
    
    struct TMove {
        TPosition From;
        TPosition To;
        bool IsShortCastling;
        bool IsLongCastling; // Note: castling not supported for now
    };
    
    class TPiece {
    public:
        TPiece(TPosition position, EPieceType type, bool isWhite);
        
        TPosition GetPosition();
        void SetPosition(TPosition pos);
        bool IsWhite();
        bool IsKing();
        
        virtual EPieceType GetType();
        virtual bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) = 0;
        void MoveTo(TPosition position, TBoardState* state);
    
    private:
        TPosition Position;
        EPieceType Type;
        bool White;
        bool King;
    };
    
    class TPawn : public TPiece {
    public:
        TPawn(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
        
    };
    
    class TKnight : public TPiece {
    public:
        TKnight(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
    };
    
    class TBishop : public TPiece {
    public:
        TBishop(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
    };
    
    class TRook : public TPiece {
    public:
        TRook(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
    };
    
    class TQueen : public TPiece {
    public:
        TQueen(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
    };
    
    class TKing : public TPiece {
    public:
        TKing(TPosition position, bool isWhite);
        
        bool CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) override;
    };
    
    class TBoardState {
    public:
        TBoardState();
        
        bool MakeMove(const std::string& moveDescr);
        bool IsCheckmate();
        
        bool IsWhiteMove();
        
    private:
        bool WhiteMove;
        
        TPiece* positions[8][8];
        std::vector<TPiece*> livePieces;
        
        bool IsCheck();
        bool IsCheckAfterMove(TMove move);
    };
    
}

#endif /* board_hpp */
