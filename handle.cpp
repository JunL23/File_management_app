#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include "helper.cpp"

class handler {
    private:
        std::string source;
        std::string destination;
        helper help;

        std::string lower(std::string word){
            std::string lowercase;
            for(int i = 0; i < word.length(); i++){
                lowercase += std::tolower(word[i]);
            }
            return lowercase;
        }

    public:
        handler(std::string source, std::string destination){
            this->source = source;
            this->destination = destination;
        }

        bool check(){
            std::filesystem::path source_path = source;
            std::filesystem::path destination_path = destination;

            bool start = std::filesystem::exists(source_path);
            bool end = std::filesystem::exists(destination_path);

            if(start == true && end == true){
                return true;
            }
            else if(start == false && end == false){
                std::cout << "Both path is invalid, please check again." << std::endl;
            }
            else if(start == false){
                std::cout << "Source path is invalid, please check again." << std::endl;
            }
            else{
                std::cout << "Destination path is invalid, please check again." << std::endl;
            }

            return false;
        }

        std::string getsource(){
            return this->source;
        }

        std::string getdestination(){
            return this->destination;
        }

        void changesource(std::string newsource){
            this->source = newsource;
        }

        void changedest(std::string newdest){
            this->destination = newdest;
        }
        
        // function to transfer every file from the source directory to the destination directory 
        void transfer_all(std::string format, std::string all){
            std::filesystem::path dest = destination;

            for(auto const& dir : std::filesystem::directory_iterator(source)){
                std::filesystem::path temp = destination / dir.path().filename();
                std::filesystem::rename(dir.path(), temp);
            }
        }

        // function for transfer of files when user wants to transfer all files of a specific extension from source to destination directory
        void transfer_extensions(std::string format, std::string all){
            std::filesystem::path dest = destination;

            if(all == "all"){
                for(auto const& dir : std::filesystem::directory_iterator(source)){
                    if(help.contain_word(dir.path().extension(), format) == true){
                        std::filesystem::path temp = destination / dir.path().filename();
                        std::filesystem::rename(dir.path(), temp);
                    }
                }
            }

            // transfer all files with same extension and name into destination file
            else{
                for(auto const& dir : std::filesystem::directory_iterator(source)){
                    if(help.contain_word(dir.path().extension(), format) == true && help.contain_word(dir.path().filename(), all) == true){
                        std::filesystem::path temp = destination / dir.path().filename();
                        std::filesystem::rename(dir.path(), temp);
                    }
                }
            }
        }

        // function to transfer all files that has the word in it from source to destination 
        void transfer_name(std::string format, std::string all){
            std::filesystem::path dest = destination;

            for(auto const& dir : std::filesystem::directory_iterator(source)){
                if(help.contain_word(dir.path().filename(), all) == true){
                    std::cout << dir.path().filename() << "\n";
                    std::filesystem::path temp = destination / dir.path().filename();
                    std::filesystem::rename(dir.path(), temp);
                }
            }
        }
};