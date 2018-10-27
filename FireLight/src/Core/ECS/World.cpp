#include"World.h"

std::vector<System*> World::m_Game_Systems;
std::vector<System*> World::m_Engine_Systems;
std::vector<Entity*> World::m_Entitys;
std::unordered_map<uint32_t, std::vector<BaseComponent*>> World::m_components;



World::World()
{
	
}

EntityHandler* World::CreateEntity()
{
	uint32_t index = m_Entitys.size();
	m_Entitys.emplace_back(new Entity());
	Entity* newEntity = m_Entitys.back();
	newEntity->setID(index);
	EntityHandler* handler = (EntityHandler*)newEntity;
	return handler;
}

void World::RemoveEntity(EntityHandler* handler)
{

}


void World::addEntityToSystems(EntityHandler* handler)
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		System* gameSystem = m_Game_Systems[i];
		Entity* ent = (HandlerToRow(handler));


		std::bitset<150>& sysKey = gameSystem->getSystemKey();


		if ((HandlerToRow(handler)->getKey() & sysKey) == sysKey)
		{
			auto componetTypeArray = gameSystem->getComponentTypes();

			std::vector<BaseComponent*>* tempComponents = new std::vector<BaseComponent*>();
			for(uint32_t j = 0; j < componetTypeArray.size(); j++)
			{
				tempComponents->push_back(m_components[componetTypeArray[j]][HandlerToRow(handler)->getComponentIndex(componetTypeArray[j])]);
			}
			gameSystem->addEntity(HandlerToRow(handler)->getID(), tempComponents);
		}
	}

	for (uint32_t i = 0; i < m_Engine_Systems.size(); i++)
	{
		System* engineSystem = m_Engine_Systems[i];
		Entity* ent = (HandlerToRow(handler));


		std::bitset<150>& sysKey = engineSystem->getSystemKey();


		if ((HandlerToRow(handler)->getKey() & sysKey) == sysKey)
		{
			auto componetTypeArray = engineSystem->getComponentTypes();

			std::vector<BaseComponent*>* tempComponents = new std::vector<BaseComponent*>();
			for (uint32_t j = 0; j < componetTypeArray.size(); j++)
			{
				tempComponents->push_back(m_components[componetTypeArray[j]][HandlerToRow(handler)->getComponentIndex(componetTypeArray[j])]);
			}
			engineSystem->addEntity(HandlerToRow(handler)->getID(), tempComponents);
		}
	}

}
void World::removeEntityToSystems(EntityHandler* handler)
{
	
}

void World::addGameSystem(System* system)
{
	m_Game_Systems.emplace_back(system);
}
void World::removeGameSystem(System* system)
{

}

void World::addEngineSystem(System* system)
{
	m_Engine_Systems.emplace_back(system);
}
void World::removeEgnineSystem(System* system)
{

}

void World::UpdateGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		m_Game_Systems[i]->UpdateComponents();
	}
}
void World::UpdateEngineSystems()
{
	for (uint32_t i = 0; i < m_Engine_Systems.size(); i++)
	{
		m_Engine_Systems[i]->UpdateComponents();
	}
}
World::~World()
{

}