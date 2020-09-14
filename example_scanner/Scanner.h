// Auto-generated code

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

class Scanner
{
  private:
    std::unordered_map<unsigned, std::string> accepted_map {
       {147, "identifier"},
       {145, "identifier"},
       {144, "identifier"},
       {143, "identifier"},
       {140, "identifier"},
       {137, "binary-op"},
       {65, "identifier"},
       {7, "semicolon"},
       {62, "identifier"},
       {55, "identifier"},
       {50, "unary-op"},
       {54, "identifier"},
       {52, "identifier"},
       {61, "identifier"},
       {103, "identifier"},
       {111, "identifier"},
       {48, "identifier"},
       {46, "relational-op"},
       {136, "unary-op"},
       {63, "identifier"},
       {96, "identifier"},
       {49, "identifier"},
       {53, "identifier"},
       {6, "star"},
       {31, "hyphen"},
       {57, "identifier"},
       {56, "identifier"},
       {79, "identifier"},
       {29, "close-scope"},
       {139, "identifier"},
       {99, "identifier"},
       {64, "identifier"},
       {12, "colon"},
       {11, "selection-keyword"},
       {90, "identifier"},
       {18, "literal-string"},
       {9, "open-scope"},
       {108, "iteration-keyword"},
       {76, "identifier"},
       {22, "comment"},
       {85, "identifier"},
       {8, "assignment-op"},
       {35, "comment"},
       {129, "identifier"},
       {0, "ellipsis"},
       {67, "identifier"},
       {38, "literal-int"},
       {17, "storage-class-specifier"},
       {28, "binary-op"},
       {142, "identifier"},
       {66, "identifier"},
       {95, "identifier"},
       {4, "literal-int"},
       {42, "binary-op"},
       {5, "literal-float"},
       {70, "identifier"},
       {120, "identifier"},
       {30, "ampersand"},
       {58, "identifier"},
       {60, "identifier"},
       {84, "identifier"},
       {134, "identifier"},
       {115, "identifier"},
       {16, "jump-keyword"},
       {106, "identifier"},
       {10, "relational-op"},
       {27, "type-qualifier"},
       {13, "unary-op"},
       {47, "relational-op"},
       {32, "comma-op"},
       {74, "identifier"},
       {15, "identifier"},
       {118, "identifier"},
       {146, "identifier"},
       {26, "whitespace"},
       {21, "struct-or-union"},
       {105, "identifier"},
       {86, "identifier"},
       {141, "identifier"},
       {23, "equality-op"},
       {132, "identifier"},
       {24, "plus"},
       {14, "iteration-keyword"},
       {20, "ternary-op"},
       {2, "postfix-op"},
       {25, "open-square"},
       {68, "identifier"},
       {71, "identifier"},
       {72, "identifier"},
       {73, "identifier"},
       {59, "identifier"},
       {75, "identifier"},
       {77, "identifier"},
       {78, "identifier"},
       {81, "identifier"},
       {80, "identifier"},
       {127, "identifier"},
       {133, "identifier"},
       {82, "identifier"},
       {83, "identifier"},
       {87, "identifier"},
       {88, "identifier"},
       {89, "identifier"},
       {91, "identifier"},
       {122, "identifier"},
       {92, "identifier"},
       {102, "identifier"},
       {93, "identifier"},
       {135, "assignment-op"},
       {124, "identifier"},
       {98, "identifier"},
       {43, "postfix-op"},
       {100, "identifier"},
       {101, "identifier"},
       {3, "close-paren"},
       {104, "identifier"},
       {117, "identifier"},
       {128, "identifier"},
       {33, "close-square"},
       {107, "identifier"},
       {109, "identifier"},
       {125, "identifier"},
       {110, "identifier"},
       {97, "identifier"},
       {112, "identifier"},
       {1, "open-paren"},
       {113, "identifier"},
       {69, "identifier"},
       {114, "identifier"},
       {119, "identifier"},
       {51, "identifier"},
       {94, "identifier"},
       {121, "identifier"},
       {123, "identifier"},
       {126, "identifier"},
       {130, "identifier"},
       {19, "type-specifer"},
       {116, "identifier"},
       {131, "identifier"}
     };

