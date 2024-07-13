#include <iostream>
#include <vector>
#include <algorithm>

int maxDifference(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        return 0;
    }
    
    int minElement = arr[0];
    int maxDiff = arr[1] - arr[0];
    
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return maxDiff;
}

int main() {
    std::vector<int> arr = {1, 2, 6, 80, 100};
    int maxDiff = maxDifference(arr);
    std::cout << "Maximum difference: " << maxDiff << std::endl;
    
    return 0;
}
