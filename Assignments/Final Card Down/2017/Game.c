// The ADT implementation of Game.c
//
// Created by the group:
//  The 4th power of Taylor Mason from Billions 2
//  https://webcms3.cse.unsw.edu.au/COMP1511/17s2/groups/14476
//
// Updated on 2017-10-21

#include <err.h>
#include <sysexits.h>
#include <stdlib.h>
#include "Game.h" 
// #include "Card.h"
// Card.h is already included in Game.h



// -------- TODOs ----------
// Fix SPOTS ERRORS!
// Test for empty deck
// Clear styles on two large function!





#define TOP 0
#define NOT_FOUND -1


// =============== Typedefs and Structs ===============

// typedef for linked lists
typedef struct _moveNode *MoveNode;
typedef struct _moveList *MoveList;
typedef struct _turnNode *TurnNode;
typedef struct _turnList *TurnList;
typedef struct _cardNode *CardNode;
typedef struct _cardList *CardList;


// linked list used to store moves
typedef struct _moveNode {
    int moveNo;
    playerMove move;
    MoveNode next;
    MoveNode prev;
} moveNode;

typedef struct _moveList {
    MoveNode head;
    MoveNode tail;
} moveList;


// linked list used to store turns
typedef struct _turnNode {
    int turnNo;
    MoveList moves;
    TurnNode next;
    TurnNode prev;
} turnNode;

typedef struct _turnList {
    TurnNode head;
    TurnNode tail;
} turnList;


// linked list used to store cards
typedef struct _cardNode {
    Card card;
    CardNode next;
} cardNode;

typedef struct _cardList {
    CardNode head;
    CardNode tail;
} cardList;


// The game struct
typedef struct _game {
    // initial states values
    unsigned int numCards;
    int numOfSuit[5];
    int numOfColor[5];
    int numOfValue[16];
    int gameWinner;

    // variable for curr game states
    int currentTurn;
    unsigned int currentPlayer;
    int currentMove;
    int playedDRAW_TWO;
    int numCardsToDraw;
    
    // whether the prev player should UNO/DUO/TRIO
    // shouldClaim[0] -> UNO
    // shouldClaim[1] -> DUO
    // shouldClaim[2] -> TRIO
    //
    // if the value is 0, then shouldn't say
    // otherwise, value indicate the index of the move
    // that should be UNO/DUO/TRIO
    int shouldClaim[3];

    // indicator for whether the discard pile
    // has once been flipped and transfered back to deck
    int isFlipped;

    direction direction;
    CardList deck;
    CardList discardPile;
    CardList playerHand[NUM_PLAYERS];
    TurnList pastTurns;
} game;



// ==================== Static function prototypes ====================

// ========== Linked list relative ==========

// ===== Card List =====
static CardList newCardList();
static void destroyCardList(CardList list);

static CardNode newCardNode(Card card);
static void destroyCardNode(CardNode node);

// get a Card stored in n'th node of a card list
static Card getCard(CardList list, int i);

// serach for a Card in given card list and return its index
static int getCardIndex(CardList list, Card card);

// return the length of a card list
static int CardListLength(CardList list);

// append a card to a card list
static void appendCard(CardList list, Card card);

// retrieve the i'th CardNode from a card list
// reconnect it's prev node and next node
static CardNode retrieveCardNodeFromList(CardList list, Card card);

// prepend a given CardNode to a given card list
static void prependCardNode(CardList list, CardNode cardNode);

// append a given CardNode to a given card list
static void appendCardNode(CardList list, CardNode cardNode);

// transfer the i'th CardNode in the list "from" to the list "to"
static void transferCard(CardList from, CardList to, Card card);

// Deal n cards to given player
static void dealCards(Game game, int player, int n);


// ===== Move List =====
static MoveList newMoveList();
static void destroyMoveList(MoveList list);

static MoveNode newMoveNode(playerMove move);
static void destroyMoveNode(MoveNode node);

// return the length of a move list
static int MoveListLength(MoveList list);

// get the playerMove stored in n'th node of a move list
static playerMove getMove(MoveList list, int i);

