#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vector<int> v(n+1);
  vector<int> minuteRoom(n+1, -1);

  // minute 0 = room 1
  minuteRoom[0] = 1;

  int counter = 1;
  int record;

  for (int i = 1; i <= n; i++) {
    cin >> record;
    // if this record is for last time we visited a room
    if (minuteRoom[record] != -1){
      minuteRoom[i] = minuteRoom[record];
      minuteRoom[record] = -1;
    }
    else{
      minuteRoom[i] = counter++;
    }
  }
  std::cout << counter << std::endl;

  return 0;
}

