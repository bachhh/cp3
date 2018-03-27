#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

char NEG(char c){ return "01"[c=='0'];}
char EQ(char c, char d){return "01"[c==d];}
char AND(char c, char d){ return "01"[c=='1' && d=='1'];}
char OR(char c, char d){return "10"[c=='0'&&d=='0'];}
char IMP(char c, char d){return"10"[c=='1'&&d=='0'];}

bool eval(string s){
  stack<char> st;
  for(char c : s){
    if( (c=='0' || c=='1') && !st.empty()){
      int flag = 1;
      while(!st.empty() && flag--){
        if((c=='0' || c=='1') &&(st.top()=='0'||st.top()=='1')){
          char a = st.top(); st.pop();
          char op = st.top(); st.pop();
          if(op == 'K'){
            c=AND(a, c);
          }
          if(op == 'A'){
            c=OR(a,c);
          }
          if(op == 'C'){
            c = IMP(a, c);
          }
          if(op == 'E'){
            c = EQ(a, c);
          }
          flag++;
        }
        else if( (c=='0' || c== '1') && st.top()=='N') {
          c = NEG(c);
          st.pop();
          flag++;
        }
      }
    }
    st.push(c);
    //std::cout << st.top() << std::endl;
  }
  assert(st.size()==1);
  return st.top() == '1';
}

bool tau(string w){
  bool flag = true;
  for (int p = 0; p < 2; ++p) {
    for(int q = 0; q < 2; ++q){
      for (int r = 0; r < 2; ++r) {
        for (int s = 0; s < 2; ++s) {
          for (int t = 0; t < 2; ++t) {
            string wcp = w;
            for (int i = 0; i < wcp.size(); ++i) {
              if(wcp[i] == 'p'){ wcp[i] = p+'0'; }
              else if(wcp[i] == 'q'){ wcp[i] = q+'0'; }
              else if(wcp[i] == 'r'){ wcp[i] = r+'0'; }
              else if(wcp[i] == 's'){ wcp[i] = s+'0'; }
              else if(wcp[i] == 't'){ wcp[i] = t+'0'; }
            }
            if (!eval(wcp)){
              //std::cout << p << std::endl;
              return false;
            }
          }
        }
      }
    }
  }
  return true;
}


//  ***** MAIN *****
int main(){

  string ans[2] ={"not", "tautology"};
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  while(cin >> s && s != "0"){
    std::cout << ans[tau(s)] << std::endl;
  }

  return 0;
}

