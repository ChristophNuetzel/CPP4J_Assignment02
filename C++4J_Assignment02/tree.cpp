#include "tree.h"

Tree::Tree()
    :m_count(0),m_root(0)
{}

unsigned int Tree::count() const
{
    return m_count;
}

// TreeNode represents the inner structure and logic of the tree. It is implemented as an inner class.
class TreeNode
{
private:
    // This constructor creates the first node in a tree
    TreeNode(TreeNode* parent = 0,
             const KeyType& key = KeyType(),
             const ValueType& value = ValueType());

    // This getter returns the key of the node
    KeyType& key(){
        return m_key;
    }

    // This getter returns the value of the node
    ValueType& value(){
        return m_value;
    }

    // This method inserts the key-value-pair in the tree ordered by adding or replacing another TreeNode.
    void insert(KeyType key,
                ValueType value);

    // This method returns the TreeNode containing the given key, else it is 0.
    TreeNode* find(const KeyType& key);

    TreeNode* findFirst();
    TreeNode* findLast();

    KeyType m_key;
    ValueType m_value;
    TreeNode *m_left;
    TreeNode *m_right;
    TreeNode *m_up;
};