     std::pair<std::string, std::string> get_lex(std::ifstream& in_stream)
     {
       std::string lexeme {};
       std::stack<unsigned> s;

       char c;
       goto s36;
s148:
       s.push(148);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '.' ) goto s0;
       else goto sout;
s147:
        s = std::stack<unsigned>();
       s.push(147);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else if (c  == 'e' ) goto s11;
       else goto sout;
s145:
        s = std::stack<unsigned>();
       s.push(145);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s144;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s144:
        s = std::stack<unsigned>();
       s.push(144);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s16;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s143:
        s = std::stack<unsigned>();
       s.push(143);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s16;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else goto sout;
s140:
        s = std::stack<unsigned>();
       s.push(140);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s19;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s138:
       s.push(138);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' ) goto s5;
       else goto sout;
s137:
        s = std::stack<unsigned>();
       s.push(137);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s134:
        s = std::stack<unsigned>();
       s.push(134);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'f' ) goto s17;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'e' || c >= 'g' && c <= 'z' ) goto s133;
       else goto sout;
s132:
        s = std::stack<unsigned>();
       s.push(132);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s130;
       else goto sout;
s130:
        s = std::stack<unsigned>();
       s.push(130);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else if (c  == 'e' ) goto s129;
       else goto sout;
s129:
        s = std::stack<unsigned>();
       s.push(129);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s139;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else goto sout;
s133:
        s = std::stack<unsigned>();
       s.push(133);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s127:
        s = std::stack<unsigned>();
       s.push(127);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'b' && c <= 'z' ) goto s133;
       else if (c  == 'a' ) goto s126;
       else goto sout;
s54:
        s = std::stack<unsigned>();
       s.push(54);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'c' ) goto s17;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'b' || c >= 'd' && c <= 'z' ) goto s133;
       else goto sout;
s52:
        s = std::stack<unsigned>();
       s.push(52);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'l' ) goto s15;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'k' || c >= 'm' && c <= 'z' ) goto s133;
       else goto sout;
s50:
        s = std::stack<unsigned>();
       s.push(50);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s23;
       else goto sout;
s48:
        s = std::stack<unsigned>();
       s.push(48);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s27;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s46:
        s = std::stack<unsigned>();
       s.push(46);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s47;
       else if (c  == '<' ) goto s42;
       else goto sout;
s37:
       s.push(37);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '.' ) goto s5;
       else if (c >= '0' && c <= '9' ) goto s37;
       else goto sout;
s96:
        s = std::stack<unsigned>();
       s.push(96);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s58;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else goto sout;
s49:
        s = std::stack<unsigned>();
       s.push(49);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'a' ) goto s140;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'b' && c <= 'z' ) goto s133;
       else goto sout;
s53:
        s = std::stack<unsigned>();
       s.push(53);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'k' ) goto s16;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'j' || c >= 'l' && c <= 'z' ) goto s133;
       else goto sout;
s61:
        s = std::stack<unsigned>();
       s.push(61);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else if (c  == 'r' ) goto s108;
       else goto sout;
s103:
        s = std::stack<unsigned>();
       s.push(103);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'l' ) goto s99;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'k' || c >= 'm' && c <= 'w' || c >= 'y' && c <= 'z' ) goto s133;
       else if (c  == 'x' ) goto s132;
       else goto sout;
s111:
        s = std::stack<unsigned>();
       s.push(111);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'k' || c >= 'm' && c <= 'z' ) goto s133;
       else if (c  == 'l' ) goto s109;
       else goto sout;
s6:
        s = std::stack<unsigned>();
       s.push(6);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s135;
       else goto sout;
