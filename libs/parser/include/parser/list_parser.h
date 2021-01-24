#ifndef LISTPARSER_H
#define LISTPARSER_H

#include <memory>
#include <vector>

#include "lexer/list_lexer.h"

class ListParser
{
public:
    constexpr static int K = 2;

    ListParser(std::unique_ptr<ListLexer> lexer);

    void parse();

private:
    void list();
    void elements();
    void element();

    void match(int tokenType);
    void consume();

    Token *lookaheadToken(const int i) const;

private:
    std::unique_ptr<ListLexer> lexer_;

    std::vector<std::unique_ptr<Token>> lookaheads_;
    int p_ { 0 };
};

#endif // LISTPARSER_H
