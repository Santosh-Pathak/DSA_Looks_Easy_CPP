#include <bits/stdc++.h>
using namespace std;

// Maximum array size constant (with a bit of extra space)
const int N = 1e5 + 2;

// Global arrays for the input array and the segment tree
int a[N];           // Input array
int tree[4 * N];    // Segment tree array (4 * n is a safe upper bound)

// Lazy propagation array to store pending updates for range addition
vector<int> lazyTree;

/*
    Function: buildSegmentTree
    ----------------------------
    Recursively builds the segment tree.

    Parameters:
      node  - current index in the segment tree array
      start - starting index of the segment in the original array
      end   - ending index of the segment in the original array

    For a leaf node, we simply copy the value from the input array.
    For an internal node, we build the left and right subtrees and
    set the current node's value as the sum of its children.
*/
void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        // Leaf node: store the corresponding array element.
        tree[node] = a[start];
        return;
    }

    int mid = start + (end - start) / 2;
    // Recursively build the left child (indices: start to mid)
    buildSegmentTree(2 * node + 1, start, mid);
    // Recursively build the right child (indices: mid+1 to end)
    buildSegmentTree(2 * node + 2, mid + 1, end);

    // Internal node stores the sum of the values from its two children.
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

/*
    Function: updateLazy
    ----------------------
    Performs a range update (adds 'value' to every element) using lazy propagation.

    Parameters:
      updateStart - start index of the update range (inclusive)
      updateEnd   - end index of the update range (inclusive)
      node        - current index in the segment tree array
      l           - start index of the segment represented by this node
      r           - end index of the segment represented by this node
      value       - value to add to each element in the update range

    The function first resolves any pending lazy updates for the current node.
    Then, depending on whether the current segment is outside, fully inside,
    or partially overlapping the update range, it updates the node or recurses further.
*/
void updateLazy(int updateStart, int updateEnd, int node, int l, int r, int value) {
    // If there's a pending update at this node, apply it first.
    if (lazyTree[node] != 0) {
        // Update the current node using the pending lazy value.
        tree[node] += lazyTree[node] * (r - l + 1);

        // If not a leaf node, propagate the lazy update to its children.
        if (l != r) {
            lazyTree[2 * node + 1] += lazyTree[node];
            lazyTree[2 * node + 2] += lazyTree[node];
        }
        // Clear the lazy value for the current node.
        lazyTree[node] = 0;
    }

    // No overlap: current segment [l, r] is completely outside the update range.
    if (r < updateStart || l > updateEnd)
        return;

    // Total overlap: current segment [l, r] is completely inside the update range.
    if (l >= updateStart && r <= updateEnd) {
        // Update the current node directly.
        tree[node] += value * (r - l + 1);
        // If not a leaf node, mark the children for lazy update.
        if (l != r) {
            lazyTree[2 * node + 1] += value;
            lazyTree[2 * node + 2] += value;
        }
        return;
    }

    // Partial overlap: update both children.
    int mid = l + (r - l) / 2;
    updateLazy(updateStart, updateEnd, 2 * node + 1, l, mid, value);
    updateLazy(updateStart, updateEnd, 2 * node + 2, mid + 1, r, value);

    // Update current node based on the updated values of its children.
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

/*
    Function: queryLazy
    ---------------------
    Answers a range sum query on the segment tree using lazy propagation.

    Parameters:
      queryStart - start index of the query range (inclusive)
      queryEnd   - end index of the query range (inclusive)
      node       - current index in the segment tree array
      l          - start index of the segment represented by this node
      r          - end index of the segment represented by this node

    Returns:
      The sum of the array elements in the query range.
*/
int queryLazy(int queryStart, int queryEnd, int node, int l, int r) {
    // First, resolve any pending lazy updates for the current node.
    if (lazyTree[node] != 0) {
        tree[node] += lazyTree[node] * (r - l + 1);
        if (l != r) {
            lazyTree[2 * node + 1] += lazyTree[node];
            lazyTree[2 * node + 2] += lazyTree[node];
        }
        lazyTree[node] = 0;
    }

    // No overlap: return 0 since this segment does not contribute.
    if (r < queryStart || l > queryEnd)
        return 0;

    // Total overlap: current segment is completely within query range.
    if (l >= queryStart && r <= queryEnd)
        return tree[node];

    // Partial overlap: query both children.
    int mid = l + (r - l) / 2;
    int sumLeft = queryLazy(queryStart, queryEnd, 2 * node + 1, l, mid);
    int sumRight = queryLazy(queryStart, queryEnd, 2 * node + 2, mid + 1, r);
    return sumLeft + sumRight;
}

/*
    Function: main
    ---------------
    Demonstrates the usage of the segment tree with lazy propagation.
      - Reads the number of elements and the array.
      - Builds the segment tree.
      - Performs a sample range update.
      - Answers some range sum queries.
*/
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Resize and initialize the lazy propagation array.
    // We use 4*n nodes (which is a safe bound) and initialize with 0.
    lazyTree.assign(4 * n, 0);
    
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Build the segment tree for the array indices [0, n-1]
    buildSegmentTree(0, 0, n - 1);
    
    // For debugging: Print the segment tree array.
    cout << "\nInitial Segment Tree array: ";
    for (int i = 0; i < 4 * n; ++i) {
        cout << tree[i] << " ";
    }
    cout << "\n";
    
    // -------- Demonstration of a Range Update --------
    // Example: Add '5' to every element in the index range [1, 3].
    int updateStart = 1, updateEnd = 3, value = 5;
    updateLazy(updateStart, updateEnd, 0, 0, n - 1, value);
    cout << "\nAfter updating range [" << updateStart << ", " << updateEnd << "] by adding " << value << ":\n";
    
    // -------- Demonstration of Range Queries --------
    // Query 1: Sum of the entire array after the update.
    int totalSum = queryLazy(0, n - 1, 0, 0, n - 1);
    cout << "Total sum of the array after update: " << totalSum << "\n";
    
    // Query 2: Sum of a sub-range, e.g., indices [2, 4].
    int qs = 2, qe = 4;
    int rangeSum = queryLazy(qs, qe, 0, 0, n - 1);
    cout << "Sum of range [" << qs << ", " << qe << "] after update: " << rangeSum << "\n";
    
    return 0;
}
