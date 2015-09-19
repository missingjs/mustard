struct _ts
{
    int v;    // value
    int i;    // leaf index
    _ts(int v = 0, int i = 0)
        : v(v), i(i)
    {}
};

_ts * build_complete_tree(int * arr, int n, int & len);

void tree_select_output(_ts * t, int len, int * arr, int n);
