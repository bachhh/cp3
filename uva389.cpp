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

#define LIMIT 100

char itochar[17]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                            'A', 'B', 'C', 'D', 'E', 'F', 'T'};

map<char, int> chartoi ={ {'0',0},
                          {'1',1},
                          {'2',2},
                          {'3',3},
                          {'4',4},
                          {'5',5},
                          {'6',6},
                          {'7',7},
                          {'8',8},
                          {'9',9},
                          {'A',10},
                          {'B',11},
                          {'C',12},
                          {'D',13},
                          {'E',14},
                          {'F',15} };

int64_t toBase10(string n, int base){
  int64_t temp = 0;
  for (int i = 0; i < n.size() ; i++) {
    temp += chartoi[n[i]] * pow(base, n.size()-i-1);
  }
  return temp;
}

string toBase(int64_t n, int base){
  string r = "";
  int i = 0;
  while(n > 0){
    r.insert(0, 1, itochar[n%base]);
    n /= base;
  }

  int s = r.size();
  for (int i = s; i < 7 ; i++) {
    r.insert(0, 1, ' ');
  }

  if (r.size() > 7) return "  ERROR";
  return r;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string input;
  string output;
  int64_t tempvalue;
  int base1;
  int base2;
  while(cin >> input >> base1 >> base2){
    tempvalue = toBase10(input, base1 );
    if (tempvalue == 0){
      std::cout << "      0" << std::endl;
      continue ;
    }
    else if (base2 == 10){
      if (tempvalue == 0){
        std::cout << "      0" << std::endl;
        continue ;
      }
      if ( tempvalue < 10000000){
        printf("%7ld\n", tempvalue);
      }
      else{
        printf("%7s\n", "ERROR");
      }
    }
    else{
      cout << toBase(tempvalue, base2) << endl;
    }
  }


  return 0;

}