s55:
        s = std::stack<unsigned>();
       s.push(55);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'd' ) goto s19;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'c' || c >= 'e' && c <= 'z' ) goto s133;
       else goto sout;
s62:
        s = std::stack<unsigned>();
       s.push(62);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 's' ) goto s48;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'r' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s102;
       else goto sout;
s31:
        s = std::stack<unsigned>();
       s.push(31);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '>' ) goto s43;
       else if (c >= '1' && c <= '9' ) goto s38;
       else if (c  == '0' ) goto s37;
       else if (c  == '-' ) goto s136;
       else if (c  == '.' ) goto s138;
       else if (c  == '=' ) goto s135;
       else goto sout;
s57:
        s = std::stack<unsigned>();
       s.push(57);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s140;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'e' || c >= 'g' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else if (c  == 'f' ) goto s11;
       else goto sout;
s56:
        s = std::stack<unsigned>();
       s.push(56);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else if (c  == 'e' ) goto s108;
       else goto sout;
s79:
        s = std::stack<unsigned>();
       s.push(79);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'p' ) goto s78;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'o' || c >= 'q' && c <= 'z' ) goto s133;
       else goto sout;
s29:
        s = std::stack<unsigned>();
       s.push(29);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s139:
        s = std::stack<unsigned>();
       s.push(139);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s17;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else goto sout;
s99:
        s = std::stack<unsigned>();
       s.push(99);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 's' ) goto s147;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'r' || c >= 't' && c <= 'z' ) goto s133;
       else goto sout;
s10:
        s = std::stack<unsigned>();
       s.push(10);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s47;
       else if (c  == '>' ) goto s42;
       else goto sout;
s27:
        s = std::stack<unsigned>();
       s.push(27);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s39:
       s.push(39);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '|' ) goto s137;
       else if (c  == '=' ) goto s135;
       else goto sout;
s11:
        s = std::stack<unsigned>();
       s.push(11);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s90:
        s = std::stack<unsigned>();
       s.push(90);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s112;
       else goto sout;
s18:
        s = std::stack<unsigned>();
       s.push(18);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s9:
        s = std::stack<unsigned>();
       s.push(9);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s36:
       s.push(36);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'a' ) goto s92;
       else if (c  == 'g' ) goto s91;
       else if (c  == '{' ) goto s9;
       else if (c  == 'r' ) goto s89;
       else if (c  == 'c' ) goto s82;
       else if (c  == 'f' ) goto s72;
       else if (c  == 's' ) goto s68;
       else if (c  == 'd' ) goto s60;
       else if (c  == '!' ) goto s50;
       else if (c  == '+' ) goto s24;
       else if (c >= 'A' && c <= 'Z' || c  == '_' || c  == 'h' || c >= 'j' && c <= 'k' || c >= 'm' && c <= 'q' || c >= 'x' && c <= 'z' ) goto s133;
       else if (c  == '?' ) goto s20;
       else if (c  == '~' ) goto s136;
       else if (c  == ':' ) goto s12;
       else if (c  == 'u' ) goto s119;
       else if (c  == ';' ) goto s7;
       else if (c  == '>' ) goto s10;
       else if (c  == 't' ) goto s80;
       else if (c  == 'b' ) goto s124;
       else if (c  == '%' ) goto s42;
       else if (c  == '=' ) goto s8;
       else if (c  == 'w' ) goto s106;
       else if (c  == '(' ) goto s1;
       else if (c  == '.' ) goto s2;
       else if (c  == '[' ) goto s25;
       else if (c  == '\n' || c  == ' ' ) goto s26;
       else if (c  == ',' ) goto s32;
       else if (c  == 'e' ) goto s103;
       else if (c  == '/' ) goto s28;
       else if (c  == '<' ) goto s46;
       else if (c  == '}' ) goto s29;
       else if (c  == '"' ) goto s40;
       else if (c  == 'l' ) goto s97;
       else if (c  == 'v' ) goto s114;
       else if (c  == '-' ) goto s31;
       else if (c  == ']' ) goto s33;
       else if (c >= '1' && c <= '9' ) goto s38;
       else if (c  == 'i' ) goto s57;
       else if (c  == '|' ) goto s39;
       else if (c  == '0' ) goto s4;
       else if (c  == '*' ) goto s6;
       else if (c  == '&' ) goto s30;
       else if (c  == ')' ) goto s3;
       else if (c  == '^' ) goto s45;
       else goto sout;
