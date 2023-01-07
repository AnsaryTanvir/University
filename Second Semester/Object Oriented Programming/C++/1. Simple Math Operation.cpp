 
/* @context         January 4, 2023 Object Oriented Programming first lab
 * @instructor      Md. Ashiqur Rahman
 * @task            Write a function to choose an operation among addition, subtration, multiplication & division.
                    Then take two numbers from input and run the choosen operation on them.
                    
 */

#include <iostream>
using namespace std;

/**
 * Constants representing the basic arithmetic operations that the program supports.
 */
enum{
    /** Addition operation */
    ADDITION,

    /** Subtraction operation */
    SUBTRACTION,

    /** Multiplication operation */
    MULTIPLICATION,

    /** Division operation */
    DIVISION
};


/**
 * Performs the addition operation on two values of type T and returns the result.
 *
 * @param first The first operand.
 * @param second The second operand.
 * @return The sum of the two operands.
 */
template<typename T>
T add( T first, T second ){
    return first + second ;
}

/**
 * Performs the subtraction operation on two values of type T and returns the result.
 *
 * @param first The minuend.
 * @param second The subtrahend.
 * @return The difference between the minuend and the subtrahend.
 */
template<typename T>
T subtract( T first, T second){
    return first - second ;
}

/**
 * Performs the multiplication operation on two values of type T and returns the result.
 *
 * @param first The first factor.
 * @param second The second factor.
 * @return The product of the two factors.
 */
template<typename T>
T multiply( T first, T second){
    return first * second ;
}

/**
 * Performs the division operation on two values of type T and returns the result.
 *
 * @param first The dividend.
 * @param second The divisor.
 * @return The quotient of the dividend and the divisor.
 */
template<typename T>
T division( T first, T second){
    return first / second ;
}

/**
 * Allows the user to choose a basic arithmetic operation (addition, subtraction, multiplication, or division) and returns a
 * void pointer to the corresponding function.
 *
 * The function uses templates to allow the user to specify the data type of the numbers.
 *
 * @return A void pointer to the function chosen by the user. If the user made an invalid choice, returns NULL.
 */
template<typename T>
void* chooseOperation(){

    // Prompt the user to choose an operation.
    cout << "Choose an operation: " << endl;
    cout << ADDITION        << ". Addition          "  << endl;
    cout << SUBTRACTION     << ". Subtraction       "  << endl;
    cout << MULTIPLICATION  << ". Multiplication    "  << endl;
    cout << DIVISION        << ". Division          "  << endl;

    int choice; cin >> choice;

    // Return a void pointer to the corresponding function based on the user's choice.
    switch (choice){
        case ADDITION:
            return (void*) &add<T>;
        
        case SUBTRACTION:
            return  (void*) &subtract<T>;
        
        case MULTIPLICATION:
            return  (void*) &multiply<T>;

        case DIVISION:
            return  (void*) &division<T>;

        default:
            return NULL;
    }

    return NULL;
}


/**
 * A type alias for a function pointer that takes in two arguments of type T and returns a value of type T.
 */
template <typename T>
using Function = T(*)(T,T);

/**
 * A type alias for the data type that the program will operate on.
 * 
 * Change the data type if necessary.
 */
typedef double type;


/**
 * A program that allows the user to choose a basic arithmetic operation (addition, subtraction, multiplication, or division)
 * and perform it on two user-specified numbers.
 *
 * The program uses templates to allow the user to specify the data type of the numbers. The program also uses a void pointer
 * and type casting to store a function pointer of the chosen operation in a single variable and call it later.
 */
int main(){

    /**
     * A function pointer of type "Function<type>", which points to a function that takes in two arguments of type "type" and
     * returns a value of type "type". The function pointed to is the one chosen by the user.
     */
    Function<type> function = (Function<type>) chooseOperation<type>();

    // If the user made an invalid choice, terminate the program.
    if ( !function ){
        cout << "Invalid choice " << endl;
        return -1;
    }

    // Read in the two numbers to perform the operation on.
    cout << endl << "Enter two numbers: ";
    type x, y; cin >> x >> y;

    // Call the chosen function and output the result.
    cout << function(x,y) << endl;

    return 0;
}
