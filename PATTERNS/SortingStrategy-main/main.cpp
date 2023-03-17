#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
};

class AscendingSort : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        std::sort(data.begin(), data.end());
    }
};

class DescendingSort : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        std::sort(data.rbegin(), data.rend());
    }
};

class Sorter {
private:
    SortingStrategy* strategy;
public:
    Sorter(SortingStrategy* strategy) : strategy(strategy) {}

    void setSortingStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void sort(vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    vector<int> numbers = { 5, 2, 7, 1, 9, 3 };

    SortingStrategy* ascending = new AscendingSort();
    SortingStrategy* descending = new DescendingSort();

    Sorter sorter(ascending);
    sorter.sort(numbers);
    cout << "Ascending sort: ";
    for (auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    sorter.setSortingStrategy(descending);
    sorter.sort(numbers);
    cout << "Descending sort: ";
    for (auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    delete ascending;
    delete descending;

    return 0;
}
