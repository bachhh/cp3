#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;

int type(string s ){
  if (s[0] == s[1] && s[1] == s[3] &&
      s[3] == s[4] && s[4] == s[6] &&
      s[6] == s[7])
    return -1;
  else if (s[0] > s[1] && s[1] > s[3] &&
      s[3] > s[4] && s[4] > s[6] &&
      s[6] > s[7])
    return 0;
  return 1;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int bestgirl = 0, bestpizza = 0, besttaxi = 0;
  vector<string> bestg, bestpiz, besttax;

  for (int i = 0; i < n; ++i) {
    int s; cin >>s;
    string name; cin >> name;

    int girl = 0, pizza = 0, taxi = 0;
    string phone;

    for (int j = 0; j < s; j++) {
      cin >> phone;
      if(type(phone) == -1){
        taxi++;
      }
      if(type(phone) == 0){
        pizza++;
      }
      if(type(phone) == 1){
        girl++;
      }
    }

    if (girl > bestgirl){
      bestgirl = girl;
      bestg.clear();
      bestg.push_back(name);
    }
    else if(girl == bestgirl){
      bestpiz.push_back(name);
    }
    if (taxi > besttaxi){
      besttaxi = taxi;
      besttax.clear();
      besttax.push_back(name);
    }
    else if(taxi == besttaxi){
      bestpiz.push_back(name);
    }
    if (pizza> bestpizza){
      bestpizza =pizza;
      bestpiz.clear();
      bestpiz.push_back(name);
    }
    else if(pizza == bestpizza){
      bestpiz.push_back(name);
    }
  }
  std::cout << "If you want to call a taxi, you should call: ";
  for (int i = 0; i < besttax.size(); ++i) {
    cout << besttax[i];
    if(i==besttax.size()-1)cout << ".\n";
    else std::cout << ", ";
  }
  std::cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < bestpiz.size(); ++i) {
    cout << bestpiz[i];
    if ( i==bestpiz.size()-1) cout << ".\n";
    else std::cout << ", ";
  }
  std::cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < bestg.size(); ++i) {
    cout << bestg[i];
    if(i==bestg.size()-1) cout << ".\n";
    else std::cout << ", ";
  }

  return 0;
}

