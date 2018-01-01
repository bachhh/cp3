#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string input; cin >> input;
  int counter_matrix[LIMIT][LIMIT];
  int paren = 0;
  int square = 0;
  int max_quare = 0;
  int start;

  for (int i = 0; i < input.size(); i++) {

    if (input[i] == '['){
      if (paren == 0 && square == 0) start = i;
      square++;
    }
    else if (input[i] == '('){
      if (paren == 0 && square == 0) start = i;
      paren++;
    }
    else if (input[i] == ']'){
      square--;
      if(square < 0) square = 0;
      // This sequence is valid
      if (square == 0 && paren == 0){
        counter_matrix[start][i] = 1;
      }
    }
    else if (input[i] == ')'){
    }

  }


  return 0;
}

