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

void Scene::addObjectColor(const std::string& objectName, std::string sValue_RGB)
{
    std::istringstream ColorStrm;
    ColorStrm.str(sValue_RGB);
    int  R,G,B;

    ColorStrm >> R >> G >> B;
    if(ColorStrm.fail())
    {
        if(findMobileObject(objectName))
        {
            class std::shared_ptr<MobileObj> mobileObject = std::make_shared<MobileObj>();
            mobileObject->SetColor(R, G, B);
        }
    }

}

void Scene::addObjectSize(const std::string& objectName, std::string sValue_SizeXYZ)
{
    std::istringstream SizeStrm;
    SizeStrm.str(sValue_SizeXYZ);
    double  x, y, z;

    SizeStrm >> x >> y >> z;
    if(SizeStrm.fail())
    {
        if(findMobileObject(objectName))
        {
            class std::shared_ptr<MobileObj> mobileObject = std::make_shared<MobileObj>();
            mobileObject->SetSize(x, y, z);
        }
    }
}

std::vector<std::shared_ptr<MobileObj>> Scene::GetObjs()
{
    class std::shared_ptr<MobileObj> mobileObject = std::make_shared<MobileObj>();
    std::map<std::string, std::shared_ptr<MobileObj>>::iterator iter;
    std::vector<std::shared_ptr<MobileObj>> SceneObjectsCollection;
    for( iter = mobileObjects.begin(); iter != mobileObjects.end(); iter++ )
    {
        mobileObject = iter->second;
        SceneObjectsCollection.push_back(mobileObject);
    }
    return SceneObjectsCollection;
}

std::string Scene::GetObjCommand()
{
    class std::shared_ptr<MobileObj> mobileObject = std::make_shared<MobileObj>();
    Vector3D poss = mobileObject->GetPositoin_m();
    std::string AngRoll = std::to_string(mobileObject->GetAng_Roll_deg());
    std::string AngPitch = std::to_string(mobileObject->GetAng_Pitch_deg());
    std::string AngYaw = std::to_string(mobileObject->GetAng_Yaw_deg());
    std::string strposs = std::to_string(poss[0])+" "+std::to_string(poss[1])+" "+std::to_string(poss[2]);
    return "Cube  " +mobileObject->GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+mobileObject->GetColor()+"\n";
}