//Build binary tree
//lvl order traversal
//INORDER traversal        LnR
//PREORDER traversal       nLR
//POSTORDER traversal      LRn
//in all 3 above traversals ^ left-subtree is visited before R-subtree

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

void level_order_traversal(node* root) {        //Breadth-first
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

void preorder_traversal(node* root) {           //nLR
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(node* root) {            //LnR
    if(root == NULL)
        return ;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

void postorder_traversal(node* root) {          //LRn
    if(root == NULL)
        return ;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
}


int main()
{
    node* root = NULL;

    //tree creation
    root = build_tree(root);
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    //12 1 -1 8 -1 -1 36 -1 -1

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);
    
    cout<<"\nPre-order traversal is : "<<endl;
    preorder_traversal(root);
    cout<<"\n\nIn-order traversal is : "<<endl;
    inorder_traversal(root);
    cout<<"\n\nPost-order traversal is : "<<endl;
    postorder_traversal(root);
    
    return 0;
}