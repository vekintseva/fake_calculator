#include<iostream>

/**
 * @brief interface for base expression
 * 
 */
class Expression {
    public:
        /**
         * @brief evaluates expression
         * 
         * @param x - first parameter
         * @param y - second parameter
         * @return int result of expression 
         */
        virtual int evaluate(int x, int y) = 0;
};

/**
 * @brief constant expression
 * 
 */
class ConstantVariable: public Expression {

    private:
        int _constant;

    public:
        ConstantVariable(int constant): _constant(constant) {}

        virtual int evaluate(int x, int y) override {
            return _constant;
        }
};

/**
 * @brief Sum expression
 */
class AddExpression: public Expression {
    private:
        Expression* _left;
        Expression* _right;

    public:
        AddExpression(Expression* left, Expression* right): _left(left), _right(right) {}

        int evaluate(int x, int y) override {
            return _left->evaluate(x, y) + _right->evaluate(x, y);
        }
};

/**
 * @brief Subtract expression
 */
class SubtractExpression: public Expression {
    private:
        Expression* _left;
        Expression* _right;

    public:
        SubtractExpression(Expression* left, Expression* right): _left(left), _right(right) {}

        int evaluate(int x, int y) override {
            return _left->evaluate(x, y) - _right->evaluate(x, y);
        }
};

/**
 * @brief Multiplication expression
 */
class MultiplicationExpression: public Expression {
    private:
        Expression* _left;
        Expression* _right;

    public:
        MultiplicationExpression(Expression* left, Expression* right): _left(left), _right(right) {}

        int evaluate(int x, int y) override {
            return _left->evaluate(x, y) * _right->evaluate(x, y);
        }
};

/**
 * @brief variable of expression
 */

enum Variable { X , Y };

class VariableExpression: public Expression {
    private:
        Variable _variable;
    
    public:
        VariableExpression(Variable variable): _variable(variable) {}

        int evaluate(int x, int y) override {
            switch (_variable) {
            case X:
                return x;
            case Y:
                return y;
            }
        }
};

/**
 * @brief checks correct adding of expression
 */

void run_add_tests() {
    VariableExpression x(X);
    VariableExpression y(Y);


    ConstantVariable two(2);
    ConstantVariable five(5);

    MultiplicationExpression two_x(&two, &x);
    MultiplicationExpression five_y(&five, &y);

    AddExpression adding(&two_x, &five_y);

    std::cout << " <=== Running add tests ===>" << std::endl;

    int passed_tests = 0;
    int tests_count = 0;

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            int expected = 2*i + 5*j;
            int actual = adding.evaluate(i, j);
            
            passed_tests += expected == actual;
            tests_count++;
        }
    }

    std::cout << " <=== Passed tests: " << passed_tests <<  " Tests count: " << tests_count << " ===>" << std::endl;
}

/**
 * @brief checks correct multiplication of expression
 */

void run_mult_test() {
    VariableExpression x(X);
    VariableExpression y(Y);


    ConstantVariable two(2);
    ConstantVariable five(5);

    MultiplicationExpression two_x(&two, &x);
    MultiplicationExpression five_y(&five, &y);

    MultiplicationExpression mult(&two_x, &five_y);

    std::cout << " <=== Running mult tests ===>" << std::endl;

    int passed_tests = 0;
    int tests_count = 0;

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            int expected = 2*i * 5*j;
            int actual = mult.evaluate(i, j);
            
            passed_tests += expected == actual;
            tests_count++;
        }
    }

    std::cout << " <=== Passed tests: " << passed_tests <<  " Tests count: " << tests_count << " ===>" << std::endl;
}

/**
 * @brief checks correct subtraction of expression
 */

void run_subtract_test() {
    VariableExpression x(X);
    VariableExpression y(Y);


    ConstantVariable two(2);
    ConstantVariable five(5);

    MultiplicationExpression two_x(&two, &x);
    MultiplicationExpression five_y(&five, &y);

    SubtractExpression subt(&two_x, &five_y);

    std::cout << " <=== Running subtract tests ===>" << std::endl;

    int passed_tests = 0;
    int tests_count = 0;

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            int expected = 2*i - 5*j;
            int actual = subt.evaluate(i, j);
            
            passed_tests += expected == actual;
            tests_count++;
        }
    }

    std::cout << " <=== Passed tests: " << passed_tests <<  " Tests count: " << tests_count << " ===>" << std::endl;
}

/**
 * @brief runs all tests
 */

void run_var_test() {
    run_add_tests();
    run_subtract_test();
    run_mult_test();
}
