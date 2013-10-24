#pragma once
#define DEFAULT_BAG 20


template <class Item>
class Bag {
public: 
    Bag(unsigned int max_capacity=DEFAULT_BAG);                               
    ~Bag( );  
    void add(Item value);                    
    Item getOne( ); 
    bool isEmpty( ) const; 
    bool isFull( ) const;
    unsigned int currentSize( ) const;   
    unsigned int capacity( ) const;        

private: 
    unsigned int m_size; 
    unsigned int m_max_capacity; 
    Item * m_container;   
};  

#include "Bag.template" 

