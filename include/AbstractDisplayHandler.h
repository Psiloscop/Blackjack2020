#pragma once

#include <vector>

#include "AbstractDisplayEntity.h"

template <typename T>
class AbstractDisplayHandler
{
public:
	virtual void display(T*) const = 0;
	virtual void displayBatch(std::vector<T*>) const = 0;
};