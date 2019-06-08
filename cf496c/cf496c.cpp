#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define VISITED 1
#define UNVISITED -1

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 101

int isLess(string a, string b){
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < b[i]) return -1;
    if (a[i] > b[i]) return i;
  }
  return -1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<string> table;
  string temp;

  int colleft= m;
  int counter = 0;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    table.push_back(temp);
  }


  int c = n;
  while(c>0){
    for (int i = 0; i < n-1; i++) {
      int column = isLess(table[i], table[i+1]);
      if (column >= 0){
        for (int i = 0; i < n; i++) {
          table[i].erase(column, 1);
        }
        c = n+1;
        counter++;
        break;
      }
    }
    c--;
  }
  std::cout << counter << std::endl;




  return 0;

}

