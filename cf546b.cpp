#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;

#define LIMIT 100
void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);



  int badges[3000];
  int distinct[3000];

  LOOP(i, 3000){
    distinct[i] = 0;
  }

  int n;
  cin >> n;

  LOOP(i, n){
    cin >> badges[i];
  }

  sort(badges, badges + n);

  int cost = 0;

  int i =0;

  while(i < n-1){
    if (badges[i] >= badges[i+1]){
      badges[i+1]++;
      cost++;
    }
    else{
      i++;
    }
  }

  cout << cost << endl;


  return 0;
}

