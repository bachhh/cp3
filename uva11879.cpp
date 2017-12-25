#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

// Cache as much as i can to avoid implement subtraction of negative
map<string, bool> isMultiple = {{"-17" , true },
                                {"0"   , true },
                                {"17"  , true },
                                {"34"  , true },
                                {"-34"  , true },
                                {"51"  , true },
                                {"-51"  , true },
                                {"68"  , true },
                                {"-68"  , true },
                                {"-85"  , true },
                                {"85"  , true },
                                {"102" , true },
                                {"119"  , true },
                                {"136"  , true },
                                {"153"  , true },
                                {"170"  , true },
                                {"187"  , true },
                                {"204"  , true },
                                {"221"  , true },
                                {"238"  , true },
                                {"255"  , true },
                                {"272"  , true },
                                {"289"  , true },
                                {"306"  , true },
                                {"323"  , true },
                                {"340"  , true },
                                {"357"  , true },
                                {"374"  , true },
                                {"391"  , true },
                                {"408"  , true },
                                {"425"  , true },
                                {"442"  , true },
                                {"459"  , true }};
map<char, string> timesfive = {
                              {'0' ,"0" },
                              {'1' ,"5" },
                              {'2' ,"10" },
                              {'3' ,"15" },
                              {'4' ,"20" },
                              {'5' ,"25" },
                              {'6' ,"30" },
                              {'7' ,"35" },
                              {'8' ,"40" },
                              {'9' ,"45" } };

string Subtract(string a, string b){
  int ap = a.size()-1;
  int bp = b.size()-1;
  int co = 0;
  string r = "";
  while(ap >= 0 && bp >= 0){
    if (a[ap] < b[bp] + co){
      r.insert(0, 1, a[ap]+10 - b[bp]-co + '0');
      co = 1;
    }
    else{
      r.insert(0, 1, a[ap] - b[bp] - co + '0');
      co = 0;
    }
    ap--;
    bp--;
  }
  while(ap >= 0){
    if ( a[ap] - '0' >= co){
      r.insert(0, 1, a[ap] - co);
      co = 0;
    }
    else {
      r.insert(0, 1, a[ap]+10-co);
      co = 1;
    }
    ap--;
  }
  while(bp >= 0){
    if (b[bp] - '0' >= co){
      r.insert(0, 1, b[bp] - co);
      co = 0;
    }
    else {
      r.insert(0, 1, b[bp]+10-co);
      co = 1;
    }
    bp--;
  }
  int trim = 0;
  while(r[trim] =='0') trim++;
  r.erase(0, trim);
  return r;
}

bool solve(string a){
  if (a.size() < 3){
    return isMultiple.find(a) != isMultiple.end();
  }
  else if (a.size() ==3 &&
      a[0] <= '4' &&
      a[1] <= '5' &&
      a[2] <= '9'){
    return isMultiple.find(a) != isMultiple.end();
  }
  return solve(Subtract(a.substr(0,a.size()-1), timesfive[ a[ a.size()-1 ] ]));
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while(cin>>s && s != "0"){
    std::cout << solve(s) << std::endl;
  }

  return 0;
}

