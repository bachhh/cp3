#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

#define EPS 1e-9

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  string player;
  int score;

  map<string, int> scoreboard;

  for (int i = 0; i < n; ++i) {
    cin >> player >> score;
    scoreboard[player] = max(scoreboard[player], score);
  }

  vector<int> v;
  for (auto p : scoreboard) {
    v.push_back(p.second);
  }

  sort(v.begin(), v.end());

  std::cout << v.size() << std::endl;
  for (auto p : scoreboard) {
    std::cout << p.first << " ";

    int u = upper_bound(v.begin(), v.end(), p.second)
      - v.begin();

    //std::cout << p.second << "|" << ((double)u)/v.size() << " ";

    if ( ( (double)u ) / v.size() < 0.5 - EPS){
      std::cout << "noob" << std::endl;
    }
    else if ( ((double)u)/ v.size() >= 0.5 - EPS
        && ((double)u)/v.size() < 0.8 - EPS ){

      std::cout << "random" << std::endl;

    }
    else if ( ((double)u)/v.size() >= 0.8 - EPS &&
        ((double)u)/v.size() < 0.9 - EPS){
      std::cout << "average" << std::endl;

    }
    else if ( ((double)u)/v.size() >= 0.9 - EPS &&
        ((double)u)/v.size() < 0.99 - EPS){
      std::cout << "hardcore" << std::endl;
    }
    else if( ((double)u)/v.size() >= 0.99){
      std::cout << "pro" << std::endl;
    }
    else {
      std::cout << "Error ";
      cout << ((double)u)/v.size() << endl;
      return 1;
    }

  }
  return 0;
}

