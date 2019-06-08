#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int switchcounter = 0;
  int notswitchcounter = 0;

  //switch
  for (int sim = 0; sim < LIMIT; ++sim) {
    int v[3] = {0};
    int car = rand()%3;
    v[car] = 1;
    int fc = rand()%3;
    if (fc != car) switchcounter++;
  }
  //noswithc
  for (int sim = 0; sim < LIMIT; ++sim) {
    int v[3] = {0};
    int car = rand()%3;
    v[car] = 1;
    int fc = rand()%3;
    if (fc == car) notswitchcounter++;
  }
  printf("Switching probability: %f\n", ((double)switchcounter)/LIMIT);
  printf("Not Switching probability: %f\n", ((double)notswitchcounter)/LIMIT);


  return 0;
}

