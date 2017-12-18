#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii; typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define LIMIT 2000000002

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n; cin >> n;
  int x, h;

  vii road;
  for (int i = 0; i < n; ++i) {
    cin >> x >> h;
    road.push_back(ii(x, h));
  }

  int largestindex = -LIMIT;
  int counter = 0;
  int i = 0;
  while(i < n){
    x = road[i].first; h = road[i].second;
    // Always fell to the left if you can
    if(x - h > largestindex){
      largestindex = x;
      counter++;
      i++;
    }
    // Have to fell the current tree to the right now
    else {
      if (i < n-1){
        // If we can fell it to the right
        if  (x+h < road[i+1].first){
          counter++;
          largestindex = x+h;
        }
        else {
          largestindex = x;
        }
      }
      else {
        // Last tree, always fell it to the right
        counter++;
      }
      i++;
    }
  }

  std::cout << counter << std::endl;

  return 0;
}
