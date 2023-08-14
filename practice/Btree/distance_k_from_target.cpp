//Printing nodes at a distance k from given TARGET
//Appl. of BFS 
//[both ways traversal applicable, i.e. P->C and C->P]
//T.C.   O(n)          all nodes traversed once
//S.C.   O(h)       

#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<vector>
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

//Save C->P relations in a map
unordered_map <node*, node*> parent;
void preorder(node* curr, node* prnt) {
    if(curr == NULL)
        return;
    parent[curr] = prnt;
    preorder(curr->left,curr);
    preorder(curr->right,curr);
}

//Maintain a vector for nodes denoting VISITED / not yet. 
//then perform BFS from TARGET node as q.front()
vector<int> dist_K_fromTarget(node* root, node* target,int dist) {
    preorder(root,NULL);

    queue<node*> q;
    q.push(target);
    unordered_set <node*> visited;

    while(!q.empty() && dist) {
        dist--;
        int size = q.size();
        for(int i=0; i<size; i++){
            node* curr = q.front();
            q.pop();
            visited.insert(curr);

            if(!visited.count(curr->left) && curr->left)        q.push(curr->left);
            if(!visited.count(curr->right) && curr->right)      q.push(curr->right);
            if(!visited.count(parent[curr]) && parent[curr])    q.push(parent[curr]); 
        }
    } 
    
    vector<int> ans;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
    }

    return ans;
}

node* Search_val(node* root,int value) {
    
}
int main()
{
    node* root = NULL, target = NULL;
    root = build_tree(root);
    //2 1 -1 -1 3 -1 4 -1 -1                                        ht. 1    d. 4

    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);

    int k,tgt;
    cout<<"\nEnter TARGET val : ";
    cin>>tgt;
    target = Search_val(root,tgt);
    cout<<"\nEnter distance val (K) : ";
    cin>>k;
    cout<<"\nFollowing are the nodes at dist K from TARGET : ";
    dist_K_fromTarget(root,target,k);

    return 0;
}