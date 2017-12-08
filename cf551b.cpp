#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
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


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b, c;

  cin >> a>> b>> c;
  int count = 0;
  string output = "";
  map<char, int> dict;

  for(char ch : a){
    count++;
    dict[ch]++;
  }

  bool flag = true;

  while(flag){
    cout << output << endl;
    for(char ch : b){ if(dict[ch] < 1){ flag = false; } }
    if (flag){ output += b; for(char ch : b){ dict[ch]--; count--; } continue;}

    for(char ch : c){ if (dict[ch] < 1){ flag = false; } }
    if (flag){ output += c; for(char ch : c){ dict[ch]--; count--; } }
  }

  for(auto it : dict){
    while(it.second--){
      output += it.first;
    }
  }

  cout << output << endl;

  return 0;

}

