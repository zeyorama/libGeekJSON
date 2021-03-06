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
  JSONObject::Set( const string& Key, JSONValue * Value )
  {
    if ( Value == this ) return;

    m_Fields.insert( pair< string, JSONValue* >( Key, Value ) );
  }

  string
  JSONObject::Generate( const unsigned int indent )
  {
    string  json    = "{\n";
    bool    commata = false;

    for ( auto& pair : m_Fields )
    {
      if ( commata ) json += ",\n";

      for ( unsigned int i = 0; i < indent + 1; i++ ) json += " ";

      json += "\"" + pair.first + "\" : " + ( pair.second ? pair.second->Generate( indent + 1 ) : "null" );

      commata = true;
    }

    json += "\n";

    for ( unsigned int i = 0; i < indent; i++ ) json += " ";

    json += "}";

    return json;
  }

  JSONValue*
  JSONObject::Get( const string& Key )
  {
    return m_Fields[ Key ];
  }

  JSONArray*
  JSONObject::GetArray( const string& Key )
  {
    return (JSONArray*)( JSONObject::Get( Key ) );
  }

  JSONBoolean*
  JSONObject::GetBoolean( const string& Key )
  {
    return (JSONBoolean*)( JSONObject::Get( Key ) );
  }

  JSONFloat*
  JSONObject::GetFloat( const string& Key )
  {
    return (JSONFloat*)( JSONObject::Get( Key ) );
  }

  JSONInteger*
  JSONObject::GetInteger( const string& Key )
  {
    return (JSONInteger*)( JSONObject::Get( Key ) );
  }

  JSONObject*
  JSONObject::GetObject( const string& Key )
  {
    return (JSONObject*)( JSONObject::Get( Key ) );
  }

  JSONString*
  JSONObject::GetString( const string& Key )
  {
    return (JSONString*)( JSONObject::Get( Key ) );
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
