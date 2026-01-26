#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <bits/stdc++.h>

class FenwickTree {
  private:
    std::vector<int> tree{};

  public:
    FenwickTree(const std::vector<int> &input) {
        tree.resize(input.size() + 1, 0);
        for (size_t i = 0; i < input.size(); i++) {
            tree[i + 1] = input[i];
        }
        for (size_t i = 1; i < tree.size(); i++) {
            int j = i & -i;
            tree[i + j] += tree[i];
        }
    }

    int prefix_sum(int pos) {
        int i = pos + 1;
        int sum{};
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
    }

    void update(int pos, int delta) {
        int i = pos + 1;
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    void print() {
        std::cout << '[';
        for (size_t i = 1; i < tree.size(); i++) {
            std::cout << tree[i];
            if (i < tree.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

#endif // FENWICK_TREE_H
