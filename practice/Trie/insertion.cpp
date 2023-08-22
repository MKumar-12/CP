//Insertion/Searching in Tries
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode * children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this->data = ch;
            for(int i = 0; i<26; i++)
                children[i] = NULL;
            
            isTerminal = false;
        }

};

class Trie {
    public:
        TrieNode* root;

        void InsertUtil(TrieNode* root, string word){
            //base condition : last char chked, mark last node as terminal
            if(word.length() == 0)
                root->isTerminal = true;

            //Assuming words are in CAPS letter
            int index = word[0] - 'A';
            TrieNode* child;

            // curr char already present
            if(root->children[index] != NULL)
                child = root->children[index];
            
            // absent
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            InsertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            InsertUtil(root, word);
        }
};

int main()
{
    Trie t;
    t.insertWord("asaz");
    
    return 0;
}