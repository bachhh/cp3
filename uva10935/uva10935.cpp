#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)


int main(){

  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);

  int n; 
  scanf("%d", &n);

  while(n != 0){ 

    queue<int> deck;
    for (int i = 1; i <= n; i++){
      deck.push(i);   
    } 
    cout << "Discarded cards: ";
    while(deck.size() > 1){

      cout << deck.front() << ", ";
      deck.pop();
      deck.push(deck.front());
      deck.pop();
    }
    cout << endl;
    cout << "Remaining card: " << deck.front();

  scanf("%d", n);
  }
  return 0;
}
