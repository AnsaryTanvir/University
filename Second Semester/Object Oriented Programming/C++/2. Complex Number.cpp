 
/* @context         January 6, 2023 Object Oriented Programming practise.
 * @instructor      Md. Ashiqur Rahman
 * @task            Write a class for handling complex number.
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * Represents a complex number, with real and imaginary components of type T.
 * 
 * @param T The type of the real and imaginary components of the complex number.
 */
template<typename T>
class Complex{

private:
    /** The real component of the complex number. */
    T real;

    /** The imaginary component of the complex number. */
    T imag;

public:
    /**
     * Constructor for the Complex<T> class. Initializes the real and imaginary
     * components of a complex number to 0.
     */
    Complex();

    /**
     * Constructor for the Complex<T> class. Initializes the real and imaginary
     * components of a complex number to the given values.
     * 
     * @param real The value to initialize the real component to.
     * @param imag The value to initialize the imaginary component to.
     */
    Complex(T real, T imag);

    /**
     * Overloads the + operator for the Complex<T> class. Adds two complex numbers and returns the result.
     * 
     * @param other The other complex number to be added to this complex number.
     * @return The sum of this complex number and the other complex number.
     */
    Complex operator+(const Complex& other) const;

    /**
     * Overloads the - operator for the Complex<T> class. Subtracts one complex number from another and returns the result.
     * 
     * @param other The complex number to be subtracted from this complex number.
     * @return The result of subtracting the other complex number from this complex number.
     */
    Complex operator-(const Complex& other) const;

    /**
     * Overloads the * operator for the Complex<T> class. Multiplies two complex numbers and returns the result.
     * 
     * @param other The other complex number to be multiplied with this complex number.
     * @return The product of this complex number and the other complex number.
     */
    Complex operator*(const Complex& other) const;

    /**
     * Overloads the / operator for the Complex<T> class. Divides one complex number by another and returns the result.
     * 
     * @param other The complex number by which this complex number is to be divided.
     * @return The result of dividing this complex number by the other complex number.
     */
    Complex operator/(const Complex& other) const;

    /**
     * Calculates the absolute value (magnitude) of the complex number.
     * 
     * @return The absolute value of the complex number.
     */
    T abs();

    /**
     * Outputs the complex number to the console in the form "a+bi", where "a" is the real component and "b" is the imaginary component.
     * If the imaginary component is negative, it is output as "a-bi" instead.
     */
    void show();
};

/**
 * Constructor for the Complex<T> class. Initializes the real and imaginary
 * components of a complex number to 0.
 * 
 * @param T The type of the real and imaginary components of the complex number.
 */
template<typename T>
Complex<T>::Complex(){
    this->real = 0;
    this->imag = 0;
}

/**
 * Constructor for the Complex<T> class. Initializes the real and imaginary
 * components of a complex number to 0.
 * 
 * @param T The type of the real and imaginary components of the complex number.
 */
template<typename T>
Complex<T>::Complex(T real, T imag){
    this->real = real;
    this->imag = imag;
}

/**
 * Overloads the + operator for the Complex<T> class. Adds two complex numbers and returns the result.
 * 
 * @param other The other complex number to be added to this complex number.
 * @return The sum of this complex number and the other complex number.
 */
template<typename T>
Complex<T> Complex<T>::operator+(const Complex& other)const {
    return Complex( this->real+other.real, this->imag+other.imag );
}

/**
 * Overloads the - operator for the Complex<T> class. Subtracts one complex number from another and returns the result.
 * 
 * @param other The complex number to be subtracted from this complex number.
 * @return The result of subtracting the other complex number from this complex number.
 */
template<typename T>
Complex<T> Complex<T>::operator-(const Complex& other)const {
    return Complex( this->real-other.real, this->imag-other.imag );
}

/**
 * Overloads the * operator for the Complex<T> class. Multiplies two complex numbers and returns the result.
 * 
 * @param other The other complex number to be multiplied with this complex number.
 * @return The product of this complex number and the other complex number.
 */
template<typename T>
Complex<T> Complex<T>::operator*(const Complex& other)const {
    Complex result;
    result.real = (this->real * other.real) - (this->imag * other.imag);
    result.imag = (this->real * other.imag) + (this->imag * other.real);
    return result;
}

/**
 * Overloads the / operator for the Complex<T> class. Divides one complex number by another and returns the result.
 * 
 * @param other The complex number by which this complex number is to be divided.
 * @return The result of dividing this complex number by the other complex number.
 */
template<typename T>
Complex<T> Complex<T>::operator/(const Complex& other)const {
    Complex result;
    result.real = ( (this->real * other.real) + (this->imag * other.imag) ) / ( other.real*other.real + other.imag*other.imag );
    result.imag = ( (this->imag * other.real) - (this->real * other.imag) ) / ( other.real*other.real + other.imag*other.imag );
    return result;
}

/**
 * Outputs the complex number to the console in the form "a+bi", where "a" is the real component and "b" is the imaginary component.
 * If the imaginary component is negative, it is output as "a-bi" instead.
 */
template<typename T>
void Complex<T>::show(){
    std::cout << this->real;
    if ( this->imag >= 0 )
        std::cout << "+";
    std::cout << this->imag << "i";
}

/**
 * Calculates the absolute value (magnitude) of the complex number.
 * 
 * @return The absolute value of the complex number.
 */
template<typename T>
T Complex<T>::abs(){
    return sqrt(this->real*this->real + this->imag*this->imag);
}

int main(){

    Complex<double> z1(10, 5), z2(5,2);
    
    z1.show();
    cout << " ";
    z2.show();


    cout << endl << endl << "Addition : ";
    (z1+z2).show();

    cout << endl << endl << "Subtraction : ";
    (z1-z2).show();

    cout << endl << endl << "Multiplication : ";
    (z1*z2).show();

    cout << endl << endl <<  "Division : ";
    (z1/z2).show();
    cout << endl;

    return 0;
}
