/*
** EPITECH PROJECT, 2021
** CommandInterpreter.c
** File description:
** Get commands from user input
*/

#include "CommandInterpreter.hpp"

CommandInterpreter::CommandInterpreter(std::istream &inputStream) : _inputStream(inputStream), _end(false)
{
}

CommandInterpreter::~CommandInterpreter() = default;

void CommandInterpreter::setEnd(bool isEnd)
{
    _end = isEnd;
}

bool CommandInterpreter::isEnd() const
{
    const std::string &my_actCommand(getActCommand());

    if (my_actCommand == "exit") {
        return true;
    }
    return _end;
}

void CommandInterpreter::setPrompt(const std::string &prompt)
{
    _prompt = prompt;
}

const std::string &CommandInterpreter::getPrompt() const
{
    return _prompt;
}

void CommandInterpreter::printPrompt()
{
    std::cout << _prompt;
}

const std::string &CommandInterpreter::getActCommand() const
{
    return _actCommand;
}

const std::string &CommandInterpreter::setCommand()
{
    std::string my_command;

    if (!getline(_inputStream, my_command)) {
        setEnd(true);
    }
    setActCommand(my_command);
    return getActCommand();
}

void CommandInterpreter::setActCommand(std::string &command)
{
    _actCommand = command;
}

// return true if _actCommand is listed as existing
bool CommandInterpreter::commandExists() const
{
    const std::string &my_actCommand(getActCommand());

    if (my_actCommand.empty())
        return false;
    return true;
}

// parse command and set vector of strings with command and arguments
void CommandInterpreter::parseCommand()
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

const std::vector<std::string> &CommandInterpreter::getActCommandParams() const
{
    return _actCommandParams;
}

bool CommandInterpreter::executeCommand()
{
    return false;
}

const std::string &CommandInterpreter::getErrorMsg(const uint msgId)
{
    return _errors.at(msgId);
}

void CommandInterpreter::printErrorMsg(const uint msgId)
{
    try {
        const std::string &my_msg(getErrorMsg(msgId));
        std::cerr << my_msg << std::endl;
    } catch (std::out_of_range &my_exception) {
        return;
    }
}

void CommandInterpreter::addErrorMsg(const uint id, const std::string &msg)
{
    auto my_pair(std::make_pair(id, msg));

    _errors.insert(my_pair);
}