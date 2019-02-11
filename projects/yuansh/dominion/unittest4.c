#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
  int old_coins, new_coins;
  //int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int cards[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};
  int cost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
  struct gameState game;

  printf("\n**********Start Testing isGameOver**********\n");
  initializeGame(2, cards, 100, &game);
  printf("Testing case #1, ");
  if(!isGameOver(&game))
    printf("Passed\n");
  else
    printf("Failed\n");
  game.supplyCount[province]=0;
  printf("Testing case #2, ");
  if(isGameOver(&game))
    printf("Passed\n");
  else
    printf("Failed\n");

  printf("**********End Testing isGameOver**********\n\n");
  return 0;
}
