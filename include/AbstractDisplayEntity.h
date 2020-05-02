#ifndef __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__
#define __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__

template <typename T>
class AbstractDisplayEntity
{
protected:
    T& entity;

public:
    explicit AbstractDisplayEntity(T& value)
        : entity(value) {}

	virtual void setDisplayEntity(T& value) const = 0;

	virtual T& getDisplayEntity() const = 0;
};

#endif // __ABSTRACT_DISPLAY_ENTITY_H_INCLUDED__