// This class define an area.

#include <vector>
#include <boost/geometry.hpp>

namespace bg = boost::geometry;

class Area
{

protected:
    int id;							// each area has a unic id
    std::string name;						// area might have a name

public:
    std::vector<int> insideEntities;	  			// Entities present in that area

    // Constructor
    Area(int areaId);

    // virtual functions
    virtual bool isPointInArea(bg::model::point<double, 2, bg::cs::cartesian> center) = 0;

    // functions
    void removeEntity(int entId);
    bool isIdInArea(int id);

    // accessors, mutators
    int getId();
    void setId(int areaId);
    std::string getName();
    void setName(std::string areaName);
};

