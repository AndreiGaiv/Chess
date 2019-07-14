//
//  board.cpp
//  Chess
//
//  Created by Гайворонский Андрей on 14/07/2019.
//  Copyright © 2019 agaiv. All rights reserved.
//

#include "board.hpp"

namespace NGameIO {
    
    // TPiece class methods
    
    TPiece::TPiece(TPosition position, EPieceType type, bool isWhite)
    : Position(position), Type(type), White(isWhite) {
        King = (type == EPieceType::King);
    }
    
    TPosition TPiece::GetPosition() {
        return Position;
    }
    
    void TPiece::SetPosition(TPosition pos) {
        Position = pos;
    }
    
    bool TPiece::IsWhite() {
        return White;
    }
    
    bool TPiece::IsKing() {
        return King;
    }
    
    EPieceType TPiece::GetType() {
        return Type;
    }
    
    void TPiece::MoveTo(TPosition position, TBoardState* state) {
        // TODO
    }
    
    // piece-specific class methods
    
    TPawn::TPawn(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::Pawn, isWhite) {}
    
    bool TPawn::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    TKnight::TKnight(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::Khight, isWhite) {}
    
    bool TKnight::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    TBishop::TBishop(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::Bishop, isWhite) {}
    
    bool TBishop::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    TRook::TRook(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::Rook, isWhite) {}
    
    bool TRook::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    TQueen::TQueen(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::Pawn, isWhite) {}
    
    bool TQueen::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    TKing::TKing(TPosition position, bool isWhite)
    : TPiece(position, EPieceType::King, isWhite) {}
    
    bool TKing::CanMoveTo(TPosition position, TBoardState* state, ENoMoveReason& reason) {
        // TODO
        return false;
    }
    
    // TBoardState class methods
    
    // Initialize classic chess game board state
    TBoardState::TBoardState() {
        // TODO
    }
    
    bool TBoardState::MakeMove(const std::string& moveDescr) {
        // TODO
        return false;
    }
    
    bool TBoardState::IsCheckmate() {
        // TODO
        return false;
    }
    
    bool TBoardState::IsWhiteMove() {
        return WhiteMove;
    }
    
    bool TBoardState::IsCheck() {
        // TODO
        return false;
    }
    
    bool TBoardState::IsCheckAfterMove(TMove move) {
       // TODO
        return false;
    }
}
