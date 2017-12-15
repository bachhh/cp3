#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<vi> vvi;

#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 1001

bool differByOne(string a, string b){
  if (a.length() != b.length() ) return false;
  int r = 0;
  int s = a.length();
  for (int i = 0; i < s && r <= 1; ++i) {
    if(a[i] != b[i]) r++;
  }
  return r == 1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);


  string word, from, to, line;
  int tc; cin >> tc;
  vector<string> dict;
  map<string, bool> isPushed;
  while(tc--){
    dict.clear();
    isPushed.clear();
    word = "";

    getline(cin, word);

    while(true){
      getline(cin, word);
      if (word == "*") break;
      dict.push_back(word);
      isPushed[word] = false;
    }

    getline(cin,line);
    while(line != ""){
      from = line.substr(0, line.find(" "));
      to = line.substr(line.find(" ")+1, line.back());
      queue<pair<string, int>> q; q.push({from, 0});
      int d; word = "";

      for (auto it = isPushed.begin(); it != isPushed.end(); ++it){
        (*it).second = false;
      }

      while(!q.empty()){
        word = q.front().first;
        d = q.front().second;
        q.pop();
        if (word == to) break;
        for(auto s : dict){
          if ( !isPushed[s] && differByOne(s, word) ){
            q.push({s, d+1});
            isPushed[s] = true;
          }
        }
      }
      std::cout << from << " " << to << " " << d << std::endl;

      getline(cin,line);
    }
    if (tc>0) std::cout << std::endl;
  }

  return 0;
}