// return the index for the first node that contains a given action
// in a move list
static int getMoveIndex(MoveList list, action a);

// append a move to a move list
static void appendMove(MoveList list, playerMove move);

// Count how many node contains the given action in a move list
static int numOfMovesInMoveList(MoveList list, action);

// return last move node in current turn
static MoveNode getLastMove(Game game);

// return previous move node relative to given move node
static MoveNode getPrevMove(MoveNode curr);

// return the move node contain the move with given action
static MoveNode getMoveByAction(MoveList list, action a);


// ===== Turn List =====
static TurnList newTurnList();
static void destroyTurnList(TurnList list);

static TurnNode newTurnNode(MoveList moves);
static void destroyTurnNode(TurnNode node);

// get the move list stored in i'th node of a turn list
static MoveList getMoveList(TurnList list, int i);

// append a move list to a turn list
static void appendTurn(TurnList list, MoveList moves);

// return the move list that store moves in current turn
static TurnNode getCurrTurn(Game g);

// return the previous turn relative to given curr turn
static TurnNode getPrevTurn(TurnNode curr);



// ========== Other Generic Functions ==========

// return next player
static int nextPlayer(Game game);

// return prev player
static int prevPlayer(Game game);

// change the direction of the game
static void changeDirection(Game game);

// play a card
static void playCard(Game game, Card card);

// return the current player's hand
static CardList currPlayerHand(Game game);

// handle call out UNO/DUO/TRIO logic
static void callOut(Game game, action);

// reset shouldClaim values to 0
static void resetClaim(Game game);

// flip the discard pile to become new deck
// except the top card on discard pile
static void flipDiscard(Game game);


// ==================== Function Implementations ====================


// Create a new game engine.
//
// This creates a game with a deck of the given size
// and the value, color, and suit of each card to be taken from
// each of the arrays in order.
//
// Your game will always have 4 players. Each player starts with a hand
// of 7 cards. The first card from the deck is given to player 0, the
// second to player 1, the third to player 2, the fourth to player 3,
// the fifth to player 0, and so on until each player has 7 cards.
Game newGame(int deckSize, value values[], color colors[], suit suits[]){
    Game game = calloc(1, sizeof(struct _game));
    // since we used calloc for game
    // all member values are set to 0
    
    // set other default values
    game->numCardsToDraw = 1;
    game->direction = CLOCKWISE;
    game->playedDRAW_TWO = FALSE;
    game->gameWinner = NOT_FINISHED;

    // Initialse linked lists
    game->deck = newCardList();
    game->discardPile = newCardList();

    int i = 0;
    while(i < NUM_PLAYERS){
        game->playerHand[i] = newCardList();
        i++;
    }

    game->pastTurns = newTurnList();
    appendTurn(game->pastTurns, newMoveList());

    // Initialise Deck with given cards
    i = 0;
    while(i < deckSize) {
        // statistics for cards
        game->numCards++;
        game->numOfSuit[suits[i]]++;
        game->numOfColor[colors[i]]++;
        game->numOfValue[values[i]]++;

        Card tempCard = newCard(values[i], colors[i], suits[i]);
        appendCard(game->deck, tempCard);
        i++;
    }

    // Deal 7 cards to each player
    i = 0;
    int j = 0;
    while(i < 7){
        j = 0;
        while(j < NUM_PLAYERS){
            dealCards(game, j, 1);
            j++;
        }
        i++;
    }

    // top card of deck moved to discard pile
    transferCard(game->deck, game->discardPile, TOP);
    Card top = topDiscard(game);
    if(cardValue(top) == DRAW_TWO){
        game->numCardsToDraw = 2;
    } else if(cardValue(top) == BACKWARDS){
        game->direction = ANTICLOCKWISE;
    } else if(cardValue(top) == ADVANCE){
        game->currentPlayer = 1;
    }
    
    return game;
}



// Destroy an existing game.
//
// This should free all existing memory used in the game including
// allocations for players and cards.
//
// Destroy every linked list and free the game struct it self
void destroyGame(Game game){
    destroyCardList(game->deck);
    destroyCardList(game->discardPile);
    int i = 0;
    while(i < NUM_PLAYERS){
        destroyCardList(game->playerHand[i]);
        i++;
    }
    destroyTurnList(game->pastTurns);

    free(game);
}



