#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ele = 0;
    cin >> n;
    int arr[n];
    for(auto& i:arr) cin >> arr[i];
    while(arr.size()!= 0)
    {
        cout << arr.size() << endl;
        ele = * min_element(arr, arr+n);
        for(int i = 0; i < n; i++)
        {
            arr[i]= arr[i] - ele;
            if(arr[i] == 0) arr.erase(i);
        }
    }
    return 0;
}