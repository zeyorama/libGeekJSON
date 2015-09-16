#include "JSONBoolean.hpp"

using namespace std;

namespace GeekJSON
{

  /* ************************************************** */
  /* ************************************************** */
  /* **************** CON-/DESTRUCTORS  *************** */
  /* ************************************************** */
  /* ************************************************** */
  JSONBoolean::JSONBoolean( const bool& Value ) :
    JSONValue(),
    m_Value( Value ) { return; }

  JSONBoolean::~JSONBoolean( void ) { return; }

/* ************************************************** */
/* ************************************************** */
/* ********************* PUBLIC  ******************** */
/* ************************************************** */
/* ************************************************** */
  void
  JSONBoolean::Set( const bool& Value )
  {
    m_Value = Value;
  }

  const bool&
  JSONBoolean::Get( void ) const
  {
    return m_Value;
  }

  string
  JSONBoolean::Generate( const unsigned int )
  {
    return m_Value ? "true" : "false";
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
