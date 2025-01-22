               
               // LeetCode - 1401

// if any doubt abt the approach just take any example it will verify them and you get to know 
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // just find out the nearest point x and nearest point y to the circle 
        // just check wether the circle lies on left side aur ride by this statement min(x2xcenter)
        // and min(y2,ycenter) if it is x2 , y2 then on the right side otherwise left side 
        
        int nearest_x = max(x1, min(x2,xCenter));
        int nearest_y = max(y1, min(y2,yCenter));
        
        // to verify what are below dx and dy just draw a circle on the right side of rectangle 
        // we get to know that we have to apply pythagorus theorem to get the distance d 
        // for that we need dx and dy

        int dx = xCenter - nearest_x;
        int dy = yCenter - nearest_y;

        // now just apply pythagorus theorem and we get the result 
        
        return dx*dx + dy*dy <= radius*radius;
    }

