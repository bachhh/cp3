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
  for( it = v.begin(); it != v.end(); it++ ) {
    cout << *it <<  " \n"[it != v.begin()];
  }
  cout << "";
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

void debug(const vector<tuple<int, int, int>>&v){
  printf("\n");
  for(auto t : v){
    printf("{%d, %d, %d}\n",get<0>(t),get<1>(t),get<2>(t)  );
  }
  printf("\n");
}

template < typename T>
void debug(T *arr, int size){
  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

template < typename T>
void debug(T **matrix, size_t row, size_t col){
  cout << "\n";
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      cout << matrix[i][j] << " \n"[j == col-1];
    }
  }
  cout << "\n";
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;

  return 0;

}

