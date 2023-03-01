/**
 * @file merge_sort_test.cpp
 * @author Mahmoud Gadallah (mahmoudgadallah876@gmail.com)
 * @brief test of merge sort
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#include "../lib/merge_sort.h"

using namespace std;

template <typename T>
bool comp(vector<T> &out, vector<T> &exp) {
    int n = out.size();
    
    for (int i = 0; i < n; ++i)
        if (out[i] != exp[i])
            return false;
    
    return true;
}

template <typename T>
void print(vector<T> &arr) {
    for (auto &x : arr)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    freopen("test_cases.txt", "r", stdin);
    int n;

    while (cin >> n) {
        vector<int> arr(n), exp(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i], exp[i] = arr[i];
        
        mergeSort(arr);
        sort(exp.begin(), exp.end());

        if (comp(arr, exp))
            cout << "Passed!\n";
        else {
            cout << "Failed\n";
            print(exp);
            assert(false);
        }
    }

    return 0;
}