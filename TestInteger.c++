#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

//Integer's operator == test begin
TEST(IntegerFixture,equal_equal_test_1)
{
	Integer<int> num1("11");
	Integer<int> num2(11);
	ASSERT_TRUE(num1==num2);
}
TEST(IntegerFixture,equal_equal_test_2)
{
	Integer<int> num1("0011");
	Integer<int> num2(11);
	ASSERT_TRUE(num1==num2);
}
TEST(IntegerFixture,equal_equal_test_3)
{
	Integer<int> num1("12");
	Integer<int> num2(11);
	ASSERT_FALSE(num1==num2);
}
TEST(IntegerFixture,equal_equal_test_4)
{
	Integer<int> num1(12);
	Integer<int> num2(12);
	ASSERT_TRUE(num1==num2);
}
TEST(IntegerFixture,equal_equal_test_5)
{
	Integer<int> num1("12");
	Integer<int> num2("12");
	ASSERT_TRUE(num1==num2);
}
//Integer's operator == test end

//Integer's operator < test begin
TEST(IntegerFixture, less_than_test_1)
{
	Integer<int> num1(12);
	Integer<int> num2(13);
	ASSERT_TRUE(num1 < num2);
}
TEST(IntegerFixture, less_than_test_2)
{
	Integer<int> num1(13);
	Integer<int> num2(12);
	ASSERT_FALSE(num1 < num2);
}
TEST(IntegerFixture, less_than_test_3)
{
	Integer<int> num1("012");
	Integer<int> num2(100);
	ASSERT_TRUE(num1 < num2);
}
TEST(IntegerFixture, less_than_test_4)
{
	Integer<int> num1("012");
	Integer<int> num2("12");
	ASSERT_FALSE(num1 < num2);
}
TEST(IntegerFixture, less_than_test_5)
{
	Integer<int> num1("012");
	Integer<int> num2("10000");
	ASSERT_TRUE(num1 < num2);
}
//Integer's operator < test end

//Integer's operator << test begin
TEST(IntegerFixture, output_test_1)
{
	Integer<int> num("000001");
	ostringstream w;
	w << num;
	ASSERT_EQ("1",w.str());
}
TEST(IntegerFixture, output_test_2)
{
	Integer<int> num("1");
	ostringstream w;
	w << num;
	ASSERT_EQ("1",w.str());
}
TEST(IntegerFixture, output_test_3)
{
	Integer<int> num("123456789");
	ostringstream w;
	w << num;
	ASSERT_EQ("123456789",w.str());
}
TEST(IntegerFixture, output_test_4)
{
	Integer<int> num("0");
	ostringstream w;
	w << num;
	ASSERT_EQ("0",w.str());
}
TEST(IntegerFixture, output_test_5)
{
	Integer<int> num("-123456789");
	ostringstream w;
	w << num;
	ASSERT_EQ("-123456789",w.str());
}
//Integer's operator << test end

//Integer's valid test begin
TEST(IntegerFixture, valid_1)
{
	Integer<int> num("123456789");
	ASSERT_TRUE(num.valid());
}
TEST(IntegerFixture, valid_2)
{
	Integer<int> num("a");
	ASSERT_FALSE(num.valid());
}
TEST(IntegerFixture, valid_3)
{
	Integer<int> num("-123");
	ASSERT_TRUE(num.valid());
}
TEST(IntegerFixture, valid_4)
{
	Integer<int> num("0");
	ASSERT_TRUE(num.valid());
}
TEST(IntegerFixture, valid_5)
{
	Integer<int> num("-");
	ASSERT_FALSE(num.valid());
}
//Integer's valid test end

//Integer(int value) test begin
TEST(IntegerFixture, constructor_int_1)
{
	Integer<int> num(123);
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, constructor_int_2)
{
	Integer<int> num(-123);
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("-123",w.str());
}
TEST(IntegerFixture, constructor_int_3)
{
	Integer<int> num(10);
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("10",w.str());
}
TEST(IntegerFixture, constructor_int_4)
{
	Integer<int> num(0);
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("0",w.str());
}
TEST(IntegerFixture, constructor_int_5)
{
	Integer<int> num(1);
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("1",w.str());
}
//Integer(int value) test end

//Integer(string value) test begin
TEST(IntegerFixture, constructor_string_1)
{
	Integer<int> num("123");
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, constructor_string_2)
{
	Integer<int> num("-123");
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("-123",w.str());
}
TEST(IntegerFixture, constructor_string_3)
{
	Integer<int> num("0000000000000123");
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, constructor_string_4)
{
	Integer<int> num("101010110101");
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("101010110101",w.str());
}
TEST(IntegerFixture, constructor_string_5)
{
	Integer<int> num("0000000000000");
	ostringstream w;
	ASSERT_TRUE(num.valid());
	w << num;
	ASSERT_EQ("0",w.str());
}
//Integer(string value) test bend

