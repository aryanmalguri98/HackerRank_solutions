#include<bits/stdc++.h>
using namespace std;
void rotate(int** arr, int* j);
void bubbleSort(int* arr, int* n);

void rotate(int** arr, int* j){
    int temp = *(*(arr) + *j);
    *(*(arr)+ *j) = *(*(arr)+ *j + 1);
    *(*(arr)+ *j + 1) = *(*(arr)+ *j + 2);
    *(*(arr)+ *j + 2) = temp;
}
void bubbleSort(int* arr, int* n){
    int size = *n;
    for(int i = 0; i < size-2; i++){
        for(int j = size-2-1; j>=i; j++){
            while(*(arr + j) > *((arr + j) + 1) || *(arr + j) > *((arr + j)+2))
                rotate(&arr, &j);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        bubbleSort(arr, &n);
        cout << (arr[n-2] < arr[n-1])?"YES":"NO";    
        cout << "\n";
    }
    return 0;
}