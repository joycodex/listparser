#ifndef CHARSTREAM_H
#define CHARSTREAM_H

#include <string>

class CharStream
{
public:
    constexpr static char CHAR_EOF = -1;

    CharStream(const std::string &input);

    char peak();
    void consume();

private:
    std::string input_;
    size_t p_ { 0 };
    char ch_ { CHAR_EOF };
};

#endif // CHARSTREAM_H
