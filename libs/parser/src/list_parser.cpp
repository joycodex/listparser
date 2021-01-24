#include "../include/parser/list_parser.h"

namespace {

}

ListParser::ListParser(std::unique_ptr<ListLexer> lexer)
    : lexer_(std::move(lexer))
{
    lookaheads_.resize(K);
    for (size_t i = 0; i < K; i++) {
        consume();
    }
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
    while (lookaheadToken(0)->getType() == ListLexer::TOKEN_COMMA) {
        match(ListLexer::TOKEN_COMMA);
        element();
    }
}

void ListParser::element()
{
    if (lookaheadToken(0)->getType() == ListLexer::TOKEN_NAME &&
            lookaheadToken(1)->getType() == ListLexer::TOKEN_EQUALS) {
        match(ListLexer::TOKEN_NAME);
        match(ListLexer::TOKEN_EQUALS);
        match(ListLexer::TOKEN_NAME);
    } else if (lookaheadToken(0)->getType() == ListLexer::TOKEN_NAME) {
        match(ListLexer::TOKEN_NAME);
    } else if (lookaheadToken(0)->getType() == ListLexer::TOKEN_LBRACK) {
        list();
    } else {
        throw std::string("expecting name or list; found " +
                          lookaheadToken(0)->toString());
    }
}

void ListParser::match(int tokenType)
{
    if (lookaheadToken(0)->getType() != tokenType) {
        throw std::string("expecting " + ListLexer::tokeName(tokenType) +
                          "; found " + ListLexer::tokeName(lookaheadToken(0)->getType()));
    }

    consume();
}

void ListParser::consume()
{
    if (!lookaheads_[p_]) {
        lookaheads_[p_].reset(new Token(lexer_->nextToken()));
    } else {
        *lookaheads_[p_] = lexer_->nextToken();
    }
    p_ = (p_ + 1) % K;
}

Token *ListParser::lookaheadToken(const int i) const
{
    return lookaheads_[(p_ + i) % K].get();
}
