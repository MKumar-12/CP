//Diameter of Binary tree
//#nodes in the longest path connecting 2 leafs
//root may/may not be included in that path

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
    if(root == NULL)
        return;
        
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

int calc_diameter(node* root) {                     //T.C. O(n^2)
    if(root == NULL)
        return 0;
    int t1 = calc_diameter(root->left);
    int t2 = calc_diameter(root->right);
    int t3 = calc_height(root->left) + 1 + calc_height(root->right);
    return max(max(t1, t2), t3);
}


//Optimization
class d_fast {
    public :
    int calc_dfast(node* root) {                    //T.C. O(n)
        pair<int,int> final = calc_diameter_fast(root);
        return final.first;
    }

    pair<int,int> calc_diameter_fast(node* root) {
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);           //Saving <diameter,height> pair-wise
            return p;
        }

        pair<int,int> left = calc_diameter_fast(root->left);
        pair<int,int> right = calc_diameter_fast(root->right);

        int t1 = left.first;
        int t2 = right.first;
        int t3 = left.second + 1 + right.second;

        pair<int,int> ans;
        ans.first = max(max(t1, t2), t3);                       //calc. of diameter
        ans.second = max(left.second,right.second) + 1;         //calc. of height
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

    int diameter = 0;
    //diameter = calc_diameter(root);
    d_fast d1;
    diameter = d1.calc_dfast(root);
    cout<<"\n\nDiameter of given Binary tree is : "<<diameter<<endl;

    return 0;
}