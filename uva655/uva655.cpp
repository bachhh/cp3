#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

bool find_vector(vector<int> vector, int value){
  bool flag = false;
  for (int i : vector){
    if (i == value ) {
      flag = true;
      break;
    } 
  }
  return flag;
}

int main(){

  //freopen("input.txt","r", stdin);
  //freopen("output.txt","w", stdout);
  int64 m;
  cin >> m;
  while(m--){
    int n, k;
    cin >> n;
    cin >> k;

    map<int, bool> bank;
    for (int i = 1; i<= n; i++){
      bank[i] = false;
    }

    while(k--){
      int p_i;
      vector<int> temp_array;
      cin >> p_i;
      p_i *= 2;
      int temp;
      while(p_i--){
        cin >> temp;
        temp_array.push_back(temp);
      }
      char op;
      cin >> op;
      if (op == '>' || op == '<'){
        for (int i = 1; i <= n; i++){
          if (find_vector(temp_array, i) == false)
            bank[i] = true;
        }
      }
      else if (op == '='){
        for (int i : temp_array){
          bank[i] = true;
        }
      }
    }

    int count = -1;
    int index = 0;
    for (int i = 1; i <= n; i++){
      if (bank[i] == false) {
        count++;
        index = i;
      }
    }

    if (count < 1 ) cout << index << endl;
    else cout << 0 << endl;

  }

}
