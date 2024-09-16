
// problem:  https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Time Complexity; O(L)  where L=length word or prefix
Space Complexity: O(N)  where N = total no. of character in all word
*/
class Trie {
public:
    struct trieNode{
    bool isLastword;
    trieNode *children[26];
    };
    trieNode* getNewNode(){
    trieNode* newNode=new trieNode();
    newNode->isLastword=false;

    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
    }
    trieNode* root;

    Trie() {
    root=getNewNode();
    }
    
    void insert(string word) {
     trieNode* crawler=root;
     for(int i=0;i<word.length();i++){
      if(!crawler->children[word[i]-'a'])
       crawler->children[word[i]-'a']=getNewNode();
     crawler=crawler->children[word[i]-'a'];
     }
     crawler->isLastword=true;
    }
    
    bool search(string word) {
     trieNode* crawler=root;
     for(int i=0;i<word.length();i++){
        if(!crawler->children[word[i]-'a'])
         return false;
         crawler=crawler->children[word[i]-'a'];
     }
     return (crawler && crawler->isLastword);
    }
    
    bool startsWith(string prefix) {
       trieNode* crawler=root;
       for(int i=0;i<prefix.length();i++){
        if(!crawler->children[prefix[i]-'a'])
         return false;
         crawler=crawler->children[prefix[i]-'a'];
       }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
