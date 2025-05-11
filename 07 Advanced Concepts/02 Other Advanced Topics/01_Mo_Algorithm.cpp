#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Query structure
struct Query {
    int L, R, idx;
};

// Correct compare function using block decomposition
int block_size;
bool compare(Query a, Query b) {
    int block_a = a.L / block_size;
    int block_b = b.L / block_size;
    if (block_a != block_b)
        return block_a < block_b;
    return (block_a & 1) ? (a.R > b.R) : (a.R < b.R);  // Better cache performance
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<Query> queries(q);
    vector<int> ans(q);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--;  // Convert to 0-based
        queries[i].R--;
        queries[i].idx = i;
    }

    block_size = sqrt(n);  // Use n, not query data
    sort(queries.begin(), queries.end(), compare);

    // Mo's algorithm logic (example: range sum)
    int current_sum = 0;
    int l = 0, r = -1;

    for (Query& q : queries) {
        while (r < q.R) current_sum += arr[++r];
        while (r > q.R) current_sum -= arr[r--];
        while (l < q.L) current_sum -= arr[l++];
        while (l > q.L) current_sum += arr[--l];

        ans[q.idx] = current_sum;
    }

    for (int x : ans)
        cout << x << endl;

    return 0;
}
