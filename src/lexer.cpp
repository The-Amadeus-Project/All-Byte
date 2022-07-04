#include <cstdint>
#include <iostream>
#include <cassert>
#include "lexer.hpp"

using namespace std;


void error(string error_name, string error_body){
    cout << error_name << ": " << error_body << "\n";
    throw;
}

Token::Token(TokenType a_type, string a_value, uint32_t a_x, uint32_t a_y) {
    type = a_type;
    value = a_value;
    x = a_x;
    y = a_y;
}
bool Token::is_string() {
    return type == TokenType::String;
}
bool Token::is_integer() {
    return type == TokenType::Integer;
}
bool Token::is_float() {
    return type == TokenType::FloatingPoint;
}
bool Token::is_bool() {
    return type == TokenType::Boolean;
}
bool Token::is_data_type() {
    return is_bool() || is_float() || is_float() || is_string();
}
string Token::true_value(){
    if (is_string()){
        return "";
    } else {
        return value;
    }
}       


Lexer::Lexer(){

}
bool Lexer::next_char(){
    ind += 1;
    if (ind == to_lex.length()){
        return false;
    } else {
        current_char = to_lex[ind];
        return true;
    }
}
vector<Token> Lexer::lex(){
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
                str_on = false;
                cout << unknown_length << "\n";
                unknown_length = "";
                unknown_length_being_used = false;
            } else {
                str_on = true;
                if (unknown_length_being_used){
                    error("some shit happened", "unknown is being used");
                }
            }
        } else if (str_on) {
            if (current_char == '\n'){
                
            } else {
                unknown_length += current_char;
            }
        } else {
            if (id_on) {
               error("UNIMPLEMTED", "IDENTIFIER");
            } else {
                switch (current_char) {
                    case ' ':
                        break;
                    case '\n':
                        break;
                    case '\t':
                        break;
                    default:
                        error("UNIMPLEMTED", "CASE CHARS");
                        break;
                }
            }
        
        }
    }

    return return_tokens;
}


vector<Token> Lexer::lex_text(string given){
    to_lex = given;
    return lex();
}

