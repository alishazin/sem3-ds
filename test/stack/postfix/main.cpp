#include <iostream>
#include "stack.cpp"
#include "larray.cpp"
using namespace std;

int getPrecedence(string item) {
    if (item == "%" || item == "/" || item == "*") {
        return 1;
    } else if (item == "+" || item == "-") {
        return 2;
    } else if (item == "(") {
        return 3;
    }
    return -1;
}

LinearArray<string> splitString(string text, char keyword) {
    
    LinearArray<string> returnArray;
    
    int count = 0;
    string latest_string = "";
    
    for (int i=0; i<text.length(); i++) {
        
        if (text[i] == keyword || i == text.length() - 1) {
            
            if (count != 0) {
                if (i == text.length() - 1) {
                    latest_string.push_back(text[i]);
                }
                returnArray.append(latest_string, true);
            }

            count = 0;
            latest_string = "";
            continue;
        } 
        
        count++;
        latest_string.push_back(text[i]);
    }

    return returnArray;
}

LinearArray<string> getPostfixFromInfix(string exp) {
    
    char space = ' ';
    LinearArray<string> postfix;

    LinearArray<string> LAexp = splitString(exp, space);
    cout << LAexp << endl;
    
    Stack<string> stack(LAexp.getLength());

    for (int i=0; i<LAexp.getLength(); i++) {

        if (LAexp.get(i) == "(") {

            stack.push(LAexp.get(i));

        } else if (LAexp.get(i) == ")") {

            while (true) {
                if (stack.peek() == "(") {
                    stack.pop();
                    break;
                } else {
                    postfix.append(stack.pop(), true);
                }
            }

        } else if (LAexp.get(i) == "+" || LAexp.get(i) == "-") {

            if (!stack.isEmpty() && getPrecedence(stack.peek()) < 2) {
                while (true) {
                    if (!stack.isEmpty()) {
                        if (stack.peek() == "(") {
                            stack.push(LAexp.get(i));
                            break;
                        }
                        
                        postfix.append(stack.pop(), true);
                        if (stack.isEmpty()) {
                            stack.push(LAexp.get(i));
                            break;
                        }
                    } else {
                        break;
                    }
                }
            } else {
                stack.push(LAexp.get(i));
            }
        
        } else if (LAexp.get(i) == "*" || LAexp.get(i) == "/") {
        
            if (!stack.isEmpty() && getPrecedence(stack.peek()) < 1) {
                while (true) {
                    if (!stack.isEmpty()) {
                        if (stack.peek() == "(") {
                            stack.push(LAexp.get(i));
                            break;
                        }

                        postfix.append(stack.pop(), true);
                        if (stack.isEmpty()) {
                            stack.push(LAexp.get(i));
                            break;
                        }
                    } else {
                        break;
                    }
                }
            } else {
                stack.push(LAexp.get(i));
            }
        
        } else {
            postfix.append(LAexp.get(i), true);
        }

        if (i == LAexp.getLength() - 1) {
            while (true) {
                if (!stack.isEmpty()) {
                    postfix.append(stack.pop(), true);
                } else {
                    break;
                }
            }
        }
    }

    return postfix;
}

float evaluatePostfix(LinearArray<string> postfix) {
    
    // 10 11 * 12 + 4 * 55 +
    
    // 10       10   
    // 11       10 11
    // *        110
    // 12       110 12
    // +        122
    // 4        122 4
    // *        488
    // 55       488 55
    // +        543

    Stack<float> stack(postfix.getLength());

    for (int i=0; i<postfix.getLength(); i++) {

        int topNum;
        int topMinusOneNum;

        if (postfix.get(i) == "+") {
            try {
                stack.push(stack.pop() + stack.pop());
            } catch(Exception &e) {
                cout << "\nInvalid postfix" << endl;
                return -1;
            }

        } else if (postfix.get(i) == "-") {

            try {
                topNum = stack.pop();
                topMinusOneNum = stack.pop();
            } catch(Exception &e) {
                cout << "\nInvalid postfix" << endl;
                return -1;
            }

            stack.push(topMinusOneNum - topNum);
            
        } else if (postfix.get(i) == "*") {

            try {
                stack.push(stack.pop() * stack.pop());
            } catch(Exception &e) {
                cout << "\nInvalid postfix" << endl;
                return -1;
            }
            
        } else if (postfix.get(i) == "/") {

            try {
                topNum = stack.pop();
                topMinusOneNum = stack.pop();
            } catch(Exception &e) {
                cout << "\nInvalid postfix" << endl;
                return -1;
            }

            stack.push(topMinusOneNum / topNum);
            
        } else {
            try {
               stack.push((float) stoi(postfix.get(i)));
            } catch(std::invalid_argument e) {
                cout << endl << "Postfix expression should only contain numbers and operators" << endl;
                return -1;
            }
        }
    }

    try {
        if (stack.getTop() != 0) {
            throw StackUnderflow(); // any derived error
        }
        return stack.pop();
    } catch(Exception &e) {
        cout << "\nInvalid postfix" << endl;
        return -1;
    }
}

int main() {

    // string exp = "( A * B + C ) * D + E";
    string exp = "( 10 * 11 + 12 ) * 4 + 55";
        
    LinearArray<string> aa = getPostfixFromInfix(exp);
    // cout << aa << endl;

    for (int i=0; i<aa.getLength(); i++) cout << aa.get(i) << " ";

    cout << evaluatePostfix(aa) << endl;

    return 0;
}

// string exp = "A+B*C+D";

// A       A
// +  +    A
// B  +    AB
// *  +*   AB
// C  +*   ABC
// +  +   ABC+*
// D      ABC*+D+

// string exp = "(A+B)*C+D";

// (  (     
// A  (    A
// +  (+   A
// B  (+   AB
// )       AB+
// *  *    AB+
// C  *    AB+C
// +  +    AB+C*
// D       AB+C*D+

// string exp = "(A*B+C)*D+E";

// (  (     
// A  (    A
// *  (*   A
// B  (*   AB
// +  (+   AB*
// C  (+   AB*C
// )       AB*C+
// *  *    AB*C+
// D  *    AB*C+D
// +  +    AB*C+D*
// E       AB*C+D*E+