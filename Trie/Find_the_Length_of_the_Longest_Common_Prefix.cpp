// problem:  https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

/*
Approach-1:  Brute Force
Time Complexity: O(n1 * n2 * d)  where d=no of digits in largest number
Space Complexity: O(d)
TLE
*/

class Solution {
public:
    int findPrefix(string& num1,string& num2){
        int i=0,j=0;
        int count=0;
        while(i<num1.length() && j<num2.length()){
         if(num1[i]==num2[j])
         count++;
         else break;
         i++;
         j++;
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen=0;
      for(int i=0;i<arr1.size();i++){
        string num1=to_string(arr1[i]);
        for(int j=0;j<arr2.size();j++){
         string num2=to_string(arr2[j]);
         maxLen=max(maxLen,findPrefix(num1,num2));
        }
      }
      return maxLen;
    }
};

/*
Approach-2:  a little optimized using unordered_map
Time Complexity:O((n1 + n2) * d)  where d=no of digits in largest number
Space Complexity: O(n2 * d)
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen=0;
     unordered_map<string,int> mp;
     for(int i=0;i<arr2.size();i++){
        string temp=to_string(arr2[i]);
        int j=0;
        string t="";
        while(j<temp.length()){
         t += temp[j];
         mp[t]=1;
         j++;
        }
     }
    
    for(int i=0;i<arr1.size();i++){
        string temp=to_string(arr1[i]);
        int j=0;
        string t="";
        while(j<temp.length()){
         t += temp[j];
         if(mp.count(t))
         maxLen=max(maxLen,j+1);
         else
         break;
         j++;
        }
    }
      return maxLen;
    }
};

/*
Approach-3:  using Trie data structure
Time Complexity:O((n1 + n2) * d)  where d=no of digits in largest number
Space Complexity: O(n1 * d)
*/


struct TrieNode {
    TrieNode* children[10]; //0, 1, 2...9
};

class Solution {
public:
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 10; i++) {
            node->children[i] = nullptr;
        }

        return node;
    }

    void insert(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for(char ch : numStr) {
            int idx = ch - '0';
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl = crawl->children[idx];
        }
    }

    //returns the length of th elongest prefix
    int search(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int length = 0;

        for(char ch : numStr) {
            int idx = ch - '0';
            if(crawl->children[idx]) {
                length++;
                crawl = crawl->children[idx];
            } else {
                break;
            }
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode(); 

        for(int num : arr1) {
            insert(num, root);
        }

        int result = 0;
        for(int num : arr2) {
            result = max(result, search(num, root));
        }

        return result;
    }
};


/*
Approach-4:  a little more optimized using unordered_set
Time Complexity: O(n1 * d)  where d=no of digits in largest number
Space Complexity: O(n2 * d)
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen=0;
       unordered_set<int> st;

       for(int val: arr1){
        while(!st.count(val) && val>0){
            st.insert(val);
            val/=10;
        }
       }
      
      for(int num: arr2){
        while(!st.count(num) && num>0){
            num/=10;
        }
        if(num>0)
        maxLen=max(maxLen,static_cast<int>(log10(num))+1);
      }

      return maxLen;
    }
};


