// problem: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

/*
Approach-1:  Brute force clean code (TLE)
Time Complexity:    O(N*M)  where M:size of queries vector
Space Complexity:   O(h)    where h:height of tree 
*/
class Solution {
public:
    int height(TreeNode* root,int q){
        if(!root || root->val==q)
            return 0;
        return 1 + max(height(root->left,q),height(root->right,q));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        for(auto& query:queries){
            result.push_back(height(root,query)-1);
        }
        return result;
    }
};

/*
Approach-2: Using simple recursion
Time Complexity:   O(N)
Space Complexity:  O(N)
*/
class Solution {
public:
    int height[100001];
    int level[100001];
    int levelFirstMaxHeight[100001];
    int levelSecondMaxHeight[100001];
    int computeHeights(TreeNode* root,int l){
        if(!root)
            return 0;
        level[root->val]=l;
        height[root->val] = 1 + max(computeHeights(root->left,l+1), computeHeights(root->right,l+1));
        if(levelFirstMaxHeight[l] < height[root->val]){
            levelSecondMaxHeight[l] = levelFirstMaxHeight[l];
            levelFirstMaxHeight[l] = height[root->val];
        }
        else if(levelSecondMaxHeight[l] < height[root->val])
            levelSecondMaxHeight[l] = height[root->val];
        
        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        computeHeights(root,0);
        vector<int> result;
        for(auto& query:queries){
            int l=level[query];

            int temp = l + (levelFirstMaxHeight[l]==height[query] ? levelSecondMaxHeight[l] : levelFirstMaxHeight[l]) - 1;
            result.push_back(temp);
        }
        return result;
    }
};

/*
Approach-3: Using DFS
Time Complexity:   O(N)
Space Complexity:  O(N)
*/

class Solution {
public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
      unordered_map<int, int> ans;
      unordered_map<TreeNode*, int> heights;
      vector<int> result;
	    function<int(TreeNode*)> height = [&](TreeNode* root) {
		      return root ? (heights[root] = 1 + max(height(root->left), height(root->right))) : 0; 
	    };
	function<void(TreeNode*,int,int)> dfs = [&](TreeNode* root, int depth, int mx) {
		  if (!root) return;
		  ans[root->val] = mx;
		  dfs(root->right, depth + 1, max(mx, depth + heights[root->left]));
		  dfs(root->left, depth + 1, max(mx, depth + heights[root->right]));
	};
	    height(root);
      dfs(root, 0, 0);
	    for(int& v: queries) 
         result.push_back(ans[v]);
    
	    return result;
    }
};
