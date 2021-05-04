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