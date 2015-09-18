#include "JSONInterpreter.hpp"

#include "JSONArray.hpp"
#include "JSONFloat.hpp"
#include "JSONValue.hpp"
#include "JSONString.hpp"
#include "JSONInteger.hpp"
#include "JSONBoolean.hpp"

#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct Tokenizer {
  const char* m_input;
  const char* m_charsToIgnore;
  const char* m_tokenChars;
};

void Tokenizer_create( Tokenizer* Tokenizer, const char* input,
                       const char* charsToIgnore, const char* tokenChars )
{
  Tokenizer->m_input         = input;
  Tokenizer->m_charsToIgnore = charsToIgnore;
  Tokenizer->m_tokenChars    = tokenChars;
}

void Tokenizer_release( Tokenizer* Tokenizer )
{
  ( void )( Tokenizer );
}

bool Tokenizer_next_token( Tokenizer* Tokenizer, char* result, unsigned int maxResultLength )
{
  const char* tokenStart;
  unsigned long tokenLength;

  while ( *Tokenizer->m_input != 0 )
  {
    if ( strchr( Tokenizer->m_tokenChars, *Tokenizer->m_input ) != NULL )
    {
      assert( maxResultLength >= 1 );

      result[ 0 ] = *Tokenizer->m_input;
      result[ 1 ] = 0;

      Tokenizer->m_input++;

      return true;
    }

    if ( strchr( Tokenizer->m_charsToIgnore, *Tokenizer->m_input ) == NULL ) break;

    Tokenizer->m_input++;
  }

  if ( *Tokenizer->m_input == 0 ) return false;

  tokenStart = Tokenizer->m_input;

  while( *Tokenizer->m_input != 0 )
  {
    if( strchr( Tokenizer->m_charsToIgnore, *Tokenizer->m_input ) != NULL ||
        strchr( Tokenizer->m_tokenChars, *Tokenizer->m_input )    != NULL ) break;

    Tokenizer->m_input++;
  }

  tokenLength = ( unsigned long )( Tokenizer->m_input - tokenStart );
  assert( maxResultLength >= tokenLength );

  strncpy( result, tokenStart, tokenLength );
  result[ tokenLength ] = 0;

  return true;
}

vector<string>
Split( const string& s, char delim )
{
  vector< string > elems;

  const char*   cstr = s.c_str();
  unsigned int  strLength = (unsigned int)s.length();
  unsigned int  start = 0;
  unsigned int  end = 0;

  while ( end <= strLength )
  {
    while ( end <= strLength )
    {
      if ( cstr[ end ] == delim ) break;

      end++;
    }

    elems.push_back( s.substr( start, end - start ) );
    start = end + 1;
    end   = start;
  }

  return elems;
}

namespace GeekJSON
{
  JSONObject* ReadObject( Tokenizer * token );

  JSONArray*
  ReadArray( Tokenizer * token )
  {
    JSONArray * arr = new JSONArray();
    char        tkn[ 1025 ];

    memset( tkn, '\0', sizeof( char ) * 1025 );

    while ( true )
    {
      Tokenizer_next_token( token, tkn, 1024 );

      string tok = tkn;

      if ( tok == "]" ) break;

      if ( tok == "," ) continue;

      if      ( tok == "\"" )
      {
        Tokenizer_next_token( token, tkn, 1024 );

        tok = tkn;

        if ( tok != "\"" )
        {
          string  val;
          bool    space = false;

          do
          {
            if ( space ) val += " ";

            val += tok;

            Tokenizer_next_token( token, tkn, 1024 );

            tok = tkn;
          }
          while ( tok != "\"" );

          arr->Append( new JSONString( val ) );
        }
        else
        {
          arr->Append( new JSONString( "" ) );
        }
      }
      else if ( tok == "{" )
      {
        arr->Append( ReadObject( token ) );
      }
      else if ( tok == "[" )
      {
        arr->Append( ReadArray( token ) );
      }
      else if ( tok == "true" )
      {
        arr->Append( new JSONBoolean( true ) );
      }
      else if ( tok == "false" )
      {
        arr->Append( new JSONBoolean( false ) );
      }
      else if ( tok == "null" )
      {
        arr->Append( 0 );
      }
      else
      {
        vector< string > numeric = Split( tok, '.' );

        if      ( numeric.size() == 1 )
        {
          arr->Append( new JSONInteger( atoi( tok.c_str() ) ) );
        }
        else if ( numeric.size() == 2 )
        {
          arr->Append( new JSONFloat( atof( tok.c_str() ) ) );
        }
        else
        {
          printf( "ERROR: %s is no numeric value\n", tkn );

          break;
        }
      }
    }

    return arr;
  }

