#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

template <typename T> class LinkedListQueue {
  private:
    struct Node {
        T data;
        Node *next;
    };
    int count{};
    Node *front{};
    Node *back{};

  public:
    ~LinkedListQueue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        front = nullptr;
        back = nullptr;
    }

    void enqueue(const T &data) {
        if (back == nullptr) {
            front = back = new Node{data, nullptr};
        }
        else {
            back->next = new Node{data, nullptr};
            back = back->next;
        }
        count++;
    }

    T dequeue() {
        if (front != nullptr) {
            Node *result = front;
            front = front->next;
            T resultValue = result->data;
            delete result;
            return resultValue;
        }
    }

    int size() {
        return count;
    }
};

#endif // LINKED_LIST_QUEUE_H
