#ifndef _MYTRICKS_OBJECTBASE_HPP_INCLUDED_
# define _MYTRICKS_OBJECTBASE_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


namespace mytricks {

class Object {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* the Base of Everything!
\**********************************/
protected:
    Object(void) {}
    virtual ~Object() {}

}; // class Object

class BasicObj : public Object {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* the Base of All Landscape Units.
* in MY opinion, EACH Type is ONE Obj!
* so, NO position info included.
\**********************************/
protected:
    BasicObj(int type) : typeID(type) {}
    virtual ~BasicObj() {}

    int typeID;

}; // class BasicObj
typedef BasicObj LandscapeType;

class AdvanceObj : public Object {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* "with Position"
* Just for Pointers.
\**********************************/
protected:
    AdvanceObj(void) {}
    virtual ~AdvanceObj() {}

}; // class AdvanceObj

} // namespace mytricks


#endif // _MYTRICKS_OBJECTBASE_HPP_INCLUDED_