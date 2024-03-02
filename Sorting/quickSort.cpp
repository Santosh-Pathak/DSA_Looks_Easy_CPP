#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int s, int e) {
     int pivot = arr[e]; // Choose last element as pivot
    int i = s - 1; // Index of smaller element

    for (int j = s; j <= e - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

// Recursive function for quick sort
void quickSort(int s, int e, int arr[]) {
    if (s >= e) {
        return;
    }
    int p = partition(arr, s, e); // Partition the array
    // Recursively sort left and right parts
    quickSort(s, p - 1, arr);
    quickSort(p + 1, e, arr);
}

int main() {
    int arr[] = {28, 153, 174, 499, 281, 117, 471, 367, 281, 460, 501, 574,
                 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269, 76, 357,
                 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577, 460,
                 417, 854, 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471,
                 367, 281, 460, 501, 574, 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752,
                 629, 269, 76, 357, 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577,
                 460, 417, 854, 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471,
                 367, 281, 460, 501, 574, 277, 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269,
                 76, 357, 502, 413, 102, 566, 794, 255, 92, 293, 888, 209, 765, 607, 491, 577, 460, 417, 854,
                 616, 343, 6, 311, 845, 804, 34, 28, 153, 174, 499, 281, 117, 471, 367, 281, 460, 501, 574, 277,
                 156, 926, 800, 694, 502, 445, 723, 700, 519, 752, 629, 269, 76, 357, 502, 413, 102, 566, 794, 255,
                 92, 293, 888, 209, 765, 607, 491, 577, 460, 417, 854, 616, 343, 6, 311, 845, 804, 34};
    int n = sizeof(arr) / sizeof(int);
    quickSort(0, n - 1, arr); // Call quick sort
    cout << "Sorted Array is:";
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i]; // Print sorted array
    }
    return 0;
}
