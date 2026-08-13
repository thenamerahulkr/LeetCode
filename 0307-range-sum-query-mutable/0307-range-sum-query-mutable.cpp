class NumArray {
public:
    vector<int> seg;
    int n;

    void build(int idx, int low, int high, vector<int>& nums) {

        // leaf node
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {

        // no overlap
        if (high < l || low > r)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        // partial overlap
        int mid = low + (high - low) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);

        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    void pointUpdate(int idx, int low, int high, int target, int val) {

        // target mil gaya
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (target <= mid) {

            pointUpdate(2 * idx + 1, low, mid, target, val);

        } else {

            pointUpdate(2 * idx + 2, mid + 1, high, target, val);
        }

        // child update hone ke baad parent ko update karo
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    NumArray(vector<int>& nums) {

        n = nums.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) { pointUpdate(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {

        return query(0, 0, n - 1, left, right);
    }
};