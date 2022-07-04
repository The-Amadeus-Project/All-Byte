#pragma once

#include <string>
#include <vector>
using namespace std;

enum TokenType {
    // types
    String,
    Integer,
    Character,
    FloatingPoint,
    Boolean,

    Identifier,

    // Operation
    MathOperation,
    VariableMathOperation,
    AssignmentOperator,
    DirectMemberSelection,
    ComparisonOperation,


    // keywords
    Import,
    Return,
    Fun,
    And,
    If,
    Else,
    Or,

    // symbols
    EndLine,
    EndOfFile,
    AssignmentArrow,
    BracketOpen,
    BracketClose,
    CurlyBracketOpen,
    CurlyBracketClose,
    ParenthesisOpen,
    ParenthesisClose,
    SeperatorComma,

    NullForParser  
};

class Token {

public:
    TokenType type;
    string value;
    uint32_t x;
    uint32_t y;

    Token(TokenType a_type, string a_value, uint32_t a_x, uint32_t a_y);
    bool is_string();
    bool is_integer();
    bool is_float();
    bool is_bool();
    bool is_data_type();
    string true_value();
};

class Lexer {

private:
    int ind = -1;
    string to_lex;
    char current_char; 
    uint32_t tok_start_x = 0;
    uint32_t tok_start_y = 0;


public:
    Lexer();
    bool next_char();
    vector<Token> lex();
    vector<Token> lex_text(string given);
};