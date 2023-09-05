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

int main() {

    // string exp = "(A*B+C)*D+E";
    string exp = "( 10 * 11 + 12 ) * 4 + 55";
        
    LinearArray<string> aa = getPostfixFromInfix(exp);
    // cout << aa << endl;

    for (int i=0; i<aa.getLength(); i++) cout << aa.get(i) << " ";

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