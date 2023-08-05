//Printing nodes at a distance k from root
// or nodes at (k+1)th lvl of tree
//T.C. theta(n)     WC       all nodes traversed
//       O(n)       AC       
//     theta(1)     BC       only root visited
//S.C.   O(h)       WC

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

void dist_K_fromRoot(node* root, int dist) {
    if(root == NULL)
        return;
    if(dist == 0)
        cout<<" "<<root->data;
    else {
        dist_K_fromRoot(root->left, dist - 1);
        dist_K_fromRoot(root->right, dist - 1);
    }
}

int main()
{
    node* root = NULL;
    root = build_tree(root);
    //2 1 -1 -1 3 -1 4 -1 -1                                        ht. 1    d. 4

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    int k;
    cout<<"\nEnter distance val (K) : ";
    cin>>k;
    cout<<"\nFollowing are the nodes at dist K from root : ";
    dist_K_fromRoot(root,k);

    return 0;
}