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

      for ( unsigned int i = 0; i < indent; i++ ) json += " ";

      json += "\"" + pair.first + "\" : " + pair.second ? pair.second->Generate( indent + 1 ) : "null";

      commata = true;
    }

    json += "\n}";

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
