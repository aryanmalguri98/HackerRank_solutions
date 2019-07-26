#include<bits/stdc++.h>
using namespace std;
int FindMaxSum(int arr[], int n) 
{ 
  int incl = arr[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  
  for (i = 1; i < n; i++) 
  { 
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl; 
  
     /* current max including i */
     incl = excl + arr[i]; 
     excl = excl_new; 
  } 
  
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl); 
} 
  
/* Driver program to test above function */
int main() 
{ 
  int num;
  cin >> num;
  int arr[num];
  for(int i = 0; i < num; i++) cin >> arr[i];
 // int n = sizeof(arr) / sizeof(arr[0]); 
  printf("%d ", FindMaxSum(arr, num)); 
  return 0; 
} 