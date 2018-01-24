#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100004

int n, k;
int v[LIMIT];
int stress[LIMIT];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  for (int i = 0; i < n; i++) { cin >> v[i]; }

  for (int i = 0; i <= k; i++) { stress[i] = 0;}

  int l= 0, r = 0;
  while(l < n){
    while(r < n && v[r] == v[l]) r++;
    r--;
    int genre = v[l];
    if (l == 0 ) {
      stress[genre]--;
    }
    else if( r == n-1){
      stress[genre]--;
    }
    else if (v[l-1] == v[r+1]){
      stress[genre]-= 2;
    }
    else if(v[l-1] != v[r+1]){
      stress[genre]--;
    }
    l = r+1;
    r = l;
  }

  int exclude, smallest = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if (stress[i] < smallest){
      smallest = stress[i];
      exclude = i;
    }
  }

  std::cout << exclude << std::endl;

  return 0;
}

