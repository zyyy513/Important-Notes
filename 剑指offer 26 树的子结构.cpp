/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //思路：首先要某个节点相同  其次，这个节点的子结构也要相同
//好比判断两个树是否相同一样，根节点要一样，左右子树的全部节点也要相同
//就是递归的过程，每次都是相同的工作，只不过数据规模变小了
//用到了两个递归函数dfs 和 check 但作用不同，前者是递归查找A树的每一个节点  后者是递归判断B树左右子树节点是否与A中某树的一样

class Solution {
public:
    //⑥ 补足check函数  判断B是否是A的子结构
    bool check(TreeNode* a,TreeNode* b)
    {
        if(!a && !b)  return true;    //ab都匹配完了
        else if(!b)   return true;    //b匹配完了
        else if(!a)   return false;   //a都匹配完了

        //否则
        if(a->val != b->val)  return false;
        return check(a->left,b->left) && check(a->right,b->right);
    }


    //①② dfs用于遍历A树，枚举节点值
    bool dfs(TreeNode* anode,TreeNode* broot)
    {
        //⑤ 递归边界
        if(!broot)  return false;   //如果B为空，直接返回false
        if(!anode)  return false;   //这个是检查A的边界

        if(anode->val==broot->val)
        {
            //③ 判断broot的左子树是否为anode左子树的子结构
            //③ 判断broot的右子树是否为anode右子树的子结构
            //用ret存结果，并用自定义函数check判断
            bool ret= check(anode->left,broot->left)
                    &&check(anode->right,broot->right);
            //如果根一样，左右子树也一样，即ret为真
            if(ret)  return true;
        }

        //④ 如果根不一样，再遍历A的左右子树中的节点，并继续和broot比较 即重复上面dfs函数，进行递归
        if(dfs(anode->left,broot))  return true;
        if(dfs(anode->right,broot))  return true;

        //都不行
        return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //① 遍历A树中的每个节点node，要判断node的值等于B树根节点的值  noe->value==B-root->value
        //② 写一个递归函数并传入AB两棵树
        return dfs(A,B);    
    }
};

作者：nian-xin-bai-mo
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/yi-shua-cun-yi-si-lu-jian-dai-ma-kuai-by-k7g6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
