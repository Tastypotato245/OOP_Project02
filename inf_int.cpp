/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_int.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:56:41 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/28 16:29:59 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_int.h"

// Default constructor
inf_int::inf_int() {
	this->digits = new char[1];

	this->digits[0] = 0;
	this->length = 1;
	this->thesign = true;
}

// Convert int to inf_int
inf_int::inf_int(int num) {
	unsigned int	un;
	unsigned int	temp;

	if (num >= 0)
	{
		thesign = true;
		un = num;
	}
	else {
		thesign = false;
		un = -num;
	}
	if (num == 0)
		inf_int();

	int len = 0;
	for (temp = un; temp > 0; temp /= 10)
		++len;

	if (len != 0)
		length = len;
	else
		length = 0;
	digits = new char[length];
	temp = un;
	for (unsigned int i = 0; i < length; ++i) {
		digits[i] = temp % 10;
		temp /= 10;
	}
}

// Convert string to inf_int
inf_int::inf_int(const char* str) {
	if (!str)
		return ;
	if (str[0] != '-' && str[0] != '+' && !(str[0] >= '0' && str[0] <= '9'))
	{
		thesign = true;
		digits = new char[1];
		digits[0] = 0;
		return ;
	}
	if (str[0] == '-')
	{
		thesign = false;
		++str;
	}
	else if (str[0] == '+')
	{
		thesign = true;
		++str;
	}
	else
		thesign = true;

	length = 0;
	while (str[length] && str[length] >= '0' && str[length] <= '9')
		++length;
	digits = new char[length];
	for (unsigned int i = 0; i < length; ++i)
		digits[i] = str[length - 1 - i] - '0';
}

// Copy constructor
inf_int::inf_int(const inf_int& other) {
	length = other.length;
	thesign = other.thesign;
	digits = new char[length];
	memcpy(digits, other.digits, length);
}

// Destructor
inf_int::~inf_int() {
	delete[] digits;
}

// Assignment operator
inf_int& inf_int::operator=(const inf_int& other) {
	if (this == &other) return *this;
	delete[] digits;

	length = other.length;
	thesign = other.thesign;
	digits = new char[length];
	memcpy(this->digits, other.digits, length);
	return (*this);
}

// Equality operator
bool operator==(const inf_int& a, const inf_int& b) {
	if (a.thesign != b.thesign) return (false);
	if (a.length != b.length) return (false);
	return (memcmp(a.digits, b.digits, a.length) == 0);
}

// Inequality operator
bool operator!=(const inf_int& a, const inf_int& b) {
	return (!(a == b));
}

// Greater than operator
bool operator>(const inf_int& a, const inf_int& b) {
	if (a.thesign && !b.thesign) return true;
	if (!a.thesign && b.thesign) return false;

	if (a.length > b.length) return a.thesign;
	if (a.length < b.length) return !a.thesign;

	for (int i = a.length - 1; i >= 0; --i) {
		if (a.digits[i] > b.digits[i]) return a.thesign;
		if (a.digits[i] < b.digits[i]) return !a.thesign;
	}

	return (false);
}

// Less than operator
bool operator<(const inf_int& a, const inf_int& b) {
	if (!a.thesign && b.thesign) return true;
	if (a.thesign && !b.thesign) return false;

	if (a.length < b.length) return a.thesign;
	if (a.length > b.length) return !a.thesign;

	for (int i = a.length - 1; i >= 0; --i) {
		if (a.digits[i] > b.digits[i]) return a.thesign;
		if (a.digits[i] < b.digits[i]) return !a.thesign;
	}
	return (false);
}

// Addition operator
inf_int operator+(const inf_int& a, const inf_int& b) {
    if (a.thesign != b.thesign) {
		inf_int a_abs = a.abs();
		inf_int b_abs = b.abs();
		inf_int result = a_abs - b_abs;
		result.thesign = a.thesign ? result.thesign : !result.thesign;
        return result;
    }

    unsigned int max_length = std::max(a.length, b.length);
    char* result_digits = new char[max_length + 1];
    bool carry = false;
    for (unsigned int i = 0; i < max_length; ++i) {
        int sum;
		if (carry)
			sum = 1;
		else
			sum = 0;
        if (i < a.length) sum += a.digits[i];
        if (i < b.length) sum += b.digits[i];
        if (sum > 9) {
			sum -= 10;
			carry = true;
        }
		else
			carry = false;
        result_digits[i] = sum;
    }
    inf_int result;
    if (carry)
	{
        result_digits[max_length] = 1;
		++max_length;
	}
	result.length = max_length;
    result.thesign = a.thesign;
	result.digits = result_digits;
    return result;
}

// Subtraction operator
inf_int operator-(const inf_int& a, const inf_int& b) {
    if (a.thesign != b.thesign) {
		inf_int a_abs = a.abs();
		inf_int b_abs = b.abs();
		inf_int result = a_abs + b_abs;
		result.thesign = a.thesign;
        return result;
    }

	if (a.thesign == false && b.thesign == false) {
		return a + -b;
	}

    const inf_int *big, *small;
    bool resultSign = true;
    if ((a.thesign == true && a > b) || (a.thesign == false && a < b)) {
        big = &a;
        small = &b;
    } else {
        big = &b;
        small = &a;
		resultSign = false;
    }

    char* result_digits = new char[big->length];
    int carry = 0;
    for (unsigned int i = 0; i < big->length; ++i) {
        int diff = big->digits[i] - carry;
        if (i < small->length)
			diff -= small->digits[i];
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
		result_digits[i] = diff;
    }

    int endi;
    for (endi = big->length - 1; endi >= 0 && result_digits[endi] == 0; --endi);
    if (endi == -1) {
        delete[] result_digits;
        return inf_int();
    }
    inf_int result;
	result.digits = result_digits;
	result.length = endi + 1;
    result.thesign = !(resultSign ^ big->thesign);
    return result;
}

// Multiplication operator
inf_int operator*(const inf_int& a, const inf_int& b) {
    std::vector<int> result(a.length + b.length, 0); // maximum length of result

    // Multiply each digit(int) of a with b
    for (unsigned int i = 0; i < a.length; i++) {
        for (unsigned int j = 0; j < b.length; j++) {
            result[i + j] += a.digits[i] * b.digits[j];
        }
    }

    // Make each space of the result have only one digit(0 ~ 9)
    for (unsigned int i = 0; i < result.size() - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    // Convert the result to a string
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back(); // remove the last zero
    }

	unsigned int size = result.size();
    char *result_digits = new char[size];
    for (unsigned int i = 0; i < size; ++i) {
        result_digits[i] = result[i];
    }
//	std::cout << "size : " << result.size() << "\n";
//	std::cout << "results : " << result_digits << "\n";

    inf_int product;
	product.digits = result_digits;
	product.length = size;
	if (product.length == 1 && product.digits[0] == 0)
		product.thesign = true;
	else
    	product.thesign = !(a.thesign ^ b.thesign);
				// Set the sign(+/-) of the result of multiplication
    return product;
}

inf_int operator-(const inf_int& a) {
	inf_int result(a);
	result.thesign = !result.thesign;
	return result;
}

// Output stream operator
std::ostream& operator<<(std::ostream& out, const inf_int& num) {
	inf_int negative_zero;
	negative_zero.thesign = false;
	if (num != negative_zero && !num.thesign) out << '-';
	for (int i = num.length - 1; i >= 0; --i) {
		out << (char)(num.digits[i] + '0');
	}
	return out;
}

inf_int inf_int::abs() const {
	inf_int result(*this);
	if (result.thesign == false)
		result.thesign = !result.thesign;
	return result;
}
