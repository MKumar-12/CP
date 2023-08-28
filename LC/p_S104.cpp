//Max Depth of a bin. tree
//T.C. 
//S.C. 

#include<bits/stdc++.h>
#include<sstream>
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(root -> left == NULL)
            return 1 + maxDepth(root -> right);
        
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
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
    cout<<"\nMax depth of given B.tree is : "<<s.maxDepth(input);
    return 0;
}