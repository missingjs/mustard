#include <cstring>
#include <cstddef>

void _to(const char * bi, const char * ei, char * bo, char * eo)
{
    if (bi == ei) {
        return;
    }

    *(eo - 1) = *bi;  // root node

    int sub_tree_size = (ei - bi - 1)/2;

    const char * left_bi = bi + 1;
    const char * left_ei = left_bi + sub_tree_size;
    char * left_bo = bo;
    char * left_eo = left_bo + sub_tree_size;
    _to(left_bi, left_ei, left_bo, left_eo);

    const char * right_bi = left_ei;
    const char * right_ei = ei;
    char * right_bo = left_eo;
    char * right_eo = right_bo + sub_tree_size;
    _to(right_bi, right_ei, right_bo, right_eo);
}

char * pre_to_post(const char * pre)
{
    if (!pre) {
        return NULL;
    }
    int len = (int) strlen(pre);
    char * post = new char[len + 1];
    post[len] = 0;

    _to(pre, pre + len, post, post + len);

    return post;
}
