#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int lo, int mid, int hi) {
    std::vector<int> aux(arr.size());
    
    // Copy to aux[]
    for (int k = lo; k <= hi; k++) {
        aux[k] = arr[k];
    }
    
    // Merge back to arr[]
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid)                arr[k] = aux[j++];
        else if (j > hi)            arr[k] = aux[i++];
        else if (aux[j] < aux[i])   arr[k] = aux[j++];
        else                        arr[k] = aux[i++];
    }
}

void mergeSort(std::vector<int>& arr, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    std::vector<int> arr = {37, 38, 39, 31, 32, 33};
    int n = arr.size();
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
