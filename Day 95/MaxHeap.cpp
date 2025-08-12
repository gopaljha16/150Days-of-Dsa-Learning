#include <iostream>
using namespace std;

class Maxheap
{

    int *arr;       // the array
    int size;       // total element in the heap
    int total_size; // total size of the array..

public:
    // constructor
    Maxheap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert into the heap
    void insert(int value)
    {
        // edge cases size
        if (size == total_size)
        {
            cout << "Heap Overflow";
            return;
        }

        // insert element value inserted on index and then index ka size badha diya
        arr[size] = value;
        int index = size;
        size++;

        // element at the correct position compare with the parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2; // update the index;
        }
        cout << arr[index] << " is inserted in the the heap " << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // now here the largest will be store the index of the element which is greater betweeen parent , and left child and right child
        if (left < size && arr[left] > arr[largest])
        { // if left is big then replace with the largest
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        { // if right is the big then replace with the largest
            largest = right;
        }

        // so here if the largest value is changed then
        if (largest != index)
        {
            swap(arr[index], arr[largest]); // then swap it with the index;
            Heapify(largest);
        }
    }

    void Delete()
    {
        // value check
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }

        // delete
        cout << arr[0] << " Delete from the heap"<<endl;
        arr[0] = arr[size - 1]; // last index replace karna hai
        size--;                 // size decrease..

        if (size == 0)
        { // if size is 0;
            return;
        }

        Heapify(0);
    }
};

int main()
{
    Maxheap h(6);
    h.insert(10);
    h.insert(20);
    h.insert(4);
    h.insert(50);
    h.insert(200);
    h.print();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.Delete();
    h.print();
}