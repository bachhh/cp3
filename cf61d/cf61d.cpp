#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

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
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
  os << "{";
  typename vector< T > :: const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    if( it != v.begin() ) os << ", ";
      os << *it;
    }
  return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
  os << "[";
  typename set< T > :: const_iterator it;
  for ( it = v.begin(); it != v.end(); it++ ) {
      if( it != v.begin() ) os << ", ";
        os << *it;
  }
  return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
  os << "[";
  typename map< F , S >::const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    if( it != v.begin() ) os << ", ";
      os << it -> first << " = " << it -> second ;
  }
  return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< vector< T > > &v ) {
  os << "\n";
  typename vector< vector< T > > :: const_iterator row;
  typename vector< T > :: const_iterator col;
  for( row = v.begin(); row != v.end(); ++row ) {
    for( col = (*row).begin(); col != (*row).end(); ++col) {
      os << *col << "\n"[col == prev((*row).end())];
    }
  }
  return os << "\n";
}

ostream &operator << ( ostream & os, const  vii &v ) {
  for(int i = 0; i < v.size(); ++i){
    os << "(" << v[i].first + 1 << ", " << v[i].second << ")"
      << " \n"[i == v.size()-1];
  }
}

ostream &operator << ( ostream & os, const vector< vii > &v ) {
  for(int i = 0; i < v.size(); ++i){
    os << i+1 << " | ";
    for( int j = 0; j < v[i].size(); ++j ) {
      os << "(" << v[i][j].first + 1 << ", " << v[i][j].second << ")"
        << " \n"[j == v[i].size()-1];
    }
  }
  return os << "\n";
}

vector<vii> AL;
int dfs_flag[100001];

int64 dfs(int u){

  dfs_flag[u] = VISITED;

  int64 max_d = 0,  d;
  int neighbor;
  for(int i = 0; i < AL[u].size(); ++i){
    neighbor = AL[u][i].first;
    if (dfs_flag[neighbor] == UNVISITED){
      d = dfs(neighbor);
      max_d = MAX(max_d, AL[u][i].second + d);
    }
  }
  return max_d;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, d;
  int n;
  cin >> n;

  LOOP(i, n){
    AL.push_back(vii {});
    dfs_flag[i] = UNVISITED;
  }
  int64 total = 0;

  LOOP(i, n-1){
    cin >> a >> b >> d;
    total += 2*d;
    AL[a-1].push_back( {b - 1, d});
    AL[b-1].push_back( {a - 1, d});
  }

  cout << total - dfs(0) << endl;

  return 0;
}

