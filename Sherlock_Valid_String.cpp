#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max = INT_MIN, current, cnt = 0;
    string s;
    char c;
    cin >> s;
    unordered_map<char, int>mp;
    unordered_map<char, int>::iterator itr;
    
    //set the map
    for(int i = 0; i < s.size(); i++){
        itr = find(mp.begin(), mp.end(), s[i]);
        if(itr != mp.end())
            itr->second++;
        else{
            mp.insert(make_pair(s[i], 0));
        }    
    }
    //check if condition is already satisfied
    for(itr = mp.begin(); itr!=mp.end(); ++itr){
        current = itr->second;
        if(current > max){
            max = current;
            c = itr->first;
        }
    }
    for(itr = mp.begin(); itr!=mp.end(); ++itr){
        if(itr->second != max){
            if(itr->first == c){
                itr->second--;
                bool flag = unique(mp.begin(), mp.end(), itr->second);
                if(flag){
                    cout << "YES"<<"\n";
                    break
                }
                else {
                    cout << "NO" << "\n";
                    break;
                }
            }
            else
            {
                cout << "NO";
                break;
            }
        }
        else
            cnt++;
    }
    if(cnt == mp.size())cout << "YES" << "\n";
    return 0;
}