//Balanced tree(AVL) check
//-1,0,1 are possible values of ht. diff. btw L n R subtree
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

int calc_height(node* root) {                       //T.C. O(n)
    if(root == NULL)
        return 0;
    else 
        return 1 + max(calc_height(root->left), calc_height(root->right));
}

bool isBalanced(node *root) {                       //T.C. O(n^2)
        //base case
    if(root == NULL)
        return true;
        
    bool t1 = isBalanced(root->left);
    bool t2 = isBalanced(root->right);

    bool t3 = abs(calc_height(root->left) - calc_height(root->right)) <= 1;
        
    if(t1 && t2 && t3)
        return true;
    else 
        return false;
}

//Optimization
class chk_fast {
    public :
    bool isBalancedFast(node* root) {                    //T.C. O(n)
        pair<bool,int> final = balanced_Fast(root);
        return final.first;
    }

    pair<bool,int> balanced_Fast(node* root) {
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = balanced_Fast(root->left);
        pair<bool,int> right = balanced_Fast(root->right);

        bool t1 = left.first;
        bool t2 = right.first;
        bool t3 = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.first = t1 && t2 && t3;
        ans.second = max(left.second, right.second) + 1; 

        return ans;
    }
};


int main()
{
    node* root = NULL;
    
    root = build_tree(root);
    //31 17 9 -1 -1 -1 46 38 -1 -1 56 -1 81 78 -1 -1 -1             ht. 4    d. 7
    //2 1 -1 -1 3 -1 4 -1 -1                                        ht. 1    d. 4

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    chk_fast f1;
    if(f1.isBalancedFast(root))
        cout<<"\n\n\nGiven tree is balanced.";
    else
        cout<<"\n\n\nGiven tree is NOT balanced.";

    return 0;
}