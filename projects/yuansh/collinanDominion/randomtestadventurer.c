#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main () {
  int i, numPlayer, player, seed;
  int k[10] = {curse,estate,duchy,province,copper,baron, smithy, treasure_map, minion, steward};
  srand(time(NULL));
  struct gameState game, game1;

  printf("******Begin Random Test Adventurer*****\n");
  for(i = 0; i < 20; i++){
    numPlayer = rand() % 10;
    seed = rand()%5000;
    initializeGame(numPlayer, k, seed, &game);
    memcpy(&game1, &game, sizeof(struct gameState));
    player = whoseTurn(&game1);

    if(game.deckCount[player]-1 == game1.deckCount[player]) printf("Passed testing deck count\n");
		else printf("Failed testing deck count\n");


		if(game.handCount[player]-1 == game1.handCount[player]) printf("Passed testing hand count\n");
		else printf("Failed testing hand count\n");


		if(game1.hand[player][game.handCount[player]] != -1) printf("Passed testing Adventurer added\n");
		else printf("Failed testing Adventurer added\n");

		if(game.playedCardCount+2 == game1.playedCardCount) printf("Passed testing Adventurer card effect on card count\n");
		else printf("Failed testing Adventurer card effect on card count\n");

		if(game.discardCount[player] == game1.discardCount[player]) printf("Passed testing Adventurer card discarded\n");
		else printf("Failed testing Adventurer card discarded\n");

		if(game.numActions+2 == game1.numActions) printf("Passed testing Adventurer card effect on action count\n");
		else printf("Failed testing Adventurer card effect on action count\n");
  }

  printf("******Random Test Adventurer Finished******\n");
  return 0;
}
