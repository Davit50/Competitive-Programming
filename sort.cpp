#include <bits/stdc++.h>

using namespace std;


void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)cout << arr[i] << " ";
}

vector<int> bubble(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}


vector<int> selection(vector<int> arr) {
    int n = arr.size();
    int min_;
    for (int i = 0; i < n - 1; i++) {
        min_ = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_]) { min_ = j; }
        swap(arr[min_], arr[i]);
    }
    return arr;
}


vector<int> insertion(vector<int> arr) {
    int n = arr.size();
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}


int main() {
    vector<int> arr{1, 2, 34, 45, 43, 3, 2, 3, 0, 4, 443, 3};
    vector<int> result;
    int n = arr.size();

//    0(n^2)
    result = bubble(arr);
    selection(arr);
    insertion(arr);

    print(result);
}