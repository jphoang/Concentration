template <class T>
class DynArray {
public:
    DynArray();   
    DynArray(int size); 
    ~DynArray(); 

    int getSize() const {return m_size;} 
    T& operator[](int x) const;  
    void resize(int new_size); 
 
private:
    T* m_container;
    int m_size;
};
#include "DynArray.template"
