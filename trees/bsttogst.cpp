class Solution {
public:
    int dfs(TreeNode* root, int sum) {
        if (root == NULL) {
            return sum;
        }
        sum = dfs(root->right, sum); //last node
        root->val += sum; //last node ka value add krdo
        sum = root->val; //sum ko update krdo node value se
        sum = dfs(root->left, sum); //left mai check kro
        return sum;
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};


//root = *8
//sum = 8

