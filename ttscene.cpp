#include "ttscene.h"

TTScene *TTScene::m_instance = NULL;

TTScene *TTScene::instance()
{
    if (!m_instance) {
        m_instance = new TTScene;
    }
    return m_instance;
}

void TTScene::addGameObject(TTGameObject *object)
{
    m_gameObjects.push_back(object);
    m_numberGameObjects++;
}

TTGameObject *TTScene::gameObjectAtIndex(int index)
{
    if (index < m_numberGameObjects && index >= 0) {
        return m_gameObjects.at(index);
    } else {
        return NULL;
    }
}

int TTScene::numberOfGameObjects()
{
    return m_numberGameObjects;
}

TTScene::TTScene() :
    m_numberGameObjects(0)
{

}

TTScene::~TTScene()
{

}
