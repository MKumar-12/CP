//Flatten a Btree
//Reference LC as prev, RC as nxt 
//for Btree to DLL conversion
//~ to INORDER traversal

//ROOT will not be HEAD ptr. if LC exists.
//T.C.  O(n)
//S.C.  O(h)

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
    if(root == NULL)                            //base case
        return;
    queue<node *> q;
    int count = 0;
    node* temp;
    q.push(root);
    while(!q.empty()) {
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

node* prevv = NULL;
//returns HEAD of newly constructed DLL
node* convert_Btree_to_DLL(node* root) {            //LnR INORDER
    if(root == NULL)   
        return NULL;
    
    node* head = convert_Btree_to_DLL(root->left);
    
    //a node with prevv = NULL will be marked as HEAD of dll
    if(prevv == NULL)
        head = root;
    else {
        root->left = prevv;
        prevv->right = root;
    }
    prevv = root;

    convert_Btree_to_DLL(root->right);

    return head; 
}

int main()
{
    node* root = NULL;

    root = build_tree(root);
    //31 17 9 -1 -1 -1 46 38 -1 -1 56 -1 81 78 -1 -1 -1             head    9 
    //2 1 -1 -1 3 -1 4 -1 -1                                        head    1

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    node* res = convert_Btree_to_DLL(root);
    cout<<"\n\nHead of flattened tree is : "<<res->data;

    return 0;
}