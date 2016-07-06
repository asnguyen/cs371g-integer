// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <sstream>
#include <array>

using namespace std;

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
    // <your code>
    for(int i = 0;i<n;++i)
        {
            *x = 0;
            ++x;
        }
        while(b!=e)
        {
            *x = *b;
            ++x;
            ++b;
        }
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
    // <your code>
    for(int i = 0; i<n;++i)
        {
            ++b;
        }
        while(b!=e)
        {
            *x = *b;
            ++x;
            ++b;
        }
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    int carry = 0;
    while( b1!=e1 && b2!=e2 )
    {
        int a = *b1;
        int b = *b2;
        int c = a+b+carry;
        carry=0;
        if(c>9)
        {
            carry=1;
            *x = c%10;
        }
        else
        {
            *x = c;
        }
        ++x;
        ++b1;
        ++b2;
    }
    while(b1!=e1)
    {
        int a = *b1+carry;
        carry = 0;
        if(a > 9)
        {
            carry = 1;
            *x = a %10;
        }
        else
        {
            *x = a;
        }
        ++b1;
        ++x;
    }
    while(b2!=e2)
    {
        int a = *b2+carry;
        carry = 0;
        if(a > 9)
        {
            carry = 1;
            *x = a %10;
        }
        else
        {
            *x = a;
        }
        ++b2;
        ++x;
    }
    *x = carry;
    //++x;
    
    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
        // <your code>
        int borrow=0;
        while( b1!=e1 && b2!=e2 )
        {
            int a = (*b1) - borrow;
            borrow = 0;
            int b = *b2;
            if(a<b || a < 0)
            {
                borrow=1;
                a+=10;
                *x = a-b;
            }
            else
            {
                *x = a-b;
            }
            ++b1;
            ++b2;
            ++x;
        }
        while(b1!=e1)
        {
            int a = *b1 - borrow;
            borrow = 0;
            if(a < 0)
            {
                borrow = 1;
                a+=10;
                *x = a;
            }
            else
            {
                *x = a;
            }
            ++x;
            ++b1;
        }
        return x;
    }

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
        int carry = 0;
        while(b1!=e1)
        {
            int a = *b1;
            int b = *b2;
            int c = (a*b)+carry;
            carry = 0;
            if(c>9)
            {
                carry=c/10;
                *x = c%10;
            }
            else
            {
                *x = c;
            }
            ++x;
            ++b1;
        }
        *x = carry;
        ++x;
        return x;
    }

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal _x
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    // <your code>
    {
        int r=0;
        int count =0;
        while(b1!=e1)
        {
            int a = (r*10) + (*b1);
            r = 0;
            int b = *b2;
            if(a<b)
            {
                ++b1;
                ++x;
                a=(a*10)+(*b1);
                *x = a / b;
                r = a % b;
            }
            else
            {
                *x = a / b;
                r = a % b;
            }
            ++x;
            ++b1;
            ++count;

        }
        return x;
    }
    return x;}

// -------
// Integer
// -------

