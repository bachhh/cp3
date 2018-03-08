#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<string, int, int, int> siii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string team1, team2;
  string score;
  map<string, int> scored;
  map<string, int> missed;
  map<string, int> point;
  map<string, int> games;
  while(cin >> team1 >> team2 >> score){
    int goal1 = score[0] -'0';
    int goal2 = score[3] -'0';
    games[team1]++;
    games[team1]++;
    scored[team1] += goal1;
    scored[team2] += goal2;
    missed[team1] += goal2;
    missed[team2] += goal1;
    if(goal1 == goal2){
      point[team1]++;
      point[team2]++;
    }
    if(goal1 < goal2){
      point[team2]+=3;
    }
    if (goal1 > goal2){
      point[team1]+= 3;
    }
  }
  vector<siii> v;
  for(auto p : point){
    string name = p.first;
    v.push_back(siii(name, point[name], scored[name], missed[name]));
  }

  sort(v.begin(), v.end(),
      [ ] (siii a, siii b){
        if(get<1>(a) > get<1>(b)) return true;
        if(get<1>(a) < get<1>(b)) return false;
        if(abs(get<3>(a)-get<2>(a)) > abs( get<3>(b)-get<2>(b) )) return true;
        if(abs(get<3>(a)-get<2>(a)) < abs( get<3>(b)-get<1>(b) )) return false;
        if(get<1>(a) > get<1>(b)) return true;
        if(get<1>(a) < get<1>(b)) return false;
        return get<0>(a) < get<0>(b);
      }
      );

  int mingame = 1000; string opponent;
  for(auto p : games){
    if(p.second < mingame){
      mingame = p.second;
      opponent = p.first;
    }
  }

  siii op1 = v[0];
  siii op2 = v[1];
  string team = "BERLAND";

  if(get<0>(op1) == team || get<0>(op2) == team){
    std::cout << "1:0" << std::endl;
    return 0;
  }

  if(point[team] < get<1>(op1)-3 && point[team] < get<1>(op2)-3){
    std::cout << "IMPOSSIBLE" << std::endl;
  }
  else {
    string min op;
    if(get)
  }

  return 0;
}

