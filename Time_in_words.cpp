#include<bits/stdc++.h>
using namespace std;
const string EMPTY = "";
const string X[] = { EMPTY, "one ", "two ", "three ", "four ", "five ",
        "six ", "seven ", "eight ", "nine ", "ten ", "eleven ",
        "twelve ", "thirteen ", "fourteen ", "fifteen ",
        "sixteen ", "seventeen ", "eighteen ", "nineteen " };

const string Y[] = { EMPTY, EMPTY, "twenty ", "thirty ", "forty ", "fifty ",
        "sixty ", "seventy ", "eighty ", "ninety " };
string convert2digit(int n, string suffix)
{
  // if n is zero
  if (n == 0) {
    return EMPTY;
  }


  if (n > 19) {
    return Y[n / 10] + X[n % 10] + suffix;
  }
  else {
    return X[n] + suffix;
  }
}
string numberToWords(unsigned long long int n)
{
 string res;
 res = convert2digit((n % 100), "");

  if (n > 100 && n % 100) {
    res = "and " + res;
  }

  return res;
}
int main()
{
  int h, m;
  cin >> h >> m;
  if(m < 30){
      if(m == 0)cout << numberToWords(h)<<"o' clock";
      else if(m==1)cout<<numberToWords(m)<<"minute past "<<numberToWords(h);
      else if(m == 15)cout << "quarter past " <<numberToWords(h);
      else{
          cout<<numberToWords(m) << "minutes past "<<
          numberToWords(h); 
      }  
  }
  else if(m == 30){
      cout << "half past "<<numberToWords(h);
  }
  else{
    if(m == 45)
        cout << "quarter to "<<numberToWords(h+1);
    else{
        int remainder = 60-m;
        cout << numberToWords(remainder)<<"minutes to "<<numberToWords(h+1);
    }          
  }
  return 0;
}