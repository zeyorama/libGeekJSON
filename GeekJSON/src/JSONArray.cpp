#include "JSONArray.hpp"

#include "JSONFloat.hpp"
#include "JSONObject.hpp"
#include "JSONString.hpp"
#include "JSONBoolean.hpp"
#include "JSONInteger.hpp"

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

  JSONValue*
  JSONArray::Get( const unsigned int& Index )
  {
    return m_List[ Index ];
  }

  JSONArray*
  JSONArray::GetArray( const unsigned int& Index )
  {
    return (JSONArray*)( Get( Index ) );
  }

  JSONBoolean*
  JSONArray::GetBoolean( const unsigned int& Index )
  {
    return (JSONBoolean*)( Get( Index ) );
  }

  JSONFloat*
  JSONArray::GetFloat( const unsigned int& Index )
  {
    return (JSONFloat*)( Get( Index ) );
  }

  JSONInteger*
  JSONArray::GetInteger( const unsigned int& Index )
  {
    return (JSONInteger*)( Get( Index ) );
  }

  JSONObject*
  JSONArray::GetObject( const unsigned int& Index )
  {
    return (JSONObject*)( Get( Index ) );
  }

  JSONString*
  JSONArray::GetString( const unsigned int& Index )
  {
    return (JSONString*)( Get( Index ) );
  }

  string
  JSONArray::Generate( const unsigned int indent )
  {
    string  json    = "[ ";
    bool    commata = false;

    for ( JSONValue * Value : m_List )
    {
      if ( commata ) json += ", ";

      json += Value->Generate( indent + 1 );

      commata = true;
    }

    json += " ]";

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
