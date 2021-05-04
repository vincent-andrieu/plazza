/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** ListDir.hpp
*/

#ifndef LISTDIR_HPP
#define LISTDIR_HPP

#include <regex>
#include <string>
#include <dirent.h>
#include <sys/types.h>

class listDir {
  public:
    listDir(std::string filepath, std::string regexp);
    ~listDir();
    const std::vector<std::string> &getDirContent() const;
    void loadDir(std::string filepath);
    void setRegexp(std::string regexp);

  private:
    void reset();
    void readDir();

  private:
    std::vector<std::string> _dirContent;
    std::string _filepath;
    std::string _regexp;
};

#endif