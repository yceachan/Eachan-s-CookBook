vector<int>path;
vector<vector<int>> res;

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    //  if(root && (root->left || root->right) && root->val==targetSum) return res;
    dfs(root, targetSum);
    return res;
}
void dfs(TreeNode* pos, int& target)
{
    if (!pos) return;
    path.push_back(pos->val);
    int sum = sumof(path);
    //if(sum>target) return;
    //叶子节点进入
    if (sum == target && !pos->left && !pos->right) res.push_back(path);
    else
    {
        dfs(pos->left, target);
        dfs(pos->right, target);
    }
    path.pop_back();
}
int sumof(const vector<int>& path)
{
    int ans = 0;
    for (auto it : path) ans += it;
    return ans;
}
};