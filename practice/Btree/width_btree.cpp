//#Max nodes at a lvl in Btree
//T.C.  O(n)
//S.C.  O(w)

#include<iostream>
#include<queue>
using namespace std;
int count_max = 0;

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
        count_max = max(count, count_max);

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

int main()
{
    node* root = NULL;

    root = build_tree(root);
    //31 17 9 -1 -1 -1 46 38 -1 -1 56 -1 81 78 -1 -1 -1             w. 3 
    //2 1 -1 -1 3 -1 4 -1 -1                                        w. 2

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    cout<<"\n\nWidth of given Binary tree is : "<<count_max<<endl;
    return 0;
}