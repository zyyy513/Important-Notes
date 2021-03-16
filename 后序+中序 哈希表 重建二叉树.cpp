解题思路
注意要先传中序，再传后序
又遇到了执行错误，这次是stack-overflow，原因是左右子树的后序区间错了！！！
右子树的后序区间端点不能用idx表示，因为idx是变化的 要用r0,l0表示



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
    unordered_map<int , int >m;    //构建哈希表

    TreeNode* dfs(vector<int>&io, vector<int>&pto , int l1, int r1,int l0,int r0)    //传入中序和后序的区间端点
    {
        if(r0<l0)  return nullptr;   //若序列不合法  返回空指针

        //寻找根节点
        TreeNode* root= new TreeNode(pto[r0]);    //根节点就是后序序列中下标为r0对应的元素  并生成根节点
        //用哈希表查询根节点在中序序列中的位置
        int idx=m[root->val];

        //左右子树中序序列的长度
        int lsize=idx-l1;
        int rsize=r1-idx;

        //再回到后序序列中找左右子树的后序序列的区间    就是[l0,l0+lsize-1]   [l0+lsize,r0-1]
        //然后是中序中左右子树的区间   [l1,idx-1]   [idx+1,r1]
        //然后就可以递归构建左右子树了了  递归调用dfs函数
        root->left=dfs(io,pto,  l1,idx-1     , l0,l0+lsize-1);    
        root->right=dfs(io, pto,     idx+1,r1     , l0+lsize,r0-1);     

        return root;
    }
    TreeNode* buildTree(vector<int>& io, vector<int>& pto )   //pto io 分别代表后序和中序序列
    {
        for(int i=0;i<io.size();i++)    //遍历中序序列
        {
            m[io[i]]=i;     //中序的哈希表
        }

        return dfs(io,pto,0,io.size()-1, 0,pto.size()-1);   
    }
};

作者：nian-xin-bai-mo
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/you-zhong-xu-hou-xu-xu-lie-zhong-jian-er-wql7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
