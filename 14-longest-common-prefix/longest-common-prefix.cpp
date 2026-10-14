class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int cnt;
    bool isEnd;
    TrieNode(){
        isEnd=false;
        cnt=0;
        for(auto &a:children) a=NULL;
    }

};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* p=root;
        for(auto a:word){
            int idx=a-'a';
            if(!p->children[idx]){
                p->children[idx]=new TrieNode();
                p->cnt++;
            } 
            p=p->children[idx];
        }
        p->isEnd = true;
    }
    string search(string word){
        TrieNode* p=root;
        string s="";
        for(auto a:word){
            if(p->cnt!=1){
                break;
            }
            if (p->isEnd)
                break;
            int idx=a-'a';
            s+=a;
            p=p->children[idx];
        }
        return s;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie root;
        for(auto &m:strs){
            root.insert(m);
        }
        return root.search(strs[0]);
    }
};