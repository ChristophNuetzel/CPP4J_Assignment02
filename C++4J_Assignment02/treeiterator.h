#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include <string>

namespace CPP4JTree{

// only the announcement that there is a class called TreeNode (a hint for the compiler).
// So it can be used in TreeIterator's methods.
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

};
#endif // TREEITERATOR_H
