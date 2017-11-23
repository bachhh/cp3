#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )


void swap(int32* a, int32* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
vector<vi> AdjList;
int dfs_flag[101];;
queue<int> q;
vi output;

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, temp, temp2, vertex;

  while(cin >> n && n != 0){
    // Graph input
    AdjList.clear();
    LOOP(i, n){
      AdjList.push_back(vi {});
    }
    while(cin >> temp && temp != 0){
      while(cin >> temp2 && temp2 != 0){
        AdjList[temp-1].push_back(temp2-1);
      }
    }

    // Query part
    cin >> temp;
    while(temp--){
      cin >> temp2;

      LOOP(i, n){
        dfs_flag[i] = UNVISITED;
      }

      q.push(temp2-1);

      while(!q.empty()){
        vertex = q.front();
        q.pop();
        for(int i= 0; i < AdjList[vertex].size(); ++i){
          if (dfs_flag[AdjList[vertex][i]] == UNVISITED){
            q.push(AdjList[vertex][i]);
            dfs_flag[AdjList[vertex][i]] = VISITED;
          }
        }
      }

      output.clear();
      for(int node = 0; node < n; ++node){
        if(dfs_flag[node] == UNVISITED){
          output.push_back(node+1);
        }
      }
      cout << output.size();
      for(int i =0; i < output.size(); ++i){
        cout << " " << output[i];
      }
      cout << endl;

    }
  }
  return 0;
}

