// COMP1511 (2018S2)
// Assignment 2: Final Card Down
// player.c
// 
// Dan Nguyen (z5206032)
// 2018/10/23 - 2018/10/26
// 
// Dean Wunder (thu11-brass)

#include <stdio.h>
#include "Game.h"
#include "player.h"

// This function is to be implemented by the AI.
// It will be called when the player can take an action on their turn.
// The function is called repeatedly until they make the action
// END_TURN.
// If the player's turn is skipped, this function is not called for that
// player.
playerMove decideMove(Game game) {
    
    playerMove move = game->move;
        
    move.action = END_TURN;
    isValidMove(game, move);
    
    if (game->currentTurn == 0) {
        // Check initial discard pile card value
        checkInitialDiscardPileCard(game);
        
    } else if (cardValue(game->playedCard) == 2) {
        // If value of card is 2 then next player must either draw 2 cards or play
        // a card with value 2
        
        move.action = PLAY_CARD;
        move.card = getHandCard(game, game->currentPlayer, index);
        
    } else if (cardValue(game->playedCard) == A) {
        // If value of card is A then next player's turn is skipped
        
        move.action = PLAY_CARD;
        move.card = getHandCard;
        
    } else if (cardValue(game->playedCard) == D) {
        // If value of card is D then current player may demand any colour for next card
        
        move.nextColor = PURPLE;
        move.action = PLAY_CARD;
    } else if (cardValue(game->playedCard) == cardValue()) {
        // else play a card with same value, suit, color as played card OR play NULL
    
    } else if (cardColor(game->playedCard) == ) {
    
    } else {
        
        move.action = DRAW_CARD;
    }
    
    // then end turn
    
    if (isValidMove == TRUE) {
        
        move.action = END_TURN;
    }
    
    return move;
}

static playerMove checkInitialDiscardPileCard(Game game) {
    
    // If value is 2
    if (cardValue(game->playedCard) == 2) {
        
    }
    
    // If value is A
    if (cardValue(game->playedCard) == A) {
        
    }
    
    // If value is D, do nothing
    if (cardValue(game->playedCard) == D) {
        
    }
}
