#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <tuple>
#include <functional>
#include <ctime>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int tc;
  scanf("%d", &tc);

  int i, D, L, H, Q, P;
  char* M;
  char u[] = "UNDETERMINED";
  char* price_list[1000000];
  while(tc--){
    scanf("%d", &D);
    for(int i=0; i < 1000000; ++i)
      price_list[i] = NULL;

    while(D--){
      M = (char*) malloc(20*sizeof(char));
      scanf("%s", M);
      scanf("%d", &L);
      scanf("%d", &H);
      for(int i = L; i <= H; ++i){
        if (price_list[i] == NULL)
          price_list[i] = M;
        else price_list[i] = u;
      }
    }

    scanf("%d", &Q);
    while(Q--){
      scanf("%d", &P);
      if (price_list[P] == NULL)
        printf("%s\n", u);
      else
        printf("%s\n", price_list[P]);
    }
    if (tc)
      puts("");

  }
  return 0;
}

