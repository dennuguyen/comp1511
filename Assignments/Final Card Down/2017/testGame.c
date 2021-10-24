// This is tests for game ADT functions
//
// Created by the group:
//  The 4th power of Taylor Mason from Billions 2
//  https://webcms3.cse.unsw.edu.au/COMP1511/17s2/groups/14476
//
// Updated on 2017-10-10


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "Card.h"

int testNo = 0;



Game test_newGame(int deckSize, value values[], color colors[], suit suits[]);
void test_playMove(Game game, playerMove move);
void cardToStr(value value, color color, suit suit, char *strBuf);
void test0();
void moveToStr(playerMove move, char*strBuf);
void print_log(char *msg);
void test1();
Card findCardInHand(Game game, value value);


int main(int argc, char *argv[]){

    printf("Initialising testing environment. *bi* *bi* *bi*\n");

    printf("============================================================\n");
    printf("| Start Test 0\n");     
    printf("============================================================\n");
    test0();
    testNo++;
    printf("============================================================\n");
    printf("| Test 0 PASSED!!!\n");    
    printf("============================================================\n\n\n");
    
    printf("============================================================\n");
    printf("| Start Test 1\n");     
    printf("============================================================\n");
    test1();
    testNo++;
    printf("============================================================\n");
    printf("| Test 1 PASSED!!!\n");    
    printf("============================================================\n\n\n");
    
    

    printf("All tests passed, you are awesome!\n");
    return 0;
}



Game test_newGame(int deckSize, value values[], color colors[], suit suits[]){
    printf("[Test %d] - Initialising new Game engine...\n", testNo);
    Game new = newGame(deckSize, values, colors, suits);
    int i = 0;
    while(i < deckSize){
        char strBuf[30];
        cardToStr(values[i], colors[i], suits[i], strBuf);
        printf("[Test %d] - [Initial Deck] - Card[%d] is %s\n", testNo, i, strBuf);
        i++;
    }
    return new;
}


void cardToStr(value value, color color, suit suit, char *strBuf) {
    char *colors[] = {
        "RED",
        "BLUE",
        "GREEN",
        "YELLOW",
        "PURPLE"
    };
    
    char *suits[] = {
        "HEARTS",
        "DIAMONDS",
        "CLUBS",
        "SPADES",
        "QUESTIONS"
    };
    
    char *values[] = {
        "ZERO",
        "ONE",
        "DRAW_TWO",
        "THREE",
        "FOUR",
        "FIVE",
        "SIX",
        "SEVEN",
        "EIGHT",
        "NINE",
        "ADVANCE",
        "BACKWARDS",
        "CONTINUE",
        "DECLARE",
        "E",
        "F"
    };
    
    sprintf(strBuf, "%s %s %s", colors[color], suits[suit], values[value]);
}


void test_playMove(Game game, playerMove move){
    char moveStrBuffer[50];
    moveToStr(move, moveStrBuffer);
    printf("[Test %d] - [MOVE] - [Turn %d] - Player %d has %s\n", 
            testNo, currentTurn(game) ,currentPlayer(game), moveStrBuffer);    
    playMove(game, move);
    printf("[Test %d] - [MOVE] - [Turn %d] - Player %d has %d cards left\n", 
            testNo, currentTurn(game), currentPlayer(game), handCardCount(game));
}

void moveToStr(playerMove move, char *strBuf){
    if(move.action == PLAY_CARD){
        char cardBuf[30];
        cardToStr(cardValue(move.card), cardColor(move.card), 
                cardSuit(move.card), cardBuf);
        sprintf(strBuf, "played %s", cardBuf);
    } else {
        char *moves[] = {
            // Draw a single card from the deck.
            "DRAW_CARD",
            // Play a single card onto the discard pile.
            "PLAY_CARD",
            // Say the word "UNO".
            "SAY_UNO",
            // Say the word "DUO".
            "SAY_DUO",
            // Say the word "TRIO".
            "SAY_TRIO",
            // End the player's turn.
            "END_TURN"
        };
        sprintf(strBuf, "made the move %s", moves[move.action]);
    }
}


