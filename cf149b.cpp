#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

int64_t toDec(string s, int base){
  int64_t output = 0;
  int64_t digit;
  int64_t power = 1;
  for (int i = s.size()-1; i >= 0; --i) {
    if (s[i] <= '9'){
      digit = s[i] - '0';
    }
    else if (s[i] >= 'A'){
      digit = s[i] -'A' + 10;
    }
    output += digit * power;
    power *= base;
  }
  return output;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int sep = s.find(':');
  string a = s.substr(0, sep);
  string b = s.substr(sep+1, s.size() - sep);

  int i = 0;
  while(a[i] == '0')i++;
  a = a.substr(i, a.size()-i);
  i = 0;
  while(b[i] == '0')i++;
  b = b.substr(i, b.size()-i);

  if(a[a.size()-2] == 0 && a[a.size()-1] <= 'N'){
    std::cout << -1 << std::endl;
    return 0;
  }
  if(b[b.size()-2] == 0 && b[b.size()-1] <= 'N'){
    std::cout << -1 << std::endl;
    return 0;
  }

  char mi = '0'- 1;

  for (char c : a) { mi = max(mi, c); }
  for (char c : b) { mi = max(mi, c); }

  int maxa = 2;
  int maxb = 2;
  //cout <<toDec(a, 11) << endl;
  while(toDec(a, maxa)< 24){maxa++; }
  while(toDec(b, maxb)< 60){maxb++; }
  int ma = min(maxa, maxb);

  for (int i = mi-'0'; i < ma; ++i) {
    std::cout << i << " \n"[i==ma-1];
  }


  return 0;
}

