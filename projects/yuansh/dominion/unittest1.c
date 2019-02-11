#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

  int i;
  struct gameState game;
  int cards[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};

  printf("\n**********Start Testing for Player Count Validation in initializeGame**********\n");

  for (i = 0; i < 10; i++) {
    printf("Validating %d players\n", i);
    if(i < 2 || i > MAX_PLAYERS){
      if(initializeGame(i, cards, 100, &game))
        printf("Passed\n");
      else
        printf("Failed\n");
    }else{
      if(initializeGame(i, cards, 100, &game))
        printf("Failed\n");
      else
        printf("Passed\n");
    }

  }
  printf("**********End of Testing for Player Count Validation in initializeGame**********\n\n");
  return 0;
}
