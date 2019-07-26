#include<bits/stdc++.h>
using namespace std;
vector<int>* digitsOfNumber(int* n);
int* answer(int* n);
int i;
vector<int>* digitsOfNumber(int* n)
{
	vector<int> v;
	vector<int>* vi = &v;
//	vector<int>* vi = &v;
	i = 0;
	while(n != 0)
	{
		
		int rem = (*n)%10;
		(*n) = (*n)/10;
		v[i] = rem;
		i++;
	} 
	return vi;
}
int* answer(int* n)
{
	int sum;
	bool flag = false;
	while(flag)
	{
		sum = 0;
		vector<int>* vec = digitsOfNumber(&(*n));
		for(int i = 0; i < vec->size(); i++){
			sum += vec->at(i);
		}
		if(sum % 4 == 0){
			flag = true;
			//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
		}
			
		else (*n)++;
		
	}
	return n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *ans = answer(&n);
	cout << *ans << "\n";
	return 0;
}