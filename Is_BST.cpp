

#include <bits/stdc++.h>

using namespace std;

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
bool chakna( Node* root, int min, int max);
bool chakna( Node* root, int min, int max){
        if(root == NULL)return 1;
        if(root->data < min || root->data > max)
            return false;
        return
            chakna(root->left, min, root->data-1) &&
            chakna(root->right, root->data+1, max);
        
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
        bool checkBST(Node* root) {
    		return(chakna(root, INT_MIN, INT_MAX));		
	}
};
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    if(myTree.checkBST(root)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
return 0;
}





