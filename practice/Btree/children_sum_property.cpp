//Children Sum Property : every parent val = sum of its childrens
//a single node / NULL tree is also said to follow children-sum-property 
//T.C. O(n)
//S.C. O(h)

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

void lvl_order_traversal(node* root) {        //Breadth-first
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

bool chk_children_sum_property(node* root) {
    if(root == NULL)
        return true;
    
    if(root->left == NULL && root->right == NULL)           //imp. base condition
        return true;
    
    int sum = 0;
    if(root->left)
        sum += root->left->data;
    if(root->right)
        sum += root->right->data;
    
    return (root->data == sum && chk_children_sum_property(root->left) && chk_children_sum_property(root->right));
}

int main()
{
    node* root = NULL;

    //tree creation
    root = build_tree(root);
    //20 8 3 -1 -1 5 -1 -1 12 -1 -1                     true
    //3 1 -1 -1 2 1 -1 -1 2 -1 -1                       false


    cout<<"\n\nLevel order traversal is : "<<endl;
    lvl_order_traversal(root);

    bool res = chk_children_sum_property(root);
    if(res)
        cout<<"\n\nGiven tree follows children sum property!!!";
    else
        cout<<"\n\nGiven tree DOESNT follows children sum property!!!";
    
    return 0;
}