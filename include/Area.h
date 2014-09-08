// This class define an area.

#include <vector>
#include <boost/geometry.hpp>

namespace bg = boost::geometry;

class Area
{

private:
    int id;							// each area has a unic id
    std::string name;						// area might have a name

public:
    std::vector<int> insideEntities;	  			// Entities present in that area

    // Constructor
    Area(int areaId):id(areaId);

    // virtual functions
    bool isInArea(bg::model::point<double, 2, bg::cs::cartesian> center) = 0;

    // functions
    bool addEntity(int entId);
    bool removeEntity(int entId);
    bool cleanEntity();
    bool isInArea(int id);

    // accessors, mutators
    int getId();
    void setId(int areaId);
    std::string getName();
    void setName(std::string areaName);
};

