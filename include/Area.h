// This class define an area.

#ifndef AREA_TOASTER_H
#define AREA_TOASTER_H

#include <vector>
#include <boost/geometry.hpp>

namespace bg = boost::geometry;

class Area {
protected:
    unsigned int id;       // each area has a unic id
    std::string name;      // area might have a name
    std::string myOwner;  // Entity related to this area
    std::string areaType;  // If an area is a room or other types...
    std::string factType;  // This is used to know what fact we should compute
    std::string entityType; // This is used to know what entities are concerned: entities, agents, robots, humans, objects
    bool isCircle_;         // To know if it is a circle area or a polygon one.
    double enterHysteresis_ ;
    double leaveHysteresis_ ;

public:
    std::vector<std::string> insideEntities_; // Entities present in that area
    std::vector<std::string> upcomingEntities_; // Entities about to enter in that area
    std::vector<std::string> leavingEntities_; // Entities about to leave that area
    // Constructor
    Area(unsigned int areaId);

    // virtual functions
    virtual bool isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> center, std::string entityID) = 0;

    // functions
    void removeEntity(std::string entId);
    bool isIdInArea(std::string id);

    // accessors, mutators
    // If you add accessors or mutators please make them here
    // When you put your function in .h, it will be inline
    // and will increase the performance of your programm
    unsigned int getId()                  { return id; }
    void setId(unsigned int areaId)       { id = areaId; }
    std::string getMyOwner()              { return myOwner; }
    void setMyOwner(std::string ownerId)  { myOwner = ownerId; }
    std::string getName()                 { return name; }
    void setName(std::string areaName)    { name = areaName; }
    std::string getAreaType()             { return areaType; }
    void setAreaType(std::string type)    { areaType = type; }
    std::string getFactType()             { return factType; }
    void setFactType(std::string myFactType) { factType = myFactType; }
    std::string getEntityType()           { return entityType; }
    void setEntityType(std::string myEntityType) { entityType = myEntityType; }
    bool getIsCircle()                    { return isCircle_; }
    void setIsCircle(bool isCircle)       { isCircle_ = isCircle; }
    double getEnterHysteresis()           { return enterHysteresis_; }
    void setEnterHysteresis(double enterHysteresis) { enterHysteresis_ = enterHysteresis; }
    double getLeaveHysteresis()           { return leaveHysteresis_; }
    void setLeaveHysteresis(double leaveHysteresis) { leaveHysteresis_ = leaveHysteresis; }

    std::vector<std::string> getInsideEntities() { return insideEntities_; }
    std::vector<std::string> getUpcomingEntities() { return upcomingEntities_; }
    std::vector<std::string> getLeavingEntities() { return leavingEntities_; }

    void addInsideEntity(std::string EntityID);
    void addUpcomingEntity(std::string EntityID);
    void addLeavingEntity(std::string EntityID);
    bool removeInsideEntity(std::string EntityID);
    bool removeUpcomingEntity(std::string EntityID);
    bool removeLeavingEntity(std::string EntityID);
    bool isInsideEntity(std::string EntityID);
    bool isLeavingEntity(std::string EntityID);
    bool isUpcomingEntity(std::string EntityID);

  private:
    bool removeFromVector(std::string id, std::vector<std::string>& vect);
    bool findInVector(std::string id, std::vector<std::string> vect);
};

#endif
