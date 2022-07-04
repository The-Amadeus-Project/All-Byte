#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

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

    Token(TokenType a_type, string a_value, uint32_t a_x, uint32_t a_y) {
        type = a_type;
        value = a_value;
        x = a_x;
        y = a_y;
    }
    bool is_string() {
        return type == TokenType::String;
    }
    bool is_integer() {
        return type == TokenType::Integer;
    }
    bool is_float() {
        return type == TokenType::FloatingPoint;
    }
    bool is_bool() {
        return type == TokenType::Boolean;
    }
    bool is_data_type() {
        return is_bool() || is_float() || is_float() || is_string();
    }
    string true_value(){
        if (is_string()){
            return "";
        } else {
            return value;
        }
    }
};

class Lexer {

private:
    int ind = -1;
    string to_lex;
    char current_char; 
    uint32_t tok_start_x = 0;
    uint32_t tok_start_y = 0;


public:
    Lexer(){

    }
    bool next_char(){
        ind += 1;
        if (ind == to_lex.length()){
            return false;
        } else {
            current_char = to_lex[ind];
            return true;
        }
    }
    vector<Token> lex(){
        if (ind != -1) {
            cout << "ERROR > unexpected index for lexer\n";
            throw;
        }

        bool str_on = false;
        bool id_on = false;
        bool num_on = false;
        bool is_float = false;
        string unknown_length = "";
        bool unknown_length_being_used= false;

        vector<Token> return_tokens;
        while (true) {
            if (!next_char()){
                break;
            }

            if (current_char == '"'){
                if (str_on){

                } else {
                    
                }
            } else if (str_on) {
                
            } else {
                assert((false) && "unimplemented");
            }
        }

        return return_tokens;
    }


    vector<Token> lex_text(string given){
        to_lex = given;
        return lex();
    }
};
