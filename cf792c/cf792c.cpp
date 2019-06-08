#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int sum =0;
  int one = 0, two = 0, three = 0;
  int damage1 = INT_MAX;
  int damage2 = INT_MAX;
  for (char c : s) {
    if ((c-'0')%3 == 1){
      one++;
    }
    else if((c-'0')%3 == 2){
      two++;
    }
    else {
      three++;
    }
    sum += c-'0';
  }
  if(sum %3 == 0){
    std::cout << s << std::endl;
    return 0;
  }
  else if(sum % 3 == 1){
    // removing one one's, count the damage
    if (one == 1){
      // removing the only digit
      if (s.size() == 1){
        std::cout << -1 << std::endl;
        return 0;
      }
      // If we have to remove the most signf digit
      else if ( (s[0] -'0')%3 == 1){
        // count the number of leading zero we also have to remove
        // together with the "one"
        damage1 = 1;
        while(damage1 < s.size()-1 && s[damage1] == '0') damage1++;
      }
      // not most sig digit
      else{
        damage1 = 1;
      }
    }
    else if(one>1){
      damage1 = 1;
    }
    if(two == 2){
      if (s.size() == 2){
        std::cout << -1 << std::endl;
        return 0;
      }
      else if (((s[0]-'0')%3) == 2){
        damage2 = 1;
        // colateral zeros of the first "Two"
        while(damage2 < s.size()-1 && s[damage2] == '0' ){damage2++;}
        // if the next "two" is right after that also count
        // colateral zeros of the second "two"
        if ((s[damage2] - '0' % 3) == 2) damage2++;
        while(damage2 < s.size()-1 && s[damage2] == '0' ){damage2++;}
      }
      else {
        damage2 = 2;
      }
    }
    else if (two> 2){
      damage2 = 2;
    }
    // remove digit accordingly
    if (damage2 < damage1){
      int counter = 2;
      for (int i = s.size()-1; counter> 0 && i >= 0; --i) {
        if( (s[i] -'0') % 3 == 2){
          counter--;
          s.erase(s.begin() + i);
        }
      }
    }
    else {
      for (int i = s.size()-1; i >= 0; --i) {
        if( (s[i] -'0') % 3 == 1){
          s.erase(s.begin() + i);
          break;
        }
      }
    }
  }
  else if (sum %3 == 2){
    if (two == 1){
      // removing the only digit
      if (s.size() == 1){
        std::cout << -1 << std::endl;
        return 0;
      }
      // If we have to remove the most signf digit
      else if ( (s[0] -'0')%3 == 2){
        // count the number of leading zero we also have to remove
        // together with the "one"
        damage2 = 1;
        while(damage2 < s.size()-1 && s[damage2] == '0') damage2++;
      }
      // not most sig digit
      else{
        damage2 = 1;
      }
    }
    else if(two>1){
      damage2 = 1;
    }
    if(one == 2){
      if (s.size() == 2){
        std::cout << -1 << std::endl;
        return 0;
      }
      else if (((s[0]-'0')%3) == 1){
        damage1 = 1;
        // colateral zeros of the first "Two"
        while(damage1 < s.size()-1 && s[damage1] == '0' ){damage1++;}
        // if the next "two" is right after that also count
        // colateral zeros of the second "two"
        if ((s[damage1] - '0' % 3) == 1) damage1++;
        while(damage1 < s.size()-1 && s[damage1] == '0' ){damage1++;}
      }
      // erase inline will never cause any colateral erasure
      else {
        damage1 = 2;
      }
    }
    else if (one> 2){
      damage1 = 2;
    }
    // remove digit accordingly
    if (damage2 <= damage1){
      for (int i = s.size()-1;i >= 0; --i) {
        if( (s[i] -'0') % 3 == 2){
          s.erase(s.begin() + i);
          break;
        }
      }
    }
    else {
      int counter = 2;
      for (int i = s.size()-1; counter > 0 && i >= 0; --i) {
        if( (s[i] -'0') % 3 == 1){
          counter--;
          s.erase(s.begin() + i);
        }
      }
    }
  }
  // trim down leading zero except for the last;
  while(s.size()>1 && s.front() == '0') s.erase(s.begin());

  if (s.empty()) std::cout << -1 << std::endl;
  else std::cout << s << std::endl;

  return 0;
}

