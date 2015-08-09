#ifndef TTSCENE_H
#define TTSCENE_H

#include <QVector>
#include "ttgameobject.h"
#include "ttlightsource.h"

class TTScene
{
public:
    static TTScene *instance();

    void addGameObject(TTGameObject *object);
    TTGameObject *gameObjectAtIndex(int index);
    int numberOfGameObjects();

    void addPrimaryLightSource(TTLightSource *light);
    void updateLightSource(TTLightSource *light);
    glm::vec3 m_lightPos;

private:
    TTScene();
    ~TTScene();
    static TTScene *m_instance;

    QVector<TTGameObject *> m_gameObjects;
    int m_numberGameObjects;

};

#endif // TTSCENE_H
