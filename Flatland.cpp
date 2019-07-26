#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, max = INT_MIN;
    cin >> n >> m;
    vector<int>vec(n);
    for(auto& i:vec)cin >> vec[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == vec[j]) continue;
            else
            {
                for(int z = 0; z < m; z++)
                {
                    int sub = min(abs(vec[i] - z))
                    if(sub > max) max = sub; 
                }
            }
        }

     cout << max;
    return 0;

}