#include "tree.h"

using namespace CPP4JTree;
Tree::Tree()
{
}

// inner class
class TreeNode
{
private:
    TreeNode(TreeNode* parent = 0, const KeyType& key = KeyType(), const ValueType& value = ValueType());
    KeyType& key();
    ValueType& value();
    TreeNode* find(const KeyType& key);
    TreeNode* findFirst();
    TreeNode* findLast();
};
