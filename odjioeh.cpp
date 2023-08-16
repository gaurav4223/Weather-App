#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long> solve(vector<vector<long>>& A) {
    int max_value = 0;
    for (const vector<long>& segment : A) {
        max_value = max(max_value, static_cast<int>(segment[1]));
    }

    vector<int> pointCount(max_value + 1, 0);
    for (const vector<long>& segment : A) {
        long start = segment[0];
        long end = segment[1];
        for (long num = start; num <= end; num++) {
            pointCount[static_cast<int>(num)]++;
        }
    }

    unordered_map<int, int> countMap;
    for (int count : pointCount) {
        countMap[count]++;
    }

    vector<long> result;
    result.push_back(0L); // B[0] must be equal to 0
    for (int i = 1; i <= A.size(); i++) {
        result.push_back(static_cast<long>(countMap[i]));
    }

    return result;
}

int main() {
    vector<vector<long>> A1 = {{0,1}, {0,0},{1,1}};
    vector<long> result1 = solve(A1);
    for (long num : result1) {
        cout << num << " ";
    }
    // Output: 0 1 2

    // vector<vector<long>> A2 = {{0, 1}, {0, 0}, {1, 1}};
    // vector<long> result2 = solve(A2);
    // for (long num : result2) {
    //     cout << num << " ";
    // }
    // Output: 0 0 2 0

    return 0;
}