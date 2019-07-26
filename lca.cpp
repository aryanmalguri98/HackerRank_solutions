// Created by ...malguri
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
#define MP make_pair
#define PB push_back
#define INF (int)1e9
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
bool findPath(Node* root, vector<int>& path, int value){
	if(root == NULL)
		return false;
	path.push_back(root->key);
	if(root->key == k)
		return 1;
	if((root->left && findPath(root->left, path, value))||(root->right && findPath(root->right, path, value)))
		return 1;
}

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        //bool flag = false;
        Node* lowest_common_ancester(Node* root, int x, int y){
			vector<int> path1, path2;
			if(!findPath(root, path, x) || !findPath(root, path, y))
				return -1;
			for(int i = 0; i<path1.size() && i < path2.size(); i++){
				if(path1[i] != path2[i])
					break;
			}	        
			return 		;
        }
};
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t, data, v1, v2;

    cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    Node* pointer_ref = myTree.lowest_common_ancester(root, v1, v2);
    cout << pointer_ref->data<<"\n";
return 0;
}





