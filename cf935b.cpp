#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c = 0;
  cin >> n;
  char ch;
  int x = 0, y = 0;
  int state = 0;

  while(n--){
    cin >> ch;
    if(ch == 'U'){
      y++;
      if (y > x && state != 1 ){
        c++;
        state = 1;
      }
    }
    if (ch == 'R'){
      x++;
      if (x > y && state != -1) {
        c++;
        state = -1;
      }
    }
    //printf("%c %d %d %d\n", ch, state, x, y);
  }

  std::cout << c-1 << std::endl;

  return 0;
}

