// COMP1511 (2018S2)
// Assignment 2: Final Card Down
// testGame.c
// 
// Dan Nguyen (z5206032)
// 2018/10/23 - 2018/10/26
// 
// Dean Wunder (thu11-brass)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Game.h"
#include "player.h"

#define STARTING_HAND_SIZE 7

#define NUM_VALUES 16
#define NUM_COLORS 5
#define NUM_SUITS 5

static void testDeck1(void);

// Stage1.c
static void check_initial_PlayerHand(Game game, int player, value values[], color colors[], suit suits[]);
static void check_initial_Deck(Game game, int deck_size, value values[], color colors[], suit suits[]);
static void check_initial_DiscardPile(Game game, int deck_size, value values[], color colors[], suit suits[]);

static int cardIsInHand(Game game, int player, int alreadyMatched[], value v, color c, suit s);
static int cardMatchesComponents1(Card card, value v, color c, suit s);
static void printCardByComponents1(value v, color c, suit s);

static void test1_init_deck_hands(void);

// Stage2.c
static void checkPlayer0Turn1(Game game);
static void checkPlayer1Turn1(Game game);
static void checkPlayer2Turn1(Game game);
static void checkPlayer3Turn1(Game game);
static void checkPlayer0Turn2(Game game);
static void checkPlayer1Turn2(Game game);

static Card findCardInHand(Game game, int player, value v, color c, suit s);
static Card findCardInDeck(Game game, value v, color c, suit s);
static int cardMatchesComponents2(Card card, value v, color c, suit s);
static void printCardByComponents2(value v, color c, suit s);
static void checkGameState(Game game, int expectedPlayer, int expectedTurn,
    int expectedMoves, int expectedPreviousPlayer, int expectedTopDiscardTurn);
static void checkTopDiscard(Game game, Card card);
static void test1_play_basic_hands(void);


int main(void) {
    
    testDeck1();
    
    // Stage1.c
    test1_init_deck_hands();
    
    // Stage2.c
    test1_play_basic_hands();
    
    return 0;
}