// Get the number of cards that were in the initial deck.
int numCards(Game game){
    return game->numCards;
}



// Get the number of cards in the initial deck of a particular
// suit.
int numOfSuit(Game game, suit suit){
    return game->numOfSuit[suit];
}



// Get the number of cards in the initial deck of a particular color.
int numOfColor(Game game, color color){
    return game->numOfColor[color];    
}



// Get the number of cards in the initial deck of a particular value.
int numOfValue(Game game, value value){
    return game->numOfValue[value];    
}



// Get the number of the player whose turn it is.
int currentPlayer(Game game){
    return game->currentPlayer;
}



// Get the current turn number.
//
// The turn number increases after a player ends their turn.
// The turn number should start at 0 once the game has started.
int currentTurn(Game game){
    return game->currentTurn;    
}



// Get the number of points for a given player.
// Player should be between 0 and 3.
//
// This should _not_ be called by a player.
int playerPoints(Game game, int player){
    CardNode curr = game->playerHand[player]->head;
    int points = 0;
    while(curr != NULL) {
        points += cardValue(curr->card);
        curr = curr->next;
    }
    return points;
}



// Get the current direction of play.
direction playDirection(Game game){
    return game->direction;    
}



// Get the card that is on the top of the discard pile.
Card topDiscard(Game game){
    return getCard(game->discardPile, TOP);    
}



// This function returns the number of turns that have occurred in the
// game so far including the current turn.
// When using either the turnMoves or pastMove function,
// the turn number should be less than the number of moves that this
// function returns.
// (i.e. on turn 0 of the game, this should return 1, as there has been
// 1 turn so far including the current turn; if you called pastMove you
// would need to call it on turn 0, as this is the only possible value
// less than 1.)
int numTurns(Game game){
    // turn number starts at 0, thus plus one
    return game->currentTurn + 1;    
}



// Get the number of moves that happened on a turn.
//
// A turn may consist of multiple moves such as drawing cards,
// playing cards, and ending the turn.
int turnMoves(Game game, int turn){
    MoveList moves = getMoveList(game->pastTurns, turn);
    if(moves == NULL){
        return 0;
    }
    return MoveListLength(moves);
}



// Look at a previous move from a specified turn.
playerMove pastMove(Game game, int turn, int move){
    MoveList moves = getMoveList(game->pastTurns, turn);
    return getMove(moves, move);
}



// Get the number of cards in a given player's hand.
int playerCardCount(Game game, int player){
    return CardListLength(game->playerHand[player]);
}



// Get the number of cards in the current player's hand.
int handCardCount(Game game){
    return CardListLength(currPlayerHand(game));
}



// View a card from the current player's own hand.
//
// The player should not need to free() this card,
// so you should not allocate or clone an existing card
// but give a reference to an existing card.
Card handCard(Game game, int card){
    return getCard(currPlayerHand(game), card);
}



