#include <iostream>
#include <string>
#include <stack>
#include <limits>
#include <cstring>

struct hf_cell
{
    double w;
    int lc, rc;
    hf_cell()
        : w(0.0), lc(-1), rc(-1)
    {}
};

void gen_code(const char * ch, int total, hf_cell * huff, char ** code)
{
    char * buff = new char[total];

    int K = total * 2 - 1, p = K - 1;
    int b = 0;
    std::stack<int> stk;
    stk.push(p);

    int * status = new int[K];
    memset(status, 0, sizeof(int) * K);
    while (!stk.empty()) {
        int t = stk.top();
        switch (status[t]) {
            case 0:
                if (huff[t].lc < 0) {   // t is leaf node
                    buff[b] = 0;
                    char * cd = new char[b+1];
                    strcpy(cd, buff);
                    code[ch[t]] = cd;
                    std::cout << ch[t] << ": " << buff << '\n';
                    status[t] = 2;
                } else {
                    status[t] = 1;
                    buff[b++] = '0';
                    stk.push(huff[t].lc);
                }
                break;
            case 1:
                status[t] = 2;
                buff[b++] = '1';
                stk.push(huff[t].rc);
                break;
            case 2:
                stk.pop();
                --b;
                break;
        }
    }

    delete[] buff;
}

void find_min(hf_cell * huff, int i, int & j1, int & j2)
{
    double m1, m2;
    m2 = m1 = std::numeric_limits<double>::max();
    for (int k = 0; k < i; ++k) {
        if (huff[k].w < 0) {
            continue;
        }
        if (huff[k].w < m1) {
            m2 = m1;
            j2 = j1;
            m1 = huff[k].w;
            j1 = k;
        } else if (huff[k].w < m2) {
            m2 = huff[k].w;
            j2 = k;
        }
    }
}

std::string _encode(char ** code, const char * content)
{
    std::string enc;
    const char * p = content;
    for (; *p; ++p) {
        char * cd = code[*p];
        if (cd) {
            enc += cd;
        }
    }
    return enc;
}

void free_code(char ** code, int num)
{
    for (int i = 0; i < num; ++i) {
        delete[] code[i];
    }
    delete[] code;
}

char * huffman_encode(
        const char * ch, const double * freq, 
        int total, const char * content)
{
    if (!ch || !freq || !content || total <= 0) {
        return NULL;
    }

    int K = 2 * total - 1;  // total nodes
    hf_cell * huff = new hf_cell[K];
    for (int i = 0; i < total; ++i) {
        huff[i].w = freq[i];
    }

    for (int i = total; i < K; ++i) {
        int j1 = 0, j2 = 0;
        find_min(huff, i, j1, j2);
        huff[i].lc = j1;
        huff[i].rc = j2;
        huff[i].w = huff[j1].w + huff[j2].w;
        huff[j1].w = -huff[j1].w;
        huff[j2].w = -huff[j2].w;
    }

    const int num_ascii = 128;
    char ** code = new char*[num_ascii];
    memset(code, 0, sizeof(char*) * num_ascii);
    gen_code(ch, total, huff, code);

    std::string encode_content = _encode(code, content);

    char * enc = new char[encode_content.size() + 1];
    strcpy(enc, encode_content.c_str());

    free_code(code, num_ascii);
    delete[] huff;

    return enc;
}

struct _hf_node
{
    double w;
    char ch;
    _hf_node *lc, *rc;
    _hf_node(double w = 0.0, char ch = 0)
        : w(w), ch(ch), lc(NULL), rc(NULL)
    {}
};

std::string _decode(_hf_node * root, const char * code)
{
    const char * p = code;
    _hf_node * n = root;
    std::string content;
    while (*p) {
        if (*p == '0') {
            n = n->lc;
        } else {
            n = n->rc;
        }
        if (!n->lc && !n->rc) {
            content.push_back(n->ch);
            n = root;
        }
        ++p;
    }
    return content;
}

void find_min(_hf_node ** nodes, int k, int & m1, int & m2)
{
    double n2, n1;
    n2 = n1 = std::numeric_limits<double>::max();
    for (int i = 0; i < k; ++i) {
        if (nodes[i]->w < n1) {
            n2 = n1;
            m2 = m1;
            n1 = nodes[i]->w;
            m1 = i;
        } else if (nodes[i]->w < n2) {
            n2 = nodes[i]->w;
            m2 = i;
        }
    }
}

char * huffman_decode(
        const char * ch, const double * freq,
        int total, const char * code)
{
    _hf_node ** nodes = new _hf_node*[total];
    for (int i = 0; i < total; ++i) {
        nodes[i] = new _hf_node(freq[i], ch[i]);
    }

    for (int k = total; k > 1; --k) {
        int m1 = 0, m2 = 0;
        find_min(nodes, k, m1, m2);
        double w = nodes[m1]->w + nodes[m2]->w;
        _hf_node * n = new _hf_node(w);
        n->lc = nodes[m1];
        n->rc = nodes[m2];
        nodes[m1] = n;
        nodes[m2] = nodes[k-1];
    }

    _hf_node * root = nodes[0];

    std::string content = _decode(root, code);

    char * p_content = new char[content.size() + 1];
    strcpy(p_content, content.c_str());

    return p_content;
}

