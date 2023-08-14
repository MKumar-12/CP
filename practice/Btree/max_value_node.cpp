//Max. value in Btree
//T.C. O(n)
//S.C. O(h)     recusive soln.  (using fn. call)     balanced Btree
//     O(w)     iterative soln. (using queue)        skewed Btree

#include<iostream>
#include<queue>
using namespace std;
int max_val = INT32_MIN;

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

            if(temp->data > max_val)            
            // updates global var. if found a val > max_value 
                max_val = temp->data;
        }
        cout<<endl;
    }
}

//M-2
int get_max(node* root) {
    if(root == NULL)
        return INT32_MIN;
    else
        return max(root->data, max(get_max(root->left), get_max(root->right)));
}

int main()
{
    node* root = NULL;

    //tree creation
    root = build_tree(root);
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    //12 1 -1 8 -1 -1 36 -1 -1
    
    // cout<<"\n\nLevel order traversal is : "<<endl;
    // lvl_order_traversal(root);

    //M-1       S.C. = O(w)
    // cout<<"\nMax. value in Btree is : "<<max_val;

    //M-2       S.C. = O(h)
    cout<<"\n\nMax. value in Btree is : "<<get_max(root);

    return 0;
}