#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> a;
  if (a == 1){
    printf("%d %d\n", 1, 1);
    printf("%d \n", 1);
    return 0;
  }
  printf("%d %d\n", 2*(a-1), 2);

  printf("%d %d\n", 1, 2);

  return 0;
}

