#include <iostream>
#include <assert.h>
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
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

void swap(int* a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

typedef struct block{
  int strength =-1;
  int bonus=-1;
  struct block* next = NULL;
}Block;


//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int s, n, x, y;
  cin >> s >> n;

  cin >> x  >> y;
  Block* first = (Block*) calloc(1, sizeof(Block));
  first->strength = x; first->bonus = y;

  Block* pos;
  Block* new_block;

  // List dragons by decreasing bonus
  LOOP(n-1){
    cin >> x >> y;
    new_block = (Block*) calloc(1, sizeof(Block));
    new_block->strength = x;
    new_block->bonus = y;
    pos = first;
    while( pos->next != NULL && pos->next->bonus > y ){
      pos = pos->next;
    }
    if(pos == first && pos->bonus < y){
      new_block->next = pos;
      first = new_block;
    }
    else {
      new_block->next = pos->next;
      pos->next = new_block;

    }
  }

  //Fight the largest bonus dragon possible
  while(true){
    pos = first;
    // If pos's strength itself is less than x
    if (pos->strength < s){
      s+= pos->bonus;
      // Increment the first pointer
      first = pos->next;
      // If no more dragons left
      if(first == NULL ) {
        break;
      }
      else{
        continue;
      }
    }
    // Pos->next is the first dragon strength less than s
    while(pos->next != NULL && pos->next->strength >= s ){
      pos = pos->next;
    }
    // No dragons of strength less than s
    if (pos->next == NULL){
      if (pos->strength >= s){
        break;
      }
    }
    // Loot the bonus
    else if (pos->next->strength < s) {
      s += pos->next->bonus;
      pos->next = pos->next->next;
    }
  }
  // If list is empty
  cout << ( (first == NULL) ? "YES" : "NO") << endl;

  return 0;
}


