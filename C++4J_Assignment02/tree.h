#ifndef TREE_H
#define TREE_H

#include <string>
#include <treeiterator.h>

namespace CPP4JTree{

class Tree
{
public:
    Tree();
    Tree(const Tree& rhs);
    Tree& operator=(const Tree& rhs);
    unsigned int count() const;
    void clear();
    bool contains(const KeyType& key);
    ValueType& operator[](const KeyType& key);
    TreeIterator begin();
    TreeIterator end();
    TreeIterator find(const KeyType& value);
};
};
#endif // TREE_H
