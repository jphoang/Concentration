#pragma once

class Point
{
public:
    Point( ); 
    Point( int x_init, int y_init ); 
        

    void shift( int x_amount, int y_amount );
       

    void rotate90( );  

public:
    int x;  
    int y;  
};

inline Point operator+(Point a, Point b) {return Point(a.x+b.x,a.y+b.y);}
inline bool operator==(Point a, Point b) {return (a.x==b.x && a.y==b.y);}
