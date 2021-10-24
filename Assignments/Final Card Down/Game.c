// COMP1511 (2018S2)
// Assignment 2: Final Card Down
// Game.c
// 
// Dan Nguyen (z5206032)
// 2018/09/22 - 2018/10/26
// 
// Dean Wunder (thu11-brass)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Game.h"

#define PLAYER_ZERO 0
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define PLAYER_THREE 3
#define STARTING_HAND_SIZE 7

// Typedef for struct pointers
typedef struct _cardNode *CardNode;
typedef struct _cardList *CardList;

// Struct for linked list of cards
typedef struct _cardNode {
    Card        card;
    CardNode    next;
} cardNode;

// Struct for a deck of cards
typedef struct _cardList {
    int         listSize;
    CardNode    cardNodeHead;
    CardNode    cardNodeCurrent;
} cardList;

// Struct to keep the state of the game
struct _game {
    
    // Information about decks and most recent played card
    CardList    players[4];
    CardList    discardPile;
    CardList    drawPile;
    Card        playedCard;
    
    // Information about the game state
    int         gameWinner;
    int         currentPlayer;
    int         currentTurn;
    int         currentMove;
    int         hasPlayed;
    int         hasDrawn;
    int         activeDrawTwos;
    int         hasDrawnDrawTwos;
    playerMove  move;
    
    // Information about the given deck
    int         deckSize;
    value       *values;
    color       *colors;
    suit        *suits;
};

//==============================================================================
//                            Function Prototypes
//==============================================================================

// General Helper Functions
static void push(CardNode head, Card card);
static void pop(CardNode head);
static void removeCard(CardNode head, Card card);
static void cardNodeReverse(CardNode head);
static Card getCard(CardNode current, int n);


// Update Helper Functions // could be helper function for playMove
static void updatePlayedCard(Game game);
static void updateCurrentPlayer(Game game);
static void updateCurrentTurn(Game game);
static void updateCurrentMove(Game game);
static void resetCurrentMove(Game game);
static void updateHasPlayed(Game game);
static void updateHasDrawn(Game game);
static void updateActiveDrawTwos(Game game);
static void updateHasDrawnDrawTwos(Game game);
static void updateCardListSize(CardList list);

// Helper Functions for newGame
static void gameInformation(Game game, int deckSize, value values[],
    color colors[], suit suits[]);
static void dealCards(Game game);
static int dealCardsPlayerHands(Game game, int i);
static int dealCardsDiscardPile(Game game, int i);
static int dealCardsDrawPile(Game game, int i);
static CardList cardListMemory(void);
static CardNode cardNodeMemory(void);

// Helper Functions for destroyGame
static void destroyGameInformation(Game game);
static void destroyCardList(CardList head);
static void destroyCardNode(CardNode head);


//==============================================================================
//                          'Game.h' Implementation
//==============================================================================


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
Game newGame(int deckSize, value values[], color colors[], suit suits[]) {
    
    // Allocate memory for game struct
    Game game = calloc(1, sizeof(struct _game));
    
    // Checking game memory allocation
    if (game == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(1);
    }
    
    // Store information into the game struct
    gameInformation(game, deckSize, values, colors, suits);
    
    // Distribute cards to player hands, discard pile, draw pile
    dealCards(game);
    
    // Update some game information
    updatePlayedCard(game);
    updateActiveDrawTwos(game);
    updateCardListSize(game->discardPile);
    updateCardListSize(game->drawPile);
    
    for (int p = 0; p < NUM_PLAYERS; p++) {
        updateCardListSize(game->players[p]);
    }
    
    return game;
}


// Destroy an existing game.
//
// This should free all existing memory used in the game including
// allocations for players and cards.
void destroyGame(Game game) {
    
    // make sure there exists a game
    assert(game != NULL);
    
    // free given arrays that are stored in game struct
    destroyGameInformation(game);
    
    // destroy player hands
    for (int p = 0; p < NUM_PLAYERS; p++) {
        assert(game->players[p] != NULL);
        destroyCardList(game->players[p]);
    }
    
    // destroy discard pile
    assert(game->discardPile != NULL);
    destroyCardList(game->discardPile);
    
    // destroy draw pile
    assert(game->drawPile != NULL);
    destroyCardList(game->drawPile);
    
    // destroy the game
    free(game);
}


