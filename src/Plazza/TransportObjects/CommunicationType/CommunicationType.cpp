/*
 * EPITECH PROJECT, 2021
 * CommunicationType
 * File description:
 * CommunicationType.cpp - Created: 03/05/2021
 */

#include "TransportObjects/CommunicationType/CommunicationType.hpp"

CommunicationType::CommunicationType()
{
}

CommunicationType::CommunicationType(ECommunicationType type) : _type(type)
{
}

ECommunicationType CommunicationType::getType() const
{
    return this->_type;
}

const string CommunicationType::_SerializeToString() const
{
    return std::to_string(this->_type);
}

void CommunicationType::_SerializeFromString(const string str)
{
    this->_type = (ECommunicationType) std::stoi(str);
}