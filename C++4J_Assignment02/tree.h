#ifndef TREE_H
#define TREE_H

#include <string>
#include <treeiterator.h>

class TreeNode;

class Tree
{
public:
    // standard constructor
    Tree();

    // copy constructor
    Tree(const Tree& rhs);

    // This operator is used to assign another tree to the existing variable;
    Tree& operator=(const Tree& rhs);

    // This method returns the count of nodes in the tree
    unsigned int count() const;

    // This method deletes the whole tree and sets null pointer.
    void clear();

    // This method checks if the key is in the tree already.
    bool contains(const KeyType& key);

    // The []-operator is used to return the corresponding value.
    // New values are also assigned by this operator (eg. tree[3] = "Dummy";)
    ValueType& operator[](const KeyType& key);

    TreeIterator begin();
    TreeIterator end();
    TreeIterator find(const KeyType& value);

private:
    unsigned int m_count;
    TreeNode *m_root;
};

#endif // TREE_H
