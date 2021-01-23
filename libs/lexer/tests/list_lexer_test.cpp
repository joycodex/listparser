#include <gtest/gtest.h>

#include "lexer/list_lexer.h"

class ListLexerTest : public testing::Test {
public:
    void lexer(const std::string &text) {
        std::cout << "lexing: <" << text << ">" << std::endl;
        try {
            ListLexer lexer(std::unique_ptr<CharStream>(new CharStream(text)));

            Token t = lexer.nextToken();
            do {
                std::cout << t.toString() << std::endl;
                if (t.getType() == ListLexer::TOKEN_EOF) {
                    break;
                }
                t = lexer.nextToken();
            } while (true);
        } catch (std::string &e) {
            std::cout << e << std::endl;
        }
    }
};

TEST_F(ListLexerTest, testLexer) {
    lexer("");
    lexer("[a, b, [a, b]]");
    lexer("[a, b^");
}
