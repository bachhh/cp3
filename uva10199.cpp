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
#define FLOAT_EPSILON 1e-6

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )
#define DEBUG(x) cerr << #x << " is " << x << endl;


int n, r;
vvi al;
int dfs_num[200];
int dfs_low[200];
int dfs_parents[200];
map<string, int> s_i;
map<int, string> i_s;

vector<string> camera_points;
bool isCamera[200];

int dfsCounter;
int root;
int rootChildren;


void dfsAPB(int u){
  dfs_num[u] = dfs_low[u] = dfsCounter;
  dfsCounter++;
  for(auto neighbor : al[u]){
    if (dfs_num[neighbor] == UNVISITED){
      dfs_parents[neighbor] = u;
      if(u == root) rootChildren++;
      dfsAPB(neighbor);
      if(dfs_low[neighbor] >= dfs_num[u]){
        isCamera[u] = true;
      }
      dfs_low[u] = MIN(dfs_low[u], dfs_low[neighbor]);
    }
    else if(dfs_parents[u] != neighbor){
      dfs_low[u] = MIN(dfs_low[u], dfs_num[neighbor]);
    }
  }

}
//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  string a, b;
  int case_no = 1;
  while( cin >> n && n!= 0){
    rootChildren = dfsCounter = 0;
    al.clear();
    s_i.clear();
    i_s.clear();
    camera_points.clear();
    LOOP(i, n){
      cin >> s;
      s_i[s] = i;
      i_s[i] = s;
      al.push_back(vi {});
      dfs_num[i] = UNVISITED;
      dfs_low[i] = UNVISITED;
      dfs_parents[i] = UNVISITED;
      isCamera[i] = false;
    }
    cin >> r;
    LOOP(i, r){
      cin >> a >> b;
      al[s_i[a]].push_back(s_i[b]);
      al[s_i[b]].push_back(s_i[a]);
    }
    for(int i = 0; i < n; ++i){
      if (dfs_num[i] == UNVISITED){
        root = i; rootChildren = 0;
        dfsAPB(i);
        isCamera[root] = (rootChildren>1);
      }
    }
    for(int i = 0; i < n; ++i){
      if(isCamera[i] == true){
        camera_points.push_back(i_s[i]);
      }
    }
    sort(camera_points.begin(), camera_points.end());
    cout << "City map #"  << case_no++ << ": ";
    cout << camera_points.size() << " camera(s) found"<< "\n";
    for(int i = 0;i < camera_points.size(); ++i){
      cout << camera_points[i] << "\n";
    }
    cout << endl;
  }


  return 0;
}

