// class defines circle with height in z direction

#include "CircleArea.h"
#include "Tools/MathFunctions.h"


// Constructor

CircleArea::CircleArea(int areaId, bg::model::point<double, 3, bg::cs::cartesian> areaCenter, double areaRay, double heightInz, double EnterHysteresis, double LeaveHysteresis) : Area(areaId), center(areaCenter), centerRelative(areaCenter), ray(areaRay), height(heightInz), enterHysteresis(EnterHysteresis), leaveHysteresis(LeaveHysteresis) {
}

// function
//TODO

// checks if given point is in the cylinrical area
bool CircleArea::isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID) {
	bg::model::point<double, 2, bg::cs::cartesian> point2d;
	bg::model::point<double, 2, bg::cs::cartesian> center2d;
	double x = point.get<0>();
	double y = point.get<1>();
	double z = point.get<2>();
	point2d.set<0>(x);
	point2d.set<1>(y);
	bg::model::point<double, 3, bg::cs::cartesian> center = getCenter();
	double cx = center.get<0>();
	double cy = center.get<1>();
	double cz = center.get<2>();
	center2d.set<0>(cx);
	center2d.set<1>(cy);
	double h = getHeight();	
// if point is in outermost cylinder
    if ((bg::distance(point2d, center2d) < (getRay() + leaveHysteresis)) && (z < cz + h/2 + leaveHysteresis) && (z > cz - h/2 - leaveHysteresis)){   
   // if point is in innermost cylinder
        if((bg::distance(point2d, center2d) < (getRay() - enterHysteresis)) && (z < cz + h/2 - enterHysteresis) && (z > cz - h/2 + enterHysteresis)){
			if(isUpcomingEntity(entityID)){ // was approaching toward innermost cyliner and now just entered it
	           	removeUpcomingEntity(entityID);
	           	addInsideEntity(entityID);
	          	return true;
			}
			else if(enterHysteresis == 0 && leaveHysteresis == 0) // to handle teh case with no hysteresis
			{
				if(isInsideEntity(entityID))
					return true;
				else {
				addInsideEntity(entityID) ;
			    return true;
					
					}
			  	
			}
			else
			{
				return true;
			}
       }
       else {
		    if(isInsideEntity(entityID)){ // still between innermost and outermost cylinder
				return true;
		    }
		    else{
			  addUpcomingEntity(entityID); // just entered outermost cylinder
		      return false;		      
		  }
        }
       }
    else {
		if(isInsideEntity(entityID)){  //just left outermost cylinder
			removeInsideEntity(entityID); // it is no more inside the cylinder so remove it
			addLeavingEntity(entityID);
		    return false ;
		}
		else 
		{
			
			 return false ;
			
		}
		   
		} 

}

// accessors, mutators

bg::model::point<double, 3, bg::cs::cartesian> CircleArea::getCenter() {
    return center;
}

void CircleArea::setCenter(bg::model::point<double, 3, bg::cs::cartesian> areaCenter) {
    center = areaCenter;
}

double CircleArea::getRay() {
    return ray;
}

void CircleArea::setRay(double areaRay) {
    ray = areaRay;
}

bg::model::point<double, 3, bg::cs::cartesian> CircleArea::getCenterRelative() {
    return centerRelative;
}

double CircleArea::getHeight(){
	return height;
}
void CircleArea::setHeight(double heightInz){
	height = heightInz;
}