s108:
        s = std::stack<unsigned>();
       s.push(108);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s76:
        s = std::stack<unsigned>();
       s.push(76);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'f' || c >= 'h' && c <= 'y' ) goto s133;
       else if (c  == 'z' ) goto s75;
       else if (c  == 'g' ) goto s115;
       else goto sout;
s22:
        s = std::stack<unsigned>();
       s.push(22);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '*' ) goto s44;
       else if (c  == '\n' || c >= ' ' && c <= ')' || c >= '+' && c <= '~' ) goto s34;
       else goto sout;
s85:
        s = std::stack<unsigned>();
       s.push(85);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s84;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s8:
        s = std::stack<unsigned>();
       s.push(8);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s23;
       else goto sout;
s35:
        s = std::stack<unsigned>();
       s.push(35);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s40:
       s.push(40);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= ' ' && c <= '!' || c >= '#' && c <= '~' ) goto s40;
       else if (c  == '"' ) goto s18;
       else goto sout;
s0:
        s = std::stack<unsigned>();
       s.push(0);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s67:
        s = std::stack<unsigned>();
       s.push(67);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s66;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s38:
        s = std::stack<unsigned>();
       s.push(38);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '.' ) goto s5;
       else if (c >= '0' && c <= '9' ) goto s38;
       else goto sout;
s17:
        s = std::stack<unsigned>();
       s.push(17);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s41:
       s.push(41);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= ' ' && c <= '~' ) goto s41;
       else if (c  == '\n' ) goto s35;
       else goto sout;
s28:
        s = std::stack<unsigned>();
       s.push(28);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '/' ) goto s41;
       else if (c  == '*' ) goto s34;
       else if (c  == '=' ) goto s135;
       else goto sout;
s95:
        s = std::stack<unsigned>();
       s.push(95);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s94;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else goto sout;
s4:
        s = std::stack<unsigned>();
       s.push(4);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '.' ) goto s5;
       else if (c >= '0' && c <= '9' ) goto s37;
       else goto sout;
s42:
        s = std::stack<unsigned>();
       s.push(42);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s135;
       else goto sout;
s5:
        s = std::stack<unsigned>();
       s.push(5);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' ) goto s5;
       else goto sout;
s30:
        s = std::stack<unsigned>();
       s.push(30);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '&' ) goto s137;
       else if (c  == '=' ) goto s135;
       else goto sout;
s58:
        s = std::stack<unsigned>();
       s.push(58);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'g' ) goto s19;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'f' || c >= 'h' && c <= 'z' ) goto s133;
       else goto sout;
s115:
        s = std::stack<unsigned>();
       s.push(115);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else if (c  == 'n' ) goto s107;
       else goto sout;
s16:
        s = std::stack<unsigned>();
       s.push(16);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s106:
        s = std::stack<unsigned>();
       s.push(106);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'g' || c >= 'i' && c <= 'z' ) goto s133;
       else if (c  == 'h' ) goto s105;
       else goto sout;
s7:
        s = std::stack<unsigned>();
       s.push(7);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s65:
        s = std::stack<unsigned>();
       s.push(65);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'c' ) goto s63;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'b' || c >= 'd' && c <= 'z' ) goto s133;
       else goto sout;
s45:
       s.push(45);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '=' ) goto s135;
       else goto sout;
