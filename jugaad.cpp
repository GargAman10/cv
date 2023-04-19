// lex program to count consonants
%{
    int vow_count=0;
    int const_count =0;
%}
 
%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%
int yywrap(){}
int main()
{
    printf("Enter the string of vowels and consonants:");
    yylex();
    printf("Number of vowels are:  %d\n", vow_count);
    printf("Number of consonants are:  %d\n", const_count);
    return 0;
}

//3 add
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to generate three-address code for the given expression
void generateThreeAddressCode(string expr) {
    stack<char> operators;
    stack<string> operands;
    string temp;

    for (int i = 0; i < expr.length(); i++) {
        // If current character is an operand, push it onto the stack of operands
        if (isalnum(expr[i])) {
            temp = "";
            while (i < expr.length() && isalnum(expr[i])) {
                temp += expr[i];
                i++;
            }
            i--;
            operands.push(temp);
        }
        // If current character is an operator, then pop operands from the stack and generate three-address code
        else if (isOperator(expr[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string res = "t" + to_string(operands.size()+1);
                operands.push(res);
                cout << res << " = " << op1 << " " << op << " " << op2 << endl;
            }
            operators.push(expr[i]);
        }
        // If current character is an opening bracket, push it onto the stack of operators
        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }
        // If current character is a closing bracket, then pop operators from the stack and generate three-address code
        else if (expr[i] == ')') {
            while (operators.top() != '(') {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string res = "t" + to_string(operands.size()+1);
                operands.push(res);
                cout << res << " = " << op1 << " " << op << " " << op2 << endl;
            }
            operators.pop();
        }
    }

    // Generate three-address code for any remaining operators
    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string res = "t" + to_string(operands.size()+1);
        operands.push(res);
        cout << res << " = " << op1 << " " << op << " " << op2 << endl;
    }

    // Print final assignment statement
    cout << "x = " << operands.top() << endl;
}

// Main function
int main() {
    cout<<"Enter an expression: ";
    string expr;
    cin>>expr;
    generateThreeAddressCode(expr);
  return 0;
}

//rec descent
#include <bits/stdc++.h>
using namespace std;
int i=0;
string s;
bool X();bool Y();bool Z();bool W();
bool X(){
    if(s[i]=='x'){
        i++;
        if(Y()){
            return true;
        }
        return false;
    }
    return false;
}
bool Y(){
    if(Z()){
        if(W()){
            if(Y()) return true;
            return false;
        }
        return false;
    }
    else if(s[i]=='x'){
        i++;
        if(s[i]=='y') {i++;return true;}
        return false;
    }
    return true;
}
bool Z(){
    if(s[i]=='y'){
        i++;
        if(W())return true;
        return false;
    }
    return false;
}
bool W(){
    if(s[i]=='z') {
        i++;
        if(W()) return true;
        return false;
    }
    return true;
}
int main(){
    cin>>s;
    if(X()){
        cout<<"Accepted"<<endl;
        return 0;
    }
    cout<<"Rejected"<<endl;
   return 0;
}


//follow set
#include <iostream>
#include <unordered_set>
using namespace std;

// Function to print the Follow Set of a given LL1 grammar
void printFollowSet(char nonTerminal, unordered_set<char> &followSet) {
    if (nonTerminal == 'E') {
        followSet.insert('$');
    }
    else if (nonTerminal == 'R') {
        followSet.insert('$');
        followSet.insert('+');
    }
    else if (nonTerminal == 'T') {
        followSet.insert('$');
        followSet.insert('+');
    }
    else if (nonTerminal == 'Y') {
        followSet.insert('$');
        followSet.insert('+');
        followSet.insert('*');
    }
}


int main() {
    // Initialize the Follow Sets of all non-terminals to empty sets
    unordered_set<char> followSet_E, followSet_R, followSet_T, followSet_Y;

    // Compute the Follow Set of E
    printFollowSet('E', followSet_E);

    // Compute the Follow Set of R
    printFollowSet('R', followSet_R);

    // Compute the Follow Set of T
    printFollowSet('T', followSet_T);

    // Compute the Follow Set of Y
    printFollowSet('Y', followSet_Y);

    // Print the Follow Sets of all non-terminals
    cout << "Follow(E) = ";
    for (char c : followSet_E) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Follow(R) = ";
    for (char c : followSet_R) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Follow(T) = ";
    for (char c : followSet_T) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Follow(Y) = ";
    for (char c : followSet_Y) {
        cout << c << " ";
    }
    cout << endl;

   return 0;
}

 // a*bb + a* 
#include <bits/stdc++.h>
using namespace std;
int main(){
   
    string s;
    cin>>s;
    int a=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a') a++;
    }
    if(a==s.length()||(a==s.length()-2&&s[s.length()-1]=='b'&&s[s.length()-2]=='b')){cout<<"Accepted"<<endl;return 0;}
    cout<<"Rejected"<<endl;
   return 0;
}

//Comment
#include <bits/stdc++.h>
using namespace std;
int main(){


    string s="",enter="";
    vector<string > vs;

    while(getline(cin,s) && s!=""){
        // enter += s+'\n';
        string curr = s;
        vs.push_back(curr);
    }

    bool single =0,multi =0;

    for(int i=0;i<vs.size();i++){
        for(int j=0;j<vs[i].size()-1;j++){
            if(vs[i][j] == '/' && vs[i][j+1] == '/' ){
                single =1;
                break;
            }
        }
    }

    int open = -1 , close= -1;

     for(int i=0;i<vs.size();i++){
        for(int j=0;j<vs[i].size()-1;j++){
            if(vs[i][j] == '/' && vs[i][j+1] == '*' ){
            open = i;
            close = j;
            break;
            }
        }
    }

     for(int i=0;i<vs.size();i++){
        for(int j=0;j<vs[i].size()-1;j++){
            if(vs[i][j] == '*' && vs[i][j+1] == '/' && i> open && open != -1 && close != -1 && j> close  ){
                multi =1;
                
            }
             if(vs[i][j] == '*' && vs[i][j+1] == '/' && i == open && j> close ){
                // multi =1;
                single =1;
                
            }
        }
    }

    if(single){
        cout<<"Single"<<endl;
    }
    if(multi){
        cout<<"Multi"<<endl;
    }

    // cout<<enter<<endl;


  return 0;

}