//Integer's operator - test begin
TEST(IntegerFixture,negative_test_1)
{
	Integer<int> num(2);
	num = -num;
	ostringstream w;
	w << num;
	ASSERT_EQ("-2",w.str());
}
TEST(IntegerFixture,negative_test_2)
{
	Integer<int> num(-2);
	num = -num;
	ostringstream w;
	w << num;
	ASSERT_EQ("2",w.str());
}
TEST(IntegerFixture,negative_test_3)
{
	Integer<int> num("2");
	num = -num;
	ostringstream w;
	w << num;
	ASSERT_EQ("-2",w.str());
}
TEST(IntegerFixture,negative_test_4)
{
	Integer<int> num("-2");
	num = -num;
	ostringstream w;
	w << num;
	ASSERT_EQ("2",w.str());
}
TEST(IntegerFixture,negative_test_5)
{
	Integer<int> num("-1");
	num = -num;
	ostringstream w;
	w << num;
	ASSERT_EQ("1",w.str());
}
//Integer's operator - test end

//Integer's operator += test begin
TEST(IntegerFixture, plus_equal_test_1)
{
	ostringstream w;
	Integer<int> a("15");
	Integer<int> b("100");
	a+=b;
	w << a;
	ASSERT_EQ("115",w.str());
}
TEST(IntegerFixture, plus_equal_test_2)
{
	ostringstream w;
	Integer<int> a("6");
	Integer<int> b("7");
	a+=b;
	w << a;
	ASSERT_EQ("13",w.str());
}
TEST(IntegerFixture, plus_equal_test_3)
{
	ostringstream w;
	Integer<int> a("100");
	Integer<int> b("3");
	a+=b;
	w << a;
	ASSERT_EQ("103",w.str());
}
TEST(IntegerFixture, plus_equal_test_4)
{
	ostringstream w;
	Integer<int> a("999");
	Integer<int> b("1");
	a+=b;
	w << a;
	ASSERT_EQ("1000",w.str());
}
TEST(IntegerFixture, plus_equal_test_5)
{
	ostringstream w;
	Integer<int> a("1");
	Integer<int> b("0");
	a+=b;
	w << a;
	ASSERT_EQ("1",w.str());
}
//Integer's operator += test end

