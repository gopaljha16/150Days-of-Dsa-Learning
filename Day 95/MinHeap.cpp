#include <iostream>
using namespace std;

class MinHeap
{

    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert
    void insert(int value)
    {
        // check is size
        if (size == total_size)
        {
            cout << "Heap overflow" << endl;
            return;
        }

        // value insert
        arr[size] = value;
        int index = size;
        size++;

        // comapring and making fixing means here it should min element top meh hoona chaiye
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into the minheap" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // left
        if (left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap underflow" << endl;
            return;
        }

        // delete
        cout << arr[0] << " Is Deleted from the heap" << endl;
        arr[0] = arr[size - 1]; // last element
        size--;

        if (size == 0)
            return;

        Heapify(0);
    }
};

int main()
{
    MinHeap h(6);
    h.insert(10);
    h.insert(20);
    h.insert(50);
    h.insert(1);
    h.print();
    h.Delete();
    h.print();
    h.Delete();
    h.print();
}