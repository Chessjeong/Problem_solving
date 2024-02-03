#include <iostream>
#include <vector>
using namespace std;

class Tree {

public:
    vector<int> parent, depth;
    Tree(int n) : parent(n + 1), depth(n + 1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot != yRoot) {
            if (depth[xRoot] < depth[yRoot]) {
                parent[xRoot] = yRoot;
            } else if (depth[xRoot] > depth[yRoot]) {
                parent[yRoot] = xRoot;
            } else {
                parent[yRoot] = xRoot;
                depth[xRoot]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    Tree t(n);

    for (int i = 0; i < m; ++i) {
        int operation, a, b;
        cin >> operation >> a >> b;

        if (operation == 0) {
            t.unite(a, b);
        } else if (operation == 1) {
            if (t.same(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
