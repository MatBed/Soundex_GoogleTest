#pragma once
#include<iostream>
#include "SoundexData.h"

class SoundexAlgorithm
{
public:    
    SoundexData soundexData; 
    std::string Encode(std::string);
    void TrimString(std::string& word);
    std::string EncodeWord(std::string, std::map<std::string, std::string>);

    std::string RemoveDuplicatedChars(std::string word);
    bool AreTwoCharsWithTheSameNumber(char firstChar, char secondChar, std::map<std::string, std::string>);
};

