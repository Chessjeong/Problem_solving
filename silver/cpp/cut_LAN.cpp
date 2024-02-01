#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<long long> wires(K);
    for(int i = 0; i < K; ++i) {
        cin >> wires[i];
    }

    long long left = 1, right = *max_element(wires.begin(), wires.end());
    long long answer = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;

        for (int i = 0; i < K; ++i) {
            count += wires[i] / mid;
        }

        if (count >= N) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}
