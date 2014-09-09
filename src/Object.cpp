// This class define an object.
// An object can be either a MovableObject or a StaticObject.

#include "Object.h"


// accessors, mutators
int Object::getSupportFurniture(){
  return supportFurniture;
}

void Object::setSupportFurniture(int idFurniture){
  supportFurniture = idFurniture;
}

int Object::getContainerId(){
  return container;
}

void Object::setContainerId(int idContainer){
  container = idContainer;
}