// Check if a given move is valid.
//
// If the last player played a 2 (DRAW_TWO),
// the next player must either play a 2
// or draw 2 cards.
// Otherwise, the player must play a card that is either a ZERO
// or that has the same color, value, or suit as the card on the top
// of the discard pile.
//
// If the player plays an ADVANCE, the next player's turn is skipped.
// If the player plays a BACKWARDS, the direction of play is reversed.
// If the player plays a CONTINUE, they may play another card.
// If the player plays a DECLARE, they must also state which color
// the next player's discarded card should be.
//
// A player can only play cards from their hand.
// A player may choose to draw a card instead of discarding a card.
// A player must draw a card if they are unable to discard a card.
//
// This check should verify that:
// * The card being played is in the player's hand
// * The player has played at least one card before finishing their turn,
//   unless a draw-two was played, in which case the player may not
//   play a card, and instead must draw the appropriate number of cards.
int isValidMove(Game game, playerMove move){ 
    int isValid = FALSE;

    MoveList currTurnMoves = getCurrTurn(game)->moves;
    int hasDrawed = 
            getMoveIndex(currTurnMoves, DRAW_CARD) != NOT_FOUND;
    int hasPlayedCard = 
            getMoveIndex(currTurnMoves, PLAY_CARD) != NOT_FOUND;

    // Test validity for call out actions
    if(!hasDrawed && !hasPlayedCard && game->currentTurn != 0
            && move.action >= SAY_UNO && move.action <= SAY_TRIO){
        if(game->shouldClaim[move.action - SAY_UNO]){
            // test if this player has called out before
            if(getMoveIndex(currTurnMoves, move.action) == NOT_FOUND){
                isValid = TRUE;
            }
        }
    }

    // Draw Card test
    if(move.action == DRAW_CARD){
        if(numOfMovesInMoveList(currTurnMoves, DRAW_CARD) 
                < game->numCardsToDraw){
            isValid = TRUE;
        }
    }

    // Play Card test
    if(move.action == PLAY_CARD){
        // test if the player has drawn a card
        if(getMoveIndex(currTurnMoves, DRAW_CARD) != NOT_FOUND){
            return FALSE;
        }     

        // test if the card to play is in the player's hand
        if(getCardIndex(currPlayerHand(game), move.card) == NOT_FOUND){
            return FALSE;
        }

        // if there's a previous PLAY_CARD action on this turn
        // then that card must be CONTINUE
        if(getMoveIndex(currTurnMoves, PLAY_CARD) != NOT_FOUND){
            // most recently move is:
            MoveNode lastMove = getLastMove(game);
            // if prev move is a SAY_UNO/DUO/TRIO
            // then the actually move for player card is another one before
            while(lastMove->move.action != PLAY_CARD){
                lastMove = getPrevMove(lastMove);
            }
            
            Card prevCard = lastMove->move.card;
            // if the player has played a card before this move
            // and the prev card played is not continue
            // then it's invalid
            if(cardValue(prevCard) != CONTINUE){
                return FALSE;
            }
        }
        
        Card prevCard = topDiscard(game);

        // if Card on top of discard pile is DRAW_TWO
        // the first card being moved to discard pile from deck
        // WILL have effect
        if(cardValue(prevCard) == DRAW_TWO){
            if(game->currentTurn == 0){
                if(cardValue(move.card) == DRAW_TWO){
                    return TRUE;
                }
                return FALSE;
            }

            // test if this DRAW_TWO is played by prev player
            // or prev player has alredy drew 2 cards or more
            MoveList prevTurnMoves = getPrevTurn(getCurrTurn(game))->moves;
            // the prev player played a card, then this DRAW_TWO
            // must be played by prev player
            if(getMoveIndex(prevTurnMoves, PLAY_CARD) != NOT_FOUND){
                if(cardValue(move.card) == DRAW_TWO){
                    return TRUE;
                }
                return FALSE;
            }
        }
        
        // default color is the color of the card on top of discard pile
        // however, if a declare was played, color changes
        color prevColor = cardColor(prevCard);

        // if Card on top of discard pile is DECLARE
        // and the card is not the first card of discard pile 
        // that is from deck
        if(cardValue(prevCard) == DECLARE && 
                CardListLength(game->discardPile) != 1 && !game->isFlipped){

            TurnNode prevTurn = getPrevTurn(getCurrTurn(game));
            // test if there's a play card move in prev turn
            // if not, then the card is being played by prev prev player
            // loop to find which player played the card
            MoveNode play = getMoveByAction(prevTurn->moves, PLAY_CARD);
            while(play == NULL){
                prevTurn = getPrevTurn(prevTurn);
                play = getMoveByAction(prevTurn->moves, PLAY_CARD);
            }

            // prev player may discard a CONTINUE first then DECLARE
            // loop to find the move that played DECALRE
            // && to prevent dereferencing a Card with NULL
            while(play->move.action == PLAY_CARD 
                    && cardValue(play->move.card) != DECLARE){

                play = play->next;
            }
            
            prevColor = play->move.nextColor;
        }

        // Player can discard NULL at any time
        if(cardValue(move.card) == ZERO){
            isValid =  TRUE;

        // Otherwise, value or suit or color must match
        } else if(cardValue(move.card) == cardValue(prevCard)){
            isValid =  TRUE;
        } else if(cardSuit(move.card) == cardSuit(prevCard)){
            isValid =  TRUE;
        } else if(cardColor(move.card) == prevColor){
            isValid =  TRUE;
        }
    }

    // End Turn test
    if(move.action == END_TURN){
        if(hasPlayedCard){
            isValid = TRUE;

        // if the played has not played a card in this turn
        // then he/she must have drew appropriate number of cards
        // to be able to end the turn
        } else{
            int cardDrawn = numOfMovesInMoveList(currTurnMoves, DRAW_CARD);
            if(cardDrawn == game->numCardsToDraw){
                isValid = TRUE;
            }
            
        }
    }

    // SAY UNO/DUO/TRIO test
    if(hasPlayedCard && move.action >= SAY_UNO && move.action <= SAY_TRIO){
        int playerHandCount = handCardCount(game);
        if(move.action == SAY_UNO){
            if(playerHandCount == 1){
                isValid = TRUE;
            }
        } else if(move.action == SAY_DUO){
            if(playerHandCount == 2){
                isValid = TRUE;
            }
        } else if(move.action == SAY_TRIO){
            if(playerHandCount == 3){
                isValid = TRUE;
            }
        }
    }

    return isValid;
}

