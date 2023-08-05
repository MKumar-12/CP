//Height of Binary tree
//Length of longest path from root to leaf node
//T.C. O(n)     every node is visited once
//S.C. O(h)     can vary based on balanced/skew tree

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build_tree(node* root) {
    int data;
    cout<<"\nEnter value : ";
    cin>>data;
    root = new node(data);

    // data entered as -1 == NULL
    if(data == -1)
        return NULL;
    
    cout<<"\nLC data for "<<data;
    root->left = build_tree(root->left);
    
    cout<<"\nRC data for "<<data;
    root->right = build_tree(root->right);

    return root;
}

void level_order_traversal(node* root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(! q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //prev lvl(i) completely traversed
            cout<<endl;

            if(! q.empty()) 
                q.push(NULL);           
            //this NULL added indicates the end of (i+1)th lvl
        }
        else {
            cout<< temp->data<< " ";
            
            if(temp->left) 
                q.push(temp->left);
        
            if(temp->right) 
                q.push(temp->right);
        }    
    }
}

int calc_height(node* root) {
    if(root == NULL)
        return 0;
    else 
        return 1 + max(calc_height(root->left), calc_height(root->right));
}

int main()
{
    node* root = NULL;
    
    root = build_tree(root);
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1                         ht. 2
    //34 21 2 -1 -1 27 23 -1 -1 -1 -1                               ht. 3
    //31 17 9 -1 -1 -1 46 38 -1 -1 56 -1 81 78 -1 -1 -1             ht. 4

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    //considering ht.(root) = 0
    int ht = 0;
    ht = calc_height(root);
    cout<<"\n\nHeight of given Binary tree is : "<<ht-1<<endl;
    
    return 0;
}