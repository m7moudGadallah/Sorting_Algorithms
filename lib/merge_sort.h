/**
 * @file merge_sort.h
 * @author Mahmoud Gadallah (mahmoudgadallah876@gmail.com)
 * @brief merge sort algorithm implementation
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief merge function to merge 2 partiions of array and sort them
 * 
 * @tparam T type of elements
 * @param arr array of elements
 * @param l index of left pointer
 * @param m index of mid pointer
 * @param r index of right pointer
 */
template <typename T>
void __merge(vector<T> &arr, int l, int m, int r) {
        int n1 = m-l + 1;       //size of left parition
    int n2 = r-m;           //size fo right parition

    vector<T> arr1(n1);     //left parition;
    vector<T> arr2(n2);     //right

    int idx = 0;

    for (int i = l; i <= m; ++i) {
        arr1[idx++] = arr[i];
    }

    idx = 0;        
    for (int i = m+1; i <= r; ++i) {
        arr2[idx++] = arr[i];
    }

    idx = l;        //reset idx to l and now we use it to iterate over arr
    int idx1 = 0, idx2 = 0;     //idx1 to iterate over arr1,   idx2 to iterate over arr2
    
    while (idx1 < n1 and idx2 < n2) {
        if (arr1[idx1] < arr2[idx2])
            arr[idx++] = arr1[idx1++];
        else
            arr[idx++] = arr2[idx2++];
    }

    while (idx1 < n1)
        arr[idx++] = arr1[idx1++];
    
    while (idx2 < n2)
        arr[idx++] = arr2[idx2++];
}

/**
 * @brief mergeSortRec is the function used to sort
 * actually used to divide and call merge function to merge
 * 
 * @tparam T 
 * @param arr  array of elements
 * @param l index of left pointer
 * @param r index of right pointer
 */
template <typename T>
void __mergeSortRec(vector<T> &arr, int l, int r) {
    if (l < r) {
        int m = l + ((r-l)>>1);     //getting mid pointer

        __mergeSortRec(arr, l, m);        //sort left partition
        __mergeSortRec(arr, m+1, r);         //sort right partition
        __merge(arr, l, m, r);            //merge left & right parition
    }
}

/**
 * @brief mergeSort is the function used to sort array based on Merge Sort Algorithm
 * 
 * @tparam T type of elements
 * @param arr array of elements
 */
template <typename T>
void mergeSort(vector<T> &arr) {
    if (arr.empty())        //if array is already empty we didn't need to sort it
        return;
    
    __mergeSortRec(arr, 0, arr.size()-1);
}

#endif  