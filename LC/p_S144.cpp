//Preorder traversal of Trees
//T.C. O(n)
//S.C. O(n)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode* left;
    TreeNode* right;

    TreeNode() :    val(0), left(NULL), right(NULL)    {}

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        left = left;
        right = right;
    }
};

class Solution {
public:
    // declared a vector that'll get deleted only after the fn call ends
    vector<int> nodes;
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL){
            //nLR
            nodes.push_back(root->val);
            preorderTraversal(root->left);        
            preorderTraversal(root->right);
        }
        return nodes;
    }
};

vector<TreeNode> extractValues(string input) {
    vector<TreeNode> values;

    istringstream iss(input);

    //ignore the beginning '['
    char c;
    iss >> c;

    //process each token in the input string
    while(iss >> c){
        if(c == 'n'){
            //handling null case
            iss.ignore(3);          //  Ignore 'nll'
        }
        else if(isdigit(c) || c == '-'){
            // extract int val
            int val;
            iss.unget();    // put the read char back to the stream
            iss >> val;
            TreeNode node(val);
            values.push_back(node);
        }

        //skip commas and WS
        iss.ignore();
    }

    return values;
}

int main()
{
    vector<TreeNode> input;
    string line;
    cout<<"Enter nodes details :    (in BFS fashion)";
    cin>>line;
    input = extractValues(line);
    
    Solution s;
    vector<int> res = s.preorderTraversal();
    cout<<"\n\nPreorder Traversal is as follows : ";
    for(auto i : res){
        cout<<i<<" ";
    }

    return 0;
}