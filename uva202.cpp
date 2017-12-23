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


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int num;
  int deno;
  string cycleStr;

  // Almost forgot primary school maths
  while(cin >> num >> deno && (num||deno)){
    cycleStr = "";
    int n = num;
    int d = deno;
    n = n%deno;
    n *= 10;
    vector<int> dividend(30004, -1);

    while(dividend[n] == -1){
      dividend[n] = cycleStr.size();
      cycleStr += n/deno + '0';
      n = n%deno;
      n *= 10;
    }

    size_t cycleSize = cycleStr.size() - dividend[n];

    //dividend[n] mark the index that starts the cycle
    // Check if cycle's size is less than 50
    if( cycleStr.size() - dividend[n] <= 50 ){
    }
    else{
      // Cut off 50 digit starting from the firt digit of cycle
      cycleStr = cycleStr.substr(0, dividend[n] + 50);
      cycleStr += "...";
    }

    // Insert '(' before the start of cycle
    cycleStr.insert(dividend[n], 1, '(');
    cycleStr += ")";
    // Insert the integer parts
    cycleStr.insert(0, 1, num/deno + '0');
    cycleStr.insert(1, 1, '.');

    std::cout<<num<<"/"<<deno<<" = ";
    std::cout << cycleStr << std::endl;
    std::cout << "   " << cycleSize;
    std::cout << " = number of digits in repeating cycle\n" << std::endl;

  }

  return 0;

}

