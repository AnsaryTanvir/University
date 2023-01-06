 
/* @context         January 4, 2023 Object Oriented Programming first lab
 * @instructor      Md. Ashiqur Rahman
 * @task            Write a function to choose an operation among addition, subtration, multiplication & division.
                    Then take two numbers from input and run the choosen operation on them.
                    
 * @implementation  The choose() fuction ask the user to choose a simple math operation & then it returns
                    a pointer to the required function if the choice is valid.
 */

#include <iostream>
using namespace std;

enum{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};


template<typename T>
T add( T first, T second ){
    return first + second ;
}

template<typename T>
T subtract( T first, T second){
    return first - second ;
}

template<typename T>
T multiply( T first, T second){
    return first * second ;
}

template<typename T>
T division( T first, T second){
    return first / second ;
}

template<typename T>
void* chooseOperation(){

    cout << "Choose an operation: " << endl;
    cout << ADDITION        << ". Addition          "  << endl;
    cout << SUBTRACTION     << ". Subtraction       "  << endl;
    cout << MULTIPLICATION  << ". Multiplication    "  << endl;
    cout << DIVISION        << ". Division          "  << endl;

    int choice; cin >> choice;
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

template <typename T>
using Function = T(*)(T,T);

/* Change int to other data type in order to change the behaviour*/
typedef double type;


int main(){

    
    Function<type> function = (Function<type>) chooseOperation<type>();
    if ( !function ){
        cout << "Invalid choice " << endl;
        return -1;
    }

    cout << "Enter two numbers: ";
    type x, y; cin >> x >> y;
    cout << function(x,y) << endl;

    return 0;
}
