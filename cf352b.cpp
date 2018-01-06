#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

typedef pair<int, int> ii;


typedef long int int32; typedef long long int int64;
typedef unsigned long int uint32; typedef unsigned long long int uint64;
typedef pair<int, int> ii; typedef vector<ii> vii; typedef vector<int> vi;
typedef vector<vi> vvi;

// BEGIN DEBUG
template < typename F, typename S >
void debug(const pair< F, S > & p ) {
  cout << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
void debug(const vector< T > &v ) {
  typename vector< T > :: const_iterator it;
  for( it = v.begin(); it != v.end(); it++ ) {
    cout << *it <<  " \n"[it == std::prev(v.end())];
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
void debug(T *matrix, size_t row, size_t col){
  cout << "\n";
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      cout << matrix[i][j] << " \n"[j == col-1];
    }
  }
  cout << "\n";
}
// END DEBUG

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int a;

  map<int, vector<int>> m;
  vector<ii> output;

  for (int i = 0; i < n; i++) {
    cin >> a;
    m[a].push_back(i);
  }

  for (auto it  = m.begin(); it != m.end(); it++ ) {

    if(it->second.size() == 1){
      output.push_back({it->first, 0});
    }
    else {
      int diff = it->second[1]  - it->second[0];
      for (int i = 1; i < it->second.size(); i++) {
        if (it->second[i] - it->second[i-1] != diff){
          diff = -1;
          break;
        }
      }
      if (diff > -1){
        output.push_back({it->first, diff});
      }
    }
  }
  std::cout << output.size() << std::endl;
  for (int i = 0; i < output.size(); i++) {
    printf("%d %d\n", output[i].first, output[i].second);
  }

  return 0;
}

