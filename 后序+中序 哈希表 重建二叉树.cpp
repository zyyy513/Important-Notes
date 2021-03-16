����˼·
ע��Ҫ�ȴ������ٴ�����
��������ִ�д��������stack-overflow��ԭ�������������ĺ���������ˣ�����
�������ĺ�������˵㲻����idx��ʾ����Ϊidx�Ǳ仯�� Ҫ��r0,l0��ʾ



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
    unordered_map<int , int >m;    //������ϣ��

    TreeNode* dfs(vector<int>&io, vector<int>&pto , int l1, int r1,int l0,int r0)    //��������ͺ��������˵�
    {
        if(r0<l0)  return nullptr;   //�����в��Ϸ�  ���ؿ�ָ��

        //Ѱ�Ҹ��ڵ�
        TreeNode* root= new TreeNode(pto[r0]);    //���ڵ���Ǻ����������±�Ϊr0��Ӧ��Ԫ��  �����ɸ��ڵ�
        //�ù�ϣ���ѯ���ڵ������������е�λ��
        int idx=m[root->val];

        //���������������еĳ���
        int lsize=idx-l1;
        int rsize=r1-idx;

        //�ٻص����������������������ĺ������е�����    ����[l0,l0+lsize-1]   [l0+lsize,r0-1]
        //Ȼ������������������������   [l1,idx-1]   [idx+1,r1]
        //Ȼ��Ϳ��Եݹ鹹��������������  �ݹ����dfs����
        root->left=dfs(io,pto,  l1,idx-1     , l0,l0+lsize-1);    
        root->right=dfs(io, pto,     idx+1,r1     , l0+lsize,r0-1);     

        return root;
    }
    TreeNode* buildTree(vector<int>& io, vector<int>& pto )   //pto io �ֱ����������������
    {
        for(int i=0;i<io.size();i++)    //������������
        {
            m[io[i]]=i;     //����Ĺ�ϣ��
        }

        return dfs(io,pto,0,io.size()-1, 0,pto.size()-1);   
    }
};

���ߣ�nian-xin-bai-mo
���ӣ�https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/you-zhong-xu-hou-xu-xu-lie-zhong-jian-er-wql7/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
