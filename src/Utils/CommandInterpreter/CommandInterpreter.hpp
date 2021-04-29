/*
 * EPITECH PROJECT, 2021
 * CommandInterpreter
 * File description:
 * CommandInterpreter.hpp - Created: 26/04/2021
 */

#ifndef COMMAND_INTERPRETER_HPP
#define COMMAND_INTERPRETER_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <sstream>

class CommandInterpreter {
    // to be called in a loop
    // with condition (CommandInterpreter.isEnd())
    // CommandInterpreter.printPrompt()
    // my_command = CommandInterpreter.getCommand()
    // CommandInterpreter.executeCommand(my_command)
  public:
    explicit CommandInterpreter(std::istream &inputStream = std::cin);
    ~CommandInterpreter();

    void setEnd(bool isEnd);
    [[nodiscard]] bool isEnd() const;
    // tells if CommandInterpreter has received an indication to stop.

    void setPrompt(const std::string &prompt);
    [[nodiscard]] const std::string &getPrompt() const;
    void printPrompt();

    const std::string &setCommand();
    // get command from standard input, set _actCommand and return it
    [[nodiscard]] const std::string &getActCommand() const;
    // return last command

    [[nodiscard]] virtual bool commandExists() const;
    // return true if _actCommand is listed as existing

    virtual void parseCommand();
    // parse command and set vector of strings with command and arguments
    [[nodiscard]] const std::vector<std::string> &getActCommandParams() const;

    virtual bool executeCommand();

    const std::string &getErrorMsg(uint msgId);
    void printErrorMsg(uint msgId);
    void addErrorMsg(uint id, const std::string &msg);

  protected:
    void setActCommand(std::string &command);

    /**
     * @brief
     */
    std::string _prompt = "What can I do for you ? ";
    std::string _actCommand;
    std::vector<std::string> _actCommandParams;
    std::istream &_inputStream;
    std::map<const uint, const std::string> _errors;
    bool _end;

  private:
};

#endif