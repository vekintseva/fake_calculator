# CALCULATOR

# Usage
Import `Expression` class and extend it with overriding virtual method `int evaluate(int x, int y)` to implement operation of your expression. Also you can use already implemented expressions like `AddExpression` and `SubtractExpression`
# Example
```kotlin
VariableExpression x(X);
VariableExpression y(Y);

ConstantVariable two(2);
ConstantVariable five(5);

MultiplicationExpression two_x(&two, &x);
MultiplicationExpression five_y(&five, &y);

SubtractExpression subt(&two_x, &five_y);

std::cout << subt.evaluate(5, 10) << std::endl;
```
