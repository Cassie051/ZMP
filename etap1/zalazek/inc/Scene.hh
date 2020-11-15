#pragma once

#include "MobileObj.hh"
#include <map>
#include <memory>

class Scene
{
private:
    std::map<std::string,std::shared_ptr<MobileObj>> mobileObjects;
public:
    std::shared_ptr<MobileObj> findMobileObject(const std::string& objectName);
    void addMobileObject(const std::string& objectName);
    Scene();
    ~Scene();
};

Scene::Scene()
{
}

Scene::~Scene()
{
}

std::shared_ptr<MobileObj> Scene::findMobileObject(const std::string& objectName)
{
    std::map<std::string, std::shared_ptr<MobileObj>>::iterator iter = mobileObjects.find(objectName);
    if(iter != mobileObjects.end())
    {
        return iter->second;
    }
    return nullptr;
}

void Scene::addMobileObject(const std::string& objectName)
{
    if(!findMobileObject(objectName))
    {
        class std::shared_ptr<MobileObj> mobileObject = std::make_shared<MobileObj>();
        mobileObject->SetName(objectName);
        mobileObjects.insert({objectName, mobileObject});
    }
}