  JSONObject*
  ReadObject( Tokenizer * token )
  {
    JSONObject  * obj = new JSONObject();
    char          tkn[ 1025 ];

    memset( tkn, '\0', sizeof( char ) * 1025 );

    while ( true )
    {
      string      tok;
      string      Key;
      JSONValue * Value = 0;

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if ( tok == "}" ) break;

      if ( tok != "\"" )
      {
        printf( "ERROR: Keys have to start with \" found '%s'\n", tkn );

        break;
      }

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if ( tok == "\"" )
      {
        printf( "ERROR: Key is emtpy\n" );

        break;
      }

      tok.swap( Key );

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if ( tok != "\"" )
      {
        printf( "ERROR: Key contains ' '\n" );

        break;
      }

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if ( tok != ":" )
      {
        printf( "ERROR: No ':' found\n" );

        break;
      }

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if      ( tok == "\"" )
      {
        Tokenizer_next_token( token, tkn, 1024 );

        tok = tkn;

        if ( tok != "\"" )
        {
          string  val;
          bool    space = false;

          do
          {
            if ( space ) val += " ";

            space = true;

            val += tok;

            Tokenizer_next_token( token, tkn, 1024 );

            tok = tkn;
          }
          while ( tok != "\"" );

          Value = new JSONString( val );
        }
        else
        {
          Value = new JSONString( "" );
        }
      }
      else if ( tok == "{" )
      {
        Value = ReadObject( token );
      }
      else if ( tok == "[" )
      {
        Value = ReadArray( token );
      }
      else if ( tok == "true" )
      {
        Value = new JSONBoolean( true );
      }
      else if ( tok == "false" )
      {
        Value = new JSONBoolean( false );
      }
      else if ( tok == "null" )
      {
        Value = 0;
      }
      else
      {
        vector< string > numeric = Split( tok, '.' );

        if      ( numeric.size() == 1 )
        {
          Value = new JSONInteger( atoi( tok.c_str() ) );
        }
        else if ( numeric.size() == 2 )
        {
          Value = new JSONFloat( atof( tok.c_str() ) );
        }
        else
        {
          printf( "ERROR: %s is no numeric value\n", tkn );

          break;
        }
      }

      obj->Set( Key, Value );

      Tokenizer_next_token( token, tkn, 1024 );

      tok = tkn;

      if ( tok == "}" ) break;
    }

    return obj;
  }

  JSONObject*
  ReadFromString( const string& JSON )
  {
    Tokenizer     token;
    char          tkn[ 1025 ];
    string        tok;

    memset( tkn, '\0', sizeof( char ) * 1025 );

    Tokenizer_create( &token, JSON.c_str(), " \t\n", "{},\":" );

    Tokenizer_next_token( &token, tkn, 1024 );
    tok = tkn;

    if ( tok != "{" )
    {
      printf( "ERROR: JSON String have to start with an object\n" );

      return 0;
    }

    return ReadObject( &token );
  }

  JSONObject*
  ReadFromFile( const string& JSONFile )
  {
    ifstream file( JSONFile );

    return ReadFromString ( string( std::istreambuf_iterator<char>( file ),
                                    std::istreambuf_iterator<char>()
                                  )
                          );
  }

} /* namespace GeekJSON */
