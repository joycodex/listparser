#ifndef LISTPARSER_H
#define LISTPARSER_H

#include <memory>

#include "lexer/list_lexer.h"

class ListParser
{
public:
    ListParser(std::unique_ptr<ListLexer> lexer);

    void parse();

private:
    void list();
    void elements();
    void element();

    void match(int tokenType);
    void consume();

private:
    std::unique_ptr<ListLexer> lexer_;
    std::unique_ptr<Token> lookahead;
};

#endif // LISTPARSER_H
