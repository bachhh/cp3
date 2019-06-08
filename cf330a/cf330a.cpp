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
  typename vector< T > :: const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    os << *it <<  " \n"[it != v.begin()];
  }
  return os << "";
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

ostream &operator << ( ostream & os, const vii &v ) {
  size_t s = v.size();
  for(int i = 0; i < s; ++i){
    os << "(" << v[i].first + 1 << ", " << v[i].second << ")" << " \n"[i == (s-1)];
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
template < typename T>
void printf(T *matrix, size_t row, size_t col){
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
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  char cake[10][10];
  cin >> r >> c;

  bool s_r[10] = {false};
  bool s_c[10] = {false};
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      cin >> cake[i][j];
      if (cake[i][j] == 'S'){
        s_r[i] = true;
        s_c[j] = true;
      }
    }
  }

  // Eat row by row'
  int output = 0;
  int eaten;

  for(int row = 0; row < r; ++row){
    if(!s_r[row]){
      for(int col = 0; col < c; ++col){
        if (cake[row][col] == '.'){
          output++;
          cake[row][col] = 'e';
        }
      }
    }
  }

  // Eat col by col
  for(int col = 0; col < c; ++col){
    if (!s_c[col]){
      for(int row = 0; row < r; ++row){
        if ( cake[row][col] == '.'){
          cake[row][col] = 'e';
          output++;
        }
      }
    }
  }

  cout << output << endl;

  return 0;
}

