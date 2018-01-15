#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  string temp; int mx;
  string team1 = "", team2 = "";
  int count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (team1 == "" && team2 == ""){
      team1 = temp;
      count1++;
    }
    else if(team2 == "" && team1 != "" && temp != team1){
      team2 = temp;
      count2++;
    }
    else if(temp == team1){
      count1++;
    }
    else if ( temp == team2){
      count2++;
    }
  }
  if(count1 < count2) std::cout << team2 << std::endl;
  else std::cout << team1 << std::endl;


  return 0;
}

