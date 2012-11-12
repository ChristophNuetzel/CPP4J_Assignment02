#ifndef TREEITERATOR_H
#define TREEITERATOR_H

// TODO INCLUDE THE NAMESPACE CPP4JTree in a working way. Could not find a solution yet (Thomas).

#include <string>

// only the announcement that there is a class called TreeNode (a hint for the compiler).
// So it can be used in TreeIterator's methods. This works because TreeIterator only has a pointer
// to a TreeNode (Which means, that the size of TreeNode can be unknown).
class TreeNode;

typedef unsigned int KeyType;
typedef std::string ValueType;

class TreeIterator
{
public:
    TreeIterator(TreeNode* node = 0);
    TreeIterator(const TreeIterator& rhs);
    TreeIterator& operator=(const TreeIterator& rhs);
    ValueType& value();
    KeyType& key();
    TreeIterator& operator++();
    TreeIterator& operator--();
    bool operator==(const TreeIterator &rhs);
    bool operator!=(const TreeIterator &rhs);
};
#endif // TREEITERATOR_H
