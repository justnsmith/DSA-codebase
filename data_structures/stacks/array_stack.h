#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <optional>

template <typename T> class ArrayStack {
  private:
    int size{4};
    int count{};
    T *arr = nullptr;

    void resizeArr() {
        size *= 2;
        T *newArr = new T[size];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

  public:
    ArrayStack() {
        arr = new T[size];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(const T &data) {
        if (count == size - 1) {
            resizeArr();
        }
        arr[count++] = data;
    }

    std::optional<T> pop() {
        if (count == 0) {
            return std::nullopt;
        }
        return arr[--count];
    }

    std::optional<T> top() {
        if (count == 0) {
            return std::nullopt;
        }
        return arr[count - 1];
    }

    bool isEmpty() const {
        return count == 0;
    }
    int size() const {
        return count;
    }

    void clear() {
        count = 0;
    }
};

#endif // ARRAY_STACK_H
