/**
 * @file quick_sort.h
 * @author Mahmoud Gadallah (mahmoudgadallah876@gmail.com)
 * @brief quick sort implementation
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief __partition function to get povit that will divide array into 2 paritions 
 * 
 * @tparam T type of elements
 * @param arr array of elements will be sorted
 * @param l left pointer
 * @param r right pointer
 * @return int povit that divide array into 2 elements 
 */
template <typename T>
int __partition(vector<T> &arr,int l, int r) {
    int pivot = l;

    while (l < r) {
        if (arr[l] > arr[r]) {      //if right > left so we need to swap them and also move povit
            swap(arr[l], arr[r]);
            pivot = (pivot == l) ? r : l;
        }

        (pivot == l) ? --r : ++l;       //we need to move pointer that povit doesn't point on it
    }
    return pivot;
}

/**
 * @brief 
 * 
 * @tparam T elements type
 * @param arr array of elements will be sorted
 * @param l left pointer
 * @param r right pointer
 */
template <typename T>
void __quickSortRec(vector<T> &arr, int l, int r) {
    if (l < r) {
        int pivot = __partition(arr, l, r);     //getting povit that will be divide array into 2 partitions

        if (pivot > 0)                                  //if we have left parition
                __quickSortRec(arr, l, pivot-1);        //sort left parition
        
        if (pivot < arr.size()-1)                   //if we have right parition
            __quickSortRec(arr, pivot+1, r);        //sort right parition
    }
}

/**
 * @brief sort elements based on quick sort algorithm
 * 
 * @tparam T elements type
 * @param arr array of elements will be sorted
 */
template <typename T>
void quickSort(vector<T> &arr) {
    if (arr.empty())            //if array is empty so we didn't need to sort it
        return;
    
    __quickSortRec(arr, 0, arr.size()-1);
}

#endif