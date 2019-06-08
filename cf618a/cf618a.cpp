#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  stack<int> st;

  for (int i = 1; i <= n; i++) {
    int s = 1;
    if (st.empty()){
      st.push(s);
    }
    else {
      while(!st.empty() && st.top() == s){
        st.pop();
        s++;
      }
      st.push(s);
    }
  }

  vector<int> v;
  while(!st.empty()){
    v.push_back(st.top());
    st.pop();
  }

  for (int i = v.size()-1; i>= 0; --i) {
    std::cout << v[i] << " \n"[i==0];
  }

  return 0;
}

