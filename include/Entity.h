// This class define an entity.
// An entity can be either an agent or an object.

#ifndef ENTITY_H
  #define ENTITY_H

  #include <boost/geometry.hpp>
  #include <vector>
  namespace bg = boost::geometry;
  enum EntityType { ROBOT, HUMAN, OBJECT, JOINT };

  class Entity
  {

  private:
    unsigned int id;						// each entity has a unic id
    std::string name;						// Entity might have a name
    unsigned long time;						// time of data in microseconds
    unsigned int confidence;
    unsigned int roomId;
    EntityType entityType;

  public:
    bg::model::point<double, 3, bg::cs::cartesian> position_;    // Entity position
    std::vector<double> orientation_;                            // Entity orientation
    std::vector<unsigned int> inArea_;			         // Entity might be in a specific area(s)

    // Constructor
    Entity(unsigned int entityId);

    // functions
    bool isInArea(unsigned int areaId);
    void removeInArea(unsigned int areaId);

    // accessors, mutators
    unsigned int getId();
    void setId(unsigned int entId);
    unsigned long getTime();
    void setTime(unsigned long entTime);
    std::string getName();
    void setName(std::string entityName);
    unsigned int getConfidence();
    void setConfidence(unsigned int confid);
    unsigned int getRoomId();
    void setRoomId(unsigned int id);
    bg::model::point<double, 3, bg::cs::cartesian> getPosition();
    void setPosition(bg::model::point<double, 3, bg::cs::cartesian> point);
    std::vector<double> getOrientation();
    void setOrientation(std::vector<double> entityOrientation);
    EntityType getEntityType();
    void setEntityType(EntityType myEntType);
  };
#endif

