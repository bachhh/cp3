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
#define LIMIT 1000

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n; cin >> n;

  int matrix[LIMIT][LIMIT];
  vector<bool> cars(n, true);
  int temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> temp;
      if (temp == 1) cars[i] = false;
      if (temp == 2) cars[j] = false;
      if (temp == 3) cars[i] = cars[j] = false;
    }
  }

  vi output;
  for (int i = 0; i < n; ++i) {
    if(cars[i]) output.push_back(i+1);
  }

  temp = output.size();
  std::cout << temp << std::endl;
  for (int i = 0; i < temp; ++i) {
    cout << output[i] << " \n"[i==temp-1];
  }

  return 0;
}
