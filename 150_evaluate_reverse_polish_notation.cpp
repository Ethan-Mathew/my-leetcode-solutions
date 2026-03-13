class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbersToCompute;
        for (int i{}; i < tokens.size(); i++) {
            if (checkIfOp(tokens[i])) {
                int secondNum = numbersToCompute.top();
                numbersToCompute.pop();
                int firstNum = numbersToCompute.top();
                numbersToCompute.pop();
                numbersToCompute.push(performArith(firstNum, secondNum, tokens[i]));
            } else {
                numbersToCompute.push(std::stoi(tokens[i]));
            }
        }

        return numbersToCompute.top();
    }

    bool checkIfOp(std::string& op) {
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            return true;
        } else {
            return false;
        }
    }

    int performArith(int num1, int num2, std::string& op) {
        switch(op[0]) {
        case('+'):
            return num1 + num2;
        case('-'):
            return num1 - num2;
        case('*'):
            return num1 * num2;
        case('/'):
            return num1 / num2;
        }

        return -1;
    }
};