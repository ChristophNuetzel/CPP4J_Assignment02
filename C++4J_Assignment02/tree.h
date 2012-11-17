#ifndef TREE_H
#define TREE_H

#include <string>

typedef unsigned int KeyType;
typedef std::string ValueType;

class TreeNode;

class TreeIterator
{

public:
    TreeIterator();
    TreeIterator(TreeNode* node = 0);
    TreeIterator(const TreeIterator& rhs);
    TreeIterator& operator=(const TreeIterator& rhs);
    ValueType& value();
    KeyType& key();
    TreeIterator& operator++();
    TreeIterator& operator--();
    bool operator==(const TreeIterator &rhs);
    bool operator!=(const TreeIterator &rhs);

private:
    TreeNode* m_currentTreeNode;
};

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

    // This method returns the count of all complete Nodes in the tree
    unsigned int countCompleteNodes();

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
    unsigned int m_countCompleteNodes;
    TreeNode *m_root;
};

#endif // TREE_H
