#ifndef ARRAY_LINKED_LIST_H
#define ARRAY_LINKED_LIST_H

#include <optional>

template <typename T> class LinkedListStack {
  private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head{};
    int count{};

  public:
    ~LinkedListStack() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T &data) {
        Node *newNode = new Node{data, head};
        head = newNode;
        ++count;
    }

    std::optional<T> pop() {
        if (count == 0) {
            return std::nullopt;
        }
        T result = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return result;
    }

    std::optional<T> top() {
        if (count == 0) {
            return std::nullopt;
        }
        return head->data;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void clear() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }
};

#endif // ARRAY_LINKED_LIST_H
