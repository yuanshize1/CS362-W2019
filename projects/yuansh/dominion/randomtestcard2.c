#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
  int i,j, numPlayer, player, seed, deckTreasures, handCount, preCount , postCount;
  int k[10] = {curse,estate,duchy,province,copper,baron, smithy, treasure_map, minion, steward};
  srand(time(NULL));
  struct gameState game, game1;

	printf("\n**********Start Testing Village card**********\n");
  for(i = 0; i < 20; i++) {
    numPlayer = rand() % 20;
    seed = rand()%5000;
    initializeGame(numPlayer, k, seed, &game);
    memcpy(&game1, &game, sizeof(struct gameState));
    player = whoseTurn(&game1);
    cardEffect(village, 0, 0,0,&game1,0, 0);
    if(numHandCards(&game1) == (numHandCards(&game)+1)) printf("Passed testing Village card effect on card count\n");
    else printf("Failed testing Village card effect on card count\n");
    printf("%d\n", numHandCards(&game1));
  }

	printf("\n**********End Testing Village card**********\n");

	return 0;
}
