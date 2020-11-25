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