// Play the given action for the current player
//
// If the player makes the END_TURN move, their turn ends,
// and it becomes the turn of the next player.
//
// This should _not_ be called by the player AI.
void playMove(Game game, playerMove move){
    if(gameWinner(game) == NOT_FINISHED && isValidMove(game, move)){
        MoveList currTurnMoves = getCurrTurn(game)->moves;
        int hasPlayedCard = 
                getMoveIndex(currTurnMoves, PLAY_CARD) != NOT_FOUND;
        // Call out UNO/DUO/TRIO
        // if just claim, do nothing
        if(move.action >= SAY_UNO && move.action <= SAY_TRIO 
                && !hasPlayedCard){
            callOut(game, move.action);
        }

        // Play Card
        if(move.action == PLAY_CARD){
            // if the player is playing the first card in this turn
            if(getMoveIndex(currTurnMoves, PLAY_CARD) == NOT_FOUND){
                game->shouldClaim[0] = 0;

            }

            playCard(game, move.card);

            // if the player should say UNO/DUO/TRIO
            // in next move
            int leftCards = CardListLength(currPlayerHand(game));
            if(leftCards >= 1 && leftCards <= 3){
                // left 1 -> shouldClaim[0] UNO
                // left 2 -> shouldClaim[1] DUO
                // left 3 -> shouldClaim[2] TRIO
                game->shouldClaim[leftCards - 1] = game->currentMove + 1;
            } else if(leftCards == 0){
                game->gameWinner = currentPlayer(game);
            }
        }

        // Draw Card
        if(move.action == DRAW_CARD){
            resetClaim(game);
            dealCards(game, currentPlayer(game), 1);
        }

        // store this move into pastTurns
        appendMove(currTurnMoves, move);

        game->currentMove++;

        // END_TURN
        if(move.action == END_TURN){
            if(hasPlayedCard){
                // traverse back to find last move that is PLAY_CARD
                // as player may discard multiple CONTINUE first
                MoveNode lastPlay = getLastMove(game);
                while(lastPlay->move.action != PLAY_CARD){
                    lastPlay = getPrevMove(lastPlay);
                }

                Card lastCardPlayed = lastPlay->move.card;
                // ADVANCE must be played last 
                // if multiple cards have been played
                if(cardValue(lastCardPlayed) == ADVANCE){
                    // set curr player to next
                    // below code will set curr player to further next
                    game->currentPlayer = nextPlayer(game);
                }
            }

            // reset values
            if(!game->playedDRAW_TWO){
                game->numCardsToDraw = 1;
            }
            game->playedDRAW_TWO = FALSE;                
            game->currentTurn++;
            appendTurn(game->pastTurns, newMoveList());
            game->currentMove = 0;
            game->currentPlayer = nextPlayer(game);
        }
    } else if(gameWinner(game) != NOT_FINISHED){
        err(EX_OSERR, "Trying to make a move after game is finished");
    } else{
        err(EX_OSERR, "Invalid move");
    }
}

