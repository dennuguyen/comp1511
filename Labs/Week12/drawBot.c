// Week 12 Lab
// An initial player for Final Card-Down.
//
// Dan Nguyen (z5206032)
// 2018/10/18
// 
// Dean Wunder (thu11-brass)

#include "Game.h"
#include "player.h"

#define NOT_FOUND -1

// Find a card in the player's hand that matches the specified color,
// if such a card exists.
// Returns the card index, or NOT_FOUND if no matching card was found.
int findMatchingCardColor(Game game, color color);

// Do two cards match on either value, color, or suit?
// Returns TRUE if they match any of the above features, and
// FALSE if they don't match on any of the above features.
int doCardsMatch(Card first, Card second);

// Determine whether the player can currently draw a card.
// If they can't draw a card, they should probably end their turn.
int canDrawCard(Game game);



// This function is to be implemented by the player.
// It will be called when the player can make an action on their turn.
//
// !!!!!   The function is called repeatedly, until   !!!!!
// !!!!!      they make the action `END_TURN`.        !!!!!
//
// If the player's turn is skipped, this funciton
// is *not* called for that player.
//
// Don't forget about the `isValidMove` function -- it's a handy way
// to work out before you play a move whether or not it will be valid
// (and you should only ever be making valid moves).
//
// You can also use it to help you work out where you are at in the
// game
//
// At the start of the game, it's valid to:
//   - draw a card,
//   - play a card, *if* you have a valid card that you can play.
//
// It's not valid to end your turn unless you've done some other
// move(s).
//


playerMove decideMove(Game game) {
    // Start out by making a move struct, to say what our move is.
    playerMove move;

    // Set our move to be END_TURN, and check whether that's
    // a valid move -- if it is, then just end our turn (for now).
    move.action = END_TURN;

    // If it's not valid to end turn, we must need to make
    // some other move...
    //
    // What moves are valid at this point?
    if (!isValidMove(game, move)) {
    
        // Some valid moves include:
        //   - play a card (*if* you have a valid card that you can play.)
        //   - draw a card (if we cannot play a card, we need to draw a card,
        //                  also, if DRAW_TWO is played in the previous 
        //                  turn (*how can we find this?*), 
        //                  we must draw multiple cards (*how do we know that 
        //                  we have already drawn enough cards?*)

        //
        // The easiest thing here is to draw a card, since we don't
        // need to try to work out if we have a valid card, etc.
        move.action = DRAW_CARD;
        
        // We need to improve on the above strategy! We canot
        // always draw cards and win!
    }

    return move;
}


// Find a card in the player's hand that matches the specified color,
// if such a card exists.
// Returns the card index, or NOT_FOUND if no matching card was found.
int findMatchingCardColor(Game game, color color) {
    
    while (game->card != NULL) {
        
        if (game->card->color = color) {
            return color;
        }
        
        game->card = game->card->next;
    }
    
    return NOT_FOUND; // TODO: replace this with your code.
}

// Do two cards match on either value, color, or suit?
// Returns TRUE if they match any of the above features, and
// FALSE if they don't match on any of the above features.
int doCardsMatch(Card first, Card second) {
    return FALSE; // TODO: replace this with your code.
}

// Determine whether the player can currently draw a card.
// If they can't draw a card, they should probably end their turn.
int canDrawCard(Game game) {
    return FALSE; // TODO: replace this with your code.
}


