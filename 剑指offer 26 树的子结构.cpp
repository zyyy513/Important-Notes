/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //˼·������Ҫĳ���ڵ���ͬ  ��Σ�����ڵ���ӽṹҲҪ��ͬ
//�ñ��ж��������Ƿ���ͬһ�������ڵ�Ҫһ��������������ȫ���ڵ�ҲҪ��ͬ
//���ǵݹ�Ĺ��̣�ÿ�ζ�����ͬ�Ĺ�����ֻ�������ݹ�ģ��С��
//�õ��������ݹ麯��dfs �� check �����ò�ͬ��ǰ���ǵݹ����A����ÿһ���ڵ�  �����ǵݹ��ж�B�����������ڵ��Ƿ���A��ĳ����һ��

class Solution {
public:
    //�� ����check����  �ж�B�Ƿ���A���ӽṹ
    bool check(TreeNode* a,TreeNode* b)
    {
        if(!a && !b)  return true;    //ab��ƥ������
        else if(!b)   return true;    //bƥ������
        else if(!a)   return false;   //a��ƥ������

        //����
        if(a->val != b->val)  return false;
        return check(a->left,b->left) && check(a->right,b->right);
    }


    //�٢� dfs���ڱ���A����ö�ٽڵ�ֵ
    bool dfs(TreeNode* anode,TreeNode* broot)
    {
        //�� �ݹ�߽�
        if(!broot)  return false;   //���BΪ�գ�ֱ�ӷ���false
        if(!anode)  return false;   //����Ǽ��A�ı߽�

        if(anode->val==broot->val)
        {
            //�� �ж�broot���������Ƿ�Ϊanode���������ӽṹ
            //�� �ж�broot���������Ƿ�Ϊanode���������ӽṹ
            //��ret�����������Զ��庯��check�ж�
            bool ret= check(anode->left,broot->left)
                    &&check(anode->right,broot->right);
            //�����һ������������Ҳһ������retΪ��
            if(ret)  return true;
        }

        //�� �������һ�����ٱ���A�����������еĽڵ㣬��������broot�Ƚ� ���ظ�����dfs���������еݹ�
        if(dfs(anode->left,broot))  return true;
        if(dfs(anode->right,broot))  return true;

        //������
        return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //�� ����A���е�ÿ���ڵ�node��Ҫ�ж�node��ֵ����B�����ڵ��ֵ  noe->value==B-root->value
        //�� дһ���ݹ麯��������AB������
        return dfs(A,B);    
    }
};

���ߣ�nian-xin-bai-mo
���ӣ�https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/yi-shua-cun-yi-si-lu-jian-dai-ma-kuai-by-k7g6/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
