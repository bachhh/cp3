#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
int n, m;
int size[5];
int packet[3000];

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m && n && m){

    for (int i = 0; i < n; i++) { cin >> size[i]; }
    for (int i = 0; i < m*3; i++) { cin >> packet[i]; }
    int byte[5] = {0};
    int buffer[10000] = {0};
    int buffEnd = 0, buffSize = 0, minBuffSize = 0;
  }

  return 0;
}

