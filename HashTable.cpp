#include <iostream>
#include <string>

// Basic Hash Table Overview
class HashTable
{
    class Entry
    {
    public:
        int key;
        std::string value;

        Entry(int key, std::string value)
            : key(key), value(value) {}
    };
    class Node
    {
    public:
        Entry *data;
        Node *next;
        Node(Entry *data)
            : data(data), next(nullptr) {}
    };

    int size;
    Node **entries;

public:
    HashTable(int size)
        : size(size), entries(new Node *[this->size]())
    {
    }

    void insert(int key, std::string value)
    {
        int index = hash(key);
        if (entries[index] == nullptr)
            entries[index] = new Node(new Entry(key, value));
        else
        {
            Node *current = entries[index];
            while (current != nullptr)
            {
                if (current->data->key == key)
                {
                    current->data->value = value;
                    return;
                }
                current = current->next;
            }
            current->next = new Node(new Entry(key, value));
        }
    }

    int hash(int key)
    {
        return key % 5;
    }

    std::string getValue(int key)
    {
        int index = hash(key);
        Node *current = entries[index];
        while (current != nullptr)
        {
            if (current->data->key == key)
                return current->data->value;
        }
        return nullptr;
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
            delete entries[i];
        delete[] entries;
    }
};

int main()
{
    HashTable *hash = new HashTable(5);
    hash->insert(1, "Hello");
    std::cout << hash->getValue(1);
    delete hash;
    return 0;
}
