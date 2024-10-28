#pragma once
#include <iostream>
#include <string>
#include <filesystem>

class helper{

    public:
        helper();

        std::string lower(std::string word);

        bool contain_word(std::filesystem::path temp_path, std::string word);
};