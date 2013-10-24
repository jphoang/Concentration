#pragma once
#include "VisualCard.h"


class ImageCard : public VisualCard
{
public:
    ImageCard(Suit suit = HEARTS, Denomination denomination = N2); 
    ~ImageCard(void); 
	
    
	void drawAt(Point pos); 

private:	
	int m_im_face;   
	int m_im_back;
};
