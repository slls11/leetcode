class Solution {
  /* O(n) solution */
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& iter : tokens){
            if (iter == "+" || iter == "-" || iter == "*" || iter == "/"){
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                switch(iter[0]){
                    case '+': s.push(num1+num2);
                        break;
                    case '-': s.push(num1-num2);
                        break;
                    case '*': s.push(num1*num2);
                        break;
                    case '/': s.push(num1/num2);
                        break;
                    default:
                        exit(1);
                }
            }
            else s.push(stoi(iter));
        }
    return s.top();
    }
};
