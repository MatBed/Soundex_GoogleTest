#include "pch.h"
#include "SoundexData.h"

SoundexData::SoundexData()
{
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("b", "1"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("f", "1"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("p", "1"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("v", "1"));

    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("c", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("g", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("j", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("k", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("q", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("s", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("x", "2"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("z", "2"));

    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("d", "3"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("t", "3"));

    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("l", "4"));

    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("m", "5"));
    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("n", "5"));

    SoundexData::charToNumber.insert(std::pair<std::string, std::string>("r", "6"));
}

