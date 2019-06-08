#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) ( (a > b ) ? a : b )
#define MIN(a, b) ( (a < b ) ? a : b )

#define LIMIT 100

// TODO: study LIMP library or reference to Knuth

class BigInt{
  private:
    // Helper method for comparing absolute value
    int absComp(vector<int16_t> a, vector<int16_t> b){
      if(a.size() < b.size() ) return -1;
      if(a.size() > b.size() ) return -1;
      for (int i = a.size()-1; i >= 0; i++) {
        if ( a[i] < b[i] ) return -1;
        else if(a[i] > b[i]) return 1;
      }
      return 0;
    }

    // a -b
    void sub(vector<int16_t> &a, vector<int16_t> &b){
      assert(absComp(a, b)> 0);
      for (int i = 0; i < a.size()-1; i++) {
        a[i] -= b[i];
        if (a[i] < 0){
          a[i] += 10;
          a[i+1]--;
        }
      }
    }

  public:
    bool neg;
    vector<int16_t> v;

    // ### Default constructor
    BigInt(void){
      neg = false;
      v.push_back(0);
    }

    // ### String constructor
    BigInt(string s){
      int i;
      if (s == "0"){
        neg = false;
        v.push_back(0);
        return;
      }
      if(s[0] == '-' ){
        i = 1;
        neg = true;
      }
      else {
        i = 0;
        neg = false;
      }
      int j = s.size()-1;
      while(j >= i){
        v.push_back(s[i] -'0');
      }
    }

    // ### Integer constructor
    BigInt(int64_t a){
      if (a < 0){
        neg = true;
        a = -a;
      }
      else if( a>0){
        neg = false;
      }
      else if( a == 0){
        neg = false;
        v.push_back(0);
        return;
      }
      while(a > 0){
        v.push_back(a%10);
        a /= 10;
      }
    }

    // ### vector<int16_t> bool constructor
    BigInt(vector<int16_t> vec, bool b){
      v = vec;
      neg = b;
    }

    // *** IsNeg()
    bool isNeg(){
      return this->neg;
    }

    // *** toString()
    string toString(){
      string r = "";
      if(neg){
        r +='-';
      }
      for (int i = v.size()-1; i >= 0 ;--i) {
        r += v[i] +'0';
      }
      return r;
    }

    // *** size()
    int size(){
      return v.size();
    }

    // *** [] OPERATOR
    int16_t& operator [] (int n){
      return v[n];
    }
    // Using a minimal structure of axioms
    // The only 2 axioms we ever need is > and ==
    bool operator > (BigInt i){
      if (this->isNeg() && !i.isNeg()) return false;
      else if (!this->isNeg() && i.isNeg()) return true;
      // A larger number is smaller when negative
      // A smaller number is larger when negative
      if (this->size() > i.size()){
        return !this->isNeg();
      }
      else if (this->size() < i.size()){
        return this->isNeg();
      }
      // this.size == i.size()
      for (int index = i.size(); index >= 0; --index) {
        if( (*this)[index] > i[index]){
          return !this->isNeg();
        }
        else if ( (*this)[index] < i[index] ){
          return this->isNeg();
        }
      }
      // 2 equal number
      return false;
    }
    bool operator == (BigInt i){
      if (this->isNeg() != i.isNeg()) return false;
      if (this->size() != i.size() ) return false;
      for(int index = 0; index < i.size(); ++index){
        if( (*this)[index] != i[index] ) return false;
      }
      return true;
    }
    bool operator < (BigInt i){
      return !(*this > i) && !(*this == i);
    }
    bool operator >= (BigInt i){
      return !(*this < i);
    }
    bool operator <= (BigInt i){
      return !(*this > i);
    }
    bool operator != (BigInt i){
      return !(*this == i);
    }
    BigInt operator + (BigInt i){
      if (i.neg == this->neg )return sum(*this, i);
      else return sub(*this, i);
    }
    BigInt operator - (BigInt i){
      if (i.neg != this->neg ) return sum(*this, i);
      else return sub(*this, i);
    }
    BigInt operator * (BigInt i){
      return mul(*this, i);
    }
    BigInt operator * (int i){
      return mulInt(*this, i);
    }
    BigInt operator / (BigInt i){
      return div(*this, i);
    }
    BigInt operator % (BigInt i){
      return mod(*this, i);
    }
    void Negate(void){
      this->neg = !this->neg;
    }
    BigInt Negate(BigInt i){
      return BigInt(i.v, !i.isNeg());
    }

