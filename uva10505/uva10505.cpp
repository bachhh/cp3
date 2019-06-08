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


void swap(int32* a, int32* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

template < typename F, typename S >
void debug(const pair< F, S > & p ) {
  cout << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
void debug(const vector< T > &v ) {
  typename vector< T > :: const_iterator it;
  cout << "{ ";
  for(int i =0; i < v.size(); ++i){
    cout << v[i] <<  ", "[i == (v.size()-1)];
  }
  cout << " }" << endl;
}

template < typename T >
void debug( const set< T > &v ) {
  cout << "[";
  typename set< T > :: const_iterator it;
  for ( it = v.begin(); it != v.end(); it++ ) {
      if( it != v.begin() ) cout << ", ";
        cout << *it;
  }
  cout << "]";
}

template < typename F, typename S >
void debug( const map< F, S > &v ) {
  cout << "[";
  typename map< F , S >::const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    if( it != v.begin() ) cout << ", ";
      cout << it -> first << " = " << it -> second ;
  }
  cout << "]";
}

template < typename T >
void debug( const vector< vector< T > > &v ) {
  cout << "\n";
  typename vector< vector< T > > :: const_iterator row;
  typename vector< T > :: const_iterator col;
  for( row = v.begin(); row != v.end(); ++row ) {
    for( col = (*row).begin(); col != (*row).end(); ++col) {
      cout << *col << " \n"[col == prev((*row).end())];
    }
  }
  cout << "\n";
}

void debug( const vii &v ) {
  size_t s = v.size();
  for(int i = 0; i < s; ++i){
    cout << "(" << v[i].first + 1 << ", " << v[i].second << ")" << " \n"[i == (s-1)];
  }
}

void debug( const vector< vii > &v ) {
  for(int i = 0; i < v.size(); ++i){
    cout << i+1 << " | ";
    for( int j = 0; j < v[i].size(); ++j ) {
      cout << "(" << v[i][j].first + 1 << ", " << v[i][j].second << ")"
        << " \n"[j == v[i].size()-1];
    }
  }
  cout << "\n";
}

template < typename T>
void printM(T *matrix, size_t row, size_t col){
  cout << "\n";
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      cout << matrix[i][j] << " \n"[j == col-1];
    }
  }
  cout << "\n";
}

vvi al;

int color[300];
int black, white;
bool dfs_bipartite(int u, int u_color){
  color[u] = u_color;
  bool r = true;
  for(int neighbor : al[u]){
    if (color[neighbor] == 0){
      r = r && dfs_bipartite(neighbor, -u_color);
    }
    else if (color[neighbor] == u_color){
      r = false;
      break;
    }
  }
  if (r) {
    if(u_color < 0){
      black++;
    }
    else if (u_color > 0){
      white++;
    }
  }
  return r;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  queue<int> q;

  cin >> m;
  while(m--){
    cin >> n;
    al.clear();
    LOOP(i, n){
      al.push_back(vi {});
      color[i] = 0;
    }

    LOOP(i, n){
      cin >> a;
      LOOP(z, a){
        cin >> b;
        al[i].push_back(b-1);
        al[b-1].push_back(i);
      }
    }

    bool flag= true;
    int output = 0;
    for(int node = 0; node < n; ++node){
      black= 0; white= 0;
      if (color[node] == 0 ){
        flag = flag && dfs_bipartite(node, 1);
      }
      output += MAX(black, white);
    }
    if (flag) cout << output << endl;
    else cout << 0 << endl;
  }
  return 0;
}
