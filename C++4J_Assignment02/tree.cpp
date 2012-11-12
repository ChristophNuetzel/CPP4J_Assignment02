#include "tree.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
    m_count = 0;
    m_root = 0;
}

unsigned int Tree::count() const
{
    return m_count;
}

ValueType& Tree::operator[](const KeyType& key)
{
    cout << "blubb" << endl;
    ValueType tempString = "Hallooechen!";
    return tempString;
//    if (!this->m_root)
//    {
//        this->m_root = new TreeNode(0, key, "");
//    }
//    TreeNode *temp = this->m_root->find(key);

//    if (!temp)
//    {
//        // TODO New node has to be created. m_root.insert(key, "")
//        return "";
//    }
//    else
//    {
//         return temp->m_value;
//    }
}

// TreeNode represents the inner structure and logic of the tree. It is implemented as an inner class.
class TreeNode
{
private:
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

    // This method inserts the key-value-pair in the tree ordered by adding or replacing another TreeNode.
    void insert(KeyType key,
                ValueType value)
    {
        TreeNode *foundNode = this->find(key);
        if (foundNode)
        {
            foundNode->m_value = value;
            return;
        } else
        {
            if (this->m_key < key)
            {
                if (!this->m_right){
                    this->m_right =  new TreeNode(this, key, value); /* NEUEN KNOTEN ERSTELLEN (THIS IN KONSTRUKTOR ALS PARAMETER MITGEBEN!) */
                    return;
                }
            }
            else
            {
                return this->m_right->insert(key, value);
            }

            if (this->m_key > key)
            {
                if (!this->m_left)
                {
                    this->m_left = new TreeNode(this, key, value); /* NEUEN KNOTEN ERSTELLEN (THIS IN KONSTRUKTOR ALS PARAMETER MITGEBEN!) */
                    return;
                }
            }
            else
            {
                return this->m_left->insert(key, value);
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

    TreeNode* findFirst();
    TreeNode* findLast();

    KeyType m_key;
    ValueType m_value;
    TreeNode *m_left;
    TreeNode *m_right;
    TreeNode *m_up;
};
