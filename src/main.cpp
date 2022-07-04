#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    Identifier,
    Integer,
    String,
    Float,  

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
    
};

class Lexer {

private:
    int ind = -1;
    string to_lex;
    char current_char;  


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

        vector<Token> return_tokens;
        while (true) {
            if (next_char()){
                cout << current_char << "\n";
            } else { 
                break;
            }
        }

        return return_tokens;
    }


    vector<Token> lex_text(string given){
        to_lex = given;
        return lex();
    }
};

int main() { 
    Lexer lexer;
    lexer.lex_text("sad is life");
    return 0; 
}