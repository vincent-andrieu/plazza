/*
 * EPITECH PROJECT, 2021
 * src
 * File description:
 * main.cpp - Created: 21/04/2021
 */

#include <cstring>
#include "Plazza.hpp"
#include "Restaurant/Restaurant.hpp"

static void printHelp(const string &binaryName)
{
    std::cout << "USAGE:\t" << binaryName << " COOKING_TIME COOKS STOCK_RELOAD" << std::endl
              << "\tCOOKING_TIME:\tMultiplier for the cooking time." << std::endl
              << "\tCOOKS:\t\tNumber of cooks per kitchen." << std::endl
              << "\tSTOCK_RELOAD:\tTime in milliseconds, used by the kitchen stock to replace ingredients." << std::endl;
}

static bool isNumber(const string &str)
{
    return !str.empty() && std::find_if(str.begin(), str.end(), [](unsigned char c) {
        return !std::isdigit(c);
    }) == str.end();
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        printHelp(argv[0]);
        return argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) ? EXIT_SUCCESS : EXIT_ERROR;
    }

    if (!isNumber(argv[1]) || !isNumber(argv[2]) || !isNumber(argv[3]))
        return EXIT_ERROR;

    double bakingMultiplier;
    size_t cooksPerKitchen;
    double restockTime;

    stringstream(argv[1]) >> bakingMultiplier;
    stringstream(argv[2]) >> cooksPerKitchen;
    stringstream(argv[3]) >> restockTime;
    if (bakingMultiplier == 0.0)
        return EXIT_ERROR;

    Restaurant<PizzaType, PizzaSize, PizzaIngredient> restaurant(bakingMultiplier, cooksPerKitchen, restockTime);
    try {
        restaurant.lunchTime();
    } catch (const ManageError &e) {
        std::cerr << e.getComponent() + ": " + e.what() << std::endl;
        return EXIT_ERROR;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}