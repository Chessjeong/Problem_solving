#include <iostream>
#include <algorithm>

using namespace std;
int ans[5001];

int deliver(int target) {
    if (target < 3) return -1;
    if (target == 3 || target == 5) return 1;
    if (target == 4) return -1;

    fill(ans, ans + target + 1, -1); // Fill the array up to the target
    ans[3] = 1;
    ans[5] = 1;

    for (int i = 6; i <= target; ++i) {
        if (i >= 3 && ans[i-3] != -1) ans[i] = ans[i-3] + 1;
        if (i >= 5 && ans[i-5] != -1) {
            if (ans[i] == -1 || ans[i-5] + 1 < ans[i]) {
                ans[i] = ans[i-5] + 1;
            }
        }
    }

    return ans[target];
}

int main(){
    int target;
    cin >> target;
    int res = deliver(target);
    cout << res<< endl;
}