s13:
        s = std::stack<unsigned>();
       s.push(13);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s47:
        s = std::stack<unsigned>();
       s.push(47);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s32:
        s = std::stack<unsigned>();
       s.push(32);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s74:
        s = std::stack<unsigned>();
       s.push(74);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s64;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s15:
        s = std::stack<unsigned>();
       s.push(15);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s27;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s118:
        s = std::stack<unsigned>();
       s.push(118);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'r' || c >= 't' && c <= 'z' ) goto s133;
       else if (c  == 'i' ) goto s128;
       else if (c  == 's' ) goto s117;
       else goto sout;
s34:
       s.push(34);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '*' ) goto s44;
       else if (c  == '\n' || c >= ' ' && c <= ')' || c >= '+' && c <= '~' ) goto s34;
       else goto sout;
s128:
        s = std::stack<unsigned>();
       s.push(128);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s51;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s117:
        s = std::stack<unsigned>();
       s.push(117);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else if (c  == 'i' ) goto s116;
       else goto sout;
s146:
        s = std::stack<unsigned>();
       s.push(146);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s143;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else goto sout;
s26:
        s = std::stack<unsigned>();
       s.push(26);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '\n' || c  == ' ' ) goto s26;
       else goto sout;
s21:
        s = std::stack<unsigned>();
       s.push(21);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s105:
        s = std::stack<unsigned>();
       s.push(105);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s98;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else goto sout;
s86:
        s = std::stack<unsigned>();
       s.push(86);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 's' ) goto s85;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'r' || c >= 't' && c <= 'z' ) goto s133;
       else goto sout;
s141:
        s = std::stack<unsigned>();
       s.push(141);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s16;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s23:
        s = std::stack<unsigned>();
       s.push(23);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s24:
        s = std::stack<unsigned>();
       s.push(24);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '+' ) goto s136;
       else goto sout;
s14:
        s = std::stack<unsigned>();
       s.push(14);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 't' || c >= 'v' && c <= 'z' ) goto s133;
       else if (c  == 'u' ) goto s104;
       else goto sout;
s20:
        s = std::stack<unsigned>();
       s.push(20);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s2:
        s = std::stack<unsigned>();
       s.push(2);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' ) goto s5;
       else if (c  == '.' ) goto s148;
       else goto sout;
s25:
        s = std::stack<unsigned>();
       s.push(25);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s84:
        s = std::stack<unsigned>();
       s.push(84);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s142;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s60:
        s = std::stack<unsigned>();
       s.push(60);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s14;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s136:
        s = std::stack<unsigned>();
       s.push(136);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s63:
        s = std::stack<unsigned>();
       s.push(63);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s21;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s12:
        s = std::stack<unsigned>();
       s.push(12);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s64:
        s = std::stack<unsigned>();
       s.push(64);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'e' || c >= 'g' && c <= 'z' ) goto s133;
       else if (c  == 'f' ) goto s13;
       else goto sout;
s142:
        s = std::stack<unsigned>();
       s.push(142);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s17;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else goto sout;
s66:
        s = std::stack<unsigned>();
       s.push(66);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s140;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else goto sout;
s120:
        s = std::stack<unsigned>();
       s.push(120);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s54;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else goto sout;
s70:
        s = std::stack<unsigned>();
       s.push(70);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s69;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'b' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else if (c  == 'a' ) goto s121;
       else goto sout;
s68:
        s = std::stack<unsigned>();
       s.push(68);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'w' ) goto s95;
       else if (c  == 't' ) goto s70;
       else if (c  == 'h' ) goto s67;
       else if (c  == 'i' ) goto s76;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'g' || c >= 'j' && c <= 's' || c >= 'u' && c <= 'v' || c >= 'x' && c <= 'z' ) goto s133;
       else goto sout;
s71:
        s = std::stack<unsigned>();
       s.push(71);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s49;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s72:
        s = std::stack<unsigned>();
       s.push(72);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'l' ) goto s71;
       else if (c  == 'o' ) goto s61;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'k' || c >= 'm' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s73:
        s = std::stack<unsigned>();
       s.push(73);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s134;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s59:
        s = std::stack<unsigned>();
       s.push(59);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'g' || c >= 'i' && c <= 'z' ) goto s133;
       else if (c  == 'h' ) goto s11;
       else goto sout;
