//Size of Btree : #nodes in it.
//T.C. O(n)
//S.C. O(h)     max h+1 active stack calls at a time

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

void lvl_order_traversal(node* root) {
    if(root == NULL)                            //base case
        return;
    queue<node *> q;
    int count = 0;
    node* temp;
    q.push(root);
    while(!q.empty()){
        count = q.size();
        for(int i = 0; i < count; i++) {        // q size changes inside the loop
            temp = q.front();
            q.pop();
            cout<< temp->data <<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout<<endl;
    }
}

int size_Btree(node* root) {
    if(root == NULL)
        return 0;
    else
        return 1 + size_Btree(root->left) + size_Btree(root->right);
}

int main()
{
    node* root = NULL;

    //tree creation
    root = build_tree(root);
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    //12 1 -1 8 -1 -1 36 -1 -1
    
    cout<<"\n\nLevel order traversal is : "<<endl;
    lvl_order_traversal(root);

    cout<<"\nSize of given Binary tree is : "<<size_Btree(root);

    return 0;
}