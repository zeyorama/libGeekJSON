#include "JSONArray.hpp"

using namespace std;

namespace GeekJSON
{

  /* ************************************************** */
  /* ************************************************** */
  /* **************** CON-/DESTRUCTORS  *************** */
  /* ************************************************** */
  /* ************************************************** */
  JSONArray::JSONArray( void ) :
    JSONValue() { return; }

  JSONArray::~JSONArray( void )
  {
    Clear();
  }

/* ************************************************** */
/* ************************************************** */
/* ********************* PUBLIC  ******************** */
/* ************************************************** */
/* ************************************************** */
  void
  JSONArray::Append( JSONValue * Value )
  {
    if ( Value == this ) return;

    m_List.push_back( Value );
  }

  void
  JSONArray::Clear( void )
  {
    for ( JSONValue * Value : m_List ) delete Value;

    m_List.clear();
  }

  void
  JSONArray::Empty( void )
  {
    m_List.clear();
  }

  unsigned int
  JSONArray::Count( void ) const
  {
    return ( unsigned int )( m_List.size() );
  }

  string
  JSONArray::Generate( void )
  {
    string  json    = "[";
    bool    commata = false;

    for ( JSONValue * Value : m_List )
    {
      if ( commata ) json += ",";

      json += Value->Generate();

      commata = true;
    }

    json += "]";

    return json;
  }

/* ************************************************** */
/* ************************************************** */
/* *******************  PROTECTED ******************* */
/* ************************************************** */
/* ************************************************** */

/* ************************************************** */
/* ************************************************** */
/* ********************* PRIVATE ******************** */
/* ************************************************** */
/* ************************************************** */

} /* namespace GeekJSON */
