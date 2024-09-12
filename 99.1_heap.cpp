#include <vector>

using namespace std;

class Heap
{
public:
    vector<int> heap;

    // heap starts at index 1 so index 1 is never gonna be touched
    Heap()
    {
        heap.push_back(0);
    }

    void push(int val)
    {
        heap.push_back(val);
        int i = heap.size() - 1;
        // Percolate up
        while (i > 1 && heap[i] < heap[i / 2]) {
            int tmp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = tmp;
            i = i / 2;
        }
    }

    int pop()
    {
        if(heap.size() == 1) return -1;
        int res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        if(heap.size() == 2) return res;

        int i = 1;
        while(2 * i < heap.size())
        {
            if(2 * i + 1 < heap.size() && heap[i] > heap[2 * i + 1] && heap[2 * i + 1] < heap[2 * i])
            {
                int tmp = heap[i];
                heap[i] = heap[2 * i + 1];
                heap[2 * i + 1] = temp;

            }

        }
    }

    int top() {return heap[1];}

};

int main()
{
}