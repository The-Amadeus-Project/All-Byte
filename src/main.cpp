#include <string>
#include <vector>
#include "lexer.hpp"
using namespace std;

int main(){
    Lexer lexer;
    lexer.lex_text(" \"string\" ");

    return 0;
}