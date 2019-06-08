#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <tuple>
#include <functional>
#include <ctime>

using namespace std;

typedef long int int32;
typedef long long int int64;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
const double pi = acos(-1.0);

#define PI 3.1415926535897932384626433832795
#define INF (int)1e9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LOOP(n) for (int z = 0; z < n; ++z)
#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

char vowel[] = {'a', 'e','i','o','u'};
char conso[] = {'b', 'c', 'd','f','g','h','j','k','l','m','n','p','q',
                 'r','s','t','v','w', 'x','y', 'z'};
bool is_vowel(char c){
  if (c =='a' ||
      c =='e' ||
      c =='i' ||
      c =='u' ||
      c =='o') return true;
  else return false;
}

char next_vow(char c){
  int i = -1;
  while(++i < 5){
    if(c == vowel[i]){
      break;
    }
  }
  return (i<5)?vowel[(i+1)%5]:vowel[0];
}

char next_conso(char c){
  int i = -1;
  while(++i < 21){
    if(conso[i] == c){
      break;
    }
  }
  return (i<21)?conso[(i+1)%21]:conso[0];
}

bool check_properties(const string s){
  map<char, int> freq;
  for(int i =0; (i<s.length()) && (s[i]>='a') && (s[i]<='z'); ++i){
    if( freq.find(s[i]) != freq.end() ){
      freq[s[i]]++;
    }
    else {
      freq[s[i]] = 1;
    }
    if((i+1)%2 == 0){
      if (!is_vowel(s[i]) ){
        return false;
      }
    }
    else if( (i+1)% 2 == 1){
      if (is_vowel(s[i])){
        return false;
      }
    }
  }
  for(map<char, int>::iterator it = freq.begin(); it != freq.end(); it++){
    if (it->second > 2){
      return false;
    }
  }
  return true;
}

int is_triplet(const string word, char c){
  int count=0;
  for(char ch : word)
    if(c==ch) count++;
  return count;
}

void next_string_ref(string &word, int index){
  char c;
  bool recurse = false;
  if ((index+1) % 2 == 0){
    c = next_vow(word[index]);
    if (c == 'a')recurse = true;
    do {
      if (recurse){
        if(index+1 < word.length()){
          next_string_ref(word, index+1);
        }
        else{
          word.push_back('b');
        }
        recurse = false;
      }
      if(is_triplet(word, c) > 1){
        int i = 0; while(word[i] != c)i++;
        if(i > index){
          c = next_vow(c);
          if(c=='a') recurse = true;
          continue;
        }
        else break;
      }
    }while( recurse || is_triplet(word, c)>1);
  }
  else if ((index+1) % 2 == 1){
    c = next_conso(word[index]);
    if(c == 'b')recurse = true;
    do{
      if (recurse){
        if(index+1 < word.length()){
          next_string_ref(word, index+1);
        }
        else{
          word.push_back('a');
        }
        recurse = false;
      }
      if (is_triplet(word, c) > 1){
        int i = 0; while(word[i] != c)i++;
        if(i > index){
          c = next_conso(c);
          if (c=='b')recurse = true;
          continue;
        }
        else break;
      }
    } while(recurse || is_triplet(word, c) > 1);
  }
  word[index] = c;
}

