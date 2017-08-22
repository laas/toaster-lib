// This class define a rectangle area.
#include "PolygonArea.h"

#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/geometry/geometries/adapted/c_array.hpp>
#include <iostream>
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)
using namespace std;

// constructor
PolygonArea::PolygonArea(int areaId, double points[][2], unsigned int polySize, double zmin, double zmax, double enter, double leave) : Area(areaId), enterHysteresis(enter), leaveHysteresis(leave) {
    for (unsigned int i = 0; i < polySize; i++) {
        bg::model::d2::point_xy<double> p(points[i][0], points[i][1]);
        bg::append(polyRelative_, p);
        bg::append(poly_, p);
    }
    z = boost::make_tuple(zmin , zmax);
    zRelative = boost::make_tuple(zmin , zmax);

}


// check if given point is in 2.5D areas
bool PolygonArea::isPointInArea(bg::model::point<double, 3, bg::cs::cartesian> point, std::string entityID) {

    boost::tuple<double, double> p = boost::make_tuple(point.get<0>(), point.get<1>());
    bg::model::polygon<bg::model::d2::point_xy<double> > enter_poly_;
    bg::model::polygon<bg::model::d2::point_xy<double> > leave_poly_;

    double zmin = z.get<0>();
    double zmax = z.get<1>();
    std::vector<boost::tuple<double, double> > vertices;
    std::vector<boost::tuple<double, double, double> > mc;
    // extracts vertices of main polygon into vector 
    std::vector<boost::tuple<double, double> >::const_iterator it;
        for (int i = 0; i != poly_.outer().size(); ++i) {
        double x = boost::geometry::get<0>(poly_.outer()[i]);
        double y = boost::geometry::get<1>(poly_.outer()[i]);
        boost::tuple<double, double> pv1 = boost::make_tuple(x,y);
        vertices.push_back(pv1);
    }
 int r = 1;
    for(std::vector<boost::tuple<double, double> >::iterator i = vertices.begin(); i < vertices.end(); ++i){
        double x1 = i->get<0>();
        double y1 = i->get<1>();
        if(i+1 == vertices.end())
          it = vertices.begin();
        else
          it = i+1;
        double a , m, c;
        double x2 = it->get<0>();
        double y2 = it->get<1>();
        // finds the parameters of line's equations. The equation line has the form a*y = m*x + c. where slope is m/a and intercept is c/a .
        if(x2 != x1)
        {   a = 1;
            m = (y2 - y1)/(x2 - x1);
            c = y1 - m*x1;
        } else {
            a = 0;
            m = 1;
            c = -x1;
        }
        r = r + 1 ;
        if(i+2 == vertices.end())
          it = vertices.begin();
        else if(i+1 == vertices.end())
           {it = vertices.begin() + 1;}
        else 
          it = i+2;
        double x ;
        double x3 = it->get<0>();
        double y3 = it->get<1>();
        // x is calculated to find the direction in which line is to be shifted
        if(m!=0)
			x = (a*y3 - c)/m;
		else {
		  if(y3 > c) {
			// shifts the line by changing the intercept to get edge of inner polygon  
			c = c + enterHysteresis ;
			boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1); 			  
		  }
		  else {
			// shifts the line by changing the intercept to get edge of inner polygon
			c = c - enterHysteresis ;
			boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1);  
			  
		  } 	
						
		}
		
		if(m != 0)	{
		// shifts the line by changing the intercept to get edge of inner polygon
        if(x3 > x )
        {
          if(-c/m > 0)
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) + enterHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) + enterHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1);

          }
          else
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) - enterHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) - enterHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1);

          }
        }
        else
        {
          if(-c/m > 0)
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) - enterHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) - enterHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1);

          }
          else
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) + enterHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) + enterHysteresis)*(sqrt(m*m + a*a));
           
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc.push_back(mc1);

          }
        
	  }
    }
   }
		std::vector<boost::tuple<double, double, double> >::iterator it2 ;
        //std::cout << "Enter polygon is :"<<endl;
        int s = 1;
        double xend1 ;
        double yend1 ;
        for(std::vector<boost::tuple<double, double, double> >::iterator i = mc.begin(); i != mc.end(); ++i){
            if(i+1 == mc.end())
              it2 = mc.begin();
            else
              it2  = i + 1;
           double a1 = boost::get<0>(*i) ;
           double m1 = boost::get<1>(*i) ;
           double c1 = boost::get<2>(*i) ;
           double a2 = boost::get<0>(*it2) ;
           double m2 = boost::get<1>(*it2) ;
           double c2 = boost::get<2>(*it2) ;
           double x, y ;
           // calculates intersection points of shifted lines to get vertices of inner polygon
           if (a1 != 0 && a2 != 0) {
			 x = ((c2/a2) - (c1/a1))/((m1/a1) - (m2/a2)) ;
			 y = (m1*x + c1)/a1 ;
		   } else {
			 if(a1 == 0)
			  {
				  x =  -c1 / m1 ;
				  y = (m2*x + c2)/a2 ;
			  }   
			  else 
			  {
				  x = -c2 / m2 ;
				  y = (m1*x + c1)/a1 ;  
			  }
			   
		   }
		   		
		   	if(i == mc.begin()) {
				xend1 = x;
				yend1 = y;
			}	
            boost::tuple<double, double> xy = boost::make_tuple(x, y);
            bg::append(enter_poly_,xy);
           
           // std::cout<< s <<". x is "<< x << " and y is "<< y << endl;
            s = s + 1;
        }
	boost::tuple<double, double> xy = boost::make_tuple(xend1, yend1);
    bg::append(enter_poly_,xy);
    std::vector<boost::tuple<double, double, double> > mc2;
    // extraction of vertices from original polygon
    for(std::vector<boost::tuple<double, double> >::iterator i = vertices.begin(); i < vertices.end(); ++i){
        double x1 = i->get<0>();
        double y1 = i->get<1>();
        if(i+1 == vertices.end())
          it = vertices.begin();
        else
          it = i+1;
        double a , m, c;
        double x2 = it->get<0>();
        double y2 = it->get<1>();
        if(x2 != x1)
        {   a = 1;
            m = (y2 - y1)/(x2 - x1);
            c = y1 - m*x1;

        } else {
            a = 0;
            m = 1;
            c = -x1;
        }
        r = r + 1 ;
        if(i+2 == vertices.end())
          it = vertices.begin();
        else if(i+1 == vertices.end())
           {it = vertices.begin() + 1;}
        else 
          it = i+2;
        double x ;
        double x3 = it->get<0>();
        double y3 = it->get<1>();
        if(m!=0)
			x = (a*y3 - c)/m;
		else {
		  if(y3 > c) {
			 // shifts the line by changing the intercept to get edge of outer polygon
			c = c - leaveHysteresis ;
			boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1); 			  
		  }
		  else {
			// shifts the line by changing the intercept to get edge of outer polygon
			c = c + leaveHysteresis ;
			boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1);  
			  
		  } 	
						
		}
		
		if(m != 0)	{
			// shifts the line by changing the intercept to get edge of outer polygon
        if(x3 > x )
        {
          if(-c/m > 0)
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) - leaveHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) - leaveHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1);

          }
          else
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) + leaveHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) + leaveHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1);

          }
        }
        else
        {
          if(-c/m > 0)
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) + leaveHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) + leaveHysteresis)*(sqrt(m*m + a*a));
            
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1);

          }
          else
          {
			if (c < 0){
            c = -(abs(c / sqrt(m*m + a*a)) - leaveHysteresis)*(sqrt(m*m + a*a));
            
		} else {
			c = (abs(c / sqrt(m*m + a*a)) - leaveHysteresis)*(sqrt(m*m + a*a));
           
			
			}
            boost::tuple<double, double, double> mc1 = boost::make_tuple(a, m, c);
            mc2.push_back(mc1);

          }
        
	}
        }
	}
  