// 5Target code generator
#include <bits/stdc++.h>
using namespace std;
vector<char>A={'X','A','B','C','D','E','F'};
vector<string>RES;
unordered_map<char,char>S;
int j=0;
void MOV(char a,char b){
    string temp="MOV ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void DIV(char a,char b){
    string temp="DIV ";
    temp+=a;
    temp+=char(32);
    temp+=b;
    RES.push_back(temp);
}
void MULT(char a,char b){
    string temp="MUL ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void ADD(char a,char b){
    string temp="ADD ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void SUB(char a,char b){
    string temp="SUB ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
    // RES.push_back("SUB "+a+' '+b);
}
void convert(string s){
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=97&&int(s[i])<=122){
            S[s[i]]=A[j];
            j++;
            
        }
        
    }
    cout<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            DIV(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='*'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            MULT(S[s[i-1]],S[s[i+1]]);
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            ADD(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            SUB(S[s[i-1]],S[s[i+1]]);
        }
    }
    MOV(s[0],S[s[0]]);
}
void show(){
    for(int i=0;i<RES.size();i++){
        bool b=false;
        for(int j=0;j<i;j++){
            if(RES[j]==RES[i])
              b=true;
        }
        if(b==false){
            cout<<RES[i]<<endl;
        }
    }
}
int main(){
    
    cout<<"Enter a expression"<<endl;
    string s;
    cin>>s;
    convert(s);
    show();
    
    return 0;
}



//Token validation

- yacc.l
%{
    #include<stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}
DIGIT [0-9]
NUM {DIGIT}+(\.{DIGIT}+)?
%%

{NUM} {yylval= atoi(yytext); return NUMBER;}
[\t] ;
[\n] {return 0;}
.  { return yytext[0];}

%%

int yywrap()
{
    return -1;
}


- yacc.y

%{
#include<stdio.h>
int flag=0;
int yylex();
void yyerror();
%}

%token NUMBER
%left '+' '-' 
%left '*' '/''%'
%left '('')'

%%
ArithmeticExpression: E { printf("\nResult:%d\n",$$); return 0;}
;
E:E'+'E  {$$=$1+$3;}
|E'-'E   {$$=$1-$3;}
|E'*'E   {$$=$1*$3;}
|E'/'E   {$$=$1/$3;}
|E'%'E   {$$=$1%$3;}
|'('E')' {$$=$2;}
|NUMBER  {$$=$1;}
;

%%

void main()
{
    printf("\n Enter an Arithmetic Expression:\n");
    yyparse();
    if(flag==0)printf("\n Entered expression is valid\n");
}

void yyerror()
{
    printf("\n this expression is invalid");
    flag=-1;
}


//first set
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// Define the grammar productions
const unordered_map<string, vector<string>> grammar = {
    {"E", {"T R"}},
    {"R", {"+ T R", "e"}},
    {"T", {"F Y"}},
    {"Y", {"* F Y", "e"}},
    {"F", {"( E )", "i"}}
};

// Calculate the first set for a given symbol
set<string> calculateFirst(string symbol, set<string>& visited) {
    if (visited.find(symbol) != visited.end()) {
        return set<string>();
    }

    visited.insert(symbol);

    set<string> firstSet;

    if (grammar.find(symbol) != grammar.end()) {
        for (auto production : grammar.at(symbol)) {
            string firstSymbol = production.substr(0, 1);

            if (firstSymbol == "e") {
                firstSet.insert("e");

                if (production.size() > 1) {
                    string secondSymbol = production.substr(1, 1);
                    set<string> subFirstSet = calculateFirst(secondSymbol, visited);
                    firstSet.insert(subFirstSet.begin(), subFirstSet.end());
                }
            } else if (grammar.find(firstSymbol) == grammar.end()) {
                firstSet.insert(firstSymbol);
            } else {
                set<string> subFirstSet = calculateFirst(firstSymbol, visited);
                firstSet.insert(subFirstSet.begin(), subFirstSet.end());

                if (subFirstSet.find("e") != subFirstSet.end() && production.size() > 1) {
                    string secondSymbol = production.substr(1, 1);
                    set<string> subFirstSet2 = calculateFirst(secondSymbol, visited);
                    firstSet.insert(subFirstSet2.begin(), subFirstSet2.end());
                }
            }
        }
    } else {
        firstSet.insert(symbol);
    }

    return firstSet;
}

int main() {
    // Calculate the first set for each symbol in the grammar
    unordered_map<string, set<string>> firstSets;
    set<string> visited;

    for (auto entry : grammar) {
        string symbol = entry.first;
        set<string> firstSet = calculateFirst(symbol, visited);
        firstSets[symbol] = firstSet;
    }

    // Print the first set for each symbol
    for (auto entry : firstSets) {
        string symbol = entry.first;
        set<string> firstSet = entry.second;

        cout << "First(" << symbol << ") = { ";

        for (auto element : firstSet) {
            cout << element << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}