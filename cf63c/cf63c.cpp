#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int checkBull(string e, string s){
  int b = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if(e[i] == s[j] && i == j){
        b++;
      }
    }
  }
  return b;
}

int checkCow(string e, string s){
  int c = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if(e[i] == s[j] && i != j) c++;
    }
  }
  return c;
}

bool check( vector<tuple<string, int, int>> v, string s){
  for (auto t : v) {
    string e = get<0>(t);
    int b = get<1>(t);
    int c  = get<2>(t);
    if (checkBull(e, s) != b || checkCow(e, s) != c){
      return false;
    }
  }
  return true;
}

string nextStr(string s){
  string w = s;
  bool flag = true;
  int i = 3;
  while(flag){
    w[i] = w[i]+1;
    if (w[i] >'9'){
      w[i] = '0';
      i--;
      flag = true;
    }
    else{
      flag = false;
    }
  }
  return w;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<tuple<string, int, int>> rules;
  vector<string> guess(10000, "");
  vector<bool> correct(10000, false);
  string temp;
  int bull, cow;

  guess[0] = "0000";

  for (int i = 1; i < 10000; i++) {
    guess[i] = nextStr(guess[i-1]);
  }

  for (int i = 0; i < n; i++) {
    cin >> temp >> bull >> cow;
    rules.push_back(tuple<string, int, int>(temp, bull, cow));
  }

  for (int i = 0; i < guess.size(); i++) {
    correct[i] = check(rules, guess[i]);
  }

  int counter = 0;
  for (int i = 0; i < guess.size(); i++) {
    if (correct[i]){
      temp = guess[i];
      counter++;
    }
  }
  if (counter > 1){
    std::cout << "Need more data" << std::endl;
  }
  else if (counter == 0){
    std::cout << "Incorrect data" << std::endl;
  }
  else {
    std::cout << temp << std::endl;
  }

  return 0;
}

