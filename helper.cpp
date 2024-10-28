#include <iostream>
#include <string>
#include <filesystem>
#include "helper.h"

helper::helper() = default;

std::string helper::lower(std::string word){
    std::string lowercase;
    for(int i = 0; i < word.length(); i++){
        lowercase += std::tolower(word[i]);
    }
    return lowercase;
}

bool helper::contain_word(std::filesystem::path temp_path, std::string word){
    int len = word.size();
    int i = 0;
    std::string pathname = temp_path.string();

    if(pathname.size() < len){
        return false;
    }

    while(i + (len - 1) < len){
        std::cout << word << ", " << pathname.substr(i, len) << "\n";
        if(pathname.substr(i, len) == word){
            return true;
        }
        i += 1;
    }
    return false;
}