//Integer's operator -= test begin
TEST(IntegerFixture, minus_equal_test_1)
{
	ostringstream w;
	Integer<int> a("8");
	Integer<int> b("3");
	a-=b;
	w << a;
	ASSERT_EQ("5",w.str());
}
TEST(IntegerFixture, minus_equal_test_2)
{
	ostringstream w;
	Integer<int> a("100");
	Integer<int> b("3");
	a-=b;
	w << a;
	ASSERT_EQ("97",w.str());
}
TEST(IntegerFixture, minus_equal_test_3)
{
	ostringstream w;
	Integer<int> a(136);
	Integer<int> b(135);
	a-=b;
	w << a;
	ASSERT_EQ("1",w.str());
}
TEST(IntegerFixture, minus_equal_test_4)
{
	ostringstream w;
	Integer<int> a(136);
	Integer<int> b(136);
	a-=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
TEST(IntegerFixture, minus_equal_test_5)
{
	ostringstream w;
	Integer<int> a("1000");
	Integer<int> b("3");
	a-=b;
	w << a;
	ASSERT_EQ("997",w.str());
}
//Integer's operator -= test end

//Integer's operator *= test begin
TEST(IntegerFixture, multiply_equal_test_1)
{
	ostringstream w;
	Integer<int> a(5);
	Integer<int> b(12);
	a*=b;
	w << a;
	ASSERT_EQ("60",w.str());
}
TEST(IntegerFixture, multiply_equal_test_2)
{
	ostringstream w;
	Integer<int> a(12);
	Integer<int> b(12);
	a*=b;
	w << a;
	ASSERT_EQ("144",w.str());
}
TEST(IntegerFixture, multiply_equal_test_3)
{
	ostringstream w;
	Integer<int> a(12);
	Integer<int> b(1);
	a*=b;
	w << a;
	ASSERT_EQ("12",w.str());
}
TEST(IntegerFixture, multiply_equal_test_4)
{
	ostringstream w;
	Integer<int> a(1);
	Integer<int> b(12);
	a*=b;
	w << a;
	ASSERT_EQ("12",w.str());
}
TEST(IntegerFixture, multiply_equal_test_5)
{
	ostringstream w;
	Integer<int> a(12);
	Integer<int> b(0);
	a*=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
//Integer's operator *= test end

//Integer's operator /= test begin
TEST(IntegerFixture, divide_equal_test_1)
{
	ostringstream w;
	Integer<int> a(60);
	Integer<int> b(12);
	a/=b;
	w << a;
	ASSERT_EQ("5",w.str());
}
TEST(IntegerFixture, divide_equal_test_2)
{
	ostringstream w;
	Integer<int> a(101);
	Integer<int> b(4);
	a/=b;
	w << a;
	ASSERT_EQ("25",w.str());
}
TEST(IntegerFixture, divide_equal_test_3)
{
	ostringstream w;
	Integer<int> a(3);
	Integer<int> b(4);
	a/=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
TEST(IntegerFixture, divide_equal_test_4)
{
	ostringstream w;
	Integer<int> a(60);
	Integer<int> b(60);
	a/=b;
	w << a;
	ASSERT_EQ("1",w.str());
}
TEST(IntegerFixture, divide_equal_test_5)
{
	ostringstream w;
	Integer<int> a(0);
	Integer<int> b(12);
	a/=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
//Integer's operator /= test end

//Integer's operator %= test begin
TEST(IntegerFixture, mod_equal_test_1)
{
	ostringstream w;
	Integer<int> a(3);
	Integer<int> b(4);
	a%=b;
	w << a;
	ASSERT_EQ("3",w.str());
}
TEST(IntegerFixture, mod_equal_test_2)
{
	ostringstream w;
	Integer<int> a(5);
	Integer<int> b(4);
	a%=b;
	w << a;
	ASSERT_EQ("1",w.str());
}
TEST(IntegerFixture, mod_equal_test_3)
{
	ostringstream w;
	Integer<int> a(60);
	Integer<int> b(5);
	a%=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
TEST(IntegerFixture, mod_equal_test_4)
{
	ostringstream w;
	Integer<int> a(10);
	Integer<int> b(4);
	a%=b;
	w << a;
	ASSERT_EQ("2",w.str());
}
TEST(IntegerFixture, mod_equal_test_5)
{
	ostringstream w;
	Integer<int> a(0);
	Integer<int> b(4);
	a%=b;
	w << a;
	ASSERT_EQ("0",w.str());
}
//Integer's operator %= test end

//Integer's operator <<= test begin
TEST(IntegerFixture, left_shift_equal_test_1)
{
	ostringstream w;
	Integer<int> num("123");
	num<<=(1);
	w << num;
	ASSERT_EQ("1230",w.str());
}
TEST(IntegerFixture, left_shift_equal_test_2)
{
	ostringstream w;
	Integer<int> num("123");
	num<<=(2);
	w << num;
	ASSERT_EQ("12300",w.str());
}
TEST(IntegerFixture, left_shift_equal_test_3)
{
	ostringstream w;
	Integer<int> num("123");
	num<<=(0);
	w << num;
	ASSERT_EQ("123",w.str());
}
//Integer's operator <<= test end

//Integer's operator >>= test begin
TEST(IntegerFixture, right_shift_equal_test_1)
{
	ostringstream w;
	Integer<int> num("123");
	num>>=(0);
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, right_shift_equal_test_2)
{
	ostringstream w;
	Integer<int> num("123");
	num>>=(1);
	w << num;
	ASSERT_EQ("12",w.str());
}
TEST(IntegerFixture, right_shift_equal_test_3)
{
	ostringstream w;
	Integer<int> num("123");
	num>>=(2);
	w << num;
	ASSERT_EQ("1",w.str());
}
//Integer's operator >>= test end

//Integer's abs test begin
TEST(IntegerFixture, abs_1)
{
	ostringstream w;
	Integer<int> num("123");
	num = num.abs();
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, abs_2)
{
	ostringstream w;
	Integer<int> num("-123");
	num = num.abs();
	w << num;
	ASSERT_EQ("123",w.str());
}
TEST(IntegerFixture, abs_3)
{
	ostringstream w;
	Integer<int> num(-123);
	num = num.abs();
	w << num;
	ASSERT_EQ("123",w.str());
}
//Integer's abs test end

//Integer's pow test begin
TEST(IntegerFixture, pow_1)
{
	ostringstream w;
	Integer<int> num(2);
	num = num.pow(1);
	w << num;
	ASSERT_EQ("2",w.str());
}
TEST(IntegerFixture, pow_2)
{
	ostringstream w;
	Integer<int> num(2);
	num = num.pow(10);
	w << num;
	ASSERT_EQ("1024",w.str());
}
TEST(IntegerFixture, pow_3)
{
	ostringstream w;
	Integer<int> num(2);
	num = num.pow(0);
	w << num;
	ASSERT_EQ("1",w.str());
}
//Integer's pow test end














