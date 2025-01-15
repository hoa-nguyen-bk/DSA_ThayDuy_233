// This is a demo task.

// Write a function:

// int solution(vector<int> &A);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // Sort the array in ascending order
    sort(A.begin(), A.end());

    // Initialize the smallest positive integer to 1
    int smallest_positive = 1;

    // Iterate through the sorted array
    for (int num : A) {
        // If the current number is the smallest positive integer, increment it
        if (num == smallest_positive) {
            smallest_positive++;
        }
        // If the current number is greater than the smallest positive integer, return it
        if (num > smallest_positive) {
            return smallest_positive;
        }
    }

    return smallest_positive;
}
int main() {
    vector<int> A1 = {1, 3, 6, 4, 1, 2}; // 1 1 2 3 4 6 
    vector<int> A2 = {1, 2, 3};
    vector<int> A3 = {-1, -3};

    cout << solution(A1) << endl; // Expected output: 5
    cout << solution(A2) << endl; // Expected output: 4
    cout << solution(A3) << endl; // Expected output: 1

    return 0;
}