#include <bits/stdc++.h>

#define MAX(a, b) ( (a>b) ? a : b)
using namespace std;

#define LIMIT 100

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  vector<int> odd;
  vector<int> even;

  for (int i = 1; i <= n*n; i++) {
    if (i%2) odd.push_back(i);
    else even.push_back(i);
  }

  int matrix[n][n] = {0};
  int circle = 0;

  // start from the middle
  int mid = (n+1)/2-1;

  while(circle <= n/2){

    int row = mid-circle;
    int col = mid-circle;

    bool isEven = (circle%2);
    // Loop for every element in outer circle
    int dir = 0;

    int limit;
    if (circle == 0) limit = 1;
    else limit = pow(2*circle+1, 2) -pow(2*(circle-1)+1, 2) ;

    for (int i = 1; i <= limit; i++) {

      //std::cout << row << "|" << col << ":" << i << " DIR : " << dir << std::endl;
      if (isEven){
        matrix[row][col] = even.back();
        even.pop_back();
      }
      else {
        matrix[row][col] = odd.back();
        odd.pop_back();
      }

      // Change direction at corner
      if ( i> 1 && ( (row == mid+circle && col == mid+circle) ||
                     (row == mid-circle && col == mid+circle) ||
                     (row == mid+circle && col == mid-circle))){
        dir = (dir+1)%4;
      }

      // Go around
      switch(dir){
        case 0: col++; break;
        case 1: row++; break;
        case 2: col--; break;
        case 3: row--; break;
      }


      isEven = !isEven;

    }

    circle++;
  }

  // TEST
  // Sum row
  for (int row = 0; row < n; ++row) {
    int sum =0;
    for (int col = 0; col < n; ++col) {
      sum += matrix[row][col];
    }
    assert(sum%2 == 1);
  }

  // Sum col
  for (int col = 0; col < n; ++col) {
    int sum =0;
    for (int row = 0; row < n; ++row) {
      sum += matrix[row][col];
    }
    assert(sum%2 == 1);
  }

  // Sum diagional
  int sum1 = 0, sum2 = 0;
  int x = 0, y = 0, _x = 0, _y = n-1;
  for (int i = 0; i < n; i++) {
    sum1 += matrix[x][y];
    sum2 += matrix[_x][_y];
    x++;
    y++;
    _x++;
    _y--;
  }
  assert(sum1%2==1);
  assert(sum2%2==1);

  for (int k = 0; k < n; k++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[k][j] << " \n"[j==n-1];
    }
  }
  return 0;
}

