#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5.5/Pr5.5.cpp" // файл з функцією Lim (шлях замініть на свій)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5_5
{
    TEST_CLASS(UnitTest5_5)
    {
    public:

        // 1. Межа послідовності дорівнює 2
        TEST_METHOD(LimitIsTwo)
        {
            int depth = 0;
            double L = Lim(1.0, 1, depth, 1e-6);
            Assert::AreEqual(2.0, L, 1e-6);
        }

        // 2. Глибина рекурсії для eps = 1e-6 дорівнює 7
        TEST_METHOD(DepthForSmallEps)
        {
            int depth = 0;
            Lim(1.0, 1, depth, 1e-6);
            Assert::AreEqual(7, depth);
        }

        // 3. Для грубішої точності eps = 1e-3 глибина менша: 6
        TEST_METHOD(DepthForLargeEps)
        {
            int depth = 0;
            double L = Lim (1.0, 1, depth, 1e-3);
            Assert::AreEqual(6, depth);
            Assert::AreEqual(2.0, L, 1e-3);
        }

        // 4. Якщо починати з самої межі (a = 2), рекурсія закінчується одразу
        TEST_METHOD(StartAtLimit)
        {
            int depth = 0;
            double L = Lim(2.0, 1, depth, 1e-6);
            Assert::AreEqual(2.0, L, 1e-12);
            Assert::AreEqual(1, depth);
        }
    };
}