// The following functions can be used by players to discover
// information about the state of the game.

// Get the number of cards that were in the initial deck.
int numCards(Game game) {
    
    // Since deckSize is stored as a variable in the game struct
    return game->deckSize;
}


// Get the number of cards in the initial deck of a particular
// suit.
int numOfSuit(Game game, suit suit) {
    
    int suitCount = 0;
    
    // i is a counter through the deck
    for (int i = 0; i < game->deckSize; i++) {
        
        // Utilises stored information about initial deck
        if (game->suits[i] == suit) {
            suitCount++;
        }
    }
    
    return suitCount;
}


// Get the number of cards in the initial deck of a particular color.
int numOfColor(Game game, color color) {
    
    int colorCount = 0;
    
    // i is a counter through the deck
    for (int i = 0; i < game->deckSize; i++) {
        
        // Utilises stored information about initial deck
        if (game->colors[i] == color) {
            colorCount++;
        }
    }
    
    return colorCount;
}


// Get the number of cards in the initial deck of a particular value.
int numOfValue(Game game, value value) {
    
    int valueCount = 0;
    
    // i is a counter through the deck
    for (int i = 0; i < game->deckSize; i++) {
        
        // Utilises stored information about initial deck
        if (game->values[i] == value) {
            valueCount++;
        }
    }
    
    return valueCount;
}


// Get the number of the player whose turn it is.
int currentPlayer(Game game) {
    
    // Since currentPlayer is stored in the game struct
    return game->currentPlayer;
}


// Get the current turn number.
//
// The turn number increases after a player ends their turn.
// The turn number should start at 0 once the game has started.
int currentTurn(Game game) {
    
    // Since currentTurn is stored in the game struct
    return game->currentTurn;
}


// Get the card that is on the top of the discard pile.
Card topDiscard(Game game) {
    
    return game->discardPile->cardNodeHead->card;
}


// This function returns the number of turns that have occurred in the
// game so far including the current turn.
// (i.e. on turn 0 of the game, this should return 1, as there has been
//       1 turn so far including the current turn.)
int numTurns(Game game) {
    
    // Turns so far including turn 0
    return game->currentTurn + 1;
}


// Get the number of moves (actions) that happened on the current turn.
//
// A turn may consist of multiple moves (actions) such as drawing cards,
// playing cards, and ending the turn.
int currentTurnMoves(Game game) {
    
    return game->currentMove;
}


// Get the number of consecutive cards with value "2" at the top of the 
// discard pile.
// If the value of the top of the discard pile is not "2", the function will 
// return zero. 
int getNumberOfTwoCardsAtTop(Game game) {
    
    int numberOfTwoCardsAtTop = 0;
    
    CardNode current = game->discardPile->cardNodeHead;
    
    while (current != NULL && cardValue(current->card) == 2) {
        
        numberOfTwoCardsAtTop++;
        
        current = current->next;
    }
    
    return numberOfTwoCardsAtTop;
}


// If the last player played a card with value "D" and declared a color, 
// the following function returns that declared color as the current color. 
// For all other cases, the function returns the color of the card at 
// the top of the discard pile. 
int getCurrentColor(Game game) {
    
    return cardColor(game->playedCard);
}


// The function returns the player who played the previous turn.
// For example, if player 1 plays "A" in turn 12, player 3 will 
// play next turn 13. During turn 13, the following function will 
// return 1 (for player 1 who played the previous turn 12).
// If the current turn is the first turn (turn 0), the function should 
// return -1.
int getPreviousTurnPlayer(Game game) {
    
    int player;
    
    if (game->currentTurn == 0) {
        player = -1;
    }
    
    player = (currentPlayer(game) - 1) % NUM_PLAYERS;
    
    return player;
}


// Get the turn number that played the card that is on the top of 
// the discard pile.
int getTopDiscardTurnNumber(Game game) {
   
    if (game->currentTurn == 0) {
        return -1;
    }
    
    
    return game->currentTurn;
}


