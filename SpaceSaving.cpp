#include "SpaceSaving.h"

// constructor
SpaceSaving::SpaceSaving(int capacity)
{
    k = capacity;
    minHeap.resize(k, nullptr);

    // initialize the min-heap with k dummy entries
    for (int i = 0; i < k; i++)
    {
        Node *n = new Node("dummy", 0, 0, i);
        minHeap[i] = n;
    }
}

// destructor
SpaceSaving::~SpaceSaving()
{
    for (auto &&i : minHeap)
    {
        delete i;
    }
    minHeap.clear();
    dict.clear();
}

// swap the values of two nodes
void SpaceSaving::swap(Node *a, Node *b)
{
    Node *tmp1 = new Node(a->id, a->weight, a->error, a->index);
    Node *tmp2 = new Node(b->id, b->weight, b->error, b->index);

    a->id = tmp2->id, a->weight = tmp2->weight, a->error = tmp2->error;
    b->id = tmp1->id, b->weight = tmp1->weight, b->error = tmp1->error;

    if (dict.find(tmp1->id) != dict.end())
    {
        dict[tmp1->id] = b;
    }

    if (dict.find(tmp2->id) != dict.end())
    {
        dict[tmp2->id] = a;
    }
}

// main algorithm
void SpaceSaving::spaceSaving(string id)
{
    // increment the weight of input if it is on the heap
    if (dict.find(id) != dict.end())
    {
        int i = dict[id]->index;
        increaseKey(i);
    }
    // o.w. replace the minimum with the new input
    else
    {

        Node *min = minHeap[0];

        if (min->id != "dummy")
        {
            dict.erase(min->id);

            // insert new input on dictionary and minHeap
            Node *n = new Node(id, min->weight, min->weight, 0);
            minHeap[0] = n;
            dict[id] = n;

            // we will always delete minHeap[0]
            // instead of actually deleting it, insert the new element in this position
            increaseKey(0);
        }
        else
        {
            Node *n = new Node(id, min->weight, min->weight, 0);
            minHeap[0] = n;
            dict[id] = n;
            increaseKey(0);
        }
    }
}

void SpaceSaving::increaseKey(int i)
{
    minHeap[i]->weight += 1;

    // maximum index = k - 1
    while (left(i) < k || right(i) < k)
    {
        int curr = minHeap[i]->weight;

        if (left(i) < k && right(i) < k)
        {
            int leftChild = minHeap[left(i)]->weight;
            int rightChild = minHeap[right(i)]->weight;
            int smallerChild = (leftChild <= rightChild) ? leftChild : rightChild;
            int smallerChildIndex = (leftChild <= rightChild) ? left(i) : right(i);

            // swap with the samller child
            if (curr > smallerChild)
            {
                swap(minHeap[i], minHeap[smallerChildIndex]);
                i = smallerChildIndex;
            }
            else
            {
                break;
            }
        }
        else if (left(i) < k)
        {
            int smallerChild = minHeap[left(i)]->weight;
            int smallerChildIndex = left(i);

            if (curr > smallerChild)
            {
                swap(minHeap[i], minHeap[smallerChildIndex]);
                i = smallerChildIndex;
            }
            else
            {
                break;
            }
        }
        else
        {
            std::cout << "Should not run into this case" << std::endl;
            // this case needs attention for further debugging
            if (curr > minHeap[right(i)]->weight)
            {
                swap(minHeap[i], minHeap[right(i)]);
                i = right(i);
            }
            else
            {
                break;
            }
        }
    }
}

// print the min-Heap
void SpaceSaving::print()
{
    for (int i = 0; i < k; i++)
    {
        cout << "Item: " << minHeap[i]->id << "; ";
        cout << "Weight: " << minHeap[i]->weight << "; ";
        cout << "Error: " << minHeap[i]->error << "\n";
    }
}