// Check the game winner.
//
// Returns NOT_FINISHED if the game has not yet finished,
// 0-3, representing which player has won the game, or
// NO_WINNER if the game has ended but there was no winner.
int gameWinner(Game game){
    return game->gameWinner;
}



// ==================== Static function implementations ====================

// ========== Linked list relative ==========

// ===== Card List =====
static CardList newCardList(){
    CardList new = calloc(1, sizeof(struct _cardList));
    if(new == NULL){
        err(EX_OSERR, "Could not allocate memory");
    }
    // no need to initialise head to NULL
    // as we used calloc
    return new;
}

static void destroyCardList(CardList list){
    CardNode curr = list->head;
    CardNode temp;
    while(curr != NULL){
        temp = curr->next;
        destroyCardNode(curr);
        curr = temp;
    }
    free(list);
}

static CardNode newCardNode(Card card){
    CardNode new = calloc(1, sizeof(struct _cardNode));
    if(new == NULL){
        err(EX_OSERR, "Could not allocate memory");
    }
    new->card = card;
    return new;
}

static void destroyCardNode(CardNode node){
    if(node->card != NULL){
        destroyCard(node->card);
    }
    free(node);
}

// get a Card stored in n'th node of a card list
static Card getCard(CardList list, int i){
    CardNode curr = list->head;
    int index = 0;
    while(curr != NULL){
        if(index == i){
            return curr->card;
        }
        index++;
        curr = curr->next;
    }
    return NULL;
}

// serach for a Card in given card list and return its index
static int getCardIndex(CardList list, Card card){
    CardNode curr = list->head;
    int index = 0;
    while(curr != NULL){
        if(curr->card == card){
            return index;
        }
        index++;
        curr = curr->next;
    }
    return NOT_FOUND;
}

// return the length of a card list
static int CardListLength(CardList list){
    int length = 0;
    CardNode curr = list->head;
    while(curr != NULL){
        length++;
        curr = curr->next;
    }
    return length;
}

static void appendCard(CardList list, Card card){
    // empty list
    if(list->tail == NULL){
        list->head = newCardNode(card);
        list->tail = list->head;
        return;
    }

    CardNode last = list->tail;
    last->next = newCardNode(card);
    list->tail = last->next;
}

