class Solution {
public:
     void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int p = split(A, 0, n - 1, 0);
        split(A, p + 1, n - 1, 1);
    }
    int split(int A[], int low, int high, int pivot) {
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            if (A[j] <= pivot) {
                i += 1;
                if (i != j) swap(A[i], A[j]);
            }
        }
        return i;
    }
};