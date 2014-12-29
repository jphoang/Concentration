#include "ImageCard.h"
#include "cs1037lib-image.h"
#include <iostream>   



ImageCard::ImageCard(Suit suit, Denomination denomination)
: VisualCard(suit,denomination) 
{
	char face_image_file_name[50], back_image_file_name[50];
    sprintf_s(face_image_file_name,50,"./cards_bmp/%c%c.bmp",toCharSuit(),toCharDenomination());
	sprintf_s(back_image_file_name,50,"./cards_bmp/b1fv.bmp");
	m_im_face = LoadImage(face_image_file_name); 
	m_im_back = LoadImage(back_image_file_name); 
}

ImageCard::~ImageCard(void)
{
	
	if (m_im_face!=0) DeleteImage(m_im_face);
	if (m_im_back!=0) DeleteImage(m_im_back);
}


void ImageCard::drawAt(Point pos)
{	
	
	if (m_im_face==0 || m_im_back==0) {VisualCard::drawAt(pos); return;} 

	if (isFaceUp()) {
		m_rect=Rect(pos,GetImageSizeX(m_im_face),GetImageSizeY(m_im_face)); 
		DrawImage(m_im_face, pos.x, pos.y); 
	}
	else {
		m_rect=Rect(pos,GetImageSizeX(m_im_back),GetImageSizeY(m_im_back)); 
		DrawImage(m_im_back, pos.x, pos.y); 
	}
}
