#pragma once
#include "Card.h"
#include "Rect.h"

#define CARD_WIDTH 70 
#define CARD_HEIGHT 95 

class VisualCard : public Card    
{
public:
    VisualCard(Suit suit = HEARTS, Denomination denomination = N2); 
    ~VisualCard(void); 

    inline bool isFaceUp(void) const {return m_face_up;}
    inline void setFaceUp(void) {m_face_up = true;}
    inline void setFaceDown(void) {m_face_up = false;}

    
    inline bool pointInCard(Point point) const {return m_rect.ptInRect(point);}
	

	void drawAt(Point pos);

private:
	bool m_face_up; 

protected:	
	Rect m_rect;   
};
