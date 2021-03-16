/**
 * Program to create simple text snowman
 * 
 *  HHHHH
 *  HHHHH
 * X(LNR)Y
 * X(TTT)Y
 *  (BBB)
 * further readeing : https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
 * Author: Mark Michaely
 * Since : 2021-03
 */

#include <stddef.h>
#include <iostream>
#include <array>
#include <string>

#include "snowman.hpp"

using namespace std;

const unsigned short valid_num_len = 8;
enum part{
    hat, nose, left_eye, right_eye, left_arm, right_arm, torso, base
};
/* 0=Straw Hat, 1=Mexican Hat, 2=Fez, 3=Ushanka */
std::array<std::string, 4> H {"     \n_===_", " ___ \n.....", "  _  \n /_\\ ", " ___ \n(_*_)"};

/* 0=Normal, 1=Dot, 2=Line, 3=None  */
std::array<std::string, 4> N {",", ".", "_", " "};

/* 0=Dot, 1=Bigger Dot, 2=Biggest Dot, 3=Closed  */
std::array<std::string, 4> L {".", "o", "O", "-"};

/* 0=Dot, 1=Bigger Dot, 2=Biggest Dot, 3=Closed  */
std::array<std::string, 4> R {".", "o", "O", "-"};

/* 0=Normal Arm, 1=Upwards Arm, 2=Downwards Arm, 3=None  */
std::array<std::string, 4> X_TOP {" ", "\\", " ", " "};

/* 0=Normal Arm, 1=Upwards Arm, 2=Downwards Arm, 3=None  */
std::array<std::string, 4> X_BOT {"<", " ", "/", " "};

/* 0=Normal Arm, 1=Upwards Arm, 2=Downwards Arm, 3=None  */
std::array<std::string, 4> Y_TOP {" ", "/", " ", " "};

/* 0=Normal Arm, 1=Upwards Arm, 2=Downwards Arm, 3=None  */
std::array<std::string, 4> Y_BOT {">", " ", "\\", " "};

/* 0=Buttons, 1=Vest, 2=Inward Arms, 3=None  */
std::array<std::string, 4> T {" : ", "] [", "> <", "   "};

/* 0=Buttons, 1=Feet, 2=Flat, 3=None  */
std::array<std::string, 4> B {" : ", "\" \"", "___", "   "};

/**
 * this function used to convert the charaters in a string to an integer.
 * it is used to chars from the converted string so as to put them as index number to choose snowman parts
 */
int charToDigit (char c){
    return ((c-'0')-1);
}

namespace ariel{
    string snowman(int num){
        std::string tmp = to_string(num);
        if (tmp.size() != valid_num_len) throw out_of_range {"num should be exacaly 8 digits"};
        char const *snow_man = tmp.c_str();
        std::string answer =string();
        
        try
        {
            answer.append("  " + H.at(charToDigit( snow_man[hat])) + "\n"); //first and secnod row
            answer.append(" " + X_TOP.at(charToDigit(snow_man[left_arm]))+"("); //third row
            answer.append(L.at (charToDigit( snow_man[left_eye])));
            answer.append(N.at (charToDigit( snow_man[nose])));
            answer.append(R.at (charToDigit( snow_man[right_eye]) ) + ")");
            answer.append(Y_TOP.at(charToDigit( snow_man[right_arm])) + "\n");
            answer.append(" " + X_BOT.at(charToDigit( snow_man[left_arm])) + "("); //fourth row
            answer.append(T.at(charToDigit( snow_man[torso])) + ")");
            answer.append(Y_BOT.at(charToDigit( snow_man[right_arm])) + "\n");
            answer.append("  (" + B.at(charToDigit(snow_man[base]))+")"); 
        }
        catch(const std::exception& )
        {
            throw out_of_range {"num digits must be between 1 to 4"};
        }
        
        
        return answer;
    }
}
