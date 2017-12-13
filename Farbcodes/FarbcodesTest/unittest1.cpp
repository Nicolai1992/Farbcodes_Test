#include "CppUnitTest.h"
#include "..\Farbcodes\Farbcodes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FarbcodesTest {
    TEST_CLASS(UnitTest1) {
public:

    TEST_METHOD(Testohm) {
        Resistor R(100);
        Assert::AreEqual(100.0f, R.ohm(), L"Test failed", LINE_INFO());
    }

    };
}