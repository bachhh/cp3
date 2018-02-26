#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<int> front(n);
  vector<int> back(n);
  map<int, int> overlap;
  for (int i = 0; i < n; ++i) {
    cin >> front[i] >> back[i];
    if(front[i] == back[i]){
      overlap[front[i]]++;
    }
  }

  sort(front.begin(), front.end());
  sort(back.begin(), back.end());

  int mi = INT_MAX;

  for(int i : front){
    int fu = upper_bound(front.begin(), front.end(), i)-front.begin();
    int fl = lower_bound(front.begin(), front.end(), i)-front.begin();
    int bu = upper_bound(back.begin(), back.end(), i)-back.begin();
    int bl = lower_bound(back.begin(), back.end(), i)-back.begin();
    if (fu - fl >= (n+1)/2){
      mi = 0;
      break;
    }
    else if (fu -fl + bu - bl - overlap[i] >= (n+1)/2 ){
      mi = min((n+1)/2 - (fu-fl) , mi);
    }
  }
  for(int i : back){
    int bu = upper_bound(back.begin(), back.end(), i)-back.begin();
    int bl = lower_bound(back.begin(), back.end(), i)-back.begin();
    if(bu-bl >= (n+1)/2){
      mi = min(mi, (n+1)/2);
    }
  }

  if (mi < INT_MAX){
    std::cout << mi << std::endl;
  }
  else {
    std::cout << -1 << std::endl;
  }
  return 0;
}