// Get the number of "active" cards with value "2" at the top of the 
// discard pile. 
// For example, say in turn-5 player-1 plays "2", as a result of this, 
// the function should return 1. Let's say in turn-6 player-2 
// draws two cards and is unable to play a card. 
// At the start of turn-7, the function should return zero.
// If the value of the top of the discard pile is not "2", the function
// should return zero.
int getActiveDrawTwos(Game game) {

    return game->activeDrawTwos;
}


// Get the number of cards in the current player's hand.
int handCardCount(Game game) {
    
    return game->players[game->currentPlayer]->listSize;
}


// View a card from the current player's own hand.
//
// The player should not need to free() this card,
// so you should not allocate or clone an existing card
// but give a reference to an existing card.
// 
// If no such card exists, the function returns NULL.
Card handCard(Game game, int card) {
    
    CardNode current = game->players[game->currentPlayer]->cardNodeHead;
    
    for (int i = 1; i < handCardCount(game); i++) {
        if (i == card) {
            break;
        }
        
        current = current->next; // IS THIS RIGHT
    }
    
    return current->card;
}


// Check if a given move is valid.
//
// If the last player played a 2 (DRAW_TWO),
// the next player must either play a 2
// or draw 2 cards.

// If the last player has NOT played a 2, 
// the player must play a card that is either a ZERO
// or that has the same color, value, or suit as the card on the top
// of the discard pile (adjust color for a case where the 
//   previous player has played a "D").
//
// If the player plays an "A", the next player's turn is skipped.
// If the player plays a "D", they must also state which color
// the next player's discarded card should be.
//
// A player can only play cards from their hand.
// A player may choose to draw a card instead of discarding a card.
// A player must draw a card if they are unable to discard a card.
//
// This check should verify that:
// * If a card is played, that card is from the player's hand, and matches 
//   the top card on the discard pile (adjust color for a case where the 
//   previous player has played a "D"), AND the player has not already
//   played a card during their turn.
// * If a DRAW_TWO was played, the player drew the appropriate number of cards.
// * If the player draws a card, either they have not yet drawn a card
//   during this turn OR a DRAW_TWO was played in the previous turn,
//   AND the player has not yet drawn the required number of cards.
//
// * The player has either played at least one card, or drawn at least
//   one card, before playing the END_TURN action.   
int isValidMove(Game game, playerMove move) {
    
    // assume the valid move is false until proven true by tests
    int isValid = FALSE;
    
    if (move.action == DRAW_CARD) {
        // draw card test
        
        if (getActiveDrawTwos(game) > 0) {
            // if draw Twos is active
            
            if (game->hasDrawnDrawTwos > 0) {
                // if number of cards required to be drawn is greater than 0
                
                isValid = TRUE;
            }
        }
    } else if (move.action == PLAY_CARD) {
        // play card test
        
        if (game->hasDrawn == TRUE) {
            // player cannot play a card if player has drawn a card
            // then isValid = FALSE
            
        } else if (cardValue(game->playedCard) == cardValue(move.card)) {
            // if value of card to play matches value of played card
            
            isValid = TRUE;
            
        } else if (cardColor(game->playedCard) == cardValue(move.card)) {
            // if colour of card to play matches colour of played card
            
            isValid = TRUE;
            
        } else if (cardSuit(game->playedCard) == cardValue(move.card)) {
            // if suit of card to play matches suit of played card
            
            isValid = TRUE;
            
        } else if (cardValue(game->playedCard) == ZERO) {
            // if value of card is zero
            
            isValid = TRUE;
        }
    } else if (move.action == END_TURN) {
        // end turn test
        
        // player must have played or drew a card
        if (game->hasDrawn == TRUE || game->hasPlayed == TRUE) {
            
            isValid = TRUE;
        }
    }
    
    return isValid;
}


// ---------------------------------------------------------
// The following functions must NOT be called by a player
// You can use the following functions to test your Game ADT 
// ---------------------------------------------------------

