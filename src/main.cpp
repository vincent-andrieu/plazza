/*
 * EPITECH PROJECT, 2021
 * src
 * File description:
 * main.cpp - Created: 21/04/2021
 */

#include <memory>
#include <cstring>
#include "Plazza.hpp"

#include "Kitchen/Kitchen.hpp"
#include "CoreDisplay/CoreDisplay.hpp"

void printHelp(const string binaryName)
{
    std::cout << "USAGE:\t" << binaryName << " COOKING_TIME COOKS STOCK_RELOAD" << std::endl
              << "\tCOOKING_TIME:\tMultiplier for the cooking time." << std::endl
              << "\tCOOKS:\t\tNumber of cooks per kitchen." << std::endl
              << "\tSTOCK_RELOAD:\tTime in milliseconds, used by the kitchen stock to replace ingredients." << std::endl;
}

int main(int argc, char **argv)
{
    /*CoreDisplay *tmp = new CoreDisplay(argv[1], Vector(1400, 900), Vector(9.95, 21.6));
    std::shared_ptr<Kitchen> one = std::make_unique<Kitchen>(0.5, 1, 2);
    std::shared_ptr<Kitchen> two = std::make_unique<Kitchen>(0.9, 2, 3);
    std::vector<std::shared_ptr<IKitchen>> tab;

    while (one->isChild())
        sleep(10);
    while (two->isChild())
        sleep(10);
    tab.push_back(one);
    tab.push_back(two);
    tmp->setPrompt("&> ");
    tmp->setLine("wut");
    while (1) {
        tmp->clear();
        tmp->printPrompt();
        tmp->printKitchen(tab);
        tmp->printDetailledKitchen(one);
        tmp->update();
    }
    delete tmp;*/
    if (argc != 4) {
        printHelp(argv[0]);
        return argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) ? EXIT_SUCCESS : EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}