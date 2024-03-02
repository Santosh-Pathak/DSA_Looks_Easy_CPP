#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

// Function to build the segment tree
void buildSegmentTree(int node, int start, int end) {
    if (start == end) {  // If it's a leaf node
        tree[node] = a[start];
        return;
    }

    int mid = start + (end - start) / 2;
    buildSegmentTree(2 * node, start, mid);       // Build left subtree
    buildSegmentTree(2 * node + 1, mid + 1, end);  // Build right subtree

    tree[node] = tree[2 * node] + tree[2 * node + 1];  // Merge values from left and right subtrees
}

// Function to query the segment tree for range sum
int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left) // If the current segment is completely outside the range [left, right]
        return 0;

    if (left <= start && end <= right) // If the current segment is completely inside the range [left, right]
        return tree[node];

    // Otherwise, the current segment overlaps with the given range, so we recurse for both children
    int mid = (start + end) / 2;
    int leftSum = query(2 * node, start, mid, left, right);
    int rightSum = query(2 * node + 1, mid + 1, end, left, right);
    return leftSum + rightSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Build the segment tree
    buildSegmentTree(1, 0, n - 1);

    // Print the segment tree
    cout << "Segment Tree: ";
    for (int i = 1; i <= 4 * n; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;

    // Query for range sum
    int left, right;
    cout << "Enter the left index of the range: ";
    cin >> left;
    cout << "Enter the right index of the range: ";
    cin >> right;
    cout << "Sum of elements in the range [" << left << ", " << right << "]: " << query(1, 0, n - 1, left, right) << endl;

    return 0;
}
