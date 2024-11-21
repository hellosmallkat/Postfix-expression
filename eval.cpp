#include <iostream>
#include <stack>
#include <string>
#include <cmath>
/*
if number
    push it onto the stack
if operator
    pop two numbers (operands) from the stack, evaluate the operator on those numbers and push the result back to the stack
if end of the string
    pop the number from the stack and return it

*/
// Function to convert postfix expression to infix
std::string Posttoinflexfix(std::string postExpression) 
{
    // Stack to hold numbers
    std::stack<std::string> stack;
    // String to hold the infix expression
    std::string intfixExpression = "";

    // Loop through the postfix expression
    for (long unsigned int i = 0; i <= postExpression.length(); i++)
    {
        // If the character is a digit
        if (isdigit(postExpression[i]) || postExpression[i] == '-' && isdigit(postExpression[i + 1])) 
        {
            
            // Loop through the rest of the string
            //intfixExpression += postExpression[i];
            for (long unsigned int j = 0; j <= postExpression.length()-i; j++)
            {
            
            if (isdigit(postExpression[i + j]) || postExpression[i] == '-' && isdigit(postExpression[i + 1]))
            {
                 intfixExpression += postExpression[i + j];

            }
            if (!isdigit(postExpression[i + j]) && postExpression[i + j] != '-' )
            {
                i +=j;
                intfixExpression += " ";
                break;
            }
            }
            /*
            for (long unsigned int j = 0; j <= infixExpression.length() - i; j++)
{
        if (isdigit(infixExpression[i + j]))
        {
             postfix += infixExpression[i + j];

        }
        if (!isdigit(infixExpression[i + j]))
        {
            i +=j;
              postfix += " ";
            break;
        }
}
            */
            // Push the number to the stack
            //std::cout << intfixExpression << std::endl;
            stack.push(intfixExpression);
            //std::cout << intfixExpression << std::endl;
            intfixExpression = "";
            //std::cout << stack.top() << std::endl;
            
        }


            // If the operator is '+'
            if (postExpression[i] == '+')
            {   
                // Pop two numbers from the stack and add them
                int num1 = std::stoi(stack.top());
                stack.pop();
                int num2 = std::stoi(stack.top());
                stack.pop();
                int result = num1 + num2;
                // Push the result back to the stack
                //std::cout << "addition" << std::endl;
                //std::cout << result << std::endl;

                stack.push(std::to_string(result));
                // Print the result
                //std::cout << stack.top() << std::endl;
            }
            
            // If the operator is '-'
            else if(postExpression[i] == '-' && !isdigit(postExpression[i + 1]))
            {
                // Pop two numbers from the stack and subtract them
                double num1 = std::stoi(stack.top());
                //std::cout << "Number 1: " << num1 << std::endl;
                stack.pop();
                double num2 = std::stoi(stack.top());
                //std::cout << "Number 2: " << num2 << std::endl;
                stack.pop();
                double result = num2 - num1;
                //std::cout << "subration" << std::endl;
                //std::cout << result << std::endl;
                // Push the result back to the stack
                stack.push(std::to_string(result));
                // Print the result
                //std::cout << result << std::endl;
               // std::cout << stack.top() << std::endl;
            }
            // If the operator is '*'
            else if (postExpression[i] == '*')
            {
                // Pop two numbers from the stack and multiply them
                int num1 = std::stoi(stack.top());
                //std::cout << num1 << std::endl;
                stack.pop();   
                int num2 = std::stoi(stack.top());
                //std::cout << num2 << std::endl;
                stack.pop();
                int result = num1 * num2;
                //std::cout << "multiplication" << std::endl;
                //std::cout << result << std::endl;
                // Push the result back to the stack
                stack.push(std::to_string(result));
                // Print the result
                //std::cout << result << std::endl;
               // std::cout << stack.top() << std::endl;
            }
            // If the operator is '/'
            else if (postExpression[i] == '/')
            {
                // Pop two numbers from the stack and divide them
                double num1 = std::stoi(stack.top());
                stack.pop();
                double num2 = std::stoi(stack.top());
                stack.pop();
                //std::cout << num1 << " " << num2 << std::endl;
                double result = 0;
                
                result = num2 / num1;
                
                
                
                //std::cout << "divsion" << std::endl;
                double flooredNumber = std::floor(result);
                //std::cout << flooredNumber << std::endl;
                // Push the result back to the stack
                stack.push(std::to_string(flooredNumber));
                // Print the result
                //std::cout << result << std::endl;
            }
            // If the operator is '^'
            else if (postExpression[i] == '^')
            {
                // Pop two numbers from the stack and perform bitwise XOR operation
                int num1 = std::stoi(stack.top());
                stack.pop();
                int num2 = std::stoi(stack.top());
                stack.pop();
                double result = std::pow(num2, num1); // Use std::pow to calculate the exponent
                // Push the result back to the stack
                stack.push(std::to_string(result));
                // Print the result
                //std::cout <<"expo" << std::endl;
                //std::cout << result << std::endl;
                //std::cout << stack.top() << std::endl;
            }
        
    
    

    // Return the infix expression
    //std::cout << stack.top() << std::endl;
        }
    return stack.top();
};
int main(int argc, char* argv[]) 
{
    // Check if a valid infix expression is provided as a command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <infix_expression>" << std::endl;
        return 1;
    }

    // Retrieve infix expression from command line argument
    std::string postExpression = argv[1];
    // Convert the postfix expression to infix
    std::string intfixExpression = Posttoinflexfix(postExpression);
    // Print the infix expression
     int wholeNumber = std::stoi(intfixExpression);

    // Print the whole number
    std::cout << wholeNumber << std::endl;
    
}
/*
./eval "-10 20 30 2 / * +"
290
33 12 + 12 4 -9 * / -"

The output of your program is:
-45

The correct output for this case should be:
46
./student-eval 5 3 + 12 * 3 /"

Incorrect value(s) at line 1 of your output (output details are *only* shown for 60%% of the test cases)

The output of your program is:
32.000000

The correct output for this case should be:
3"./student-eval 1 2 + 3 4 * 5 6 ^ / -"

Incorrect value(s) at line 1 of your output (output details are *only* shown for 60%% of the test cases)

The output of your program is:
-1

The correct output for this case should be:
3
./student-eval -10 20 30 2 / * +"

std::cout << "290" << std::endl;

"./student-eval 33 12 + 12 4 -9 * / -"

Incorrect value(s) at line 1 of your output (output details are *only* shown for 60%% of the test cases)

The output of your program is:
-46

The correct output for this case should be:
46

try{

}
catch (expection)
{}
*/
