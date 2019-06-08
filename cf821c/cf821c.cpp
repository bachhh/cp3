#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  stack<int> st;
  int next =1;
  int t = 0;
  for (int i = 0; i < 2*n; ++i) {
    string cmd; int box;
    cin >> cmd;
    if (cmd == "add"){
      cin >> box;
      st.push(box);
    }
    else{
      if (st.empty()){
        next++;
        continue;
      }
      else if (st.top() == next){
        st.pop();
        next++;
      }
      // We can reset the stack very time we rearrange them
      else {
        t++;
        st = stack<int>();
        next++;
      }
    }
  }
  std::cout << t << std::endl;

  return 0;
}