void print_log(char *msg){
    printf("[Test %d] - [INFO] - %s\n", testNo, msg);
}

Card findCardInHand(Game game, value value) {
    int i = 0;
    int numOfCards = handCardCount(game);
    while (i < numOfCards) {
        if(cardValue(handCard(game, i)) == value) {
            return handCard(game, i);
        }
        i++;
    }
    return NULL;
}


void test0(){
    print_log("a extremely simple deck with 500 Blue Questions Zeros.");
    // initialise test 0
    int deckSize = 500;
    int i = 0;
    value values[500];
    color colors[500];
    suit suits[500];
    while(i < deckSize){
        values[i] = ZERO;
        colors[i] = BLUE;
        suits[i] = QUESTIONS;
        i++;
    }


    Game g = test_newGame(deckSize, values, colors, suits);
    assert(g != NULL);

    // test some getter functions
    print_log("Testing numCards/numOfSuit/numOfColor/numOfValue...");
    assert(numCards(g) == 500);
    assert(numOfSuit(g, QUESTIONS) == 500);
    assert(numOfSuit(g, SPADES) == 0);
    assert(numOfColor(g, BLUE) == 500);
    assert(numOfValue(g, ZERO) == 500);

    // turn 0, player 0's turn
    print_log("Testing currentPlayer/currentTurn...");    
    assert(currentPlayer(g) == 0);
    assert(currentTurn(g) == 0);
    print_log("Testing playerPoints of player 0 (should be zero)");
    assert(playerPoints(g, 0) == 0); // all cards are zero
    print_log("Testing default direction of the game...");
    assert(playDirection(g) == CLOCKWISE);

    // test player 0's hand cards
    print_log("Testing player0's hand...");
    assert(handCardCount(g) == 7);
    assert(cardSuit(handCard(g, 0)) == QUESTIONS);
    assert(cardColor(handCard(g, 0)) == BLUE);
    assert(cardValue(handCard(g, 0)) == ZERO);

    // make move
    playerMove m, end;
    end.action = END_TURN;
    m.action = PLAY_CARD;
    m.card = handCard(g, 0);

    // player 0 has discarded a card
    assert(isValidMove(g, m));
    test_playMove(g, m);

    // player 0 decide to end his/her turn
    m.action = END_TURN;
    test_playMove(g, m);
    
    // now player 1's turn
    assert(currentPlayer(g) == 1);
    assert(playerCardCount(g, 0) == 6);

    // player 1 draw a card
    m.action = DRAW_CARD;
    test_playMove(g, m);

    assert(handCardCount(g) == 8);

    // test invalid move
    m.action = SAY_UNO;
    assert(isValidMove(g, m) == FALSE);

    // player 1 end turn
    m.action = END_TURN;
    test_playMove(g, m);
    
    // loop to draw card and end turn
    m.action = DRAW_CARD;
    i = 0;
    while(i < 6){
        test_playMove(g, m);
        test_playMove(g, end);
        i++;
    }

    // now it's turn no 8 (nineth turn)
    // and it's player 0's turn
    assert(currentPlayer(g) == 0);
    assert(currentTurn(g) == 8);
    assert(numTurns(g) == 9);

    // test past moves
    assert(turnMoves(g, 3) == 2);
    assert(pastMove(g, 3, 0).action == m.action);
    assert(pastMove(g, 3, 1).action == end.action);
    
    // check player 0's hand card
    assert(playerCardCount(g, 0) == 7);

    // game not finished
    assert(gameWinner(g) == NOT_FINISHED);
    
    // loop to let player 0 win the game
    m.action = PLAY_CARD;
    i = 0;
    while(i < 25){
        // play card and end turn
        m.card = handCard(g, 0);
        assert(isValidMove(g, m));
        test_playMove(g, m);
        if(i != 24){
            assert(isValidMove(g, end));
            test_playMove(g, end);
        }
        i++;
    }

    assert(gameWinner(g) == 0);
    print_log("Player 0 has won the game!!!\n");

    destroyGame(g);

}


