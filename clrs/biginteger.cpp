#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100
string Negate(string a);
string Sum(string a, string b);
string Subtract(string a, string b);
string Multiply(string a, string b);
string Divide(string a, string b);

string Negate(string a){
  if (a== "0")
    return a;
  else if (a[0] == '-')
    return a.substr(1, a.size());
  else
   return a.insert(0, 1, '-');
}

bool Greater(string a, string b){
  if (a.size() != b.size()) return a.size() > b.size();
  for (int i = 0; i < a.size(); i++) {
    if(a[i] < b[i]) return false;
    if(a[i] > b[i]) return true;
  }
  // a == b
  return false;
}

bool Smaller(string a, string b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = 0; i < a.size(); i++) {
    if(a[i] > b[i]) return false;
    if(a[i] < b[i]) return true;
  }
  // a == b
  return false;
}

bool Equal(string a, string b){
  if (a.size() != b.size() ) return false;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

// Implementation only handles sum of 2 non negative integer
string Sum(string a, string b){

  // User recursion to handle our edge case
  // -a + -b = -(a+b)
  if(a[0] == '-' && b[0] == '-'){
    return Negate(Sum(Negate(a), Negate(b)));
  }
  // -a + b = b-a
  else if(a[0] == '-'){
    return Subtract(b, Negate(a));
  }
  // -b + a = a - b
  else if (b[0] == '-'){
    return Subtract(a, Negate(b));
  }

  string r = "";
  int carryOver = 0;

  int ap = a.size()-1;
  int bp = b.size()-1;

  while(ap >=0 && bp >= 0 ){
    r += ((a[ap]-'0') + (b[bp]-'0') + carryOver)%10 + '0';
    carryOver  = ((a[ap]-'0') + (b[bp]-'0') + carryOver)/10;
    ap--;
    bp--;
  }

  // No more than 1 loop will execute
  while(ap >= 0){
    r += ( (a[ap]-'0') + carryOver)%10 + '0';
    carryOver = (a[ap] - '0' + carryOver)/10;
    ap--;
  }

  while(bp >= 0){
    r += ( (b[bp]-'0') + carryOver)%10 + '0';
    carryOver = (b[bp] - '0' + carryOver)/10;
    bp--;
  }

  // If we still need to carry over
  if (carryOver > 0){
    r += carryOver + '0';
  }
  reverse(r.begin(), r.end());
  return r;
}

// Implementation only handles subtraction of non-negative integer
string Subtract(string a, string b){
  string r = "";

  // User recursion to handle subtracting negative integer
  if(a[0] != '-' && b[0] == '-'){
    return Sum(a, Negate(b));
  }
  else if(a[0] == '-' && b[0] != '-'){
    return Negate(Sum(Negate(a), b));
  }
  else if(a[0] == '-' && b[0] == '-'){
    return Subtract(Negate(b), Negate(a));
  }


  int ap = a.size()-1;
  int bp = b.size()-1;
  int carryOver = 0;

  if(Greater(a, b)){
    while(ap >= 0 && bp >= 0){
      if (b[bp]- '0' + carryOver > a[ap] -'0'){
        r += (a[ap]-'0')*10 - (b[bp] - '0' + carryOver) + '0';
        carryOver = 1;
      }
      else {
        r += ((a[ap] - '0') - (b[bp] - '0') + carryOver) + '0';
        carryOver = 0;
      }
      ap--;
      bp--;
    }

    while(ap >= 0 ){
      if(carryOver > a[ap]-'0'){
        r += ((a[ap] - '0')*10 - carryOver)+'0';
      }
      else{
        r += a[ap];
        carryOver = 0;
      }
      ap--;
    }
  }
  else if(Greater(b, a)) {
    return Negate(Subtract(b, a));
  }
  else{
    return "0";
  }
  reverse(r.begin(), r.end());
  int i = 0;
  while( r[i] < '1'){i++;}
  r.erase(0, i);
  return r;
}

string Multiply(string a, string b){

}

string Divide(string a, string b){
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout << Subtract("111", "112") << std::endl;

  return 0;
}

