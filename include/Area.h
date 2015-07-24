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

    // Constructor
    Area(unsigned int areaId);

    // virtual functions
    virtual bool isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> center) = 0;

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
};

#endif
