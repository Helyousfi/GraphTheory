#include <iostream>
#include "Tree.hpp"
int LeafSum(TreeNode* node)
{
    if(node->children.size() == 0) // isLeaf
        return node->val;
    int total = 0;
    for(TreeNode* nodeIterator : node->children)
    {
        total += LeafSum(nodeIterator);
    }
    return total;
}