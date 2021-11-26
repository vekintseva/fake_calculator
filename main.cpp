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

