#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int64_t arithsum(int64_t i){
  if(i<0) return 0;
  return i*(i+1)/2;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int matrix[51][51];

  int cal[2000] = {0};
  for (int i = 0; i < n; i++) {
    int64_t sum = i*(n-i) + arithsum(i-1) ;
    cal[sum] = i;
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  int output[51];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += matrix[i][j];
    }
    output[i] = cal[sum];
    // Everybody get to be a genius once in a while
    cal[sum] = n;
  }

  for (int i = 0; i < n; i++) {
    std::cout << output[i] << " \n"[i==n-1];
  }


  return 0;
}

