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

 \file JSONString.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONSTRING_HPP_
#define JSONSTRING_HPP_

#include "JSONValue.hpp"

#include <string>

namespace GeekJSON
{

  /**
   * @brief Contains a string value.
   * @version 1.0.0
   * @author Frank Kevin Zey
   * @extends GeekJSON::JSONValue
   */
  class JSONString : public JSONValue
  {
  public:
    /**
     * @brief Initializes the JSONString instance.
     * @param const std::string& The string value to be set.
     * @since 1.0.0
     */
    JSONString( const std::string& );
    virtual
    ~JSONString( void );

    /**
     * @brief Sets a string value.
     * @param const std::string& The string value to be set.
     * @return void
     * @since 1.0.0
     */
    void
    Set( const std::string& );

    /**
     * @brief Generates the JSONString as string.
     *
     * @param const unsigned int Indentation of this value.
     * @return std::string String-coded string.
     * @since 1.0.0
     */
    std::string
    Generate( const unsigned int ) override;

    /**
     * @return const std::string& Returns the current string value as constant.
     * @since 1.0.0
     */
    const std::string&
    Get( void ) const;

  protected:
  private:
    std::string m_Value;

  };

} /* namespace GeekJSON */

#endif /* JSONSTRING_HPP_ */