// Play the given action for the current player
//
// If the player makes the END_TURN move, their turn ends,
// and it becomes the turn of the next player.
//
// This should _not_ be called by the player AI.
void playMove(Game game, playerMove move) {
    
    // player's turn is skipped
    // if playMove is not called in decideMove and decideMove is not called in
    // playMove then where/ how is the player's turn skipped
    if (cardValue(game->playedCard) == A) {
        move.action = END_TURN;
        return;
    }
    
    if (move.action == PLAY_CARD) {
        // player is playing a card!
        
        // put the card into the discard pile from the player hand
        push(game->discardPile->cardNodeHead, move.card);
        
        // removes the card from the player hand
        removeCard(game->players[game->currentPlayer]->cardNodeHead, move.card);
        
        // card has been played and is updated in game struct
        updatePlayedCard(game);
        updateHasPlayed(game);
        updateCurrentMove(game);
        
        // if the played card has value 2
        if (cardValue(game->playedCard) == 2) {
            game->activeDrawTwos = 0;
        }
    } else if (move.action == DRAW_CARD) {
        // player is drawing a card!
        
        // put the card into the player hand from the draw pile
        push(game->players[game->currentPlayer]->cardNodeHead, move.card);
        
        // removes the card from the draw pile
        pop(game->drawPile->cardNodeHead);
        
        // player has drawn a card
        updateHasDrawn(game);
        updateCurrentMove(game);
        
        // if draw twos is active then card drawn was a result of that
        if (getActiveDrawTwos(game) > 0) {
            updateHasDrawnDrawTwos(game);
        }
        
    } else if (move.action == END_TURN) {
        // player is ending their turn!
        
        // Updating game state
        updateCurrentPlayer(game);
        updateCurrentTurn(game);
        
        // Resetting turn states for the next player
        resetCurrentMove(game);
        updateHasPlayed(game);
        updateHasDrawn(game);
    }
    
    updateCardListSize(game->players[game->currentPlayer]);
}


// Check the game winner.
//
// Returns NOT_FINISHED if the game has not yet finished,
// 0-3, representing which player has won the game, or
// NO_WINNER if the game has ended but there was no winner.
int gameWinner(Game game) {
    
    return game->gameWinner;
}


// Get nth card from the deck, n=0 means top card from deck
// If no such card exists, the function returns NULL.
Card getDeckCard (Game game, int n) {
    
    return getCard(game->drawPile->cardNodeHead, n);
}


// Get nth card from the discard pile, n=0 means top card from discard pile
// If no such card exists, the function returns NULL.
Card getDiscardPileCard (Game game, int n) {
    
    return getCard(game->discardPile->cardNodeHead, n);
}


// Get nth card from the hand of a player p.
// If no such card exists, the function returns NULL.
Card getHandCard (Game game, int player, int n) {
    
    return getCard(game->players[player]->cardNodeHead, n);
}

// Get the number of cards in a given player's hand.
int playerCardCount(Game game, int player) {
    
    int cardCount = 0;
    
    CardNode current = game->players[player]->cardNodeHead;
    
    while (current != NULL) {
        
        // increase the card count
        cardCount++;
        
        // go to next card
        current = current->next;
    }
    
    game->players[player]->listSize = cardCount;
    
    return cardCount;
}


// Get the number of points for a given player.
// Player should be between 0 and 3.
//
// The number of points is always equal to
// the sum of the values for all the cards in a player's hand.
// This should return this number of points at any point in the game.
int playerPoints(Game game, int player) {
    
    int pointCount = 0;
    
    CardNode current = game->players[player]->cardNodeHead;
    
    while (current != NULL) {
        
        // Adding value of the card to the count
        pointCount += cardValue(current->card);
        
        // go to next card
        current = current->next;
    }
    
    return pointCount;
}


// =============================================================================
//                              Helper Functions
// =============================================================================


// Adds a card to the end of a card list
static void push(CardNode head, Card card) {
    
    // If head is an empty card node
    if (head->card == NULL) {
        head->card = card;
        head->next = NULL;
        
        return;
    }
    
    CardNode current = head;
    
    // Traverse the linked list to get to the end of the list
    while (current->next != NULL) {
        
        current = current->next;
    }
    
    current->next = cardNodeMemory();
    current->next->card = card;
    current->next->next = NULL;
}


// Removes a card from the end of a card list
static void pop(CardNode head) {
    
    assert(head != NULL);
    
    CardNode current = head;
    CardNode previous = current;
    
    while (current->next != NULL) {
        
        previous = current;
        current = current->next;
    }
    
    previous->next = NULL;
    free(current);
}


