#include "lexer/token.h"

Token::Token(const int type, const std::string &typeName, const std::string &text)
    : type_(type), typeName_(typeName), text_(text)
{

}

int Token::getType() const
{
    return type_;
}

std::string Token::getText() const
{
    return text_;
}

std::string Token::toString() const
{
    return "<'" + text_ + "', " + typeName_ + ">";
}
