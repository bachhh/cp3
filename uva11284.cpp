#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define INF 1e9

typedef pair<int, double> id;
typedef vector<id> vid;

vector<vector<double>> am;
vector<double> dvdCost;

double dp[1<<13][50];
int n, m, p;


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
      cout << *col << "\t\n"[col == prev((*row).end())];
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
      cout << matrix[i][j] << "\n"[j == col-1];
    }
  }
  cout << "\n";
}
// END DEBUG


double solve(int mask, int lastnode){
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(famse);
  cin.tie(NULL);

  int tc; cin >> tc;
  while(tc--){

    cin >> n >> m;

    am = vector<vector<double>>(n+1, vector<double>(n+1, -1));
    int x, y;
    double cost;

    for (int i = 0; i < m; i++) {
      cin >> x >> y >> cost;
      am[x][y] = cost;
      am[y][x] = cost;
    }

    cin >> p;
    dvdCost = vector<double>(n+1, -1);
    double saving = 0;
    for (int i = 0; i < p; i++) {
      cin >> x >> cost;
      saving += cost;
      dvdCost[x] = cost;
    }

    debug(am);
    for (int i = 1; i <= n; i++) {
      if(dvdCost[i] < 0){
        for (int j = 0; j <= n; j++) {
          if (am[i][j] < 0 ) continue;
          for (int k = j+1; k <= n; ++k) {
            if(am[i][k] < 0) continue;
            std::cout << j << "|" << k << std::endl;
            debug(am);
            am[k][i] = am[j][i] = -1;
            am[j][k] += am[i][j] + am[i][k];
            am[k][j] += am[i][j] + am[i][k];
            am[i][k] = -1;
          }
          am[i][j] = -1;
        }
      }
    }

    debug(am);

    double travelCost = solve(1, 0);

    if(travelCost - saving < 0){
      printf("Daniel can save $%.2f\n", travelCost - saving);
    }
    else {
      printf("Don't leave the house\n");
    }
  }



  return 0;
}

