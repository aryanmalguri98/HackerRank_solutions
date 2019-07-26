#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, max = INT_MIN, count = 0;
    string s, required;
    char c;
    cin >> n >> s;
    unordered_map<char, int>m;
    unordered_map<char, int>::iterator itr;
    //to identify which all genes are to cutt off
    m.emplace("A",0);
    m.emplace("C",0);
    m.emplace("T",0);
    m.emplace("G",0);
    for(int i = 0; i < s.size(); i++){
        itr = find(m.begin(), m.end(), s[i]);
        if(itr != m.end())
            (itr->second)++;
    }
    for(itr = m.begin(); itr!=m.end(); itr++){
        int current = itr->second;
        if(current > max){
            max = current;
            c = itr->first;
        }
    }
    //computing the sub-strings
    for(int i = 0; i < (1<<n); i++){
        required = "";
        for(int j = 0; j < n; j++){
            if(i & (1<<j))
            {
                required += s[i];
            }
        }
        for(int k = 0; k < required.size(); k++){
            count = 0;
            if(required[k] = c)count++;
        }
        //we've found the required string
        if(count == max) break;
    }
    //Now we've the string that we want
    //Further procedure is to add from the unwanting to the wanting part
    int answer = 0;
    while(max!=(n/4))
    {
        for(itr = m.begin(); itr!=m.end(); itr++){
            if(itr->second == 0){
                int remainder = max - (n/4);
                itr->second += remainder;
                answer += remainder;
            }
            else if(itr->second < (n/4)){
                int re -= (n/4)-itr->second;
                max-=re;
                itr->second+=re;
                answer += re;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}