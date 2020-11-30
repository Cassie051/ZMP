#pragma once
#include "MobileObj.hh"
#include "AccessControl.hh"
#include <map>
#include <memory>
#include <sstream>
#include <vector>
#include "Vector3D.hh"

class Scene : public AccessControl
{
private:
    std::map<std::string,std::shared_ptr<MobileObj>> mobileObjects;
public:
    std::shared_ptr<MobileObj> findMobileObject(const std::string& objectName);
    void addMobileObject(const std::string& objectName);
    void addObjectColor(const std::string& objectName, std::string sValue_RGB);
    void addObjectPose(const std::string& objectName, std::string sValue_Pose);
    void addObjectSize(const std::string& objectName, std::string sValue_SizeXYZ);
    std::vector<std::shared_ptr<MobileObj>> GetObjs();
    Scene();
    ~Scene();
};
