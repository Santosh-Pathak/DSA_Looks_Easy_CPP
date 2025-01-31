#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

// Function to build the segment tree
void buildSegmentTree(int node, int start, int end) {
    if (start == end) { // If it's a leaf node
        tree[node] = a[start];
        return;
    }

    int mid = start + (end - start) / 2;
    buildSegmentTree(2 * node + 1, start, mid);    // Left subtree
    buildSegmentTree(2 * node + 2, mid + 1, end);  // Right subtree

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Merge values from left and right subtrees
}

// Function to query the segment tree for range sum
int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left)  // No overlap
        return 0;

    if (left <= start && end <= right) // Complete overlap
        return tree[node];

    // Partial overlap
    int mid = (start + end) / 2;
    int leftSum = query(2 * node + 1, start, mid, left, right);
    int rightSum = query(2 * node + 2, mid + 1, end, left, right);
    return leftSum + rightSum;
}

// Function to update a value in the segment tree
void updateSegmentTree(int node, int start, int end, int targetIndex, int targetValue) {
    if (start == end) { // Leaf node
        tree[node] = targetValue;
        return;
    }

    int mid = (start + end) / 2;
    if (targetIndex <= mid)
        updateSegmentTree(2 * node + 1, start, mid, targetIndex, targetValue);
    else
        updateSegmentTree(2 * node + 2, mid + 1, end, targetIndex, targetValue);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Merge updates
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
    buildSegmentTree(0, 0, n - 1);

    // Print the segment tree
    cout << "Segment Tree: ";
    for (int i = 0; i < 4 * n; ++i) { // Corrected index from 1 to 0
        cout << tree[i] << " ";
    }
    cout << endl;

    // Query for range sum
    int left, right;
    cout << "Enter the left index of the range: ";
    cin >> left;
    cout << "Enter the right index of the range: ";
    cin >> right;
    cout << "Sum of elements in the range [" << left << ", " << right << "]: " 
         << query(0, 0, n - 1, left, right) << endl;

    // Update Tree
    int targetIndex, targetValue;
    cout << "Enter the target index for update: ";
    cin >> targetIndex;
    cout << "Enter the new value: ";
    cin >> targetValue;

    updateSegmentTree(0, 0, n - 1, targetIndex, targetValue);

    // Print the updated segment tree
    cout << "Updated Segment Tree: ";
    for (int i = 0; i < 4 * n; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;

    return 0;
}
