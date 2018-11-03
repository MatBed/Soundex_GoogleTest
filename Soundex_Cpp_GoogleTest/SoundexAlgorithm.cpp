#include "pch.h"
#include "SoundexAlgorithm.h"
#include <algorithm>
#include <string> 

std::string SoundexAlgorithm::Encode(std::string word)
{
    if (word.empty())
        return "0000";

    if (word.length() == 1)
        return word + "000";

    for (int i = 0; i < word.length(); i++)
        if (!((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)))
            return "0000";

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    std::string encodedWord = EncodeWord(word, soundexData.charToNumber);
    TrimString(encodedWord);

    return encodedWord;
}

void SoundexAlgorithm::TrimString(std::string& word)
{
    if (word.length() > 4)
        word = word.substr(0, 4);
    else if (word.length() < 4)
    {
        do
        {
            word += "0";
        } while (word.length() < 4);
    }
}

std::string SoundexAlgorithm::EncodeWord(std::string word, std::map<std::string, std::string> charToNumber)
{
    std::string encodedWord = "";
    encodedWord += word[0];

    for (int i = 1; i < word.length(); i++)
    {
        char letter = word[i];
        std::string charToString(1, letter);

        if (i > 1 && (word[i - 1] == 'w' || word[i - 1] == 'h')
            && AreTwoCharsWithTheSameNumber(word[i - 2], word[i], charToNumber))
            continue;

        else if (charToNumber.find(charToString) != charToNumber.end())
        {
            encodedWord += charToNumber[charToString];
            bool temp = AreTwoCharsWithTheSameNumber(word[i], word[i - 1], charToNumber);

            if (i > 1)
                if (temp)
                    encodedWord = RemoveDuplicatedChars(encodedWord);

        }

        else if ((AreTwoCharsWithTheSameNumber(word[i - 1], word[i + 1], charToNumber)
                && (word[i] == 'w' || word[i] == 'h'))
                || (AreTwoCharsWithTheSameNumber(word[i], word[i + 1], charToNumber))
                && i > word.length() - 1)
            encodedWord = RemoveDuplicatedChars(encodedWord);
    }

    return encodedWord;
}

std::string SoundexAlgorithm::RemoveDuplicatedChars(std::string word)
{
    int current = 0;
    int last = 0;

    for (; word[current]; current++)
        if (word[last] != word[current])
            word[++last] = word[current];

    word = word.substr(0, last + 1);

    return word;
}

bool SoundexAlgorithm::AreTwoCharsWithTheSameNumber(char firstChar, char secondChar, std::map<std::string, std::string> charToNumber)
{
    std::string stringFirstChar(1, firstChar);
    std::string stringSecondChar(1, secondChar);

    if (charToNumber.find(stringFirstChar) != charToNumber.end() && charToNumber.find(stringSecondChar) != charToNumber.end())
    {
        std::string valueOfFirstChar = charToNumber[stringFirstChar];
        std::string valueOfSecondChar = charToNumber[stringSecondChar];

        if (valueOfFirstChar == valueOfSecondChar)
            return true;
    }

    return false;
}


