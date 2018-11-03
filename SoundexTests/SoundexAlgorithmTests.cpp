#include "pch.h"
#include "../Soundex_Cpp_GoogleTest/SoundexAlgorithm.h"

TEST(SoundexAlgorithmTest, WhenTheWordIsEmptyThenReturn0000)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("");
    ASSERT_EQ("0000", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveOneCharThenFillTheWordBy0)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("w");
    ASSERT_EQ("w000", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveUpperCaseThenChangeToLowerCase)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("ABCD");
    ASSERT_EQ("a123", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveFoutCharsWithDifferentNumbersThenReturnEncodedWord)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("bcdm");
    ASSERT_EQ("b235", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveMoreThanOneCharAndLessThanFourCharsThenAdd0)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("an");
    ASSERT_EQ("a500", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveMoreThanFourCharsThenRemoveRedundantChars)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("anrtzv");
    ASSERT_EQ("a563", expected);
}

TEST(SoundexAlgorithmTest, WhenTheWordHaveNeighboringCharsWithTheSameNumberThenRemoveAllThisCharsWitchoutFirst)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("accb");
    ASSERT_EQ("a210", expected);
}

TEST(SoundexAlgorithmTests, WhenTheWordHaveCharsWhichDoNotExistInDictionaryThenRemoveThisChars)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("acob");
    ASSERT_EQ("a210", expected);
}

TEST(SoundexAlgorithmTests, WhenTheWordHaveSpecialCharsThenReplaceThisCharsTo0)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("!%#&");
    ASSERT_EQ("0000", expected);
}

TEST(SoundexAlgorithmTests, WhenInTheWordTwoLettersWithTheSameNumberAreSeparatedByWThenEncodeLikeOneNumber)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("bgwjlm");
    ASSERT_EQ("b245", expected);
}

TEST(SoundexAlgorithmTests, WhenInTheWordTwoLettersWithTheSameNumberAreSeparatedByHThenEncodeLikeOneNumber)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("bghjlm");
    ASSERT_EQ("b245", expected);
}

TEST(SoundexAlgorithmTests, WhenInTheWordTwoLettersWithTheSameNumberAreSeparatedByVowelThenEncodeTwice)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("bditv");
    ASSERT_EQ("b331", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsRobertThenReturnR163)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Robert");
    ASSERT_EQ("r163", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsRuperThenReturnR163)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Rupert");
    ASSERT_EQ("r163", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsRubinThenReturnR150)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Rubin");
    ASSERT_EQ("r150", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsAshcraftThenReturnA261)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Ashcraft");
    ASSERT_EQ("a261", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsAshcroftThenReturnA261)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Ashcroft");
    ASSERT_EQ("a261", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsTymczakThenReturnT522)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Tymczak");
    ASSERT_EQ("t522", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsPfisterThenReturnP123)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Pfister");
    ASSERT_EQ("p123", expected);
}

TEST(SoundexAlgorithmTests, WhentTheWordIsHoneymanThenReturnH555)
{
    SoundexAlgorithm soundex;
    std::string expected = soundex.Encode("Honeyman");
    ASSERT_EQ("h555", expected);
}