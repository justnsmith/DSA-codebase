#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

template <typename T> class ArrayQueue {
  private:
    T *arr;
    int size_{};
    int front_{};
    int back_{};
    int count_{};

  public:
    ArrayQueue() = delete;
    ArrayQueue(int size) : size_(size) {
        arr = new T[size];
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    void enqueue(const T &data) {
        if (count_ < size_) {
            arr[back_] = data;
            back_ = (back_ + 1) % size_;
            count_++;
        }
    }

    T &dequeue() {
        if (count_ != 0) {
            const T &result = arr[front_];
            front_ = (front_ + 1) % 10;
            count_--;
            return result;
        }
    }

    int size() {
        return count_;
    }
};

#endif // ARRAY_QUEUE_H
