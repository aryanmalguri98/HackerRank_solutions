#include<bits/stdc++.h>
using namespace std;
Node * readListInter();

Node * readListInter(){
    Node* root = NULL;//returning object
    Node* temp;
    Node* input;//new node to add
    int x;
    
    cout << "enter number (>0 to stop): ";
    cin >> x;
    while(x>=0){
        input = cons(x);
        if(root == NULL){//if root is empty
            root = input;
            temp = root;//temp is use to store value for compare
        }
        else{
            temp = root; //for each new addition, must start at root to find correct spot
            while(input != NULL){
                if( x < temp->value){//if smaller x to add to left
                    if(temp->lLink == NULL){//left is empty
                        temp->lLink = input;
                        input = NULL;//new node added, exit the loop
                    }
                    else{//if not empty set temp to subtree
                        temp = temp->lLink;//need to move left from the current position
                    }
                }
                else{//otherwise x add to right
                    if(temp->rLink == NULL){//right is empty
                        temp->rLink = input;
                        input = NULL;//new node added, exit the loop
                    }
                    else{
                        temp = temp->rLink;//need to move right from the current position
                    }
                }
            }
        }
        cin >> x;
    }
    return root;
}
int main(){
    int* ptr;
    ptr = readListInter();
    return 0;
}