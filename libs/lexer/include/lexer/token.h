#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
public:
    Token(const int type, const std::string &typeName, const std::string &text);

    int getType() const;
    std::string getText() const;

    std::string toString() const;

private:
    int type_;
    std::string typeName_;
    std::string text_;
};

#endif // TOKEN_H
