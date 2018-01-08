#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

string longestCommonSubsequence(string a, string b){
  struct entry{
    char commonchar;
    int length;
    struct entry* previous;
  };

  struct entry table[a.size()][b.size()];

  for (int i = 0; i <= a.size(); i++) {
    for (int j = 0; j <= b.size(); j++) {

    }
  }

}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}

