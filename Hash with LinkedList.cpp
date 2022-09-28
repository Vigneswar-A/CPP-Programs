#include <iostream>

using namespace std;

class Node
{
    int key;
    Node *next;
    Node(int k, Node *nxt = nullptr)
    {
        key = k;
        next = nxt;
    }
    friend class HashSet;
};

class HashSet
{
private:
    int size = 1007;
    Node *set[1007];

    int hash(int key)
    {
        return 61 * key + 73;
    }

public:
    HashSet()
    {
        for (int i = 0; i < 1007; i++)
            set[i] = nullptr;
    }
    void add(int key)
    {
        if (contains(key))
            return;
        set[hash(key) % size] = new Node(key, set[hash(key) % size]);
    }

    void remove(int key)
    {
        Node *currnode = set[hash(key) % size];

        if (currnode == nullptr)
            return;

        if (currnode->key == key)
        {
            set[hash(key) % size] = currnode->next;
            return;
        }
        while (currnode->next != nullptr)
        {
            if (currnode->next->key == key)
            {
                currnode->next = currnode->next->next;
                return;
            }
            currnode = currnode->next;
        }
    }

    bool contains(int key)
    {
        for (Node *currnode = set[hash(key) % size]; currnode != nullptr; currnode = currnode->next)
            if (currnode->key == key)
                return true;
        return false;
    }
};

int main(void)
{
    HashSet hashset;
    hashset.add(3);
    hashset.add(4);
    hashset.add(5);
    cout << boolalpha;
    cout << hashset.contains(5) << endl;
    cout << hashset.contains(3) << endl;
    cout << hashset.contains(4) << endl;
    cout << hashset.contains(9) << endl;
}