s75:
        s = std::stack<unsigned>();
       s.push(75);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s74;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s77:
        s = std::stack<unsigned>();
       s.push(77);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'd' ) goto s73;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'c' || c >= 'e' && c <= 'z' ) goto s133;
       else goto sout;
s78:
        s = std::stack<unsigned>();
       s.push(78);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s77;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s81:
        s = std::stack<unsigned>();
       s.push(81);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s62;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else goto sout;
s80:
        s = std::stack<unsigned>();
       s.push(80);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'y' ) goto s79;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'x' || c  == 'z' ) goto s133;
       else goto sout;
s82:
        s = std::stack<unsigned>();
       s.push(82);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'h' ) goto s83;
       else if (c  == 'o' ) goto s81;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'g' || c >= 'i' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s83:
        s = std::stack<unsigned>();
       s.push(83);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'b' && c <= 'z' ) goto s133;
       else if (c  == 'a' ) goto s110;
       else goto sout;
s87:
        s = std::stack<unsigned>();
       s.push(87);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s86;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else goto sout;
s88:
        s = std::stack<unsigned>();
       s.push(88);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'g' ) goto s87;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'f' || c >= 'h' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s131;
       else goto sout;
s44:
       s.push(44);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == '*' ) goto s44;
       else if (c  == '\n' || c >= ' ' && c <= ')' || c >= '+' && c <= '.' || c >= '0' && c <= '~' ) goto s34;
       else if (c  == '/' ) goto s22;
       else goto sout;
s89:
        s = std::stack<unsigned>();
       s.push(89);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s88;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s91:
        s = std::stack<unsigned>();
       s.push(91);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s145;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s131:
        s = std::stack<unsigned>();
       s.push(131);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'u' ) goto s146;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 't' || c >= 'v' && c <= 'z' ) goto s133;
       else goto sout;
s19:
        s = std::stack<unsigned>();
       s.push(19);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'z' ) goto s133;
       else goto sout;
s116:
        s = std::stack<unsigned>();
       s.push(116);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'f' || c >= 'h' && c <= 'z' ) goto s133;
       else if (c  == 'g' ) goto s115;
       else goto sout;
s122:
        s = std::stack<unsigned>();
       s.push(122);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'a' ) goto s53;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'b' && c <= 'z' ) goto s133;
       else goto sout;
s92:
        s = std::stack<unsigned>();
       s.push(92);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'u' ) goto s90;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 't' || c >= 'v' && c <= 'z' ) goto s133;
       else goto sout;
s102:
        s = std::stack<unsigned>();
       s.push(102);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else if (c  == 'i' ) goto s101;
       else goto sout;
s93:
        s = std::stack<unsigned>();
       s.push(93);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'c' ) goto s59;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'b' || c >= 'd' && c <= 'z' ) goto s133;
       else goto sout;
s135:
        s = std::stack<unsigned>();
       s.push(135);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s124:
        s = std::stack<unsigned>();
       s.push(124);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else if (c  == 'r' ) goto s123;
       else goto sout;
s98:
        s = std::stack<unsigned>();
       s.push(98);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'l' ) goto s56;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'k' || c >= 'm' && c <= 'z' ) goto s133;
       else goto sout;
s43:
        s = std::stack<unsigned>();
       s.push(43);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s100:
        s = std::stack<unsigned>();
       s.push(100);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'u' ) goto s141;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 't' || c >= 'v' && c <= 'z' ) goto s133;
       else goto sout;
s101:
        s = std::stack<unsigned>();
       s.push(101);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else if (c  == 'n' ) goto s100;
       else goto sout;
