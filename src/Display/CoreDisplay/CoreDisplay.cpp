/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.cpp - Created: 21/04/2021
 */

#include "CoreDisplay.hpp"
#include "Logger/Logger.hpp"

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
CoreDisplay<ProductType, ProductSize, ProductIngredientType>::CoreDisplay(
    Vector screenSize, Vector screenScale, std::size_t maxLen)
    : _maxLen(maxLen), _input(std::make_unique<UserInput>()), _dirName(), _pos(0), _kitechToPrint(0), _screenSize(screenSize),
      _screenScale(screenScale)
{
    listDir lib("./lib/", "arcade_.+\\.so");
    std::vector<string> nameList = lib.getDirContent();
    auto it = nameList.begin();

    for (size_t i = 0; it != nameList.end(); it++, i++) {
        this->_dirName[i] = std::make_unique<DLLib<IDisplayModule>>(string("./lib/") + *it);
        this->_dirName[i]->setEntryPoint("entryPoint");
        if (!it->compare(PRIORITORY_LIB))
            this->_pos = i;
    }
    if (!this->_dirName.size())
        throw std::invalid_argument("no lib found");
    this->_dirName[this->_pos]->getEntryPoint()->open(this->_screenSize, this->_screenScale);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
CoreDisplay<ProductType, ProductSize, ProductIngredientType>::~CoreDisplay()
{
    this->_dirName[this->_pos]->getEntryPoint()->close();
    this->_input.reset();
    this->_dirName.clear();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setPrompt(string prompt)
{
    this->_prompt = prompt;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printPrompt()
{
    string to_display = this->_prompt + this->_input->getInput();

    to_display = to_display.substr(0, this->_maxLen);
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(0, 0), to_display);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printKitchen(
    std::vector<std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>>> &kitchenList)
{
    typename std::vector<std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>>>::iterator it =
        kitchenList.begin();
    string to_display;
    std::size_t pos_y = 1;
    std::size_t max = 15;
    size_t len = kitchenList.size();

    if (len) {
        if (len <= this->_kitechToPrint)
            this->_kitechToPrint = len - 1;
    }
    for (size_t i = 0; it != kitchenList.end() && max; it++, pos_y += 3, max--, i++) {
        this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(IDisplayModule::Color::YELLOW, Coord(20, 3), Coord(0, pos_y));
        to_display = (i == this->_kitechToPrint) ? "Selected" : "Available";
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(1, pos_y + 1), to_display);
    }
    if (it != kitchenList.end()) {
        this->_dirName[this->_pos]->getEntryPoint()->putText(
            IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), "too much kitchen ...");
        pos_y += 3;
    }
    to_display = string("There are ") + std::to_string(kitchenList.size()) + string(" kitchens.");
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), to_display);
    if (len)
        this->_printDetailledKitchen(kitchenList[this->_kitechToPrint]);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::_printDetailledKitchen(
    std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>> &kitchen)
{
    // Logger log("./last_display");
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> finish(
        kitchen->kitchenStatus.getFinishedOrders());
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> pending(
        kitchen->kitchenStatus.getPendingOrders());
    std::vector<Order<Product<ProductType, ProductSize, ProductIngredientType>>> cooking(
        kitchen->kitchenStatus.getIsCookingOrders());
    std::unordered_map<ProductIngredientType, size_t> stock(kitchen->kitchenStatus.getStock());
    std::unordered_map<string, PizzaSize>::const_iterator size_it;
    std::unordered_map<string, PizzaType>::const_iterator type_it;
    string to_write;
    std::size_t limit = 27;
    std::size_t pos_x = 30;
    std::size_t pos_y = 4;

    this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(
        IDisplayModule::Color::WHITE, Coord(80, 30), Coord(pos_x, pos_y++));
    this->_dirName[this->_pos]->getEntryPoint()->putText(
        IDisplayModule::Color::CYAN, Coord(pos_x + 1, pos_y++), string("finished orders:"));
    for (size_t i = 0; i < limit && !finish.empty(); i++) {
        const Order<Product<ProductType, ProductSize, ProductIngredientType>> tmp = finish.front();
        finish.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end())
            to_write = "wrong data";
        else
            to_write = type_it->first + string(" ") + size_it->first;
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), to_write);
    }
    if (!finish.empty()) {
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), "\t...");
    }

    pos_y = 5;
    pos_x += 20;
    this->_dirName[this->_pos]->getEntryPoint()->putText(
        IDisplayModule::Color::CYAN, Coord(pos_x + 1, pos_y++), string("pending orders:"));
    for (size_t i = 0; i < limit && !pending.empty(); i++) {
        const Order<Product<ProductType, ProductSize, ProductIngredientType>> tmp = pending.front();
        pending.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end())
            to_write = "wrong data";
        else
            to_write = type_it->first + string(" ") + size_it->first;
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), to_write);
    }
    if (!pending.empty()) {
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), "\t...");
    }

    pos_y = 5;
    pos_x += 20;
    this->_dirName[this->_pos]->getEntryPoint()->putText(
        IDisplayModule::Color::CYAN, Coord(pos_x + 1, pos_y++), string("cooking order:"));
    size_t u = 0;
    for (; u < limit && u < cooking.size(); u++) {
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [cooking, u](const auto &params) {
            return params.second == cooking[u].getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [cooking, u](const auto &params) {
            return params.second == cooking[u].getOrder().getType();
        });
        if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end())
            to_write = "data wrong";
        else
            to_write = type_it->first + string(" ") + size_it->first;
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), to_write);
    }
    if (u < cooking.size()) {
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), "\t...");
    }

    pos_y = 5;
    pos_x += 20;
    this->_dirName[this->_pos]->getEntryPoint()->putText(
        IDisplayModule::Color::CYAN, Coord(pos_x + 1, pos_y++), string("stock:"));
    for (auto &q : stock) {
        to_write = PizzaIngredientListName.at(q.first) + string(": ") + std::to_string(q.second);
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::GREEN, Coord(pos_x + 1, pos_y++), to_write);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
string CoreDisplay<ProductType, ProductSize, ProductIngredientType>::getLine() const
{
    string input = this->_input->getInput();
    std::size_t pos = input.find('\n');
    string exec;

    if (pos == string::npos)
        return string("");
    exec = input.substr(0, pos);
    this->_input->setInputState(input.substr(pos + 1, input.length()));
    return exec;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setLine(string line)
{
    this->_input->setInputState(line);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::update()
{
    this->_libraryDisplaySwitch();
    this->_kitchenSwitch();
    this->_dirName[this->_pos]->getEntryPoint()->displayScreen();
    this->_dirName[this->_pos]->getEntryPoint()->refreshScreen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::clear()
{
    this->_input->runInput(this->_dirName[this->_pos]->getEntryPoint());
    this->_dirName[this->_pos]->getEntryPoint()->clearScreen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::_libraryDisplaySwitch()
{
    if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_LEFT)) {
        this->_dirName[this->_pos]->getEntryPoint()->close();
        this->_pos = (this->_pos > 0) ? this->_pos - 1 : this->_dirName.size() - 1;
    } else if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_RIGHT)) {
        this->_dirName[this->_pos]->getEntryPoint()->close();
        this->_pos = (this->_pos < this->_dirName.size() - 1) ? this->_pos + 1 : 0;
    } else {
        return;
    }
    this->_dirName[this->_pos]->getEntryPoint()->open(this->_screenSize, this->_screenScale);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool CoreDisplay<ProductType, ProductSize, ProductIngredientType>::isRunning()
{
    return this->_dirName[this->_pos]->getEntryPoint()->isOpen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setError(string error)
{
    if (error.length() > 50)
        error = error.substr(0, 24) + string(" ...");
    this->_error = error;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printError()
{
    size_t pos_y = 1;
    size_t pos_x = 50;

    if (this->_error.length()) {
        this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(
            IDisplayModule::Color::RED, Coord(52, 3), Coord(pos_x, pos_y));
        this->_dirName[this->_pos]->getEntryPoint()->putText(
            IDisplayModule::Color::WHITE, Coord(pos_x + 1, pos_y + 1), this->_error);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::_kitchenSwitch()
{
    if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_UP)) {
        this->_kitechToPrint = (this->_kitechToPrint > 0) ? this->_kitechToPrint - 1 : 0;
    } else if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_DOWN)) {
        this->_kitechToPrint++;
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::updatingKitchenStatus(
    std::function<void(const Kitchen<ProductType, ProductSize, ProductIngredientType> &)> func,
    std::vector<std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>>> &kitchenList)
{
    size_t pos_x = 30;
    size_t pos_y = 1;
    size_t len = kitchenList.size();
    IDisplayModule::Color color =
        (this->_mouseOver(Coord(pos_x, pos_y), Coord(15, 3))) ? IDisplayModule::Color::GREEN : IDisplayModule::Color::BLUE;

    if (this->_mouseClickedHere(Coord(pos_x, pos_y), Coord(15, 3))) {
        color = IDisplayModule::Color::YELLOW;
        if (len && this->_kitechToPrint < len)
            func(kitchenList[this->_kitechToPrint]->kitchen);
    }
    this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(color, Coord(15, 3), Coord(pos_x, pos_y));
    this->_dirName[this->_pos]->getEntryPoint()->putText(
        IDisplayModule::Color::WHITE, Coord(pos_x + 1, pos_y + 1), string("Update status"));
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool CoreDisplay<ProductType, ProductSize, ProductIngredientType>::_mouseClickedHere(Coord pos, Coord size)
{
    bool clicked = this->_dirName[this->_pos]->getEntryPoint()->isMouseClicked();
    Coord mouse = this->_dirName[this->_pos]->getEntryPoint()->getMousePos();

    if (!clicked)
        return false;
    if (mouse.x < pos.x || mouse.y < pos.y)
        return false;
    if (mouse.x > pos.x + size.x || mouse.y > pos.y + size.y)
        return false;
    return true;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool CoreDisplay<ProductType, ProductSize, ProductIngredientType>::_mouseOver(Coord pos, Coord size)
{
    Coord mouse = this->_dirName[this->_pos]->getEntryPoint()->getMousePos();

    if (mouse.x < pos.x || mouse.y < pos.y)
        return false;
    if (mouse.x > pos.x + size.x || mouse.y > pos.y + size.y)
        return false;
    return true;
}

template class Pizzeria::CoreDisplay<PizzaType, PizzaSize, PizzaIngredient>;