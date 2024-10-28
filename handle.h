#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include "helper.h"

class handler {
    private:
        std::string source;
        std::string destination;
        helper help;

    public:
        handler(std::string source, std::string destination);

        bool check();

        std::string getsource();

        std::string getdestination();

        void changesource(std::string newsource);

        void changedest(std::string newdest);
        
        // function to transfer every file from the source directory to the destination directory 
        void transfer_all(std::string format, std::string all);

        // function for transfer of files when user wants to transfer all files of a specific extension from source to destination directory
        void transfer_extensions(std::string format, std::string all);

        // function to transfer all files that has the word in it from source to destination 
        void transfer_name(std::string format, std::string all);
};