#include "tree.h"
#include <iostream>

using namespace std;

// TreeNode represents the inner structure and logic of the tree. It is implemented as an inner class.
class TreeNode
{
public:
    // TODO Destructor for recursive Deletion of all TreeNodes
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

    // finds the first element in the tree (the one with the smallest key)
    TreeNode* findFirst()
    {
        if ((!this->m_left))
        {
            return this;
        }
        return this->m_left->findFirst();
    }

    // finds the first element in the tree (the one with the largest key)
    TreeNode* findLast()
    {
        if ((!this->m_right))
        {
            return this;
        }
        return this->m_right->findLast();
    }

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

Tree::Tree()
{
    m_countCompleteNodes = 0;
    m_count = 0;
    m_root = 0;
}

Tree::Tree(const Tree& rhs)
{
    this->m_countCompleteNodes = rhs.m_countCompleteNodes;
    this->m_count = rhs.m_count;
    this->m_root = rhs.m_root;
}

void Tree::clear()
{
    //if root node ist not 0 delete is called
    if(this->m_root){

        // calling the destructor of the root node.
        // the recursive deletion of alle the nodes is handled in the TreeNode destructor
        delete this->m_root;
    }

    // setting the node counter to 0.
    this->m_count = 0;
    cout << "whole tree deleted!" << endl;
}

bool Tree::contains(const KeyType& key)
{
    TreeNode *findNode = m_root->find(key);
    if(findNode){
        return true;
    }
    return false;
}

unsigned int Tree::countCompleteNodes()
{
    // NOT implemented yet
    // Fucking shit a the bottom doesn´t work

    /*if root node ist not 0
    if(this->m_root){

        // if the right node is not 0
        if (this->m_root->m_right->m_value != "")
        {
            m_countCompleteNodes++;
            return this->countCompleteNodes();
        }

        // if the right node is not 0
        if (this->m_root->m_left->m_value != "")
        {
            m_countCompleteNodes++;
            return this->countCompleteNodes();
        }
    }*/
    return m_countCompleteNodes;
}

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

TreeIterator Tree::begin()
{
    TreeNode* temp = this->m_root->findFirst();

    return TreeIterator(temp);
}

TreeIterator Tree::end()
{
    // end() returns only an iterator with a TreeNode * == 0
    return TreeIterator(0);
}

TreeIterator Tree::find(const KeyType &value)
{
    TreeNode* temp = this->m_root->find(value);
    return TreeIterator(temp);
}

TreeIterator::TreeIterator(TreeNode *node)
{
    m_currentTreeNode = node;
}

TreeIterator& TreeIterator::operator=(const TreeIterator& rhs)
{
    this->m_currentTreeNode = rhs.m_currentTreeNode;
    return *this;
}

bool TreeIterator::operator==(const TreeIterator &rhs)
{
    if(this->m_currentTreeNode == rhs.m_currentTreeNode){
        return true;
    }
    return false;
}

bool TreeIterator::operator!=(const TreeIterator &rhs)
{
    if(this->m_currentTreeNode != rhs.m_currentTreeNode){
        return true;
    }
    return false;
}

ValueType& TreeIterator::value()
{
    return this->m_currentTreeNode->m_value;
}

KeyType& TreeIterator::key()
{
    return this->m_currentTreeNode->m_key;
}

// TODO Return a new TreeIterator, or return this??? --> return this!
TreeIterator& TreeIterator::operator++()
{
    if (this->m_currentTreeNode->m_right)
    {
        this->m_currentTreeNode = this->m_currentTreeNode->m_right->findFirst();
        return *this;
    }
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

TreeIterator& TreeIterator::operator--()
{
    // The same as the ++operator (only in reverse!)
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
