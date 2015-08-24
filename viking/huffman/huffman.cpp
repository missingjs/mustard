// @mission: 给定若干字符(英文字母)和对应的频率，以及由这些字符组成的原文，对其进行Huffman编码，并实现对应的解码

#include <iostream>
#include <string>

char * huffman_encode(
        const char * ch, const double * freq, 
        int total, const char * content);

char * huffman_decode(
        const char * ch, const double * freq,
        int total, const char * code);

int main()
{
    int total = 0;
    std::cin >> total;
    if (total <= 0) {
        std::cerr << "invalid total: " << total << '\n';
        return 1;
    }

    char * ch = new char[total];
    double * freq = new double[total];
    for (int i = 0; i < total; ++i) {
        std::cin >> ch[i] >> freq[i];
    }

    std::string content;
    std::getline(std::cin, content);  // skip '\n'
    std::getline(std::cin, content);

    char * code = huffman_encode(ch, freq, total, content.c_str());

    if (code) {
        std::cout << "code: " << code << '\n';
    }

    char * decode_content = huffman_decode(ch, freq, total, code);
    if (decode_content) {
        std::cout << "content: " << decode_content << '\n';
    }

    delete[] ch;
    delete[] freq;
    delete[] code;
    delete[] decode_content;

    return 0;
}
