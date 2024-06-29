// heaps -- order property -- the node is smaller than every descendant
// heaps -- structure property -- complete binary tree -- the last level should have missing nodes at right
// entire point of having a heap is to find min or max value
// root node is always gonna be at index 1
//  left child = 2 * i
// right child = 2 * i + 1
// parent = i / 2

#include <vector>
#include <iostream>

using namespace std;

class Heap
{
public:
    vector<int> heap;
    Heap()
    {
        heap = {0};
    }

    void push(int value)
    {

        heap.push_back(value);
        int i = heap.size() - 1;
        int temp;

        // shift up til priority conidtion
        // is
        while (heap[i] < heap[i / 2])
        {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    /*

    check if every node has a value smaller than its descendants
    half of the nodes do not have children so we can skip half


    */
    void heapify(vector<int> values)
    {
        values.push_back(values[0]);
        heap = values;
        int n = heap.size();
        int curr = (n - 1) / 2;
        int i;

        while (curr > 0)
        {
            i = curr;
            while (2 * i < n)
            {

                if (2 * i + 1 < n && heap[2 * i + 1] < heap[2 * i] && heap[i] > heap[2 * i + 1])
                {
                    swap(2 * i + 1, i, heap);
                    i = 2 * i + 1;
                }
                else if (heap[2 * i] < heap[i])
                {
                    swap(2 * i, i, heap);
                    i = 2 * i;
                }
                else
                    break;
            }
            curr--;
        }
    }

    void swap(int i, int j, vector<int> &arr)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // poppping the minimum element
    int pop()
    {
        if (heap.size() == 1)
            return -1;

        int val = heap[1];
        heap[1] = heap.back();
        heap.pop_back();

        int n = heap.size();

        if (n == 1)
            return val;

        int i = 1;
        int temp;

        while (2 * i < n)
        {

            if (2 * i + 1 < n && heap[2 * i + 1] < heap[2 * i] && heap[i] > heap[2 * i + 1])
            {
                temp = heap[i];
                heap[i] = heap[2 * i + 1];
                heap[2 * i + 1] = heap[i];
                i = 2 * i + 1;
            }
            else if (heap[i] > heap[2 * i])
            {

                temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = heap[i];
                i = 2 * i;
            }
            else
                break;
        }

        return val;
    }
};
