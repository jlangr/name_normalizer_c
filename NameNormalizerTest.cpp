#include "CppUTest/TestHarness.h"

#include "NameNormalizer.h"

TEST_GROUP(ANameNormalizer) {};

TEST(ANameNormalizer, ReturnsEmptyStringWhenEmpty) {
   STRCMP_EQUAL("", NameNormalizer_Convert(""));
}

TEST(ANameNormalizer, ReturnsLastFirstWhenFirstLastProvided) {
   STRCMP_EQUAL("Heller, Joseph", NameNormalizer_Convert("Joseph Heller"));
   STRCMP_EQUAL("Murakami, Haruki", NameNormalizer_Convert("Haruki Murakami"));
}

TEST(ANameNormalizer, ReturnsSingleWordName) {
   STRCMP_EQUAL("Plato", NameNormalizer_Convert("Plato"));
}

TEST(ANameNormalizer, TrimsWhitespace) {
   STRCMP_EQUAL("Boi, Big", NameNormalizer_Convert("  Big Boi   "));
}

TEST(ANameNormalizer, InitializesMiddleName) {
   STRCMP_EQUAL("Thoreau, Henry D.", NameNormalizer_Convert("Henry David Thoreau"));
}

TEST(ANameNormalizer, DoesNotInitializeOneLetterMiddleName) {
   STRCMP_EQUAL("Truman, Harry S", NameNormalizer_Convert("Harry S Truman"));
}

TEST(ANameNormalizer, InitializesEachOfMultipleMiddleNames) {
   STRCMP_EQUAL("Louis-Dreyfus, Julia S. E.", NameNormalizer_Convert("Julia Scarlett Elizabeth Louis-Dreyfus"));
}

/*
TEST(ANameNormalizer, AppendsSuffixesToEnd) {
   STRCMP_EQUAL("King, Martin L., Jr.", NameNormalizer_Convert("Martin Luther King, Jr."));
}

TEST(ANameNormalizer, ThrowsWhenNameContainsTwoCommas) {
// proper way to do in C?
   NameNormalizer_Convert("Thurston, Howell, III");
}
*/
