// thêm thư viện 
#include <cppunit/extensions/HelperMacros.h>//macro giúp định nghĩa test dễ dàng
#include <cppunit/ui/text/TestRunner.h>// hiển thị kết quả
#include <cmath>
#include "Logic_bt.h"

// Test class for Calculator
class CalculatorTest : public CppUnit::TestFixture {
    // gọi hàm 
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSubtract);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivide);
    CPPUNIT_TEST(testDivideByZero);
    //CPPUNIT_TEST(testWrongAdd); // test sai
    CPPUNIT_TEST_SUITE_END();

public:
    //chạy trước mỗi test → dùng khi cần khởi tạo biến, dữ liệu.
    void setUp() override {
        // No setup needed for these tests
    }
    //chạy sau mỗi test → dùng để dọn dẹp.
    void tearDown() override {
        // No cleanup needed
    }
    //test phép cộng
    void testAdd() {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0, Calculator::add(2.0, 3.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, Calculator::add(-1.0, 1.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-4.0, Calculator::add(-2.0, -2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(3.5, Calculator::add(1.5, 2.0), 0.0001);
    }
    //test phép trừ
    void testSubtract() {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.0, Calculator::subtract(2.0, 3.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(2.0, Calculator::subtract(1.0, -1.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, Calculator::subtract(-2.0, -2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.5, Calculator::subtract(1.5, 2.0), 0.0001);
    }
    //test nhân 
    void testMultiply() {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(6.0, Calculator::multiply(2.0, 3.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.0, Calculator::multiply(-1.0, 2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(4.0, Calculator::multiply(-2.0, -2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(3.0, Calculator::multiply(1.5, 2.0), 0.0001);
    }
    //test phép chia
    void testDivide() {
        CPPUNIT_ASSERT_DOUBLES_EQUAL(2.0, Calculator::divide(6.0, 3.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.0, Calculator::divide(-4.0, 2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.5, Calculator::divide(1.0, 2.0), 0.0001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.75, Calculator::divide(1.5, 2.0), 0.0001);
    }
    //chia cho 0
    void testDivideByZero() {
        CPPUNIT_ASSERT_THROW(Calculator::divide(5.0, 0.0), std::runtime_error);
        try {
            Calculator::divide(5.0, 0.0);
        }
        catch (const std::runtime_error& e) {
            CPPUNIT_ASSERT(std::string(e.what()) == "Khong the chia cho 0!");
        }
    }
    /*// test sai để minh chứng Unit Test
    void testWrongAdd() {
        // 2 + 2 thực tế = 4, nhưng mình cố tình kiểm tra = 5
        CPPUNIT_ASSERT_DOUBLES_EQUAL(5.0, Calculator::add(2.0, 2.0), 0.0001);
    }*/

};

// Danh sách các test 
CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTest);

// Main function to run the tests
int main() {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    bool wasSuccessful = runner.run("", false);
    return wasSuccessful ? 0 : 1;
}