#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
//typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

bool isType(string s){
  if (s == "pair") return false;
  return true;
}


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<string> st;
  string s;

  while(cin >> s){
    if(st.size() < 2 ){
      st.push_back(s);
    }
    else{
      //std::cout << s << std::endl;
      st.push_back(s);
      while(
        st.size() > 2 &&
        isType(st[st.size()-1]) &&
        isType(st[st.size()-2]) &&
        st[st.size()-3] == "pair"){

        string t1 = st.back(); st.pop_back();
        string t2 = st.back(); st.pop_back();
        string s3 = st.back(); st.pop_back();
        string w = s3+"<"+t2+","+t1+">";
        st.push_back(w);
      }
    }
  }

  if (st.size()> 1 ){
    std::cout << "Error occurred"  << std::endl;
  }
  else{
    std::cout << st.back() << std::endl;
  }

  return 0;
}

