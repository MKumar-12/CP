//
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node* lchild;
    Node* rchild;

    node(char c, int f, Node* l = NULL, Node* r = NULL) {
        ch = c;
        freq = f;
        lchild = l;
        rchild = r;
    }
};


struct compare {
    bool operator(Node* l, Node* r) {
        return l.freq < r.freq;
    }
};

void printHEAP(vector<char> var, vector<int> freq, int n){
    priority_queue<Node*, vector<Node*>, compare> h;
    for(int i = 0; i<n; i++){
        h.push(new Node(var[i], freq[i]));
    } 

    while(h.size() > 1){
        Node* l = h.top();
        h.pop();

        Node* r = h.top();
        h.pop();

        Node* new_node = new Node('$', l->freq + r->freq, l , r);
        h.push(new_node);

    }
}

int main()
{

    return 0;
}