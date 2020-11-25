//
// Created by kasia on 24.11.2020.
//
#include "Scene.hh"

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