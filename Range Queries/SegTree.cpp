class SegmentTree {
    //m_modify_type : {assign, add}
    //m_query_type : {sum,min,max}

    // vector<long long> a = {1, 2, 3, 4, 5};
    // SegmentTree seg1(a.size(), "add", "sum");
    // seg1.build(a);
    // std::cout<<seg1.get(1, 3);
    // seg1.modify(1, 3, 10);

public:
    SegmentTree(int size, const string &modify_type, const string &query_type)
        : m_n(size), m_modify_type(modify_type), m_query_type(query_type) {
        m_seg.resize(4 * m_n);
        if (m_query_type == "sum") m_default_value = 0;
        else if (m_query_type == "min") m_default_value = LLONG_MAX;
        else if (m_query_type == "max") m_default_value = LLONG_MIN;
    }

    void build(const vector<long long> &arr) {
        build(0, 0, m_n - 1, arr);
    }

    void modify(int l, int r, long long val) {
        modify(0, 0, m_n - 1, l, r, val);
    }

    long long get(int l, int r) {
        return get(0, 0, m_n - 1, l, r);
    }

private:
    void build(int node, int l, int r, const vector<long long> &arr) {
        if (l == r) {
            m_seg[node].value = arr[l];
        } else {
            int m = (l + r) / 2;
            build(2 * node + 1, l, m, arr);
            build(2 * node + 2, m + 1, r, arr);
            m_seg[node].value = combine(m_seg[2 * node + 1].value, m_seg[2 * node + 2].value);
        }
    }

    void push(int node, int l, int r) {
        if (m_seg[node].has_assign) {
            m_seg[node].value = apply_assign(m_seg[node].lazy_assign, r - l + 1);
            if (l != r) {
                apply_assign_lazy(2 * node + 1, m_seg[node].lazy_assign);
                apply_assign_lazy(2 * node + 2, m_seg[node].lazy_assign);
            }
            m_seg[node].lazy_assign = 0;
            m_seg[node].lazy_add = 0;
            m_seg[node].has_assign = false;
        } else if (m_seg[node].lazy_add != 0) {
            m_seg[node].value = apply_add(m_seg[node].value, m_seg[node].lazy_add, r - l + 1);
            if (l != r) {
                m_seg[2 * node + 1].lazy_add += m_seg[node].lazy_add;
                m_seg[2 * node + 2].lazy_add += m_seg[node].lazy_add;
            }
            m_seg[node].lazy_add = 0;
        }
    }

    void apply_assign_lazy(int node, long long val) {
        m_seg[node].lazy_assign = val;
        m_seg[node].has_assign = true;
        m_seg[node].lazy_add = 0;
    }

    long long apply_add(long long current, long long val, int len) {
        if (m_query_type == "sum") return current + val * len;
        else return current + val;
    }

    long long apply_assign(long long val, int len) {
        if (m_query_type == "sum") return val * len;
        else return val;
    }

    long long combine(long long a, long long b) {
        if (m_query_type == "sum") return a + b;
        else if (m_query_type == "min") return min(a, b);
        else return max(a, b);
    }

    void modify(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            if (m_modify_type == "assign") {
                apply_assign_lazy(node, val);
            } else if (m_modify_type == "add") {
                m_seg[node].lazy_add += val;
            }
            push(node, l, r);
            return;
        }

        int m = (l + r) / 2;
        modify(2 * node + 1, l, m, ql, qr, val);
        modify(2 * node + 2, m + 1, r, ql, qr, val);
        m_seg[node].value = combine(m_seg[2 * node + 1].value, m_seg[2 * node + 2].value);
    }

    long long get(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return m_default_value;
        if (ql <= l && r <= qr) return m_seg[node].value;
        int m = (l + r) / 2;
        long long left = get(2 * node + 1, l, m, ql, qr);
        long long right = get(2 * node + 2, m + 1, r, ql, qr);
        return combine(left, right);
    }

private:
    struct Node {
        long long value = 0;
        long long lazy_add = 0;
        long long lazy_assign = 0;
        bool has_assign = false;
    };

    int m_n;
    vector<Node> m_seg;
    string m_modify_type, m_query_type;
    long long m_default_value;
};
