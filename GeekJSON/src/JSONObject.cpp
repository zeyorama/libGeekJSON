#include "JSONObject.hpp"

using namespace std;

namespace GeekJSON
{

  /* ************************************************** */
  /* ************************************************** */
  /* **************** CON-/DESTRUCTORS  *************** */
  /* ************************************************** */
  /* ************************************************** */
  JSONObject::JSONObject( void ) :
    JSONValue() { return; }

  JSONObject::~JSONObject( void )
  {
    for ( auto& pair : m_Fields ) delete pair.second;

    m_Fields.clear();
  }

/* ************************************************** */
/* ************************************************** */
/* ********************* PUBLIC  ******************** */
/* ************************************************** */
/* ************************************************** */
  void
  JSONObject::Set( const string& Key, const JSONValue * Value )
  {
    m_Fields.insert( pair< string, JSONValue* >( Key, Value ) );
  }

  string
  JSONObject::Generate( void )
  {
    string  json    = "{";
    bool    commata = false;

    for ( auto& pair : m_Fields )
    {
      if ( commata ) json += ",\n";

      json += "\"" + pair.first + "\" : " + pair.second->Generate();

      commata = true;
    }

    json += "}";

    return json;
  }

  JSONValue*
  JSONObject::Get( const string& Key )
  {
    return m_Fields[ Key ];
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
