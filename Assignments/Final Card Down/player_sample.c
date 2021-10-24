#include "Game.h"
#include "player.h"


// This function is to be implemented by the AI.
// It will be called when the player can take an action on their turn.
// The function is called repeatedly until they make the action
// END_TURN.
// If the player's turn is skipped, this funciton is not called for that
// player.
playerMove decideMove(Game game){


/* All the required information regarding the current state of the game 
   is available via "Game.h" functions. We can retrive  information using all 
   the functions in "Game.h" above the comment "The following functions 
   must NOT be called by a player". 
   
   Some of the functions a player can call are listed below, 
   see the latest Game.h for the updated list.

    int handCardCount(Game game);
    Card handCard(Game game, int card);
    
    int currentPlayer(Game game);
    int getPreviousTurnPlayer(Game game);
        
    int currentTurn(Game game);
    int numTurns(Game game);
    int getTopDiscardTurnNumber(Game game);    
    int currentTurnMoves(Game game);
            
    Card topDiscard(Game game);
    int getCurrentColor(Game game);

    int getNumberOfTwoCardsAtTop(Game game);
    int getActiveDrawTwos(Game game);

    int isValidMove(Game game, playerMove move);

    see the latest Game.h for the updated list ... 

    // implement your decideMove here ... 


}


/*   Helper functions below ... 
*/






