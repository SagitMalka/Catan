//
// Created by SAGIT on 22/06/2024.
//

#pragma once

#include <vector>
#include <memory>
#include <iostream>

namespace model
{
    int getUserChoice(size_t  options_size)
    {
        int choice = 0;

        while (true) {
            std::cout << "Enter the number corresponding to your choice: ";
            std::cin >> choice;

            if (choice > 0 && choice <= options_size) {
                return choice;
            } else {
                std::cout << "Invalid choice. Please select a number between 1 and " << options_size << ".\n";
            }
        }
    }
}
