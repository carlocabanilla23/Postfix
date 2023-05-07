#include "evaluator.h"
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

double Evaluate(const string& postfix, bool& error){
    string s = "";
    stack<double> sti;
    double  a,b;
    char temp = postfix[postfix.size()-1];

//// Check if the last string is an operator. if the last string is not operator, return error = true;
    if(temp=='+' || temp == '*' || temp == '^' || temp == '/' || temp == '-'){}
    else return error = true;


//// Read the strings from left to right.
/// Check if the of string is an operator. if its not operator push it to the stack.
/// if its operator, pop the stack two times and then evaluate it with the operator the push the answer back to the stack.
/// At the end of the loop there will be last string left.

    for(size_t i = 0 ; i < postfix.length() ; i++){
        if(postfix[i]== ' '){
            if(s == "+" || s == "*" || s=="^" || s =="/" || s =="-"){
                a = sti.top();
                sti.pop();
                b = sti.top();
                sti.pop();

                if(s == "+"){
//                  cout << a+b<< endl;
                    sti.push(a+b);
                }else if(s == "*"){
//                  cout << a*b<< endl;
                    sti.push(a*b);
                }else if (s=="^"){
//                  cout << pow(b,a) << endl;
                    sti.push(pow(b,a));
                }else if (s=="/"){
//                  cout << b/a << endl;
                    sti.push((b/a));
                }else if (s=="-"){
//                  cout << b-a << endl;
                    sti.push(double(b-a));
                }
            }else{
                sti.push(stod(s));
            }
            s = "";
        } else{
            s += postfix[i];
        }
    }


//// Evaluate for the final operation
//// check if the last string is greater than 1. if its greater than one then return the error = true;
    if(s.size() > 1){
        return error = true;
    }

    a = sti.top();
    sti.pop();
    b = sti.top();
    sti.pop();



    if(s == "+"){
        sti.push(a+b);
    }else if(s == "*"){
        sti.push( (a*b));
    }else if (s=="^"){
        sti.push(pow(a,5));
    }else if (s=="/"){
        sti.push(b/a);
    }else if (s=="-"){
        sti.push(int(b-a));
    }

//  cout << s.size() << endl;
    error = false;
    return sti.top();
}
