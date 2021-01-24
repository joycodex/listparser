#include "../include/parser/list_parser.h"

namespace {

}

ListParser::ListParser(std::unique_ptr<ListLexer> lexer)
    : lexer_(std::move(lexer))
{
    consume();
}

void ListParser::parse()
{
    list();
}

void ListParser::list()
{
    match(ListLexer::TOKEN_LBRACK);
    elements();
    match(ListLexer::TOKEN_RBRACK);
}

void ListParser::elements()
{
    element();
    while (lookahead->getType() == ListLexer::TOKEN_COMMA) {
        match(ListLexer::TOKEN_COMMA);
        element();
    }
}

void ListParser::element()
{
    if (lookahead->getType() == ListLexer::TOKEN_NAME) {
        match(ListLexer::TOKEN_NAME);
    } else if (lookahead->getType() == ListLexer::TOKEN_LBRACK) {
        list();
    } else {
        throw std::string("expecting name or list; found " + lookahead->toString());
    }
}

void ListParser::match(int tokenType)
{
    if (lookahead->getType() != tokenType) {
        throw std::string("expecting " + ListLexer::tokeName(tokenType) + "; found " + ListLexer::tokeName(lookahead->getType()));
    }

    consume();
}

void ListParser::consume()
{
    if (!lookahead) {
        lookahead.reset(new Token(lexer_->nextToken()));
    } else {
        *lookahead = lexer_->nextToken();
    }
}
