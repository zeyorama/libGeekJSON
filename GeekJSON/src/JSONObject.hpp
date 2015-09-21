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

 \file JSONObject.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONOBJECT_HPP_
#define JSONOBJECT_HPP_

#include "JSONValue.hpp"

#include <map>
#include <string>

namespace GeekJSON
{

  class JSONArray;
  class JSONFloat;
  class JSONString;
  class JSONBoolean;
  class JSONInteger;

  /**
   * @brief Contains a map of key and values.
   * @version 1.0.0
   * @author Frank Kevin Zey
   * @extends GeekJSON::JSONValue
   */
  class JSONObject : public JSONValue
  {
  public:
    /**
     * @brief Initialize the JSONObject instance.
     */
    JSONObject( void );
    virtual
    ~JSONObject( void );

    /**
     * @brief Sets a pair of key string and JSONValue.
     * @param const std::string& Key of the pair
     * @param JSONValue* Value of the pair.
     * @return void
     * @since 1.0.0
     */
    void
    Set( const std::string&, JSONValue* );

    /**
     * @brief Generates the object as string and returns it.
     *
     * @param const unsigned int Indentation of this object.
     * @return std::string String-coded object in JSON style.
     * @since 1.0.0
     * @see JSONValue::Generate()
     */
    std::string
    Generate( const unsigned int ) override;

    /**
     * @brief Returns the value matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONValue* The value matching to the key.
     * @since 1.0.0
     */
    JSONValue*
    Get( const std::string& );

    /**
     * @brief Returns the array matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONArray* The array matching to the key.
     * @since 1.0.0
     */
    JSONArray*
    GetArray( const std::string& );

    /**
     * @brief Returns the boolean value matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONBoolean* The boolean value matching to the key.
     * @since 1.0.0
     */
    JSONBoolean*
    GetBoolean( const std::string& );

    /**
     * @brief Returns the float matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONFloat* The float matching to the key.
     * @since 1.0.0
     */
    JSONFloat*
    GetFloat( const std::string& );

    /**
     * @brief Returns the int matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONInteger* The int matching to the key.
     * @since 1.0.0
     */
    JSONInteger*
    GetInteger( const std::string& );

    /**
     * @brief Returns the object matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONobject* The object matching to the key.
     * @since 1.0.0
     */
    JSONObject*
    GetObject( const std::string& );

    /**
     * @brief Returns the string value matching to the given key.
     *
     * @param const std::string& The key to be looking for.
     * @return JSONValue* The string value matching to the key.
     * @since 1.0.0
     */
    JSONString*
    GetString( const std::string& );

  protected:
  private:
    std::map< std::string, JSONValue* > m_Fields;

  };

} /* namespace GeekJSON */

#endif /* JSONOBJECT_HPP_ */
