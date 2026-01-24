#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <bits/stdc++.h>
#include <bitset>

class MaxHeap {
  private:
    std::vector<int> heap;
    int counter{0};

    void bubbleUp(int index) {
        int parent = (index - 1) / 2;
        while (parent >= 0) {
            if (heap[parent] < heap[index]) {
                std::swap(heap[parent], heap[index]);
                index = parent;
                parent = (index - 1) / 2;
            } else {
                break;
            }
        }
    }

    void bubbleDown(int index) {
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < counter && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < counter && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

  public:
    void insert(int data) {
        heap.push_back(data);
        bubbleUp(counter++);
    }

    int pop() {
        int result = heap[0];
        std::swap(heap[0], heap[--counter]);
        bfsPrint();
        bubbleDown(0);
        return result;
    }

    void bfsPrint() {
        std::cout << "[";
        for (int i = 0; i < counter; i++) {
            std::cout << heap[i];
            if (i < counter - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

#endif // MAX_HEAP_H
