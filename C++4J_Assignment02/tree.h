#ifndef TREE_H
#define TREE_H

#include <string>

namespace CPP4JTree
{
// these typedefs are used for better readability.
typedef unsigned int KeyType;
typedef std::string ValueType;

// Declaration of a class called TreeNode.
// TreeNode contains the logic of the Tree and is an inner class, found in tree.cpp
class TreeNode;

// This class represents an iterator for the tree, to step through every single tree-element step by step.
class TreeIterator
{

public:
    //constructor
    TreeIterator(TreeNode* node = 0);

    //copy constructor
    TreeIterator(const TreeIterator& rhs);

    //overloaded = operator
    TreeIterator& operator=(const TreeIterator& rhs);

    // getter for the value of the current iteration step
    ValueType& value();

    // getter for the key of the current iteration step
    KeyType& key();

    //overloaded ++ operator, one step through the nodes of the tree via increment.
    TreeIterator& operator++();

    //overloaded -- operator, one step through the nodes of the tree via decrement.
    TreeIterator& operator--();

    //overloaded == operator, return true if the current TreeNode* of both TreeIterators is equal
    bool operator==(const TreeIterator &rhs);

    //overloaded == operator, returns true if the current TreeNode* of both TreeIterators are different
    bool operator!=(const TreeIterator &rhs);

private:
    // the current TreeNode of the tree through which the iterator is iterating.
    TreeNode* m_currentTreeNode;
};

// This class represents an unbalanced binary tree.
// The logic is hidden in the inner class called TreeNode.
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

    // This method returns the count of all nodes in the tree, which values are not an empty string.
    unsigned int countCompleteNodes();

    // This method deletes all nodes of the tree and sets all values to 0.
    void clear();

    // This method checks if the key is in the tree already.
    bool contains(const KeyType& key);

    // The []-operator is used to return the corresponding value.
    // New values are also assigned by using this operator (eg. tree[3] = "Dummy";)
    ValueType& operator[](const KeyType& key);

    // This method returns a TreeIterator, which represents the first node in the tree (the one with the smallest key).
    TreeIterator begin();

    // This method returns a TreeIterator, which represents the last node in the tree (the one with the largest key).
    TreeIterator last();

    // This method returns a TreeIterator, which represents the end of a tree (not the last node, but one node AFTER the last node).
    TreeIterator end();

    // This method returns a TreeIterator, which represents the node corresponding the given key.
    TreeIterator find(const KeyType& value);

private:
    // The number of nodes in the tree.
    unsigned int m_count;

    // The root node of the tree.
    TreeNode *m_root;
};
}
#endif // TREE_H