// Removes a particular card from a deck
static void removeCard(CardNode head, Card card) {
    
    assert(head != NULL);
    
    CardNode current = head;
    CardNode temporary;
    
    // if first card in list is the card to be removed
    if (current->card == card) {
        temporary = current->next;
        free(current);
        current = temporary;
        
        return;
    }
    
    // for any other card in the list to remove
    while (current->next != NULL) {
    
        if (current->next->card == card) {
            temporary = current->next->next;
            free(current->next);
            current->next = temporary;
            
            return;
        }
        
        current = current->next;
    }
}

// Reverses the order of card nodes
static void cardNodeReverse(CardNode head) {
    
    CardNode current = head;
    CardNode swap = NULL;
    CardNode previous = NULL;
    
    // if list is empty
    if (head == NULL) {
        return;
    }
    
    while (current != NULL) {
        swap = current->next;
        current->next = previous;
        previous = current;
        current = swap;
    }
    
    head = previous;
}


// Gets a particular card from any cardNode by its position
static Card getCard(CardNode head, int n) {
    
    assert(head != NULL);
    
    CardNode current = head;
    
    int i = 0;
    while (current != NULL) {
        if (i == n) {
            assert(current->card != NULL);
            return current->card;
        }
        
        current = current->next;
        i++;
    }
    
    return NULL;
}


// Update the most recent played card in the game struct
static void updatePlayedCard(Game game) {
    
    CardNode current = game->discardPile->cardNodeHead;
    
    while (current->next != NULL) {
        
        current = current->next;
    }
    
    game->playedCard = current->card;
}


// Update the current player in the game struct
static void updateCurrentPlayer(Game game) {
    
    game->currentPlayer = (game->currentPlayer + 1) % NUM_PLAYERS;
}


// Update the current turn in the game struct
static void updateCurrentTurn(Game game) {
    
    game->currentTurn++;
}


// Update the current move in the game struct
static void updateCurrentMove(Game game) {
    
    game->currentMove++;
}


// Resets current move to 0
// Should only be called when current player ends their turn
static void resetCurrentMove(Game game) {
    
    game->currentMove = 0;
}


// Updates whether the player has played a card
// Function must be called when player is playing a card or ending a turn
static void updateHasPlayed(Game game) {
    
    if (game->currentMove == 0) {
       game->hasPlayed = FALSE;
        
    } else {
        game->hasPlayed = TRUE;
    }
}


// Updates whether the player has drawn a card
// Function must be called when player is playing a card or ending a turn
static void updateHasDrawn(Game game) {
    
    if (game->currentMove == 0) {
       game->hasDrawn = FALSE;
        
    } else {
        game->hasDrawn = TRUE;
    }
}


// Update the number of active draw two cards in the game struct
static void updateActiveDrawTwos(Game game) {
    
    // if first card that is played is 2
    if (cardValue(game->playedCard) == 2) {
        game->activeDrawTwos++;
        
    } else {
        game->activeDrawTwos = 0;
    }
}


// Update the number of cards drawn as a result of activeTwos
static void updateHasDrawnDrawTwos(Game game) {
    
    if (game->hasDrawnDrawTwos > 0) {
        
        game->hasDrawnDrawTwos--;
        
        if (game->hasDrawnDrawTwos == 0) {
            game->activeDrawTwos = 0;
        }
    }
}


// Update the size of any card list in the card struct
static void updateCardListSize(CardList list) {
    
    CardNode current = list->cardNodeHead;
    
    int i = 0;
    
    while (current != NULL) {
        
        i++;
        current = current->next;
    }
    
    list->listSize = i;
}


// Storing all info in the game struct will allow easier info calls
static void gameInformation(Game game, int deckSize,
    value values[], color colors[], suit suits[]) {
    
    // Stores given deck size in game struct
    game->deckSize = deckSize;
       
    // Initialise and store given arrays in game struct
    game->values = calloc(deckSize, sizeof(value));
    game->colors = calloc(deckSize, sizeof(color));
    game->suits = calloc(deckSize, sizeof(suit)); 
    
    for (int i = 0; i < deckSize; i++) {
        game->values[i] = values[i];
        game->colors[i] = colors[i];
        game->suits[i] = suits[i];
    }
}

