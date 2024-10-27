#include <iostream>
#include "handle.cpp"


int main(int argc, char* argv[]){
    std::string source, destination, extension, all, check;
    bool exit = false;

    while(exit == false){
        std::cout << "Please enter the souce path: ";
        std::getline(std::cin, source);
        std::cout << "Please enter the destination path: ";
        std::getline(std::cin, destination);

        handler transfer(source, destination);
        helper help;

        if(transfer.check() == false){
            std::cout << std::endl;
            continue;
        }

        std::cout << "Enter the extension of the files you want to move (type in all if you does not have a preference): ";
        std::getline(std::cin, extension);
        std::cout << "Enter the keyword of the files you want to move (type in all if you does not have a preference): ";
        std::getline(std::cin, all);

        extension = help.lower(extension);
        all = help.lower(all);


        if(extension == "all" && all == "all"){
            transfer.transfer_all(extension, all);
        }
        else if(extension == "all" && all != "all"){
            transfer.transfer_name(extension, all);
        }
        else{
            transfer.transfer_extensions(extension, all);
        }

        std::cout << "Transfer completed, do you want to exit (Y or N): ";
        std::getline(std::cin, check);

        if(check == "Y"){
            std::cout << "Thank you for using this application, have a great day!";
            exit = true;
        }
        std::cout << "\n";

    }
}