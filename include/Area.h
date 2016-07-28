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
    bool isCircle;         // To know if it is a circle area or a polygon one.

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
    unsigned int getId();
    void setId(unsigned int areaId);
    std::string getMyOwner();
    void setMyOwner(std::string ownerId);
    std::string getName();
    void setName(std::string areaName);
    std::string getAreaType();
    void setAreaType(std::string type);
    std::string getFactType();
    void setFactType(std::string myFactType);
    std::string getEntityType();
    void setEntityType(std::string myEntityType);
    bool getIsCircle();
    void setIsCircle(bool isCircle);
    void addInsideEntity(std::string EntityID);
    void addUpcomingEntity(std::string EntityID);
    void addLeavingEntity(std::string EntityID);
    bool removeInsideEntity(std::string EntityID);
    bool removeUpcomingEntity(std::string EntityID);
    bool removeLeavingEntity(std::string EntityID);
    bool isInsideEntity(std::string EntityID);
    bool isLeavingEntity(std::string EntityID);
    bool isUpcomingEntity(std::string EntityID);
};

#endif
