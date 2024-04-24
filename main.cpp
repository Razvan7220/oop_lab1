#include <iostream>


template <typename T>
struct Node
{
    T value;
    Node<T>** children;
    unsigned int nrChildren;

    Node() : value(), children(nullptr), nrChildren(0) {}
};

template <class T>
class Tree
{
private:
    Node<T>* root;
    unsigned int maxChildrenPerNode;

    void deleteNodeAndChildren(Node<T>* node)
    {
        if (node == nullptr)
            return;

        for (unsigned int i = 0; i < node->nrChildren; ++i)
            deleteNodeAndChildren(node->children[i]);

        delete[] node->children;
        delete node;
    }


    Node<T>* findHelper(Node<T>* parent, T value, int (*compare)(T, T))
    {
        if (parent == nullptr)
            return nullptr;

        if (compare(parent->value, value) == 0)
            return parent;

        for (unsigned int i = 0; i < parent->nrChildren; ++i)
        {
            Node<T>* found = findHelper(parent->children[i], value, compare);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    void insertAtIndex(Node<T>* parent, T value, unsigned int index)
    {
        if (parent == nullptr)
            return;


        for (unsigned int i = parent->nrChildren; i > index; --i)
            parent->children[i] = parent->children[i - 1];


        parent->children[index] = new Node<T>;
        parent->children[index]->value = value;
        parent->children[index]->nrChildren = 0;
        parent->children[index]->children = new Node<T>*[maxChildrenPerNode] {};

        parent->nrChildren++;
    }

public:
    Tree(unsigned int nrChildren) : root(nullptr), maxChildrenPerNode(nrChildren) {}

    ~Tree()
    {
        deleteNodeAndChildren(root);
    }

    Node<T>* add_node(Node<T>* parent, T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->nrChildren = 0;
        newNode->children = new Node<T>*[maxChildrenPerNode] {};
        if (parent == nullptr)
            root = newNode;

        else
            parent->children[parent->nrChildren++] = newNode;

        return newNode;
    }


    Node<T>* get_node(Node<T>* parent)
    {
        return parent == nullptr ? root : parent;
    }

    void delete_node(Node<T>* node)
    {
        if (node == nullptr)
            return;
        deleteNodeAndChildren(node);
    }

    Node<T>* find(T value, int (*compare)(T, T))
    {
        return findHelper(root, value, compare);
    }

    void insert(Node<T>* parent, T value, unsigned int index)
    {
        insertAtIndex(parent, value, index);
    }

    void sort(Node<T>* parent, int (*comparatie)(T, T) = nullptr)
    {
        if (parent == nullptr)
            return;
        if (comparatie == nullptr)
            comparatie = [](T a, T b) { return a < b ? -1 : (a > b ? 1 : 0); };

        for (unsigned int i = 0; i < parent->nrChildren - 1; ++i)
        {
            for (unsigned int j = i + 1; j < parent->nrChildren; ++j)
            {
                if (comparatie(parent->children[i]->value, parent->children[j]->value) > 0)
                    std::swap(parent->children[i], parent->children[j]);

            }
        }
    }

    void printNodes(Node<T>* parent)
    {
        if (parent == nullptr)
            return;

        std::cout << parent->value << " ";

        for (unsigned int i = 0; i < parent->nrChildren; ++i)
            printNodes(parent->children[i]);

    }

    unsigned int count(Node<T>* parent = nullptr)
    {
        if (parent == nullptr)
            parent = root;

        unsigned int totalCount = parent->nrChildren;
        for (unsigned int i = 0; i < parent->nrChildren; ++i)
            totalCount += count(parent->children[i]);

        return totalCount;
    }

};
