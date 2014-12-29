#include "VisualCard.h"
#include "cs1037lib-window.h"

VisualCard::VisualCard(Suit suit, Denomination denomination)
: m_face_up(false)
, m_rect()
, Card(suit,denomination) 
{
}

VisualCard::~VisualCard(void)
{
}


void VisualCard::drawAt(Point pos)
{	
	m_rect=Rect(pos,CARD_WIDTH,CARD_HEIGHT); 
    if (isFaceUp()) 
    {
        
        SetDrawColour(180,180,180);
        DrawRectangleFilled(m_rect.get_left(),m_rect.get_top(),m_rect.get_right(),m_rect.get_bottom());

        char text[2]="0";
        SetDrawColour(0,0,0);
        text[0]=toCharSuit();
        DrawText(m_rect.get_left()+10,m_rect.get_top()+8,text);
        text[0] = toCharDenomination();
        DrawText(m_rect.get_left()+10,m_rect.get_top()+30,text);
	}
    else 
    {
        SetDrawColour(0,190,0);
        DrawRectangleFilled(m_rect.get_left(),m_rect.get_top(),m_rect.get_right(),m_rect.get_bottom());
    }
}