//  ***** MAIN *****
int main(){
  ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<map<char, pair<int, double>>> average;
  LOOP(7){
    map<char, pair<int, double>> temp_map;
    average.push_back(temp_map);
  }
  map<char, double> p_table;
  string temp;
  p_table['a'] = 1253;
  p_table['b'] = 142;
  p_table['c'] = 468;
  p_table['d'] = 586;
  p_table['e'] = 1368;
  p_table['f'] = 69;
  p_table['g'] = 101;
  p_table['h'] = 70;
  p_table['i'] = 625;
  p_table['j'] = 44;
  p_table['k'] = 0;
  p_table['l'] = 497;
  p_table['m'] = 315;
  p_table['n'] = 671;
  p_table['o'] = 868;
  p_table['p'] = 251;
  p_table['q'] = 88;
  p_table['r'] = 687;
  p_table['s'] = 798;
  p_table['t'] = 463;
  p_table['u'] = 393;
  p_table['v'] = 90;
  p_table['w'] = 2;
  p_table['x'] = 22;
  p_table['y'] = 90;
  p_table['z'] = 52;
  average[0]['b'].first = 1;
  average[0]['b'].second = 142;
  average[0]['c'].first = 1;
  average[0]['c'].second = 468;
  average[0]['d'].first = 1;
  average[0]['d'].second = 586;
  average[0]['f'].first = 1;
  average[0]['f'].second = 69;
  average[0]['g'].first = 1;
  average[0]['g'].second = 101;
  average[0]['h'].first = 1;
  average[0]['h'].second = 70;
  average[0]['j'].first = 1;
  average[0]['j'].second = 44;
  average[0]['k'].first = 1;
  average[0]['k'].second = 0;
  average[0]['l'].first = 1;
  average[0]['l'].second = 497;
  average[0]['m'].first = 1;
  average[0]['m'].second = 315;
  average[0]['n'].first = 1;
  average[0]['n'].second = 671;
  average[0]['p'].first = 1;
  average[0]['p'].second = 251;
  average[0]['q'].first = 1;
  average[0]['q'].second = 88;
  average[0]['r'].first = 1;
  average[0]['r'].second = 687;
  average[0]['s'].first = 1;
  average[0]['s'].second = 798;
  average[0]['t'].first = 1;
  average[0]['t'].second = 463;
  average[0]['v'].first = 1;
  average[0]['v'].second = 90;
  average[0]['w'].first = 1;
  average[0]['w'].second = 2;
  average[0]['x'].first = 1;
  average[0]['x'].second = 22;
  average[0]['y'].first = 1;
  average[0]['y'].second = 90;
  average[0]['z'].first = 1;
  average[0]['z'].second = 52;
  average[1]['b'].first = 5;
  average[1]['b'].second = 9724;
  average[1]['c'].first = 5;
  average[1]['c'].second = 11354;
  average[1]['d'].first = 5;
  average[1]['d'].second = 11944;
  average[1]['f'].first = 5;
  average[1]['f'].second = 9359;
  average[1]['g'].first = 5;
  average[1]['g'].second = 9519;
  average[1]['h'].first = 5;
  average[1]['h'].second = 9364;
  average[1]['j'].first = 5;
  average[1]['j'].second = 9234;
  average[1]['k'].first = 5;
  average[1]['k'].second = 9014;
  average[1]['l'].first = 5;
  average[1]['l'].second = 11499;
  average[1]['m'].first = 5;
  average[1]['m'].second = 10589;
  average[1]['n'].first = 5;
  average[1]['n'].second = 12369;
  average[1]['p'].first = 5;
  average[1]['p'].second = 10269;
  average[1]['q'].first = 5;
  average[1]['q'].second = 9454;
  average[1]['r'].first = 5;
  average[1]['r'].second = 12449;
  average[1]['s'].first = 5;
  average[1]['s'].second = 13004;
  average[1]['t'].first = 5;
  average[1]['t'].second = 11329;
  average[1]['v'].first = 5;
  average[1]['v'].second = 9464;
  average[1]['w'].first = 5;
  average[1]['w'].second = 9024;
  average[1]['x'].first = 5;
  average[1]['x'].second = 9124;
  average[1]['y'].first = 5;
  average[1]['y'].second = 9464;
  average[1]['z'].first = 5;
  average[1]['z'].second = 9274;
  average[2]['b'].first = 105;
  average[2]['b'].second = 286794;
  average[2]['c'].first = 105;
  average[2]['c'].second = 321024;
  average[2]['d'].first = 105;
  average[2]['d'].second = 333414;
  average[2]['f'].first = 105;
  average[2]['f'].second = 279129;
  average[2]['g'].first = 105;
  average[2]['g'].second = 282489;
  average[2]['h'].first = 105;
  average[2]['h'].second = 279234;
  average[2]['j'].first = 105;
  average[2]['j'].second = 276504;
  average[2]['k'].first = 105;
  average[2]['k'].second = 271884;
  average[2]['l'].first = 105;
  average[2]['l'].second = 324069;
  average[2]['m'].first = 105;
  average[2]['m'].second = 304959;
  average[2]['n'].first = 105;
  average[2]['n'].second = 342339;
  average[2]['p'].first = 105;
  average[2]['p'].second = 298239;
  average[2]['q'].first = 105;
  average[2]['q'].second = 281124;
  average[2]['r'].first = 105;
  average[2]['r'].second = 344019;
  average[2]['s'].first = 105;
  average[2]['s'].second = 355674;
  average[2]['t'].first = 105;
  average[2]['t'].second = 320499;
  average[2]['v'].first = 105;
  average[2]['v'].second = 281334;
  average[2]['w'].first = 105;
  average[2]['w'].second = 272094;
  average[2]['x'].first = 105;
  average[2]['x'].second = 274194;
  average[2]['y'].first = 105;
  average[2]['y'].second = 281334;
  average[2]['z'].first = 105;
  average[2]['z'].second = 277344;
  average[3]['b'].first = 525;
  average[3]['b'].second = 3326910;
  average[3]['c'].first = 525;
  average[3]['c'].second = 3498060;
  average[3]['d'].first = 525;
  average[3]['d'].second = 3560010;
  average[3]['f'].first = 525;
  average[3]['f'].second = 3288585;
  average[3]['g'].first = 525;
  average[3]['g'].second = 3305385;
  average[3]['h'].first = 525;
  average[3]['h'].second = 3289110;
  average[3]['j'].first = 525;
  average[3]['j'].second = 3275460;
  average[3]['k'].first = 525;
  average[3]['k'].second = 3252360;
  average[3]['l'].first = 525;
  average[3]['l'].second = 3513285;
  average[3]['m'].first = 525;
  average[3]['m'].second = 3417735;
  average[3]['n'].first = 525;
  average[3]['n'].second = 3604635;
  average[3]['p'].first = 525;
  average[3]['p'].second = 3384135;
  average[3]['q'].first = 525;
  average[3]['q'].second = 3298560;
  average[3]['r'].first = 525;
  average[3]['r'].second = 3613035;
  average[3]['s'].first = 525;
  average[3]['s'].second = 3671310;
  average[3]['t'].first = 525;
  average[3]['t'].second = 3495435;
  average[3]['v'].first = 525;
  average[3]['v'].second = 3299610;
  average[3]['w'].first = 525;
  average[3]['w'].second = 3253410;
  average[3]['x'].first = 525;
  average[3]['x'].second = 3263910;
  average[3]['y'].first = 525;
  average[3]['y'].second = 3299610;
  average[3]['z'].first = 525;
  average[3]['z'].second = 3279660;
  average[4]['b'].first = 11000;
  average[4]['b'].second = 84151200;
  average[4]['c'].first = 11000;
  average[4]['c'].second = 87672000;
  average[4]['d'].first = 11000;
  average[4]['d'].second = 88946400;
  average[4]['f'].first = 11000;
  average[4]['f'].second = 83362800;
  average[4]['g'].first = 11000;
  average[4]['g'].second = 83708400;
  average[4]['h'].first = 11000;
  average[4]['h'].second = 83373600;
  average[4]['j'].first = 11000;
  average[4]['j'].second = 83092800;
  average[4]['k'].first = 11000;
  average[4]['k'].second = 82617600;
  average[4]['l'].first = 11000;
  average[4]['l'].second = 87985200;
  average[4]['m'].first = 11000;
  average[4]['m'].second = 86019600;
  average[4]['n'].first = 11000;
  average[4]['n'].second = 89864400;
  average[4]['p'].first = 11000;
  average[4]['p'].second = 85328400;
  average[4]['q'].first = 11000;
  average[4]['q'].second = 83568000;
  average[4]['r'].first = 11000;
  average[4]['r'].second = 90037200;
  average[4]['s'].first = 11000;
  average[4]['s'].second = 91236000;
  average[4]['t'].first = 11000;
  average[4]['t'].second = 87618000;
  average[4]['v'].first = 11000;
  average[4]['v'].second = 83589600;
  average[4]['w'].first = 11000;
  average[4]['w'].second = 82639200;
  average[4]['x'].first = 11000;
  average[4]['x'].second = 82855200;
  average[4]['y'].first = 11000;
  average[4]['y'].second = 83589600;
  average[4]['z'].first = 11000;
  average[4]['z'].second = 83179200;
  average[5]['b'].first = 52800;
  average[5]['b'].second = 689489280;
  average[5]['c'].first = 52800;
  average[5]['c'].second = 706389120;
  average[5]['d'].first = 52800;
  average[5]['d'].second = 712506240;
  average[5]['f'].first = 52800;
  average[5]['f'].second = 685704960;
  average[5]['g'].first = 52800;
  average[5]['g'].second = 687363840;
  average[5]['h'].first = 52800;
  average[5]['h'].second = 685756800;
  average[5]['j'].first = 52800;
  average[5]['j'].second = 684408960;
  average[5]['k'].first = 52800;
  average[5]['k'].second = 682128000;
  average[5]['l'].first = 52800;
  average[5]['l'].second = 707892480;
  average[5]['m'].first = 52800;
  average[5]['m'].second = 698457600;
  average[5]['n'].first = 52800;
  average[5]['n'].second = 716912640;
  average[5]['p'].first = 52800;
  average[5]['p'].second = 695139840;
  average[5]['q'].first = 52800;
  average[5]['q'].second = 686689920;
  average[5]['r'].first = 52800;
  average[5]['r'].second = 717742080;
  average[5]['s'].first = 52800;
  average[5]['s'].second = 723496320;
  average[5]['t'].first = 52800;
  average[5]['t'].second = 706129920;
  average[5]['v'].first = 52800;
  average[5]['v'].second = 686793600;
  average[5]['w'].first = 52800;
  average[5]['w'].second = 682231680;
  average[5]['x'].first = 52800;
  average[5]['x'].second = 683268480;
  average[5]['y'].first = 52800;
  average[5]['y'].second = 686793600;
  average[5]['z'].first = 52800;
  average[5]['z'].second = 684823680;
  average[6]['b'].first = 1101600;
  average[6]['b'].second = 16413086880;
  average[6]['c'].first = 1101600;
  average[6]['c'].second = 16749323280;
  average[6]['d'].first = 1101600;
  average[6]['d'].second = 16871028480;
  average[6]['f'].first = 1101600;
  average[6]['f'].second = 16337794680;
  average[6]['g'].first = 1101600;
  average[6]['g'].second = 16370799480;
  average[6]['h'].first = 1101600;
  average[6]['h'].second = 16338826080;
  average[6]['j'].first = 1101600;
  average[6]['j'].second = 16312009680;
  average[6]['k'].first = 1101600;
  average[6]['k'].second = 16266628080;
  average[6]['l'].first = 1101600;
  average[6]['l'].second = 16779233880;
  average[6]['m'].first = 1101600;
  average[6]['m'].second = 16591519080;
  average[6]['n'].first = 1101600;
  average[6]['n'].second = 16958697480;
  average[6]['p'].first = 1101600;
  average[6]['p'].second = 16525509480;
  average[6]['q'].first = 1101600;
  average[6]['q'].second = 16357391280;
  average[6]['r'].first = 1101600;
  average[6]['r'].second = 16975199880;
  average[6]['s'].first = 1101600;
  average[6]['s'].second = 17089685280;
  average[6]['t'].first = 1101600;
  average[6]['t'].second = 16744166280;
  average[6]['v'].first = 1101600;
  average[6]['v'].second = 16359454080;
  average[6]['w'].first = 1101600;
  average[6]['w'].second = 16268690880;
  average[6]['x'].first = 1101600;
  average[6]['x'].second = 16289318880;
  average[6]['y'].first = 1101600;
  average[6]['y'].second = 16359454080;
  average[6]['z'].first = 1101600;
  average[6]['z'].second = 16320260880;
  uint64 score;
  while(N--){
    score = 0;
    cin >> temp;
    for(int c = 1; c<=temp.length(); ++c ) score += c*p_table[temp[c-1]];
    if(score < average[temp.length()-1][temp[0]].second / average[temp.length()-1][temp[0]].first)
    {
      cout << "below" << endl;
    }
    else
    {
      cout << "above or equal" << endl;
    }
  }
  return 0;
}

