//Chk whether given tree is AVL
//diff. of height in LC n RC is atmost 1, for every node
//i.e.  |LC - RC| ==  -1,0,1
//T.C. 
//S.C. 

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

int calc_height(node* root){
    if(root == NULL)
        return 0;
    else
        return 1 + max(calc_height(root->left), calc_height(root->right));
}

bool chk_AVL1(node* root) {                  //T.C. O(n^2)
    if(root == NULL)                        //naive soln.
        return true;
    else
    {
        int lh = calc_height(root->left);
        int rh = calc_height(root->right);
        
        return (abs(lh - rh)<= 1 && chk_AVL1(root->left) && chk_AVL1(root->right));
    }
}

//single return type value with only O(n) T.C as every node visited only once.
int chk_AVL2(node* root) {
    if(root == NULL)
        return 0;
    
    int lh = chk_AVL2(root->left);
    if(lh == -1)
        return -1;
    
    int rh = chk_AVL2(root->right);
    if(rh == -1)
        return -1;
    
    if(abs(lh - rh) > 1)
        return -1;
    else
        return max(lh,rh) + 1;
}

int main()
{
    node* root = NULL;

    root = build_tree(root);
    //3 4 5 -1 -1 -1 -1                                 false
    //18 4 -1 -1 20 13 -1 -1 70 -1 -1                   true
    
    cout<<"\n\nLevel order traversal is : "<<endl;
    lvl_order_traversal(root);

    // bool res = chk_AVL1(root);
    // if(res)
    //     cout<<"\n\nGiven tree follows AVL property!!!";
    // else
    //     cout<<"\n\nGiven tree DOESNT follows AVL property!!!";

    int res = chk_AVL2(root);
    if(res != -1)
        cout<<"\n\nGiven tree follows AVL property!!!";
    else
        cout<<"\n\nGiven tree DOESNT follows AVL property!!!";
    
    return 0;
}