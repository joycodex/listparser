#include <iostream>

#include "lexer/list_lexer.h"

int main(int argc, char *argv[])
{
    try {
        if (argc > 1) {
            ListLexer lexer(std::unique_ptr<CharStream>(new CharStream(argv[1])));

            Token t = lexer.nextToken();
            do {
                std::cout << t.toString() << std::endl;
                if (t.getType() == ListLexer::TOKEN_EOF) {
                    break;
                }
                t = lexer.nextToken();
            } while (true);
        }
    } catch (std::string &e) {
        std::cerr << e << std::endl;
        return -1;
    }

    return 0;
}
