// problem:  https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

/*
Approach-1: Brute Force using sorting
Time Complexity:  O(NlogN + N^2*L^2)  where L: longest word
Space Complexity: o(N*Lmax)
*/

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<string> suggestion=words;
        sort(suggestion.begin(),suggestion.end());
        vector<int> result;
        for(auto& w:words){
            string temp="";
            int count=0;
            for(auto& s:w){
                temp+=s;
                for(auto& prefix:suggestion){
                    if(prefix.find(temp)==0)
                     count++;
                }
            }
            result.push_back(count);
        }    

        return result;
    }
};


/*
Approach-2: optimal solution using Trie
Time Complexity:  O(N*Lmax)   where L: longest word
Space Complexity: O(N*Lmax)
*/

struct TrieNode {
    int count=0;
    TrieNode* children[26]; //0, 1, 2...9
};
class Solution {
public:
    TrieNode* getTrieNode(){
        TrieNode* node=new TrieNode();
        for(int i=0;i<26;i++){
        node->children[i]=nullptr;
        }
        return node; 
    }
   
    void insert(string word,TrieNode* root){
        TrieNode* crawler=root;
        for(auto& w:word){
             int ch=w-'a';
            if(!crawler->children[ch])
              crawler->children[ch]=getTrieNode();
        crawler->children[ch]->count++;
         crawler=crawler->children[ch];
        }
    }
   
   int search(string word,TrieNode* root){
        TrieNode* crawler=root;
        int length=0;
        for(auto& w:word){
             int ch=w-'a';
            if(crawler->children[ch]){
                length+=crawler->children[ch]->count;
                crawler=crawler->children[ch];
            }
            else
            break;
        }
        return length;
   }


    vector<int> sumPrefixScores(vector<string>& words) {
      TrieNode* root=getTrieNode();
      vector<int> result;
      for(auto& w:words){
        insert(w,root);
      }
      for(auto& w:words){
        int length=search(w,root);
        result.push_back(length);
      }
      return result;
    }
};
