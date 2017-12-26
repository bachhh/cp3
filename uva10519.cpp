#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

string sum(string a, string b){
  if(a == "0"|| a == "" ) return b;
  if(b == "" || b == "0") return a;
  int co = 0;
  int ap = a.size()-1;
  int bp = b.size()-1;
  string r ="";

  while(ap>=0 && bp >= 0){
    r += (a[ap]-'0' + b[bp]-'0' + co)%10 + '0';
    co = (a[ap]-'0' + b[bp]-'0' + co)/10;
    ap--;
    bp--;
  }
  while(ap >= 0){
    r+= (a[ap] - '0' + co)%10 +'0';
    co =(a[ap] - '0' + co)/10;
    ap--;
  }
  while(bp >= 0){
    r+= (b[bp] - '0' + co)%10 +'0';
    co =(b[bp] - '0' + co)/10;
    bp--;
  }
  if(co > 0) r += co+'0';
  reverse(r.begin(), r.end());
  int j = 0;
  while(r[j] == '0') j++;
  r.erase(0, j);
  return r;
}

string subtract(string a, string b){
  if(a == "0"|| a == "" ) return b;
  if(b == "" || b == "0") return a;
  int co = 0;
  int ap = a.size()-1;
  int bp = b.size()-1;
  string r ="";

  while(ap >= 0 && bp >= 0){
    if (a[ap] - b[bp] - co < 0){
      r += (a[ap] + 10 - b[bp] - co) + '0';
      co = 1;
    }
    else {
      r += (a[ap] - b[bp] - co) + '0';
      co = 0;
    }
    ap--;
    bp--;
  }


  while(ap>= 0){
    if (a[ap] - '0' - co < 0){
      r += (a[ap] + 10 - co);
      co = 1;
    }
    else {
      r += (a[ap]- co);
      co =0;
    }
    ap--;
  }

  reverse(r.begin(), r.end());
  int j = 0;
  while(r[j] == '0') j++;
  r.erase(0, j);

  if(r.empty()) return "0";
  return r;
}

string pow10(string a, int p){
  for (int i = 0; i < p; i++) {
    a+='0';
  }
  return a;
}

string multiply(string a, char b){
  if (b == '0' ) return "0";
  if (b == '1' ) return a;
  int co = 0;
  int ap = a.size()-1;
  string r = "";
  while(ap >= 0){
    r += ((a[ap]-'0')*(b-'0')+co)%10 +'0';
    co = ((a[ap]-'0')*(b-'0')+co)/10;
    ap--;
  }
  if (co > 0) r+= co+'0';
  reverse(r.begin(), r.end());
  return r;
}

string multiply(string a, string b){
  string accumulator = "0";
  for (int i = 0; i < b.size(); i++) {
    accumulator = sum(accumulator,pow10(multiply(a, b[i]), b.size()-i-1));
  }
  return accumulator;
}

map<char, string> square = {{'0' ,"0" },
                            {'1' ,"1" },
                            {'2' ,"4" },
                            {'3' ,"9" },
                            {'4' ,"16" },
                            {'5' ,"25" },
                            {'6' ,"36" },
                            {'7' ,"49" },
                            {'8' ,"64" },
                            {'9' ,"81" }};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string n;
  // N*(N-1) + 2
  // = N^2 - N + 2
  string accumulator;
  string nextterm;

  while(cin >> n){
    if (n == "0"){ std::cout << 1 << std::endl; continue;}

    string one = subtract(n, "1");
    string two = multiply(n, one );
    string three = sum(two, "2");
    std::cout << three << std::endl;

  }

  return 0;
}
