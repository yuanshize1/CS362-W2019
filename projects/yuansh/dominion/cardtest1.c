#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
	printf("\n**********Start Testing adventurer card**********\n");
  int x, treas, draw;
	int treas1 = 0;
	int treas2 = 0;
	int i = 0;
	int temp[MAX_HAND];
	int seed = 1000;
	struct gameState game, game1;
  int cards[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};

	initializeGame(2, cards, 100, &game);
	memcpy(&game1, &game, sizeof(struct gameState));
	game1.hand[game1.whoseTurn][0] = minion;

	newAdventurer(&game1, 0);
	printf("Expected value: %d, Result: %d\n", game.handCount[game.whoseTurn] + 2, game1.handCount[game1.whoseTurn]);

	game.discardCount[game.whoseTurn] = 5;
	memcpy(&game1, &game, sizeof(struct gameState));
	newAdventurer(&game1, 0);

	while(treas<2){
    	drawCard(game.whoseTurn, &game);
    	draw = game.hand[game.whoseTurn][game.handCount[game.whoseTurn]-1];
    	if (draw == copper || draw == silver || draw == gold){
    	  treas++;
    	}
    	else{
    	  temp[i]=draw;
    	  game.handCount[game.whoseTurn]--;
    	  i++;
    	}
    }

	printf("Expected  card count: %d, Result: %d\n", game.discardCount[game.whoseTurn] + i, game1.discardCount[game1.whoseTurn]);

	printf("\n**********End Testing adventurer card**********\n");

	return 0;
}