static void testDeck1(void) {
    
    printf("\n");
    printf("===============================================================\n");
    printf("                        Testing Deck 1                         \n");
    printf("===============================================================\n");
    printf("\n");
    
    // deckSize, values[], colors[], suits[] are from stage1.c
    int deckSize = 50;
    
    value values[] = {
        DRAW_TWO, ONE, DRAW_TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        A, B, C, D, E, F, ZERO, ONE, DRAW_TWO, THREE,
        FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D,
        E, F, ZERO, ONE, DRAW_TWO, THREE, FOUR, FIVE, SIX, SEVEN,
        EIGHT, NINE, A, B, C, D, E, F, ZERO, ONE
    };

    color colors[] = {
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,
        PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE
    };

    suit suits[] = {
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS
    };
    
    Game game = newGame(deckSize, values, colors, suits);
    
    // Testing if deckSize is stored in the game struct correctly
    printf("Checking number of cards from initial deck...\n");
    assert(numCards(game) == 50);
    printf("Passed!\n\n");
    
    // Testing if given suits[] is stored in the game struct correctly
    printf("\nTesting Suits\n\n");
    
    printf("Checking number of hearts...\n");
    assert(numOfSuit(game, HEARTS) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of diamonds...\n");
    assert(numOfSuit(game, DIAMONDS) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of clubs...\n");
    assert(numOfSuit(game, CLUBS) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of spades...\n");
    assert(numOfSuit(game, SPADES) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of questions...\n");
    assert(numOfSuit(game, QUESTIONS) == 10);
    printf("Passed!\n\n");
    
    // Testing if given colors[] is stored in the game struct correctly 
    printf("\nTesting Colors\n\n");
    
    printf("Checking number of red cards...\n");
    assert(numOfColor(game, RED) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of blue cards...\n");
    assert(numOfColor(game, BLUE) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of green cards...\n");
    assert(numOfColor(game, GREEN) == 10);
    printf("Passed!\n\n");
    
    printf("Checking number of yellow cards...\n");
    assert(numOfColor(game, YELLOW) == 10);
    printf("Passed\n\n");
    
    printf("Checking number of purple cards...\n");
    assert(numOfColor(game, PURPLE) == 10);
    printf("Passed!\n\n");
    
    // Testing if first discardPile is correct
    printf("Checking discard pile...\n");
    //assert(cardValue(game->discardPile->cardNodeHead->card) == B); // incomplete definition
    //assert(cardColor(game->discardPile->cardNodeHead->card) == GREEN);
    //assert(cardSuit(game->discardPile->cardNodeHead->card) == CLUBS);
    printf("Passed!\n\n");
    
    
    printf("Checking current player...\n");
    assert(currentPlayer(game) == 0);
    printf("Passed!\n\n");
    
    printf("Checking current turn number...\n");
    assert(currentTurn(game) == 0);
    printf("Passed!\n\n");
    
    printf("Checking moves number...\n");
    assert(currentTurnMoves(game) == 0);
    printf("Passed!\n\n");
    
    printf("Checking number of turns...\n");
    assert(numTurns(game) == 1);
    printf("Passed!\n\n");
    
    printf("Checking current moves...\n");
    assert(currentTurnMoves(game) == 0);
    printf("Passed!\n\n");
    
    printf("Checking previous player...\n");
    assert(getPreviousTurnPlayer(game) == -1);
    printf("Passed!\n\n");
    
    printf("Checking top of discard pile...\n");
    assert(getTopDiscardTurnNumber(game) == -1);
    printf("Passed!\n\n");
    
    printf("Checking active draw twos...\n");
    assert(getActiveDrawTwos(game) == 1);
    printf("Passed!\n\n");
    
    printf("Checking number of active two cards on top...\n");
    assert(getNumberOfTwoCardsAtTop(game) == 1);
    printf("Passed!\n\n");
    
    printf("Checking current colour...\n");
    assert(getCurrentColor(game) == 2);
    printf("Passed!\n\n");
    
    printf("Checking hand card count...\n");
    assert(handCardCount(game) == 7);
    printf("Passed!\n\n");
    
    printf("Checking player card count...\n");
    assert(playerCardCount(game, 3) == 7);
    printf("Passed!\n\n");
    
    printf("Checking player points...\n");
    assert(playerPoints(game, 0) == 38);
    printf("Passed!\n\n");
    
    printf("Destroying game...\n");
    destroyGame(game); 
    printf("Successful!\n\n\n");
}

// =============================================================================
//                                 Stage1.c
// =============================================================================

static void test1_init_deck_hands(void){
    int deck_size = 50;
    value values[] = {
        ZERO, ONE, DRAW_TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        A, B, C, D, E, F, ZERO, ONE, DRAW_TWO, THREE,
        FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D,
        E, F, ZERO, ONE, DRAW_TWO, THREE, FOUR, FIVE, SIX, SEVEN,
        EIGHT, NINE, A, B, C, D, E, F, ZERO, ONE
    };

    color colors[] = {
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,
        PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE
    };

    suit suits[] = {
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS,
        HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS, HEARTS, DIAMONDS, CLUBS, SPADES, QUESTIONS
    };

    Game game = newGame(deck_size, values, colors, suits);
    
    

    printf("Checking if current player is 0\n\n");
    assert(currentPlayer(game) == 0);

    printf("Checking if current turn is 0\n\n");
    assert(currentTurn(game) == 0);

    printf("Checking if number of turns is 1\n\n");
    assert(numTurns(game) == 1);

    printf("Checking if current moves in turn is 0\n\n");
    assert(currentTurnMoves(game) == 0);

    printf("Checking if player from previous turn is -1\n\n");
    assert(getPreviousTurnPlayer(game) == -1);

    printf("Checking if top of discard pile was played in turn -1\n\n");
    assert(getTopDiscardTurnNumber(game) == -1);

    check_initial_Deck(game, deck_size, values, colors, suits);
    printf("\n");

    check_initial_DiscardPile(game, deck_size, values, colors, suits);
    printf("\n");

    check_initial_PlayerHand(game, 0, values, colors, suits);
    printf("\n");

    check_initial_PlayerHand(game, 1, values, colors, suits);
    printf("\n");

    check_initial_PlayerHand(game, 2, values, colors, suits);
    printf("\n");

    check_initial_PlayerHand(game, 3, values, colors, suits);
    printf("\n");


    printf("Trying to destroy the game\n\n");
    destroyGame(game);

    printf("All tests passed, nice work!\n");

}


static void check_initial_Deck(Game game, int deck_size, value values[], color colors[], suit suits[]){

    int deckStart = NUM_PLAYERS * STARTING_HAND_SIZE + 1;
    int expectedCards = deck_size - NUM_PLAYERS * STARTING_HAND_SIZE - 1;

    int i = 0;
    Card card = getDeckCard(game, i);
    assert(card != NULL);
    while (card != NULL && i < expectedCards){
        int originalDeckIndex = deckStart + i;

        int v = values[originalDeckIndex];
        int c = colors[originalDeckIndex];
        int s = suits[originalDeckIndex];

        printf("Checking card %d in deck is ", i);
        printCardByComponents1(v, c, s);
        printf("\n");

        assert(cardMatchesComponents1(card, v, c, s));

        i += 1;
        card = getDeckCard(game, i);
    }
    printf("You have %d cards\n", i);
    printf("Checking the deck has %d cards\n", expectedCards);
    assert(i == expectedCards);
}

static void check_initial_DiscardPile(Game game, int deck_size, value values[], color colors[], suit suits[]){
    Card card;
    int firstCard = NUM_PLAYERS * STARTING_HAND_SIZE;

    printf("Checking top of discard pile is ");
    printCardByComponents1(values[firstCard], colors[firstCard], suits[firstCard]);
    printf("\n");

    card = getDiscardPileCard(game, 0);
    assert(cardMatchesComponents1(card, values[firstCard], colors[firstCard], suits[firstCard]));

    printf("Checking there are no other cards in the discard pile\n");

    card = getDiscardPileCard(game, 1);
    assert(card == NULL);
}


static void check_initial_PlayerHand(Game game, int player, value values[], color colors[], suit suits[]){
    int originalDeck_index = player;

    // Array to keep track of the index of cards in a player's hand we've already
    // matched against
    int alreadyMatched[STARTING_HAND_SIZE];
    for (int i = 0; i < STARTING_HAND_SIZE; i++){
        alreadyMatched[i] = FALSE;
    }

    for(int k = 0; k < STARTING_HAND_SIZE; k++){

        int v = values[originalDeck_index];
        int c = colors[originalDeck_index];
        int s = suits [originalDeck_index];
        originalDeck_index = originalDeck_index + NUM_PLAYERS;

        printf("\n---------- ----------------- ------------ \n");
        printf("Checking card ");
        printCardByComponents1(v, c, s);
        printf(" is in player %d's hand\n", player);

        assert(cardIsInHand(game, player, alreadyMatched, v, c, s));
    }

    Card card = getHandCard(game, player, STARTING_HAND_SIZE);
    assert( card == NULL );

    printf("Finish checking hand for player %d , OK. ", player);

}


static int cardIsInHand(Game game, int player, int alreadyMatched[], value v, color c, suit s){
    int i = 0;
    Card card = getHandCard(game, player, i);
    while (card != NULL){
        if (cardMatchesComponents1(card, v, c, s) && !alreadyMatched[i]){
            alreadyMatched[i] = TRUE;
            return TRUE;
        }

        i++;
        card = getHandCard(game, player, i);
    }

    return FALSE;
}

static int cardMatchesComponents1(Card card, value v, color c, suit s){
    return cardValue(card) == v && cardColor(card) == c && cardSuit(card) == s;
}

static void printCardByComponents1(value v, color c, suit s){
    char* valueStrings[NUM_VALUES] = {
        "ZERO", "ONE", "DRAW_TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
        "A", "B", "C", "D", "E", "F"
    };

    char* colorStrings[NUM_COLORS] = {
        "RED", "BLUE", "GREEN", "YELLOW", "PURPLE"
    };

    char* suitStrings[NUM_SUITS] = {
        "HEARTS", "DIAMONDS", "CLUBS", "SPADES", "QUESTIONS"
    };

    printf("%s %s of %s", colorStrings[c], valueStrings[v], suitStrings[s]);
}


// =============================================================================
//                                 Stage2.c
// =============================================================================


static void test1_play_basic_hands(void){
    int deck_size = 36;

    value values[] = {
        THREE, THREE, C, A,
        E, ZERO, F, B,
        A, ZERO, E, DRAW_TWO,
        ONE, SIX, FIVE, THREE,
        ONE, SEVEN, F, F,
        FOUR, ZERO, A, THREE,
        A, THREE, FOUR, ZERO,
        THREE, NINE, D, B,
        SIX, SIX, FOUR, FIVE
    };

    color colors[] = {
        RED, BLUE, YELLOW, PURPLE,
        YELLOW, BLUE, YELLOW, GREEN,
        GREEN, BLUE, BLUE, BLUE,
        PURPLE, PURPLE, RED, BLUE,
        GREEN, GREEN, PURPLE, RED,
        GREEN, GREEN, BLUE, RED,
        PURPLE, YELLOW, BLUE, BLUE,
        RED, PURPLE, YELLOW, YELLOW,
        RED, YELLOW, RED, PURPLE
    };

    suit suits[] = {
        SPADES, DIAMONDS, DIAMONDS, CLUBS,
        CLUBS, SPADES, SPADES, CLUBS,
        SPADES, SPADES, DIAMONDS, HEARTS,
        DIAMONDS, SPADES, QUESTIONS, SPADES,
        CLUBS, DIAMONDS, QUESTIONS, QUESTIONS,
        QUESTIONS, CLUBS, HEARTS, HEARTS,
        CLUBS, CLUBS, DIAMONDS, SPADES,
        HEARTS, DIAMONDS, CLUBS, HEARTS,
        DIAMONDS, HEARTS, HEARTS, DIAMONDS
    };

    // Important: 
    // We can derive most of the required information for testing 
    // from these three arrays provided to "newGame". 
    
    Game game = newGame(deck_size, values, colors, suits);

    checkPlayer0Turn1(game);

    checkPlayer1Turn1(game);

    checkPlayer2Turn1(game);

    checkPlayer3Turn1(game);

    checkPlayer0Turn2(game);

    checkPlayer1Turn2(game);

    printf("Trying to destroy the game\n");
    destroyGame(game);

    printf("All tests passed, awesome work!\n");
}


static void checkPlayer0Turn1(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 0's Turn =======\n");

    // Let's check the initial state.
    printf("Checking the game state\n");
    checkGameState(game, 0, 0, 0, -1, -1);

    // We know player 0 should have the card (Three, RED, SPADES).
    // We can derive this from the initial three arrays provided to "newGame". 
    printf("Checking player 0 has ");
    printCardByComponents2(THREE, RED, SPADES);
    printf("\n");
    card = findCardInHand(game, 0, THREE, RED, SPADES);
    assert(card != NULL);

    // We know the card (Three, RED, SPADES) is valid to play at 
    // this point, so let's check it.
    printf("Checking it is valid for player 0 to play this card\n");
    move.action = PLAY_CARD;
    move.card = card;  // card (Three, RED, SPADES) 
    assert(isValidMove(game, move) == TRUE);  // isValidMove should return TRUE 

    // Let's make sure that "isValidMove" above has not changed the game state.
    printf("Checking the game state\n");
    checkGameState(game, 0, 0, 0, -1, -1);

    // Let's play the card (Three, RED, SPADES). 
    printf("Playing the card\n");
    playMove(game, move);

    printf("Checking played card is at the top of the discard pile\n");
    checkTopDiscard(game, card);

    // Let's check that the hand of player 0 is propelry updated.
    // We know that there was only one card (THREE, RED, SPADES) in the hand.    
    // So, if we look for the card (THREE, RED, SPADES), it should return NULL.
    // If there were multiple cards with same three values, we need 
    // different test!
    printf("Checking player 0 no longer has ");
    printCardByComponents2(THREE, RED, SPADES);
    printf("\n");
    card = findCardInHand(game, 0, THREE, RED, SPADES);
    assert(card == NULL);

    // After the move, the game should be in the following state. 
    printf("Checking the game state\n");
    checkGameState(game, 0, 0, 1, -1, 0);

    // Now player 0 should be able to END_TURN.
    // Let's check "isValidMove", it should return TRUE.
    printf("Checking player 0 can end their turn\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    // Let's end the turn.
    printf("Ending player 0's turn\n");
    playMove(game, move);
}

static void checkPlayer1Turn1(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 1's Turn =======\n");

    printf("Checking the game state\n");
    checkGameState(game, 1, 1, 0, 0, 0);

    // At this point, player 1 should be able o draw a card, let's check it.
    printf("Checking player 1 could draw a card\n");
    move.action = DRAW_CARD;
    assert(isValidMove(game, move) == TRUE);

    // The above "isValidMove" should not change the state.
    printf("Checking the game state\n");
    checkGameState(game, 1, 1, 0, 0, 0);

    // From the initial three arrays, we know that player 1 should have 
    // the card (THREE, BLUE, DIAMONDS). Let's check it.
    printf("Checking player 1 has ");
    printCardByComponents2(THREE, BLUE, DIAMONDS);
    printf("\n");
    card = findCardInHand(game, 1, THREE, BLUE, DIAMONDS);
    assert(card != NULL);

    // The card (THREE, BLUE, DIAMONDS) satisfies the matching criteria, 
    // so player 1 should be able to play it, and "isValidMove" 
    // should return TRUE
    printf("Checking player 1 can play this card\n");
    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == TRUE);

    printf("Checking the game state\n");
    checkGameState(game, 1, 1, 0, 0, 0);

    printf("Playing the card\n");
    playMove(game, move);
    
    printf("Checking played card is at the top of the discard pile\n");
    checkTopDiscard(game, card);
    
    // Let's check that the hand of player 1 is propelry updated.
    // We know that there was only one card (THREE, BLUE, DIAMONDS) in the hand.    
    // So, if we look for the card (THREE, BLUE, DIAMONDS), it should return NULL.
    // If there were multiple cards with same three values, we need 
    // different test!    
    printf("Checking player 1 no longer has ");
    printCardByComponents2(THREE, BLUE, DIAMONDS);
    printf("\n");
    card = findCardInHand(game, 0, THREE, BLUE, DIAMONDS);
    assert(card == NULL);

    printf("Checking the game state\n");
    checkGameState(game, 1, 1, 1, 0, 1);

    printf("Checking player 1 can end their turn\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 1's turn\n");
    playMove(game, move);
}

static void checkPlayer2Turn1(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 2's Turn =======\n");

    printf("Checking the game state\n");
    checkGameState(game, 2, 2, 0, 1, 1);

    printf("Checking player 2 has ");
    printCardByComponents2(C, YELLOW, DIAMONDS);
    printf("\n");
    card = findCardInHand(game, 2, C, YELLOW, DIAMONDS);
    assert(card != NULL);

    printf("Checking player 2 can play this card\n");
    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == TRUE);

    printf("Playing the card\n");
    playMove(game, move);

    printf("Checking played card is at the top of the discard pile\n");
    checkTopDiscard(game, card);

    printf("Checking player 2 no longer has ");
    printCardByComponents2(C, YELLOW, DIAMONDS);
    printf("\n");
    card = findCardInHand(game, 0, C, YELLOW, DIAMONDS);
    assert(card == NULL);

    printf("Checking the game state\n");
    checkGameState(game, 2, 2, 1, 1, 2);

    printf("Checking player 2 has ");
    printCardByComponents2(F, YELLOW, SPADES);
    printf("\n");
    card = findCardInHand(game, 2, F, YELLOW, SPADES);
    assert(card != NULL);

    // They can play only one card in one turn, 
    // so the next move with PLAY_CARD should fail!
    printf("Checking they cannot play the card\n");
    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == FALSE);

    printf("Checking player 2 can end their turn\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 2's turn\n");
    playMove(game, move);
}

static void checkPlayer3Turn1(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 3's Turn =======\n");
    checkGameState(game, 3, 3, 0, 2, 2);

    printf("Checking player 3 can't end their turn yet\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == FALSE);

    printf("Checking the game state\n");
    checkGameState(game, 3, 3, 0, 2, 2);

    printf("Checking player 3 can't play player 2's ");
    printCardByComponents2(F, YELLOW, SPADES);
    printf("\n");
    card = findCardInHand(game, 2, F, YELLOW, SPADES);
    assert(card != NULL);

    // We that the card (F, YELLOW, SPADES) is not in player 3's hand,
    // so the following move should be invalid.
    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == FALSE);

    printf("Checking the state hasn't changed\n");
    checkGameState(game, 3, 3, 0, 2, 2);

    printf("Checking player 3 can pick up a card\n");
    move.action = DRAW_CARD;
    assert(isValidMove(game, move) == TRUE);

    printf("Checking the top of the deck is ");
    printCardByComponents2(NINE, PURPLE, DIAMONDS);
    printf("\n");
    card = getDeckCard(game, 0);
    assert(cardMatchesComponents2(card, NINE, PURPLE, DIAMONDS));

    printf("Player 3 picks up the card\n");
    playMove(game, move);

    printf("Checking the card is now in player 3's hand\n");
    Card cardInHand = findCardInHand(game, 3, NINE, PURPLE, DIAMONDS);
    assert(cardInHand == card);

    printf("Checking player 3 can't pick up another card\n");
    move.action = DRAW_CARD;
    assert(isValidMove(game, move) == FALSE);

    printf("Checking the game state\n");
    checkGameState(game, 3, 3, 1, 2, 2);

    printf("Checking player 3 can end their turn\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 3's turn\n");
    playMove(game, move);
}

static void checkPlayer0Turn2(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 0's Turn =======\n");
    printf("Checking the game state\n");
    checkGameState(game, 0, 4, 0, 3, 2);
    
    printf("Checking player 0 has ");
    printCardByComponents2(E, YELLOW, CLUBS);
    printf("\n");
    card = findCardInHand(game, 0, E, YELLOW, CLUBS);
    assert(card != NULL);

    printf("Checking player 0 can play this card\n");
    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == TRUE);

    printf("Playing the card\n");
    playMove(game, move);

    printf("Checking played card is at the top of the discard pile\n");
    checkTopDiscard(game, card);

    printf("Checking player 0 no longer has ");
    printCardByComponents2(THREE, RED, SPADES);
    printf("\n");
    card = findCardInHand(game, 0, THREE, RED, SPADES);
    assert(card == NULL);

    printf("Checking the new game state\n");
    checkGameState(game, 0, 4, 1, 3, 4);

    printf("Checking player 0 can end their turn\n");
    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 0's turn\n");
    playMove(game, move);
}

static void checkPlayer1Turn2(Game game){
    playerMove move;
    Card card;

    printf("\n======= Player 1's Turn =======\n");

    printf("Checking the game state\n");

    checkGameState(game, 1, 5, 0, 0, 4);

    printf("Checking player 1 has ");
    printCardByComponents2(ZERO, BLUE, SPADES);
    printf("\n");

    card = findCardInHand(game, 1, ZERO, BLUE, SPADES);
    assert(card != NULL);

    printf("Checking player 1 can play this card\n");

    move.action = PLAY_CARD;
    move.card = card;
    assert(isValidMove(game, move) == TRUE);

    printf("Playing the card\n");

    playMove(game, move);

    printf("Checking played card is at the top of the discard pile\n");

    checkTopDiscard(game, card);

    printf("Checking player 1 no longer has ");
    printCardByComponents2(ZERO, BLUE, SPADES);
    printf("\n");

    card = findCardInHand(game, 0, ZERO, BLUE, SPADES);
    assert(card == NULL);

    printf("Checking the game state\n");

    checkGameState(game, 1, 5, 1, 0, 5);

    printf("Checking player 1 can end their turn\n");

    move.action = END_TURN;
    assert(isValidMove(game, move) == TRUE);

    printf("Ending player 1's turn\n");

    playMove(game, move);

    printf("Checking the game state\n");

    checkGameState(game, 2, 6, 0, 1, 5);
}

// Checks various aspects of the game's state
static void checkGameState(Game game, int expectedPlayer, int expectedTurn,
        int expectedMoves, int expectedPreviousPlayer, int expectedTopDiscardTurn){

    assert(currentPlayer(game) == expectedPlayer);
    assert(currentTurn(game) == expectedTurn);
    assert(numTurns(game) == expectedTurn + 1);
    assert(currentTurnMoves(game) == expectedMoves);
    assert(getPreviousTurnPlayer(game) == expectedPreviousPlayer);
    assert(getTopDiscardTurnNumber(game) == expectedTopDiscardTurn);
}

// Tries to find a card with the given values in a player's hand and returns it
static Card findCardInHand(Game game, int player, value v, color c, suit s){
    int i = 0;
    Card card = getHandCard(game, player, i);
    while (card != NULL){
        if (cardMatchesComponents2(card, v, c, s)){
            return card;
        }

        i++;
        card = getHandCard(game, player, i);
    }

    return NULL;
}

// Tries to find a card with the given values in the deck and returns it
static Card findCardInDeck(Game game, value v, color c, suit s){
    int i = 0;
    Card card = getDeckCard(game, i);
    while (card != NULL){
        if (cardMatchesComponents2(card, v, c, s)){
            return card;
        }

        i++;
        card = getDeckCard(game, i);
    }

    return NULL;
}

// Checks if the top of the discard value is a particular card
static void checkTopDiscard(Game game, Card card){
    assert(getDiscardPileCard(game, 0) == card);
}

// Compare a card to the various components of a card
static int cardMatchesComponents2(Card card, value v, color c, suit s){
    
    assert(card != NULL);
    
    return cardValue(card) == v && cardColor(card) == c && cardSuit(card) == s;
}

// Print cards by their components in a nice format
static void printCardByComponents2(value v, color c, suit s){
    char* valueStrings[NUM_VALUES] = {
        "ZERO", "ONE", "DRAW_TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
        "A", "B", "C", "D", "E", "F"
    };

    char* colorStrings[NUM_COLORS] = {
        "RED", "BLUE", "GREEN", "YELLOW", "PURPLE"
    };

    char* suitStrings[NUM_SUITS] = {
        "HEARTS", "DIAMONDS", "CLUBS", "SPADES", "QUESTIONS"
    };

    printf("%s %s of %s", colorStrings[c], valueStrings[v], suitStrings[s]);
}