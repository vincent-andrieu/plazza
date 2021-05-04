/*
 * EPITECH PROJECT, 2021
 * DLLib
 * File description:
 * DLLib.cpp - Created: 21/04/2021
 */

#include "DLLib.hpp"

template<typename T>
DLLib<T>::DLLib(std::string filepath) : _loader(std::make_unique<DLLoader<T>>(filepath))
{
}

template<typename T>
DLLib<T>::~DLLib()
{
    delete this->_loader.release();
}

template<typename T>
std::shared_ptr<T> DLLib<T>::getEntryPoint() const
{
    return this->_entryPoint;
}

template<typename T>
void DLLib<T>::setEntryPoint(std::string entryPointName)
{
    this->_entryPoint = this->_loader->load_sym(entryPointName);
}

template class DLLib<plazza::IDisplayModule>;