/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> currNode;
        vector<TreeNode*> nextNode;
        vector<vector<int>> answer;
        return bfs(root,currNode,nextNode,answer);
    }
private:
    vector<vector<int>> bfs(TreeNode* root,vector<TreeNode*> currNode,vector<TreeNode*> nextNode,vector<vector<int>> answer){
        if(!root){
            return answer;
        }
        currNode.push_back(root);
        while(currNode.size()!=0){
            answer.push_back({});
            for(int i=0;i<currNode.size();++i){
                answer.back().push_back(currNode[i]->val);
                if(currNode[i]->left){
                    nextNode.push_back(currNode[i]->left);
                }
                if(currNode[i]->right){
                    nextNode.push_back(currNode[i]->right);
                }
            }
            currNode.swap(nextNode);
            nextNode.clear();
        }
        return answer;
        
    }
};