template <typename T, typename C = std::vector<T>>
class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * <your documentation>
     this function compares lhs with rhs and ignores leading zeroes. it 
     uses the equal function that c++ provides
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {

            ostringstream sleft;
            ostringstream sright;

            sleft  << lhs;
            //return false;
            sright << rhs;
            
            Integer<T,C> left(sleft.str());
            Integer<T,C> right(sright.str());
            if(left._x.size()!=right._x.size())
                return false;
            return equal((left._x).begin(), (left._x).end(), (right._x).begin());
        }

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
       ostringstream sleft;
            ostringstream sright;
            sleft  << lhs;
            sright << rhs;
            Integer<T,C> left(sleft.str());
            Integer<T,C> right(sright.str());
            if(left == right)
                return false;
            if(left._x.size()>right._x.size())          //left has more _x than right
                return false;
            if(right._x.size() > left._x.size())        //right has more _x than left
                return true;
            for(int i = right._x.size()-1;i>=0;--i)         //right and left have the same Integer of _x
            {
                if(left._x[i]>right._x[i])
                    return false;
            }
            return true;
        }

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        bool leading_zero =true;
        
        if(rhs.negative) lhs << "-";
        for(int i = rhs._x.size()-1;i>=0;--i)
        {
            if(rhs._x[i]!=0)
                  leading_zero = false;
                if(!leading_zero)
                    lhs << rhs._x[i];
            }
            if(leading_zero)
                lhs << 0;
            return lhs;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}

    public:
        // ----
        // data
        // ----

        C _x; // the backing container
        bool negative = false;
        // <your data>

    public:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            if(_x.empty())
                return false;
            for(auto i : _x)
            {
                if(i>9 || i<0)
                    return false;
            }
            return true;}

    public:
        // ------------
        // constructors
        // ------------
        Integer()
        {
            string s = to_string(0);
            auto a = s.rbegin();
            auto b = s.rend();
            while(a!=b)
            {
                int i = *a - '0';
                _x.push_back(i);
                ++a;
            }
            //ssert(valid());
        }
        /**
         * <your documentation>
         */
        Integer (int value) {
            // <your code>
            string s = to_string(value);
            auto a = s.rbegin();
            auto b = s.rend();
            while(a!=b)
            {
                if(*a == '-')
                    negative = !negative;
                else
                {
                    int i = *a - '0';
                    _x.push_back(i);
                }
                ++a;
            }
            //assert(valid());
        }

        /**
         * <your documentation>
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
            auto a = value.rbegin();
            auto b = value.rend();
            while(a!=b)
            {
                if(*a == '-')
                    negative = !negative;
                else
                {
                    int i = *a - '0';
                    _x.push_back(i);
                }
                ++a;
            }
            }

                 Integer    (const Integer&) = default;
                 ~Integer   ()               = default;
        Integer& operator = (const Integer&) = default;

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            ostringstream w;
            if((*this).negative)                    //if Integer is negative
            {
                w << "-" <<*this;
            }
            else                                //Integer is positve
            {
                w << "-" << *this;
            }
            Integer<T,C> output(w.str());
            return output;} // fix

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            Integer<T,C> output("0");
            //cout << *this << " + " << rhs << " ";
            output._x.resize((*this)._x.size()+rhs._x.size(),0);
            plus_digits( (*this)._x.begin(), (*this)._x.end(),
                         (rhs )._x.begin(), (rhs )._x.end(),
                         output._x.begin()
                       ); 
            //cout << output << "\n";
            return *this = output;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            Integer<T,C> output("0");
            output._x.resize((*this)._x.size(),0);
            minus_digits( (*this)._x.begin(), (*this)._x.end(),
                          ( rhs )._x.begin(), ( rhs )._x.end(),
                          output._x.begin()
                        );
            return *this = output;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            Integer<T,C> output("0");
            Integer Multiply_table[10];
            for(int i=0;i<10;++i)
            {
                Integer <T,C> temp(i);
                Multiply_table[i]._x.resize((*this)._x.size()+rhs._x.size(),0);

                multiplies_digits( (*this)._x.begin(), (*this)._x.end(),
                                   ( temp)._x.begin(), ( temp)._x.end(),
                                   Multiply_table[i]._x.begin()
                                 );
            }
            int digit = rhs._x[0];
            output+=Multiply_table[digit];
            for(int i = 1; i<rhs._x.size();++i)
            {
                digit = rhs._x[i];
                Integer<T,C> temp;
                temp._x.resize(Multiply_table[digit]._x.size()+i,0);
                shift_left_digits(Multiply_table[digit]._x.begin(),
                                  Multiply_table[digit]._x.end(), i,
                                  temp._x.begin()
                                 );
                output+=temp;

            }
            return *this = output;
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            //Integer<T,C> quotient(0);
            int count =0;
            //quotient._x.resize((*this)._x.size(),0);
            while(*this>=rhs)
            {
                *this-=rhs;
                //quotient+=1;
                ++count;
            }
            Integer<T,C> quotient(count);
            quotient._x.resize((*this)._x.size(),0);
            return *this = quotient;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            while(*this>=rhs)
            {
                *this -= rhs;
            }
            return *this;
        }

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            Integer<T,C> output;
            output._x.resize((*this)._x.size()+n,0);
            shift_left_digits((*this)._x.begin(),(*this)._x.end(),n,output._x.begin());
            return *this = output;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            Integer<T,C> output;
            output._x.resize((*this)._x.size()+n,0);
            shift_right_digits((*this)._x.begin(),(*this)._x.end(),n,output._x.begin());
            return *this = output;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            ostringstream sthis;
            bool temp = (*this).negative;
            (*this).negative = false;
            sthis << *this;
            Integer<T,C> output(sthis.str());
            (*this).negative = temp;
            return *this = output;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            Integer<T,C> output("1");
            for(int i = 0;i<e;++i)
            {
                output *= *this; 
            }

            return *this = output;}};

#endif // Integer_h
