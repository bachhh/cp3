#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100
#define DIV 1000000009


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  uint64_t n, m, k;
  cin >> n >> m >> k;

  uint64_t score = 0;
  /*
   * wrong answers = n-m
   * score double n/k times maximum
   * Observations:
   *
   * GREEDY:
   * 1: We want slip the number of wrong answers(n-m) into as many n/k partitions
   *      as possible to avoid doubling the score
   * 2: If it is impossible for the player not to double the score
   *      it should happens as early as possible
   *
   *
   */

  // The unavoidable number of answers that double the score
  int64_t doubleAnswers = n/k - (n-m);

  // All the Double answers happens at as early as possible
  /*
  for (uint64_t i = 0; i < doubleAnswers; i++) {
    score += k;
    score = score << 1;
    score %= DIV;
  } */

  // This transform into algebraic forms
  // k*(1 + 2 + 4 + ..+ 2^doubleAnswers+1)
  // <=> k*(2^(doubleAnswers+1) )
  // Upperbound for doubleAnswers = 10^9/2
  // with bitshift width == 32 maximum, we are looking at
  // ~ 16x10E6 calculations (times with the cost of %DIV operation

  int64_t rest = (m - k*MAX(doubleAnswers, 0));

  // #### modulo arithematics
  if (doubleAnswers > 0){
    score = 1;
    while(doubleAnswers > 16){
      score *= (1 << 16);
      score %= DIV;
      doubleAnswers -= 16;
    }
    score *= (1 << (doubleAnswers+1))%DIV;
    score *= k%DIV;
    score -= 2*k%DIV;
  }

  // The rest of them is +1 answers

  score += rest;
  score %= DIV;
  std::cout << score << std::endl;

  return 0;

}