// Distribute cards to 4 players - each player has 7 cards
// Put single card to discard pile
// Distribute the rest of the cards to the draw pile
static void dealCards(Game game) {
    
    // 'i' is count of distributed card
    int i = 0;
    
    i = dealCardsPlayerHands(game, i);
    i = dealCardsDiscardPile(game, i);
    i = dealCardsDrawPile(game, i);
    
    // if cards have been distributed correctly then i == deckSize
    assert(i == game->deckSize);
}

// Helper function for dealCards - deals cards to players
static int dealCardsPlayerHands(Game game, int i) {
    
    // Assign memory allocation to players[p] and cardNodeHead of players[p]
    // 'p' is count of player
    for (int p = 0; p < NUM_PLAYERS; p++) {
        game->players[p] = cardListMemory();
        game->players[p]->cardNodeHead = cardNodeMemory();
    }
    
    // 'playerCount' is count of player
    //     
    // (playerCount % NUM_PLAYERS) has a fixed range of 0-3 therefore only
    // players 0-3 will be called which is valid
    int playerCount = 0;
    
    // STARTING_HAND_SIZE * NUM_PLAYERS = 28 which is the total number of cards
    // required to distribute to all players at the beginning of the game
    while (i < STARTING_HAND_SIZE * NUM_PLAYERS) {
        
        // push the newCard into the player hand
        push(game->players[(playerCount % NUM_PLAYERS)]->cardNodeHead,
            newCard(game->values[i], game->colors[i], game->suits[i]));
        
        // increase playerCount to go to next player
        playerCount++;
        
        // increase count of distributed card
        i++;
    }
    
    return i;
}

// Helper function for dealCards - deals one card to discard pile
static int dealCardsDiscardPile(Game game, int i) {
   
    // Assign memory allocation to discardPile
    game->discardPile = cardListMemory();
    
    // Assign memory allocation to cardNodeHead of discardPile
    game->discardPile->cardNodeHead = cardNodeMemory();
    
    // put a single card to the discard pile
    push(game->discardPile->cardNodeHead,
        newCard(game->values[i], game->colors[i], game->suits[i]));
    
    // increase count once only
    i++;
    
    return i;
}

// Helper function for dealCards - deals leftover cards to draw pile
static int dealCardsDrawPile(Game game, int i) {
    
    // Assign memory allocation to drawPile
    game->drawPile = cardListMemory();
    
    // Assign memory allocation to cardNodeHead of drawPile
    game->drawPile->cardNodeHead = cardNodeMemory();
    
    while (i < game->deckSize) {
        
        // push the newCard into the drawPile
        push(game->drawPile->cardNodeHead,
            newCard(game->values[i], game->colors[i], game->suits[i]));
        
        i++;
    }
    
    return i;
}

static CardList cardListMemory(void) {
    
    // Allocate and initialising memory for the cardList struct using calloc
    CardList cardList = calloc(1, sizeof(struct _cardList));
    
    // Checking cardList memory allocation
    if (cardList == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(1);
    }
    
    return cardList;
}

static CardNode cardNodeMemory(void) {
    
    // Allocate and initialising memory for the cardNode struct using calloc
    CardNode cardNode = calloc(1, sizeof(struct _cardNode));
    
    // Checking cardList memory allocation
    if (cardNode == NULL) {
        fprintf(stderr, "Malloc failed to allocate memory.\n");
        exit(1);
    }
    
    return cardNode;
}


// Frees all memory allocated in the gameInformation function
static void destroyGameInformation(Game game) {
    
    // free values array
    assert(game->values != NULL);
    free(game->values);
    
    // free colors array
    assert(game->colors != NULL);
    free(game->colors);
    
    // free suits array
    assert(game->suits != NULL);
    free(game->suits);
}

// Destroy cardList structs
static void destroyCardList(CardList cardList) {
    
    CardNode current = cardList->cardNodeHead;
    CardNode temporary;
    
    // destroy all cardNodes in the cardList
    while (current != NULL) {
        
        temporary = current->next;
        destroyCardNode(current);
        
        current = temporary;
    }
    
    // destroy the cardList
    free(cardList);
}


// Destroy cardNode structs
static void destroyCardNode(CardNode cardNode) {
    
    // this destroys the card in the cardNode
    destroyCard(cardNode->card);
    
    // destroy the cardNode
    free(cardNode);
}