s3:
        s = std::stack<unsigned>();
       s.push(3);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s104:
        s = std::stack<unsigned>();
       s.push(104);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c  == 'a' || c >= 'c' && c <= 'z' ) goto s133;
       else if (c  == 'b' ) goto s111;
       else goto sout;
s33:
        s = std::stack<unsigned>();
       s.push(33);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s107:
        s = std::stack<unsigned>();
       s.push(107);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s55;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s109:
        s = std::stack<unsigned>();
       s.push(109);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'e' ) goto s19;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else goto sout;
s125:
        s = std::stack<unsigned>();
       s.push(125);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s52;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'z' ) goto s133;
       else goto sout;
s110:
        s = std::stack<unsigned>();
       s.push(110);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'r' ) goto s19;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'q' || c >= 's' && c <= 'z' ) goto s133;
       else goto sout;
s97:
        s = std::stack<unsigned>();
       s.push(97);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s96;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s112:
        s = std::stack<unsigned>();
       s.push(112);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'o' ) goto s17;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else goto sout;
s1:
        s = std::stack<unsigned>();
       s.push(1);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       goto sout;
s113:
        s = std::stack<unsigned>();
       s.push(113);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'i' ) goto s55;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'h' || c >= 'j' && c <= 'k' || c >= 'm' && c <= 'z' ) goto s133;
       else if (c  == 'l' ) goto s127;
       else goto sout;
s69:
        s = std::stack<unsigned>();
       s.push(69);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'u' ) goto s65;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 't' || c >= 'v' && c <= 'z' ) goto s133;
       else goto sout;
s114:
        s = std::stack<unsigned>();
       s.push(114);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'n' || c >= 'p' && c <= 'z' ) goto s133;
       else if (c  == 'o' ) goto s113;
       else goto sout;
s119:
        s = std::stack<unsigned>();
       s.push(119);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else if (c  == 'n' ) goto s118;
       else goto sout;
s51:
        s = std::stack<unsigned>();
       s.push(51);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 'n' ) goto s21;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'm' || c >= 'o' && c <= 'z' ) goto s133;
       else goto sout;
s94:
        s = std::stack<unsigned>();
       s.push(94);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c  == 't' ) goto s93;
       else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else goto sout;
s121:
        s = std::stack<unsigned>();
       s.push(121);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s120;
       else goto sout;
s123:
        s = std::stack<unsigned>();
       s.push(123);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 'd' || c >= 'f' && c <= 'z' ) goto s133;
       else if (c  == 'e' ) goto s122;
       else goto sout;
s126:
        s = std::stack<unsigned>();
       s.push(126);
       if (!in_stream.get(c))
       {
         lexeme = lexeme + " ";
         goto sout;
       }
       lexeme = lexeme + c;

       if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c  == '_' || c >= 'a' && c <= 's' || c >= 'u' && c <= 'z' ) goto s133;
       else if (c  == 't' ) goto s125;
       else goto sout;
sout:
       s.push(-1);
       std::string old {lexeme};
       do
       {
         s.pop();
         if (in_stream.eof())
         {
           in_stream.clear();
         }
         else
         {
           in_stream.unget();
         }
         lexeme = lexeme.substr(0, lexeme.length() - 1);
       } while (!s.empty() && accepted_map.count(s.top()) == 0);

if (!s.empty() && accepted_map.count(s.top()) > 0)
         return make_pair(accepted_map[s.top()], lexeme);
       else
         return make_pair("", old);
       }

  public:

  std::vector<std::pair<std::string, std::string>> scan(std::ifstream& stream)
{
    std::vector<std::pair<std::string, std::string>> res_vec;
    std::pair<std::string, std::string> res;

    do
    {
     res = get_lex(stream);
     res_vec.push_back(res);
    } while (stream.peek() != EOF && res.first != "");

    stream.close();
    if (res.first == "")
    {
     std::cerr << "Scanner error: couldn't recognize token " << res.second
       << std::endl;
     return {};
    }
    else
    {
     return res_vec;
    }
   }
};