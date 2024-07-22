#ifndef TREENODE_H
#define TREENODE_H

#include <vector>

struct TreeNode
{
    int val;
    std::vector<TreeNode*> children;

    TreeNode(int v) : val(v) {};
};

#endif // TREENODE_H