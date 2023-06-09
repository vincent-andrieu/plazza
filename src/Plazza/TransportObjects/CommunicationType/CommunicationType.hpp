/*
 * EPITECH PROJECT, 2021
 * CommunicationType
 * File description:
 * CommunicationType.hpp - Created: 03/05/2021
 */

#ifndef COMMUNICATION_TYPE_HPP
#define COMMUNICATION_TYPE_HPP

#include "Serializer/Serializer.hpp"

enum ECommunicationType
{
    UNDEFINED,
    ORDER_PIZZA,
    STATUS,
    KILL_CHILD
};

class CommunicationType : public Serializer {
  public:
    CommunicationType() = default;
    explicit CommunicationType(ECommunicationType type);
    ~CommunicationType() = default;

    ECommunicationType getType() const;

  protected:
    const string SerializeToString() const override;
    void SerializeFromString(const string &str) override;

  private:
    ECommunicationType _type = ECommunicationType::UNDEFINED;
};

#endif