#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int CAP = 10;

class String {
private:
public:
    string str;
    String(string str) : str(str) {};
    int hashCode();
    static string nulll() { return ""; }
};

int String::hashCode() {
    int hash = 0;
    int c = 1;
    
    for(int i = str.size() - 1; i >= 0; i--) {
        hash += c * (str[i] - 'a');
        c *= 26;
    }

    return hash;
}


template<class K, class V>
class HashTableNode
{
public:
    const int hash;
    K key;
    V value;
    HashTableNode(int hash, K key, V value) : hash(hash), key(key), value(value) {};
};

template<class K, class V>
class HashTable
{
private:
    vector<HashTableNode<K, V>> table;
    int _size;
public:
    HashTable(int capacity) : _size(0) {}
    HashTable() { this(CAP); }
    int size() { return _size; }
    int capacity() { return table.size(); }
    bool empty() { return !_size; }
    void put(K key, V value);
    void resize(int capacity);
    V get(K key);
    bool contains(K key) { return get(key) != V::nullValue(); }
    V remove(K key);
    int linearProbling(int index) { return (index + 1) % capacity(); }
    int quadricProbing(int index) { return ((index * index) & INT32_MAX) % capacity(); }
    int h_double(int key, int i) { return (h_double2(key) + i) % capacity(); }
    int h_double2(int key, int i) { return (1 + key) % (capacity() - 1); }
    int hash(K key) { return key == K::nullValue() ? 0 : INT32_MAX & key.hashCode(); }
    int getIndex(int hash) { return hash % capacity(); }
    static HashTableNode<K, V> nullValue() { return HashTableNode<K, V>(K.nullValue(), V.nullValue()); }
};

template<class K, class V>
void HashTable<K, V>::put(K key, V value) {
    int hashCode = hash(key);
    int index = getIndex(hashCode);
    int start = index;
    HashTableNode<K, V> node;

    while ( (node = table[index]) != HashTableNode<K, V>::nullValue() ) {
        if (hashCode = node.hash && node.key == key) {
            table[index].value = value;
            return;
        }

        index = linearProbling(index);
        if (index == start) {
            resize(capacity() * 2);
            index = getIndex(hash);
            start = index;
        }
    }

    table[index] = HashTableNode<K, V>(hash, key, value);
    size++;
}

template<class K, class V>
void HashTable<K, V>::resize(int capacity) {
    vector<HashTableNode<K, V>> oldTable = table;
    table = new vector<HashTableNode<K, V>>(capacity);
    // table.resize(capacity);
    // table.clear();
    size = 0;
    for(HashTableNode<K, V> hashNode : oldTable) {
        if (hashNode != HashTableNode<K, V>::nullValue()) {
            put(hashNode.key, hashNode.value);
        }
    }
}

template<class K, class V>
V HashTable<K, V>::get(K key) {
    int hashCode = hash(key);
    HashTableNode<K, V> node;
    int index = getIndex(hashCode);
    int start = index;

    while ( (node = table[index]) != HashTableNode<K, V>::nullValue() ) {
        if (hashCode == node.hash && key == node.key) {
            return table[index].value;
        }

        index = linearProbling(index);
        if (index == start) return V::nullValue();
    }
    return V::nullValue();
}

template<class K, class V>
V HashTable<K, V>::remove(K key) {
    int hashCode = hash(key);
    int index = getIndex(hashCode);
    int start = index;
    HashTableNode<K, V> node;
    V oldValue = V::nullValue();

    while( (node = table[index]) != HashTableNode<K, V>::nullValue() ) {
        if (hashCode == node.hash && key == node.key) {
            oldValue = table[index].value;
            table[index] = HashTableNode<K, V>::nullValue();
            size--;
        }
        index = linearProbling(index);
        if (index == start) break;
    }

    if (size == capacity() / 4 && capacity / 2 != 0) {
        resize(capacity() / 2);
    }

    return oldValue;
}

int main() {
    HashTable<String, String> ht(20);
    ht.put(String("alireza"), String("jafartash"));
    cout << ht.get(String("alireza")).str << endl;
}