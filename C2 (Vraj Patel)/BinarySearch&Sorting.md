# Binary Search
## binary search algorithm
#### binary search algorithm is used searching a element in a sorted array, The  algorithm Steps is given below 

### steps:
#### 1. Divide the search space into two halves by finding the middle index "mid". 
#### 2.Compare the middle element of the search space with the key. 
#### 3.If the key is found at middle element, the process is terminated.
#### 4.If the key is not found at middle element, choose which half will be used as the next search space.
#### 5.If the key is larger than the middle element, then the right side is used for next search.
#### 6.If the key is smaller than the middle element, then the left side is used for next search.
#### 7.This process is continued until the key is found or the total search space is exhausted.

### code:
```cpp
#include<iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end){
    while (start <= end)
    {
        // finding mid element 
        int mid = start + (end - start) / 2;

        // finding key element at mid part
        if(arr[mid] == key){
            return mid;
        }

        // if key element is greater than mid element then move into right part because array is sorted
        if(key > arr[mid]){
            start = mid + 1;
        }

        // if key element is smaller than mid element then move searching into left part because array is sorted
        else{
            end = mid - 1;
        }
    }

    // if key element is not present in the array 
    return -1;
}

int main()
{
    int arr[] = {10,24,48,65,76,90};
    int key = 45;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binarySearch(arr, key, 0, n-1);
    if (result == -1)
    {
        cout << "Element is not present in the array" << endl;
    }
    else{
        cout << "Element is present in the array" << endl;
    }
    
    return 0;
}
```

## Questions Based on Binary Search

### 1. First and Last occurence position of an element in sorted array

### First Occurrence steps:
#### 1. Divide the search space into two halves by finding the middle index "mid". 
#### 2.Compare the middle element of the search space with the key. 
#### 3.If the key is found at middle element, then store middle as answer and last index set at before middle.
#### 4.If the key is not found at middle element, choose which half will be used as the next search space.
#### 5.If the key is larger than the middle element, then the right side is used for next search.
#### 6.If the key is smaller than the middle element, then the left side is used for next search.
#### 7.This process is continued until the key is found or the total search space is exhausted.

### Last Occurrence steps:
#### 1. Divide the search space into two halves by finding the middle index "mid". 
#### 2.Compare the middle element of the search space with the key. 
#### 3.If the key is found at middle element, then store middle as answer and first index set at after middle.
#### 4.If the key is not found at middle element, choose which half will be used as the next search space.
#### 5.If the key is larger than the middle element, then the right side is used for next search.
#### 6.If the key is smaller than the middle element, then the left side is used for next search.
#### 7.This process is continued until the key is found or the total search space is exhausted.

T.C = O(n)
S.C = O(1)
### Code:
```cpp
#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        
        // if mid element is same as key then store mid as answer
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }

        // if key element is greater than mid element then move into right part because array is sorted
        else if(key > arr[mid]){
            s = mid + 1;
        }

        // if key element is smaller than mid element then move searching into left part because array is sorted
        else if(key < arr[mid]){
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        
        // if mid element is same as key then store mid as answer
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }

        // if key element is greater than mid element then move into right part because array is sorted
        else if(key > arr[mid]){
            s = mid + 1;
        }

        // if key element is smaller than mid element then move searching into left part because array is sorted
        else if(key < arr[mid]){
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}
 
int main()
{
    int arr[7] = {1,2,3,4,4,4,5};
    cout << "First Occurence of the 4 is " << firstOcc(arr,7,4) << endl;
    cout << "Last Occurence of the 4 is " << lastOcc(arr,7,4) << endl;

    return 0;
}
```

## 2. Peak element index in mountain array
T.C = O(n)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int peakElement(int arr[], int n) {
  
    // If there is only one element, then it's a peak
    if (n == 1) 
        return 0;
        
    // Check if the first element is a peak
    if (arr[0] > arr[1])
        return 0;
        
    // Check if the last element is a peak
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    
    // Search Space for binary Search
    int s = 1, e = n - 2;
    int mid = s + (e - s)/2;
    
    while(s < e) {
        // If next neighbor is greater, then peak
        // element will exist in the right subarray
        if(arr[mid] < arr[mid + 1])
            s = mid + 1;
            
        // Otherwise, it will exist in left subarray
        else
            e = mid;
        mid = s + (e - s)/2;
    }
    return s;
}

int main() {
    int arr[7] = {1, 2, 4, 5, 7, 8, 3};
    cout << peakElement(arr, 7);
    return 0;
}
```
# Sorting
## 1. selection sort
T. C. = O(n^2)
S. C. = O(1)
### Code:
```cpp
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);        
    }   
}

int main()
{
    int arr[7] = {10,5,15,2,1,8,12};
    selectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

## bubble Sort
T. C. = O(n^2)
S. C. = O(1)
### Code:
```cpp
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[7] = {10,5,15,2,1,8,12};
    bubbleSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
```


### Color Sort
T.C = O(n)
S.C = O(1)
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array of 0s, 1s and 2s
void colorSort(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high) {
        if (arr[mid] == 0)
            swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }
}

int main() {
    int arr[6] = { 0, 1, 2, 0, 1, 2 };

    colorSort(arr,6);

    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";

    return 0;
}
```