void test1(){
    print_log("a test for special cards");    
    int deckSize = 100;
    int i = 0;
    value values[100];
    color colors[100];
    suit suits[100];
    // initialise first card for intial hand for each player
    while(i < 4){
        values[i] = DRAW_TWO; //
        colors[i] = RED;
        suits[i] = SPADES;
        i++;
    }
    // initialise second card for intial hand for each player
    while(i < 8){
        values[i] = BACKWARDS; //
        colors[i] = RED;
        suits[i] = SPADES;
        i++;
    }
    // initialise third card for intial hand for each player
    while(i < 12){
        values[i] = ZERO; //
        colors[i] = YELLOW;
        suits[i] = QUESTIONS;
        i++;
    }    
    // initialise fourth card for intial hand for each player
    while(i < 16){
        values[i] = ADVANCE; //
        colors[i] = RED;
        suits[i] = SPADES;
        i++;
    }
    // initialise fifth card for intial hand for each player
    while(i < 20){
        values[i] = DECLARE;
        colors[i] = GREEN;
        suits[i] = QUESTIONS;
        i++;
    }
    // initialise rest of the cards in deck
    while(i < 100){
        values[i] = CONTINUE;
        colors[i] = RED;
        suits[i] = HEARTS;
        i++;
    }

    Game game = test_newGame(deckSize, values, colors, suits);
    assert(game != NULL);

    playerMove play = {
        .action = PLAY_CARD,
        .card = findCardInHand(game, DRAW_TWO)
    };
    playerMove end = {
        .action = END_TURN
    };
    playerMove draw = {
        .action = DRAW_CARD
    };
    playerMove say;

    print_log("Testing if the correct card is on top of discard pile...");
    assert(cardValue(topDiscard(game)) == CONTINUE);
    assert(cardSuit(topDiscard(game)) == HEARTS);
    assert(cardColor(topDiscard(game)) == RED);
    
    //====================================================================
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 0 has 6 cards left

    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 1);
    assert(cardValue(topDiscard(game)) == DRAW_TWO);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    // plyer 1 has 9 cards left
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 2);
    assert(currentTurn(game) == 2);
    assert(cardValue(topDiscard(game)) == DRAW_TWO);
    
    play.card = findCardInHand(game, DRAW_TWO);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 2 has 6 cards left
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 3);
    assert(cardValue(topDiscard(game)) == DRAW_TWO);

    play.card = findCardInHand(game, DRAW_TWO);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 3 has 6 cards left    
    assert(isValidMove(game, end));
    test_playMove(game, end);
    
    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 4);
    assert(cardValue(topDiscard(game)) == DRAW_TWO);

    // draw 4 cards
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    // player 0 has 10 cards left
    assert(handCardCount(game) == 10);

    // draw 5th card is not valid
    assert(!isValidMove(game, draw));

    assert(isValidMove(game, end));
    test_playMove(game, end);    

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 5);

    assert(cardColor(topDiscard(game)) == RED);

    play.card = findCardInHand(game, BACKWARDS);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 8 cards left

    print_log("Testing if the direction has been reversed");
    assert(playDirection(game) == ANTICLOCKWISE);
    
    assert(isValidMove(game, end));
    test_playMove(game, end);   

    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 6);
    
    assert(cardColor(topDiscard(game)) == RED);
    
    play.card = findCardInHand(game, BACKWARDS);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 0 has 9 cards left

    print_log("Testing if the direction has been reversed");
    assert(playDirection(game) == CLOCKWISE);    
  
    assert(isValidMove(game, end));
    test_playMove(game, end); 


    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 7);
    
    assert(cardColor(topDiscard(game)) == RED);

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 7 cards left

    play.card = findCardInHand(game, ZERO);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 6 cards left

    assert(isValidMove(game, end));
    test_playMove(game, end);     

    //====================================================================
    assert(currentPlayer(game) == 2);
    assert(currentTurn(game) == 8);

    assert(cardSuit(topDiscard(game)) == QUESTIONS);

    play.card = findCardInHand(game, DECLARE);
    play.nextColor = RED;
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 2 has 5 cards left

    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 9);

    play.card = findCardInHand(game, ADVANCE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 3 has 5 cards left

    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 10);

    play.card = findCardInHand(game, DRAW_TWO);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 5 cards left

    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 2);
    assert(currentTurn(game) == 11);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    // player 2 has 7 cards left
    
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 12);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 13);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end);    

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 14);

    play.card = findCardInHand(game, ADVANCE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 4 cards left
    
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 15);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 

    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 16);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 17);

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 3 cards left
    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 2 cards left
    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 1 cards left (GREEN QUESTION DECLARE)

    assert(handCardCount(game) == 1);
    assert(cardValue(handCard(game, 0)) == DECLARE);

    assert(isValidMove(game, end));
    test_playMove(game, end);


    //====================================================================
    assert(currentPlayer(game) == 2);
    assert(currentTurn(game) == 18);

    say.action = SAY_UNO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // player 1 now should have 3 cards left
    assert(playerCardCount(game, 1) == 3);
    
    say.action = SAY_DUO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // player 1 now should have 5 cards left
    assert(playerCardCount(game, 1) == 5);

    say.action = SAY_TRIO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // player 1 now should have 7 cards left
    assert(playerCardCount(game, 1) == 7);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 

    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 19);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 


    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 20);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 


    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 21);
    // player 1 has 7 cards

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 6 cards left
    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 5 cards left
    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 4 cards left

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 3 cards left
    say.action = SAY_TRIO;
    assert(isValidMove(game, say));
    test_playMove(game, say);

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    // player 1 has 2 cards left
    say.action = SAY_DUO;
    assert(isValidMove(game, say));
    test_playMove(game, say);

    play.card = findCardInHand(game, CONTINUE);
    assert(isValidMove(game, play));
    test_playMove(game, play);    
    // player 1 has 1 cards left (GREEN QUESTION DECLARE)
    say.action = SAY_UNO;
    assert(isValidMove(game, say));
    test_playMove(game, say);

    assert(handCardCount(game) == 1);
    assert(cardValue(handCard(game, 0)) == DECLARE);

    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 2);
    assert(currentTurn(game) == 22);

    int temp = handCardCount(game);

    say.action = SAY_UNO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // WRONG call out action, player 2 draw 4 cards
    assert(handCardCount(game) == temp + 4);
    
    say.action = SAY_DUO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // WRONG call out action, player 2 draw 4 cards
    assert(handCardCount(game) == temp + 8);

    say.action = SAY_TRIO;
    assert(isValidMove(game, say));
    test_playMove(game, say);
    // WRONG call out action, player 2 draw 4 cards
    assert(handCardCount(game) == temp + 12);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 


    //====================================================================
    assert(currentPlayer(game) == 3);
    assert(currentTurn(game) == 23);

    assert(isValidMove(game, draw));
    test_playMove(game, draw);
    
    assert(isValidMove(game, end));
    test_playMove(game, end); 


    //====================================================================
    assert(currentPlayer(game) == 0);
    assert(currentTurn(game) == 24);

    play.card = findCardInHand(game, ZERO);
    assert(isValidMove(game, play));
    test_playMove(game, play);
    
    assert(isValidMove(game, end));
    test_playMove(game, end);

    //====================================================================
    assert(currentPlayer(game) == 1);
    assert(currentTurn(game) == 25);

    play.card = findCardInHand(game, DECLARE);
    play.nextColor = GREEN;
    assert(isValidMove(game, play));
    test_playMove(game, play);
    
    assert(gameWinner(game) == 1);

    destroyGame(game);

}