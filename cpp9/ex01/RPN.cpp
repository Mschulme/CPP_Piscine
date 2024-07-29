#include "RPN.hpp"

int RPN_calculator(std::string str)
{
    int result = 0;
    std::stack<int> stack;

    for(std::string::size_type i = 0; i < str.size(); ++i)
    {
        char c = str[i];
    
        if (std::isdigit(c))
            stack.push(c - '0');

        else if  (c == '+' or c == '-' or c == '*' or c == '/')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Not enough operands for operator: '" << c << "'" << std::endl;
                return EXIT_FAILURE;
            }
            
            int rhs = stack.top();
            stack.pop();
            int lhs = stack.top();
            stack.pop();

            switch (c)
            {
                case '+':
                    result = lhs + rhs;
                    break;
                case '-':
                    result = lhs - rhs;
                    break;
                case '*':
                    result = lhs * rhs;
                    break;
                case '/':
                    result = lhs / rhs;
                    break;
            }

            stack.push(result);
        }
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error: Invalid expression (extra operands)" << std::endl;
        return EXIT_FAILURE;
    }
    

    int final_result = stack.top();
    std::cout << "The result is: " << final_result << std::endl;
    return (EXIT_SUCCESS);
}
