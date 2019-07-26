#include<bits/stdc++.h>
using namespace std;
  
void Array(int arr[], int size) 
{ 
  vector<int> vec;
    for(int i = 1; i < size; i++){
      //printf("%d ", arr[i]);
      int seq_num = arr[i];
      if(abs(i - seq_num) == k){
        vec.emplace_back(seq_num)
      }
    } 
    if(vec.size() == (size-1)){
      for(int i = 1; i <= size; i++){
        cout << vec[i] << " ";
      }
      return;
    }
    printf("\n");
    cout << "-" << 1;
    return; 
    
} 
  
void SequencesRecur(int arr[], int n, int k, int index) 
{ 
   int i; 
   if (k == 1) 
   { 
     Array(arr, index); 
   } 
   if (k > 1) 
   { 
      for(i = 1; i<=n; ++i) 
      { 
        arr[index] = i; 
        SequencesRecur(arr, n, k-1, index+1); 
      } 
   } 
} 
  
void Sequences(int n, int k) 
{ 
    int *arr = new int[k]; 
    SequencesRecur(arr, n, k, 1); 
  
    delete(arr); 
    return; 
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
      int n, k;
      cin >> n >> k;
      Sequences(n, k);
    }
     
    return 0; 
} 