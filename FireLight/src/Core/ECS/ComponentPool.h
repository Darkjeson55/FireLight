#ifndef COMPONENTPOOL_H
#define	COMPONENTPOOL_H

#include "Component.h"
#include <vector>

class ComponentPool
{
public:
	ComponentPool();

	template<class T, class... Args>
	void addComponent(uint32_t entityID, Args... args)
	{
		uint32_t index = m_Components.size();
		m_Components.resize(index + T::SIZE);
		BaseComponent* comp = new(&m_Components[index])T(*(T*)new T(args...));
		if (entityID >= m_EntitySparset.size())
		{
			m_EntitySparset.resize(entityID + 1);
		}
		m_EntitySparset[entityID] = index;

		comp->entityIndex = entityID;

	}

	template<class T>
	T& getComponent(uint32_t entityID)
	{
		return (*(T*)&m_Components[m_EntitySparset[entityID]]);
	}


	template<class Component>
	void destroyComponent(Component* comp)
	{
		comp->~Component();
	}


	template<class T>
	void removeComponent(uint32_t entitID)
	{
		T* lastComp = (T*)&m_Components[m_EntitySparset.size() - 1];
		T* CompoForRemove = (T*)&m_Components[m_EntitySparset[entitID]];
		m_EntitySparset[lastComp->entityIndex] = m_EntitySparset[entitID];
		destroyComponent(CompoForRemove);
		memmove(CompoForRemove, lastComp, T::SIZE);


		uint32_t index = m_Components.size();
		m_Components.resize(index - T::SIZE);

		m_EntitySparset[entitID] = 0;
		//TODO:: test if it work!
	}

	int Size(size_t size) { return m_Components.size() / size; }

	void Clear(size_t size);


	~ComponentPool();
private:
	std::vector<uint32_t> m_EntitySparset;
	std::vector<uint8_t> m_Components;
};

#endif
