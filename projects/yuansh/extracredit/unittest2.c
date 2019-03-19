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
  int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int cost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
  printf("\n**********Start Testing getCost**********\n");

  for (i = 0; i < 27; i++) {
    printf("Testing cost for card #%d\n", cards[i]+1);
    if(getCost(cards[i])==cost[i])
      printf("Passed\n");
    else
      printf("Failed\n");
  }
  printf("**********End Testing getCost**********\n\n");
  return 0;
}
