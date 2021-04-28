/*
** EPITECH PROJECT, 2021
** CommandInterpreter.c
** File description:
** Get commands from user input
*/

#include "CommandInterpreter.hpp"

commandInterpreter::commandInterpreter(std::istream &inputStream) : _inputStream(inputStream), _end(false)
{
}

commandInterpreter::~commandInterpreter() = default;

void commandInterpreter::setEnd(bool isEnd)
{
    _end = isEnd;
}

bool commandInterpreter::isEnd() const
{
    const std::string &my_actCommand(getActCommand());

    if (my_actCommand == "exit") {
        return true;
    }
    return _end;
}

void commandInterpreter::setPrompt(const std::string &prompt)
{
    _prompt = prompt;
}

const std::string &commandInterpreter::getPrompt() const
{
    return _prompt;
}

void commandInterpreter::printPrompt()
{
    std::cout << _prompt;
}

const std::string &commandInterpreter::getActCommand() const
{
    return _actCommand;
}

const std::string &commandInterpreter::setCommand()
{
    std::string my_command;

    if (!getline(_inputStream, my_command)) {
        setEnd(true);
    }
    setActCommand(my_command);
    return getActCommand();
}

void commandInterpreter::setActCommand(std::string &command)
{
    _actCommand = command;
}

// return true if _actCommand is listed as existing
bool commandInterpreter::commandExists() const
{
    const std::string &my_actCommand(getActCommand());

    if (my_actCommand.empty())
        return false;
    return true;
}

// parse command and set vector of strings with command and arguments
void commandInterpreter::parseCommand()
{
    const std::string &my_actCommand(getActCommand());
    std::stringstream ssin(my_actCommand);
    std::string my_param;
    std::vector<std::string> my_commandParams;

    while (ssin.good()) {
        ssin >> my_param;
        my_commandParams.push_back(my_param);
    }
}

const std::vector<std::string> &commandInterpreter::getActCommandParams() const
{
    return _actCommandParams;
}

bool commandInterpreter::executeCommand()
{
    return false;
}

const std::string &commandInterpreter::getErrorMsg(const uint msgId)
{
    return _errors.at(msgId);
}

void commandInterpreter::printErrorMsg(const uint msgId)
{
    try {
        const std::string &my_msg(getErrorMsg(msgId));
        std::cerr << my_msg << std::endl;
    } catch (std::out_of_range &my_exception) {
        return;
    }
}

void commandInterpreter::addErrorMsg(const uint id, const std::string &msg)
{
    auto my_pair(std::make_pair(id, msg));

    _errors.insert(my_pair);
}