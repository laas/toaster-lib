// This class define an object.
// An object can be either a MovableObject or a StaticObject.

#include "Entity.h"

class Object : public Entity
{

private:
    int supportFurniture;			// id from supporting furniture if any
    int container;				// id from object containing current
    
    

public:
    std::vector<int> containedObject;		// List of id from object contained in current
    std::vector<int> aboveObject;		// List of id from object above current
    std::vector<int> closeObject;		// List of id from object next to current

    // accessors, mutators
    int getSupportFurniture();
    void setSupportFurniture(int idFurniture);

    int getContainerId();
    void setContainerId(int idContainer);
};