    // *** sum()
    BigInt sum(BigInt a, BigInt b){
      if (a == BigInt(0)) return b;
      if (b == BigInt(0)) return a;
      if (a.size() < b.size()){
        swap(a, b);
      }
      for (int i = 0; i < b.size(); i++) {
        a[i] += b[i];
      }
      a.v.push_back(0);
      for (int i = 0; i < a.size()-1; i++) {
        if (a[i] > 9){
          a[i+1]++;
          a[i] -= 10;
        }
      }
      while(a.v.size() > 1 && a.v.back() == 0) a.v.pop_back();
      return a;
    }

    // *** sub()
    BigInt sub(BigInt a, BigInt b){
      if (a == BigInt(0)) return b;
      if (b == BigInt(0)) return a;
      if (a.size() < b.size()){
        swap(a, b);
      }
      else if (a.size() == b.size()){
        for (int i = a.size()-1; i >= 0;i++) {
          if(a[i] < b[i]){
            swap(a, b);
            break;
          }
          else if (a[i] > b[i]){
            break;
          }
        }
      }
      a.v.push_back(0);
      for (int i = 0; i < a.size()-1; i++) {
        a[i] -= b[i];
        if (a[i] < 0){
          a[i] += 10;
          a[i+1]--;
        }
      }
      while(a.size() > 1 && a.v.back() == 0) a.v.pop_back();
      return a;
    }

    // mul() for integer
    BigInt mulInt(BigInt a, int b){
      vector<int16_t> vec(a.size() + (int)log10(b)+1, 0);
      for (int i = 0; i < a.v.size(); i++) {
        vec[i+1] += a[i]*b/10;
        vec[i] += (a[i]*b)%10;
      }
      while(vec.size() > 0 && vec.back() == 0) vec.pop_back();
      BigInt r(vec, a.neg != (b<0));
      return r;
    }

    // mul() for BigInt
    BigInt mul(BigInt a, BigInt b) {
      vector<int16_t> vec(a.size() + b.size() + 1, 0);
      for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
          vec[j+i] += a[i] * b[j];
        }
      }
      for (int i = 0; i < vec.size()-1; i++) {
        if (vec[i] > 9){
          vec[i+1] += vec[i]/10;
          vec[i] %= 10;
        }
      }
      while(vec.size() > 1 && vec.back() == 0) vec.pop_back();
      bool n = a.neg != b.neg;
      return BigInt(vec, n);
    }

    BigInt div(BigInt a, BigInt b) {
      if (a < b) return 0;
      vector<int16_t> vec(a.size() - b.size() + 1, 0);
      vector<int16_t> rem;
      for (int i = vec.size()-1, k = a.v.size()-1; i >= 0; --k, --i){
        vec[i] = a.v[a.v.size()-1]/b.v[b.v.size()-1];
        // Calculate remainder
        rem = vector<int16_t>(a.v.size()+1,0);
        int j = k - b.v.size() + 1;
        while(j <= k){
          rem[j] = vec[i]*b.v[j-k + b.size() - 1];
          if (rem[j] > 10){
            rem[i+1] += rem[i] /10;
            rem[i] %= 10;
          }
          j++;
        }
        // If remainder is less than divisor
        if ( absComp(rem, a.v) < 0){
        }
        else {
          vec[i]--;
          // Recalculate remainder
        }
      }
    }

    BigInt mod(BigInt a, BigInt b){
    }

};

#define RANDLIMIT 10000
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc = 11;
  while(tc--){
    int a = (rand()%RANDLIMIT) - (rand()%RANDLIMIT);
    int b = (rand()%RANDLIMIT) - (rand()%RANDLIMIT);

    int d = 10;
    int c = d*a;

    BigInt biga(a);
    BigInt bigb(b);
    BigInt bigc = biga * d;

    std::cout << a << "|" << biga.toString() << "\t" << b << "|" << bigb.toString() << std::endl;
    std::cout << c << "\t\t" << bigc.toString() << std::endl;
    cout << "\n";
  }

  return 0;
}

