#include "tree.h"
#include <iostream>

using namespace std;

// TreeNode represents the inner structure and logic of the tree. It is implemented as an inner class.
class TreeNode
{
public:
    // TODO Destructor for recursive Deletion of all TreeNodes

    // This constructor creates the first node in a tree
    TreeNode(TreeNode* parent,
             const KeyType& key,
             const ValueType& value)
    {
        this->m_up = parent;
        this->m_key = key;
        this->m_value = value;
        this->m_left = 0;
        this->m_right = 0;
    }

    TreeNode* findFirst();
    TreeNode* findLast();

    KeyType m_key;
    ValueType m_value;
    TreeNode *m_left;
    TreeNode *m_right;
    TreeNode *m_up;

    // This getter returns the key of the node
    KeyType& key()
    {
        return m_key;
    }

    // This getter returns the value of the node
    ValueType& value()
    {
        return m_value;
    }

    // This method inserts the key-value-pair in the tree ordered by adding or replacing another TreeNode and returns it.
    TreeNode* insert(KeyType key,
                ValueType value)
    {
        // checking if the given key does already exist
        TreeNode *foundNode = this->find(key);
        if (foundNode)
        {
            foundNode->m_value = value;
            return foundNode;
        } else
        {
            // going the right direction in the tree
            if (this->m_key < key)
            {
                // if there is no right child, the new node is created and returned.
                if (!this->m_right)
                {
                    TreeNode *newRightTreeNode = new TreeNode(this, key, value); /* NEUEN KNOTEN ERSTELLEN (THIS IN KONSTRUKTOR ALS PARAMETER MITGEBEN!) */
                    this->m_right =  newRightTreeNode;
                    return newRightTreeNode;
                }

                else
                {
                    // recursive method call if there is a right child
                    return this->m_right->insert(key, value);
                }
            }

            // going the left direction in the tree
            if (this->m_key > key)
            {
                // if there is no left child, the new node is created and returned.
                if (!this->m_left)
                {
                    TreeNode *newLeftTreeNode = new TreeNode(this, key, value); /* NEUEN KNOTEN ERSTELLEN (THIS IN KONSTRUKTOR ALS PARAMETER MITGEBEN!) */
                    this->m_left = newLeftTreeNode;
                    return newLeftTreeNode;
                } 
                else
                {
                    // recursive method call if there is a left child
                    return this->m_left->insert(key, value);
                }
            }
        }
    }

    // This method returns the TreeNode containing the given key, else it is 0.
    TreeNode* find(const KeyType& key)
    {
        if (this->key() == key){
            return this;
        }

        if (this->key() < key)
        {
            if (this->m_right)
            {
                return this->m_right->find(key);
            }
            else
            {
                return 0;
            }
        }
        if (this->key() > key)
        {
            if (this->m_left)
            {
                return this->m_left->find(key);
            }
            else
            {
                return 0;
            }
        }
    }
};

Tree::Tree()
{
    m_count = 0;
    m_root = 0;
}

void clear();
bool contains(const KeyType& key);
TreeIterator begin();
TreeIterator end();

unsigned int Tree::count() const
{
    return m_count;
}

ValueType& Tree::operator[](const KeyType& key)
{

    // if the root node doesn't exist, it is created.
    if (!this->m_root)
    {
        this->m_root = new TreeNode(0, key, "");
        m_count++;
    }

    // returns the the node relating to the given key or null if the key doesn't exist yet.
    TreeNode *temp = this->m_root->find(key);

    if (!temp)
    {
        // TreeNode not found
        // A new node has to be created (by calling the root node and its method insert).

        // count is incremented
        m_count++;

        // the value of the new node is returned directly.
        return this->m_root->insert(key, "")->m_value;
    }
    else
    {
         return temp->m_value;
    }
}
