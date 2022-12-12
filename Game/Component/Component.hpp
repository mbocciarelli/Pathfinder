#pragma once

class Component
{
public:
	virtual ~Component() = default;

	template <typename TComponent>
	TComponent* GetComponent()
	{
		return static_cast<TComponent*>(this);
	}
};