// retrieve the CardNode contains card from a card list
// reconnect it's prev node and next node
static CardNode retrieveCardNodeFromList(CardList list, Card card){
    CardNode curr = list->head;

    // if trying to retrieve node from empty list
    if(curr == NULL){
        err(EX_OSERR, "Trying retrieve node from an empty list");
    }

    // if retrieve first card
    if(card == TOP){
        list->head = curr->next;
        curr->next = NULL;
        return curr;
    }

    CardNode prev = NULL;
    while(curr != NULL && curr->card != card){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        err(EX_OSERR, "Trying to get card that is not in the card list");
    }

    // retrieve the first node
    if(prev == NULL){
        list->head = curr->next;
        if(list->head == NULL){
            list->tail = NULL;
        }
        curr->next = NULL;
        return curr;
    }

    // retrieve the last node
    if(curr->next == NULL){
        list->tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    return curr;
}

// prepend a given cardNode to a given card list
static void prependCardNode(CardList list, CardNode cardNode){
    cardNode->next = list->head;
    list->head = cardNode;
    if(cardNode->next == NULL){
        list->tail = cardNode;
    }
}

// append a given CardNode to a given card list
static void appendCardNode(CardList list, CardNode cardNode){
    cardNode->next = NULL;
    // if the list is empty
    if(list->tail == NULL){
        list->head = cardNode;
        list->tail = cardNode;
        return;
    }

    list->tail->next = cardNode;
    list->tail = cardNode;
}

// transfer a card of index of i in the "from" list 
// to the head of the "to" list
static void transferCard(CardList from, CardList to, Card card){
    CardNode cardNode = retrieveCardNodeFromList(from, card);
    prependCardNode(to, cardNode);

}

// Deal n cards to given player
static void dealCards(Game game, int player, int n){
    int i = 0;
    while(i < n){
        if(CardListLength(game->deck) == 0){
            flipDiscard(game);
            game->isFlipped = TRUE;
            if(gameWinner(game) == NO_WINNER){
                return;
            }
        }
        CardNode cardNode = retrieveCardNodeFromList(game->deck, TOP);
        prependCardNode(game->playerHand[player], cardNode);
        i++;
    }
}



// ===== Move List =====
static MoveList newMoveList(){
    MoveList new = calloc(1, sizeof(struct _moveList));
    return new;
}

static void destroyMoveList(MoveList list){
    MoveNode curr = list->head;
    MoveNode temp;
    while(curr != NULL){
        temp = curr->next;
        destroyMoveNode(curr);
        curr = temp;
    }
    free(list);
}

static MoveNode newMoveNode(playerMove move){
    MoveNode new = calloc(1, sizeof(struct _moveNode));
    new->move = move;
    return new;
}

static void destroyMoveNode(MoveNode node){
    free(node);
}

// return the length of a move list
static int MoveListLength(MoveList list){
    int length = 0;
    MoveNode curr = list->head;
    while(curr != NULL){
        length++;
        curr = curr->next;
    }    
    return length;
}

// get the playerMove stored in n'th node of a move list
static playerMove getMove(MoveList list, int i){
    int index = 0;
    MoveNode curr = list->head;
    while(curr != NULL) {
        if(index == i){
            return curr->move;   
        }
        index++;
        curr = curr->next;
    }
    // index out of range
    // err handling
    err(EX_OSERR, "Trying to get a move outside move list boundry");

}

// return the index for the first node that contains a given action 
// in a move list
static int getMoveIndex(MoveList list, action a){
    int i = 0;
    MoveNode curr = list->head;
    while(curr != NULL){
        if(curr->move.action == a){
            return i;
        }
        i++;
        curr = curr->next;
    }
    return NOT_FOUND;
}

// append a move to a move list
static void appendMove(MoveList list, playerMove move){
    // if the list is empty
    if(list->tail == NULL){
        list->tail = newMoveNode(move);
        list->head = list->tail;
        return;
    }

    MoveNode last = list->tail;
    last->next = newMoveNode(move);
    list->tail = last->next;
    list->tail->prev = last;
}

// Count how many node contains the given action in a move list
static int numOfMovesInMoveList(MoveList list, action action){
    MoveNode curr = list->head;
    int count = 0;
    while(curr != NULL){
        if(curr->move.action == action){
            count++;
        }
        curr = curr->next;
    }
    return count;
}

// return last move node in current turn
static MoveNode getLastMove(Game game){
    return getCurrTurn(game)->moves->tail;
}

// return previous move node relative to given move node
static MoveNode getPrevMove(MoveNode curr){
    return curr->prev;
}

// return the first move node contain the move with given action
// if not found any, return NULL
static MoveNode getMoveByAction(MoveList list, action a){
    MoveNode curr = list->head;
    while(curr != NULL){
        if(curr->move.action == a){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}



// ===== Turn List =====
static TurnList newTurnList(){
    TurnList new = calloc(1, sizeof(struct _turnList));
    return new;
}

static void destroyTurnList(TurnList list){
    TurnNode curr = list->head;
    TurnNode temp;
    while(curr != NULL){
        destroyMoveList(curr->moves);
        temp = curr->next;
        destroyTurnNode(curr);
        curr = temp;
    }
    free(list);
}

static TurnNode newTurnNode(MoveList moves){
    TurnNode new = calloc(1, sizeof(struct _turnNode));
    new->moves = moves;
    return new;
}

static void destroyTurnNode(TurnNode node){
    free(node);
}

// return the given index of MoveList stored in
// the given TurnList
// return NULL if cannot reach the given index
static MoveList getMoveList(TurnList list, int i){
    int index = 0;
    TurnNode curr = list->head;
    while(curr != NULL) {
        if(index == i){
            return curr->moves;   
        }
        index++;
        curr = curr->next;
    }
    err(EX_OSERR, "Cannot reach given index in turn list");
}

// append a move list to a turn list
static void appendTurn(TurnList list, MoveList moves){
    // if the list is empty
    if(list->tail == NULL){
        list->tail = newTurnNode(moves);
        list->head = list->tail;
        return;
    }

    TurnNode last = list->tail;
    last->next = newTurnNode(moves);
    list->tail = last->next;
    list->tail->prev = last;
}

// return the move list that store moves in current turn
// i.e. the move list stored in the last node of pastTurns
static TurnNode getCurrTurn(Game g){
    return g->pastTurns->tail;
}

// return the previous turn relative to given curr turn
static TurnNode getPrevTurn(TurnNode curr){
    return curr->prev;
}


// ========== Other Generic Functions ==========

// get next n'th player relative to current player
// this function accept negative n value for get prev n'th player
static unsigned int getNextNthPlayer(Game game, int n){
    // consider current direction
    unsigned int player;
    if(game->direction == CLOCKWISE){
        player = (game->currentPlayer + n) % NUM_PLAYERS;
    } else {
        player = (game->currentPlayer - n) % NUM_PLAYERS;
    }
    return player;
}

// return next player
static int nextPlayer(Game game){
    if(game->direction == CLOCKWISE){
        return (game->currentPlayer + 1) % NUM_PLAYERS;
    } else {
        // prevent negative int
        return (game->currentPlayer - 1 + NUM_PLAYERS) % NUM_PLAYERS;
    }
}

// return prev player
static int prevPlayer(Game game){
    if(game->direction == CLOCKWISE){
        // prevent negative int
        return (game->currentPlayer - 1 + NUM_PLAYERS) % NUM_PLAYERS;
    } else {
        return (game->currentPlayer + 1) % NUM_PLAYERS;
    }
}

// change the direction of the game
static void changeDirection(Game game){
    // direction is either CLOCKWISE (0 -> FALSE)
    // or ANTICLOCKWISE (1 -> TRUE)
    game->direction = !(game->direction);
}

// play a card
static void playCard(Game game, Card card){
    // If the card being played is BACKWARDS
    if(cardValue(card) == BACKWARDS){
        changeDirection(game);

    // If the card being played is DRAW TWO
    } else if(cardValue(card) == DRAW_TWO){
        game->playedDRAW_TWO = TRUE;
        if(game->numCardsToDraw == 1){
            game->numCardsToDraw = 2;
        } else {
            game->numCardsToDraw += 2;
        }
    }

    transferCard(currPlayerHand(game), game->discardPile, card);
}

// return the current player's hand
static CardList currPlayerHand(Game game){
    return game->playerHand[game->currentPlayer];
}

// handle call out UNO/DUO/TRIO logic
static void callOut(Game game, action action){
    // if this player haven't played a card
    // then he/she must be calling out
    MoveList prevMoves = getPrevTurn(getCurrTurn(game))->moves;
    
    int prevClaimed = 
            getMove(
                prevMoves,
                game->shouldClaim[action - SAY_UNO]
            ).action == action;
    
    if(!prevClaimed && game->shouldClaim[action - SAY_UNO]){
        dealCards(game, prevPlayer(game), 2);
    } else{
        dealCards(game, currentPlayer(game), 4);
    }
}

// reset shouldClaim values to 0
static void resetClaim(Game game){
    game->shouldClaim[0] = 0;
    game->shouldClaim[1] = 0;
    game->shouldClaim[2] = 0;
}

// flip the discard pile to become new deck
// except the top card on discard pile
// Discard pile:
// card1(top) -> card2 -> card3 -> x
//
// Deck after:
// card3 -> card2 -> x
static void flipDiscard(Game game){
    if(CardListLength(game->discardPile) != 1){
        game->gameWinner = NO_WINNER;
    }
    // let curr be second node of discard pile
    CardNode curr = game->discardPile->head->next;
    // break the list, remain the first node only
    game->discardPile->head->next = NULL;

    while(curr != NULL){
        prependCardNode(game->deck, curr);
        curr = curr->next;
    }
    
}