#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int v[100001];
  while(cin >> n && n != 0){

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n ; i++) {
      sum += v[i];
      maxsum = max(maxsum, sum);
      if(sum < 0) sum = 0;
    }

    if (maxsum > 0){
      printf("The maximum winning streak is %d.\n", maxsum);
    }
    else {
      printf("Losing streak.\n");
    }

  }

  return 0;
}

