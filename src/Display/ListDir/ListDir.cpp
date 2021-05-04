/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** ListDir.cpp
*/

#include "ListDir.hpp"

listDir::listDir(std::string filepath, std::string regexp) : _filepath(filepath), _regexp(regexp)
{
    this->readDir();
}

listDir::~listDir()
{
    this->reset();
}

const std::vector<std::string> &listDir::getDirContent() const
{
    return this->_dirContent;
}

void listDir::loadDir(std::string filepath)
{
    this->_filepath = filepath;
    this->reset();
    this->readDir();
}

void listDir::reset()
{
    this->_dirContent.clear();
}

void listDir::readDir()
{
    struct dirent *file;
    std::regex reg(this->_regexp);
    DIR *dir = opendir(this->_filepath.c_str());

    if (dir) {
        for (file = readdir(dir); file; file = readdir(dir)) {
            if (std::regex_match(file->d_name, reg)) {
                this->_dirContent.push_back(file->d_name);
            }
        }
    } else {
        throw std::invalid_argument("Directory: Can't open directory");
    }
    closedir(dir);
}

void listDir::setRegexp(std::string regexp)
{
    this->_regexp = regexp;
}