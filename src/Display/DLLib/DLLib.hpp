/*
 * EPITECH PROJECT, 2021
 * DLLib
 * File description:
 * DLLib.hpp - Created: 21/04/2021
 */

#ifndef DLLIB_HPP
#define DLLIB_HPP

#include <memory>
#include <dlfcn.h>
#include "DLLoader/DLLoader.hpp"

template <typename T> class DLLib {
  public:
    DLLib(std::string filepath);
    ~DLLib();
    std::shared_ptr<T> getEntryPoint() const;
    void setEntryPoint(std::string entryPointName);

  private:
    std::unique_ptr<DLLoader<T>> _loader;
    std::shared_ptr<T> _entryPoint;
};

#endif