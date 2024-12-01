#ifndef SCENEMANAGER_H__
#define SCENEMANAGER_H__

#include <map>
#include "Scene.h"

class SceneManager {
	static SceneManager* m_instance;
	std::map<std::string, Scene*> m_scenes;
	Scene* m_currentScene;

public:
	SceneManager();
	Scene* getScene(std::string _key);
	Scene* getCurrentScene();
	void changesScene(std::string _key);
	void addScene(std::string _key, Scene* _scene);
	static SceneManager* getInstance();
};

#endif

