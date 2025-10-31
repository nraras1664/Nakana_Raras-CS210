//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //Adds the index to the end of the heap (which is size), fixes the order with upheap(), then adjusts the size of the heap
    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        ++size;
    }

    //returns smallest index (always at index 0), then fixes the order with downheap()
    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int smallest = data[0];
        // replaces root with last element
        data[0] = data[size - 1];
        --size;
        if (size > 0) {
            downheap(0, weightArr);
        }
        return smallest;
    }

    //restores the order if the child is smaller than the parent
    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            //if parent is bigger than child
            if (weightArr[data[parent]] > weightArr[data[pos]]) {
                int temp = data[parent];
                data[parent] = data[pos];
                data[pos] = temp;

                pos = parent;
            }
            else {
                break;
            }
        }
    }

    //restores order if parent is larger than left or right child
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos < size) {
            int smallest = pos;
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;

            //if there is left child in the heap AND if the weight of left child is smaller than the weight of parent
            if ((leftChild < size) && (weightArr[data[leftChild]] < weightArr[data[pos]])) {
                smallest = leftChild;
            }

            //if there is a right child AND if the weight of right child is smaller than the weight of parent
            if ((rightChild < size) && (weightArr[data[rightChild]] < weightArr[data[pos]])) {
                smallest = rightChild;
            }

            //if the assumed smallest (pos) is not the actual smallest, swap them
            if (smallest != pos) {
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            }
            else {
                break;
            }
        }
    }
};

#endif