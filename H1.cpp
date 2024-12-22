#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    // Function to compute the greatest common divisor (GCD)
    int gcd(int a, int b) const {
        while (b != 0) {
        
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;

        // Ensure the denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructors
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }

    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Setters
    void setNumerator(int num) { numerator = num; simplify(); }
    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom; 
        simplify();
    }

    // Overloaded operators
    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        simplify();
        return *this;
    }

    // Conversion to double
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Overloaded stream operators
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        char slash; // to consume the '/' character
        is >> fraction.numerator >> slash >> fraction.denominator;
        fraction.simplify();
        return is;
    }
};

// Overloaded arithmetic operators
Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}

int main() 
    {
        Fraction f1(1, 2); // 1/2
        Fraction f2(3, 4); // 3/4

        std::cout << "f1: " << f1 << ", f2: " << f2 << std::endl;

        Fraction f3 = f1 + f2;
        std::cout << "f1 + f2: " << f3 << std::endl;

        f1 += f2;
        std::cout << "f1 += f2: " << f1 << std::endl;

        f1 -= f2;
        std::cout << "f1 -= f2: " << f1 << std::endl;

        f1 *= f2;
        std::cout << "f1 *= f2: " << f1 << std::endl;

        f1 /= f2;
        std::cout << "f1 /= f2: " << f1 << std::endl;

        std::cout << "f1 as double: " << f1.toDouble() << std::endl;
    }
