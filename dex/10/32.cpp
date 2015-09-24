// @mission: 一个仅由红白蓝三色条块组成的序列，在O(n)时间内按红、白、蓝顺序排好，实现中以ABC代替三种颜色
#include "32.def.h"
#include "common/xstring.h"
#include <cstring>
using namespace mustard;

int main()
{
    char * str = xstring::read_line();
    int len = (int) strlen(str);

    netherland_flag(str, len);

    xstring::print(str);

    delete[] str;
    return 0;
}
