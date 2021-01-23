#include <gtest/gtest.h>

#include "parser/list_parser.h"

class ListParserTest : public testing::Test {
public:
    void parse(const std::string &text) {
        std::cout << "parsing: <" << text << ">" << std::endl;
        try {
            std::unique_ptr<ListLexer> lexer(new ListLexer(std::unique_ptr<CharStream>(new CharStream(text))));
            ListParser parser(std::move(lexer));
            parser.parse();
        } catch (std::string &e) {
            std::cout << e << std::endl;
        }
    }
};

TEST_F(ListParserTest, testParser) {
    parse("");
    parse("[]");
    parse("[a]");
    parse("[a, b]");
}
