#pragma once

template <typename T>
class AbstractDisplayEntity
{
protected:
    T entity;

public:
    AbstractDisplayEntity(T value)
        : entity(value) {}

	virtual T& getDisplayEntity() = 0;
};