int t = 1;
std::vector<boost::tuple<double, double, double> >::iterator it3 ;
double xend2 ;
double yend2;
//cout << "leave polygon is : "<<endl;
        for(std::vector<boost::tuple<double, double, double> >::iterator i = mc2.begin(); i < mc2.end(); ++i){
            if(i+1 == mc2.end())
              it3 = mc2.begin();
            else
              it3  = i + 1;
           double a1 = boost::get<0>(*i) ;
           double m1 = boost::get<1>(*i) ;
           double c1 = boost::get<2>(*i) ;
           double a2 = boost::get<0>(*it3) ;
           double m2 = boost::get<1>(*it3) ;
           double c2 = boost::get<2>(*it3) ;
           double x, y ;
           // calculates intersection of outward shifted lines to find vertices of outer polygon
           if (a1 != 0 && a2 != 0) {
			 x = ((c2/a2) - (c1/a1))/((m1/a1) - (m2/a2)) ;
			 y = (m1*x + c1)/a1 ;
		   } else {
			 if(a1 == 0)
			  {
				  x =  -c1 / m1 ;
				  y = (m2*x + c2)/a2 ;
			  }   
			  else 
			  {
				  x = -c2 / m2 ;
				  y = (m1*x + c1)/a1 ;  
			  }
			   
		   }
		    if(i == mc2.begin()) {
				xend2 = x;
				yend2 = y;
			}
		    			
            boost::tuple<double, double> xy = boost::make_tuple(x, y);
            bg::append(leave_poly_,xy);
           
           // std::cout<< s <<". x is "<< x << " and y is "<< y << endl;
            s = s + 1;
        }
        xy = boost::make_tuple(xend2, yend2);
        bg::append(leave_poly_,xy) ;
       // if point is inside the outermost 2.5D polygon 
       if ( bg::within(p, leave_poly_) && ( point.get<2>() < zmax + leaveHysteresis )  && ( point.get<2>() > zmin - leaveHysteresis )  ){
        // if point is inside the innermost 2.5D polygon
        if ( bg::within(p, enter_poly_) && ( point.get<2>() < zmax - enterHysteresis )  && ( point.get<2>() > zmin + enterHysteresis )  ){
            if(isUpcomingEntity(entityID)){ // signs of entity was approching towards this area or is on boundary
	           	removeUpcomingEntity(entityID);
	           	addInsideEntity(entityID); // and finally it entered inside
	          	return true;
			}
			else if(enterHysteresis == 0 && leaveHysteresis == 0)
			{
				if(isInsideEntity(entityID)) // handle the case where no hysteresis exist
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
		    if(isInsideEntity(entityID)){ // is not left the outermost polygon so it is considered to be inside
				return true;
		    }
		    else{
			  if(isUpcomingEntity(entityID)) // is still between outermost polygon and main polygon, not entered innermost yet
					return false;
				else {
				addUpcomingEntity(entityID) ; // just enterd the outermost circle
			    return false;
					
				}		      
		  }
        }
       }
    else {
		if(isInsideEntity(entityID)){ // just left the outermost circle
			removeInsideEntity(entityID); // remove it from inside entity
			addLeavingEntity(entityID);
		    return false ;
		}
		else 
		{			
			 return false ;			
		}
    }
}


// Accessors

bg::model::polygon<bg::model::d2::point_xy<double> > PolygonArea::getPolyRelative() {
    return polyRelative_;
}

boost::tuple<double,double> PolygonArea::getZRelative(){
    return zRelative ;
}

double PolygonArea::getZmin(){
    return z.get<0>();
}
double PolygonArea::getZmax(){
    return z.get<1>();
}
