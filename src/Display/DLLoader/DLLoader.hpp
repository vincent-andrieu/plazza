/*
 * EPITECH PROJECT, 2021
 * DLLoader
 * File description:
 * DLLoader.hpp - Created: 21/04/2021
 */

#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <memory>
#include <dlfcn.h>

#include "Interfaces/IDisplayModule.hpp"

template <typename T> class DLLoader {
  public:
    DLLoader(std::string filepath);
    ~DLLoader();
    std::shared_ptr<T> load_sym(std::string funcName);

  private:
    void *_handle;
};

#endif