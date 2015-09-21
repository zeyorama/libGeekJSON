/*
 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:

 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.

 \file JSONArray.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONARRAY_HPP_
#define JSONARRAY_HPP_

#include "JSONValue.hpp"

#include <string>
#include <vector>

namespace GeekJSON
{

  class JSONFloat;
  class JSONObject;
  class JSONString;
  class JSONBoolean;
  class JSONInteger;

  class JSONArray : public JSONValue
  {
  public:
    JSONArray( void );
    virtual
    ~JSONArray( void );

    /**
     * @brief Appends a JSONValue to the list.
     * @param JSONValue* Value to be pushed.
     * @return void
     * @since 1.0.0
     */
    void
    Append( JSONValue* );

    /**
     * @brief Empties the list and deletes all JSONValue pointers.
     * @return void
     * @since 1.0.0
     */
    void
    Clear( void );

    /**
     * @brief Emtpies the list, but all JSONValue pointer won't be touched.
     * @return void
     * @since 1.0.0
     */
    void
    Empty( void );

    /**
     * @brief Returns the number of all containing elements.
     * @return unsigned int Number of all containing elements.
     * @since 1.0.0
     */
    unsigned int
    Count( void ) const;

    /**
     * @brief Returns the value matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONValue* The value at the index.
     * @since 1.0.0
     */
    JSONValue*
    Get( const unsigned int& );

    /**
     * @brief Returns the array matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONArray* The array at the index.
     * @since 1.0.0
     */
    JSONArray*
    GetArray( const unsigned int& );

    /**
     * @brief Returns the boolean matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONBoolean* The boolean at the index.
     * @since 1.0.0
     */
    JSONBoolean*
    GetBoolean( const unsigned int& );

    /**
     * @brief Returns the float matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONFloat* The float at the index.
     * @since 1.0.0
     */
    JSONFloat*
    GetFloat( const unsigned int& );

    /**
     * @brief Returns the int matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONInteger* The int at the index.
     * @since 1.0.0
     */
    JSONInteger*
    GetInteger( const unsigned int& );

    /**
     * @brief Returns the object matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONObject* The object at the index.
     * @since 1.0.0
     */
    JSONObject*
    GetObject( const unsigned int& );

    /**
     * @brief Returns the string value matching at the index.
     *
     * @param const unsigned int& The index to be looking for.
     * @return JSONValue* The string value at the index.
     * @since 1.0.0
     */
    JSONString*
    GetString( const unsigned int& );

    /**
     * @brief Generates the array as string and returns it.
     *
     * @param const unsigned int Indentation of this array.
     * @return std::string String-coded array in JSON style.
     * @since 1.0.0
     * @see JSONValue::Generate()
     */
    std::string
    Generate( const unsigned int ) override;

  protected:
  private:
    std::vector< JSONValue* > m_List;

  };

} /* namespace GeekJSON */

#endif /* JSONARRAY_HPP_ */
