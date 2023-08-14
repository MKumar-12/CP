//Building tree from given lvl order traversal/ BFS
//T.C. theta(n)
//S.C. theta(width)     : WC of having atmost 1 full lvl inside the queue 
//                          [O(n) as n/2 nodes at last lvl]

//3 states for every node :
//Unvisited     : yet to be traversed
//Processing    : inside queue, adding its childs
//Discovered    : popped from queue. prcessing completed

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

//nothing is returned, just root node is used as reference
void build_tree_from_lvl_order(node* &root) {
    queue <node*> q;
    int data,LC,RC;
    cout<<"\nEnter value for root : ";
    cin>>data;
    root = new node(data);
    q.push(root);

    while(! q.empty()) {
        node* temp = q.front();
        q.pop();
        cout<<"\nEnter value for LC of "<<temp->data<<": ";
        cin>>LC;

        if(LC != -1){           //valid LC data, i.e., node reqd to be made
            temp->left = new node(LC);
            q.push(temp->left);
        }

        cout<<"\nEnter value for RC of "<<temp->data<<": ";
        cin>>RC;

        if(RC != -1){           //valid RC data, i.e., node reqd to be made
            temp->right = new node(RC);
            q.push(temp->right);    
        }
    }
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

int noOfLeafNodes(node* root){
    int count = 0;
    queue<node *> q;
    q.push(root);
    while(! q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp->left) 
            q.push(temp->left);
        
        if(temp->right) 
            q.push(temp->right);

        //leaf node
        if((temp->left == NULL)&&(temp->right == NULL))
            count++;
    }
    return count;
}

int main()
{
    node* root = NULL;
    int leafs;

    //tree creation
    build_tree_from_lvl_order(root);
    //12 1 36 -1 8 -1 -1 -1 -1
    
    cout<<"\n\nLevel order traversal is : "<<endl;
    level_order_traversal(root);
    
    leafs = noOfLeafNodes(root);
    cout<<"\n\nNo. of leaf nodes is : "<<leafs<<endl;

    return 0;
}