#ifndef SPACESAVING_H
#define SPACESAVING_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#define newline "\n"
using namespace std;

struct Node
{
    string id;
    int weight, error, index;

    // constructor
    Node(string a, int b, int c, int d)
    {
        id = a;
        weight = b;
        error = c;
        index = d;
    }
};

typedef unordered_map<string, Node *> umsn;
typedef vector<Node *> vn;

class SpaceSaving
{
private:
    vn minHeap;                                                 // data structure for the summary
    int k;                                                      // capacity of heap
    umsn dict;                                                  // keys on heap

public:
    SpaceSaving(int capacity);                                  // constructor
    ~SpaceSaving();                                             // destructor

    void swap(Node *a, Node *b);                                // swap two nodes

    int parent(int i) { return (i - 1) / 2; }                   // to get index of parent of node at index i
    int left(int i) { return (2 * i + 1); }                     // to get index of left child of node at index i
    int right(int i) { return (2 * i + 2); }                    // to get index of right child of node at index i

    void spaceSaving(string id);                                // main algorithm
    void increaseKey(int i);                                    // increment counter
    void print();                                               // print the stream summary
};

#endif // SPACESAVING_H