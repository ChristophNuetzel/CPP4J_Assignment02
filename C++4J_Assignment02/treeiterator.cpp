#include <treeiterator.h>
#include <iostream>


using namespace std;

TreeIterator::TreeIterator()
{
    KeyType m_key;
    ValueType m_value;
}

TreeIterator& TreeIterator::operator=(const TreeIterator& rhs)
{
    this->m_key = rhs.m_key;
    this->m_value = rhs.m_value;
    return *this;
}

bool TreeIterator::operator==(const TreeIterator &rhs)
{
    if(this->m_key == rhs.m_key && this->m_value == rhs.m_value){
        return true;
    }
    return false;
}

bool TreeIterator::operator!=(const TreeIterator &rhs)
{
    if(this->m_key != rhs.m_key || this->m_value != rhs.m_value){
        return true;
    }
    return false;
}

ValueType& TreeIterator::value()
{
    return m_value;
}

KeyType& TreeIterator::key()
{
    return m_key;
}
