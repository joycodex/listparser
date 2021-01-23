#ifndef LISTLEXER_H
#define LISTLEXER_H

#include <memory>
#include <string>

#include "char_stream.h"
#include "token.h"

class ListLexer
{
public:
    constexpr static int TOKEN_EOF = 1;
    constexpr static int TOKEN_NAME = 2;
    constexpr static int TOKEN_COMMA = 3;
    constexpr static int TOKEN_LBRACK = 4;
    constexpr static int TOKEN_RBRACK = 5;

    static std::string tokeName(const int token);

    ListLexer(std::unique_ptr<CharStream> stream);

    Token nextToken();

private:
    std::unique_ptr<CharStream> stream_;
};

#endif // LISTLEXER_H
