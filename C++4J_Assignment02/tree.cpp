#include "tree.h"
#include <iostream>

using namespace std;
using namespace CPP4JTree;

/** The class TreeNode **/
// TreeNode represents the inner structure and logic of the tree. It is implemented as an inner class.
class CPP4JTree::TreeNode
{
public:
    // the key of the node
    KeyType m_key;

    // the value corresponding to the key
    ValueType m_value;

    // the left child node
    TreeNode *m_left;

    // the right child node
    TreeNode *m_right;

    // the parent node
    TreeNode *m_up;

    // This destructor takes care of deleting all child nodes of the node that is deleted (by the help of recursion).
    ~TreeNode()
    {
        if (this->m_right)
        {
           delete this->m_right;
        }
        if (this->m_left)
        {
           delete this->m_left;
        }
    }

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

    // finds the first element in the subtree of the calling node (the one with the smallest key)
    TreeNode* findFirst()
    {
        if ((!this->m_left))
        {
            return this;
        }
        return this->m_left->findFirst();
    }

    // finds the first element in the subtree of the calling node (the one with the largest key)
    TreeNode* findLast()
    {
        if ((!this->m_right))
        {
            return this;
        }
        return this->m_right->findLast();
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
                    TreeNode *newRightTreeNode = new TreeNode(this, key, value);
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
                    TreeNode *newLeftTreeNode = new TreeNode(this, key, value);
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
        return 0;
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
        return 0;
    }
};


/** The class Tree **/

CPP4JTree::Tree::Tree()
{
    m_count = 0;
    m_root = 0;
}

//TODO: copy consructor für Tree & Iterator
//TODO: Zuweisungs-Operator für Tree & Iterator
CPP4JTree::Tree::Tree(const Tree& rhs)
{
    this->m_count = rhs.m_count;
    this->m_root = rhs.m_root;
}

void CPP4JTree::Tree::clear()
{
    //if root node ist not 0 delete is called
    if(this->m_root){

        // calling the destructor of the root node.
        // the recursive deletion of alle the nodes is handled in the TreeNode destructor
        delete this->m_root;
    }

    // setting the node counter to 0.
    this->m_count = 0;
}

bool CPP4JTree::Tree::contains(const KeyType& key)
{
    TreeNode *findNode = m_root->find(key);
    if(findNode){
        return true;
    }
    return false;
}

unsigned int CPP4JTree::Tree::count() const
{
    return m_count;
}

ValueType& CPP4JTree::Tree::operator[](const KeyType& key)
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

TreeIterator CPP4JTree::Tree::begin()
{
    TreeNode* temp = this->m_root->findFirst();

    return TreeIterator(temp);
}

TreeIterator CPP4JTree::Tree::last()
{
    TreeNode* temp = this->m_root->findLast();

    return TreeIterator(temp);
}

TreeIterator CPP4JTree::Tree::end()
{
    // end() returns only an iterator with a TreeNode* == 0
    return TreeIterator(0);
}

TreeIterator CPP4JTree::Tree::find(const KeyType &value)
{
    TreeNode* temp = this->m_root->find(value);
    return TreeIterator(temp);
}


/** The class TreeIterator**/

CPP4JTree::TreeIterator::TreeIterator(TreeNode *node)
{
    m_currentTreeNode = node;
}

TreeIterator& CPP4JTree::TreeIterator::operator=(const TreeIterator& rhs)
{
    this->m_currentTreeNode = rhs.m_currentTreeNode;
    return *this;
}

bool CPP4JTree::TreeIterator::operator==(const TreeIterator &rhs)
{
    if(this->m_currentTreeNode == rhs.m_currentTreeNode){
        return true;
    }
    return false;
}

bool CPP4JTree::TreeIterator::operator!=(const TreeIterator &rhs)
{
    if(this->m_currentTreeNode != rhs.m_currentTreeNode){
        return true;
    }
    return false;
}

ValueType& CPP4JTree::TreeIterator::value()
{
    return this->m_currentTreeNode->m_value;
}

KeyType& CPP4JTree::TreeIterator::key()
{
    return this->m_currentTreeNode->m_key;
}

TreeIterator& CPP4JTree::TreeIterator::operator++()
{
    // If the current TreeNode has a right child the first element of this child tree is the next TreeNode
    if (this->m_currentTreeNode->m_right)
    {
        this->m_currentTreeNode = this->m_currentTreeNode->m_right->findFirst();
        return *this;
    }
    // If the current TreeNode doesn't have a right child, the parent node is checked if it is the next TreeNode
    // If the current TreeNode is the left child of the parent node, the parent note is the next TreeNode
    // If the current TreeNode is the right child of the parent node, the search continues in the parents' parent node.
    // If there are no more parent nodes, then there is no following node to the current TreeNode.
    else
    {
        TreeNode *parentNode = this->m_currentTreeNode->m_up;
        TreeNode *lastParentNode = this->m_currentTreeNode;

        while (parentNode)
        {
            if  (parentNode->m_left == lastParentNode)
            {
                this->m_currentTreeNode = parentNode;
                return *this;
            }
            else
            {
                lastParentNode = parentNode;
                parentNode = parentNode->m_up;
            }
        }
        this->m_currentTreeNode = 0;
        return *this;
    }
}

// This method works exactly like the ++operator (only in reverse!)
TreeIterator& CPP4JTree::TreeIterator::operator--()
{
    // TODO: findlast() for -- bei iterator.end() --> Nach Konvention würde dann auf den letzten Node gesprungen werden.
    if (this->m_currentTreeNode->m_left)
    {
        this->m_currentTreeNode = this->m_currentTreeNode->m_left->findLast();
        return *this;
    }
    else
    {
        TreeNode *parentNode = this->m_currentTreeNode->m_up;
        TreeNode *lastParentNode = this->m_currentTreeNode;

        while (parentNode)
        {
            if (parentNode->m_right == lastParentNode)
            {
                this->m_currentTreeNode = parentNode;
                return *this;
            }
            else
            {
                lastParentNode = parentNode;
                parentNode = parentNode->m_up;
            }
        }
        this->m_currentTreeNode = 0;
        return *this;
    }
}
