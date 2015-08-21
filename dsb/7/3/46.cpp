// @mission: 设b是一棵采用二叉链存储的满二叉树，设计一个算法将其先序遍历序列转换为后序遍历序列

char * pre_to_post(const char * pre);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * pre = xstring::read_line();
    char * post = pre_to_post(pre);
    xstring::print(post);
    delete[] pre;
    delete[] post;
    return 0;
}
