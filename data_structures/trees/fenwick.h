#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <bits/stdc++.h>
#include <bitset>

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

    int prefix_sum(int index) {
        int treeIndex = index + 1;

        if (static_cast<size_t>(treeIndex) > tree.size() - 1) {
            return -1;
        }

        int currentRemaining = treeIndex;
        int sum{};

        while (currentRemaining - (treeIndex & -treeIndex) >= 0) {
            if (currentRemaining == 0) {
                break;
            }
            sum += tree[treeIndex];
            currentRemaining -= (treeIndex & -treeIndex);
            treeIndex -= treeIndex & -treeIndex;
        }
        return sum;
    }

    void update(int pos, int value) {
        int treeIndex = pos + 1;
        int j = treeIndex & -treeIndex;
        int diff = value - tree[treeIndex];

        if (static_cast<size_t>(treeIndex) > tree.size() - 1) {
            return;
        }

        tree[treeIndex] = value;

        while (static_cast<size_t>(j + treeIndex) < tree.size() - 1) {
            tree[treeIndex + j] += diff;
            treeIndex += j;
            j = treeIndex & -treeIndex;
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
