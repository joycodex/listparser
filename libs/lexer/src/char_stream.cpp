#include "lexer/char_stream.h"

#include <cassert>

CharStream::CharStream(const std::string &input)
    : input_(input)
{
    if (input_.size() > 0) {
        p_ = 0;
        ch_ = input[0];
    }
}

char CharStream::peak()
{
    return ch_;
}

void CharStream::consume()
{
    assert(ch_ != EOF);

    p_++;
    if (p_ >= input_.size()) {
        ch_ = EOF;
    } else {
        ch_ = input_[p_];
    }
}
