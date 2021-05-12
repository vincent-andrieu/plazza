/*
 * EPITECH PROJECT, 2021
 * DLLoader
 * File description:
 * DLLoader.cpp - Created: 21/04/2021
 */

#include <cstring>
#include <stdexcept>
#include "DLLoader.hpp"

template <typename T> DLLoader<T>::DLLoader(std::string filepath) : _handle(nullptr)
{
    if (std::strncmp("./", filepath.c_str(), 2))
        filepath = std::string("./") + filepath;
    this->_handle = dlopen(filepath.c_str(), RTLD_NOW | RTLD_NODELETE | RTLD_GLOBAL);
    if (!this->_handle)
        throw std::invalid_argument(dlerror());
}

template <typename T> DLLoader<T>::~DLLoader()
{
    dlclose(this->_handle);
}

template <typename T> std::shared_ptr<T> DLLoader<T>::load_sym(std::string funcName)
{
    std::shared_ptr<T> (*instance)(void);

    *(void **) (&instance) = dlsym(this->_handle, funcName.c_str());
    if (!instance)
        throw std::invalid_argument(dlerror());
    return (*instance)();
}

template class DLLoader<plazza::IDisplayModule>;