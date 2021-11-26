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

