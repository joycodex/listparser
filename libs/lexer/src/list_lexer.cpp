#include "lexer/list_lexer.h"

#include <vector>

namespace {

std::vector<std::string> tokenNames {
    "n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"
};

bool isWhiteSpace(const char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

bool isLetter(const char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <=ch && ch <= 'Z');
}

void WS(CharStream *stream) {
    while (isWhiteSpace(stream->peak())) {
        stream->consume();
    }
}

Token NAME(CharStream *stream) {
    std::vector<char> buf;

    while (isLetter(stream->peak())) {
        buf.push_back(stream->peak());
        stream->consume();
    }

    return Token(ListLexer::TOKEN_NAME, ListLexer::tokeName(ListLexer::TOKEN_NAME), std::string(buf.begin(), buf.end()));
}

}

std::string ListLexer::tokeName(const int token)
{
    if (token < 0 || static_cast<size_t>(token) > tokenNames.size() - 1) {
        return tokenNames[0];
    } else {
        return tokenNames[token];
    }
}

ListLexer::ListLexer(std::unique_ptr<CharStream> stream)
    : stream_(std::move(stream))
{

}

Token ListLexer::nextToken()
{
    while (stream_->peak() != CharStream::CHAR_EOF) {
        if (isWhiteSpace(stream_->peak())) {
            WS(stream_.get());
        } else if (stream_->peak() == ',') {
            stream_->consume();
            return Token(TOKEN_COMMA, tokeName(TOKEN_COMMA), ",");
        } else if (stream_->peak() == '[') {
            stream_->consume();
            return Token(TOKEN_LBRACK, tokeName(TOKEN_LBRACK), "[");
        } else if (stream_->peak() == ']') {
            stream_->consume();
            return Token(TOKEN_RBRACK, tokeName(TOKEN_RBRACK), "]");
        } else if (isLetter(stream_->peak())) {
            return NAME(stream_.get());
        } else {
            throw std::string("invalid character: ") + stream_->peak();
        }
    }

    return Token(TOKEN_EOF, tokeName(TOKEN_EOF), "<EOF>");
}
