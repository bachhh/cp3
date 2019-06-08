#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int a[100];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      for (int k = j+1; k < n; ++k) {

        if (a[i] == a[j] + a[k]){
          printf("%d %d %d\n",  i+1 ,  j+1 ,  k+1 );
          return 0;
        }
        if( a[j] == a[i] + a[k]){
          printf("%d %d %d\n",  j +1,  i+1 ,  k+1 );
          return 0;
        }
        if( a[k] == a[i] + a[j] ){
          printf("%d %d %d\n",  k +1,  j +1,  i +1);
          return 0;
        }
      }
    }
  }

  std::cout << -1 << std::endl;

  return 0;
}

