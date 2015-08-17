#ifndef MUSTARD_XSTRING_H
#define MUSTARD_XSTRING_H 1

namespace mustard {

namespace xstring {

char * read(int & len);

char * read();

char * read_line();

void free(const char * str);

void print(const char * str);

char * clone(const char * str);

} // namespace ::mustard::xstring

} // namespace ::mustard

#endif
