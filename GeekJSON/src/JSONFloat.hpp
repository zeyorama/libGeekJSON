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

 \file JSONFloat.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONFLOAT_HPP_
#define JSONFLOAT_HPP_

#include "JSONValue.hpp"

#include <string>

namespace GeekJSON
{

  /**
   * @brief Contains a float value.
   * @version 1.0.0
   * @author Frank Kevin Zey
   * @extends GeekJSON::JSONValue
   */
  class JSONFloat : public JSONValue
  {
  public:
    /**
     * @brief Initializes the JSONFloat instance.
     * @param const int& The float value to be set.
     * @since 1.0.0
     */
    JSONFloat( const float& );
    virtual
    ~JSONFloat( void );

    /**
     * @brief Sets a float value.
     * @param const float& The float value to be set.
     * @return void
     * @since 1.0.0
     */
    void
    Set( const float& );

    /**
     * @brief Gets the float value.
     * @return const float& The stored float value.
     * @since 1.0.0
     */
    const float&
    Get( void ) const;

    /**
     * @brief Generates the JSONFloat as string.
     *
     * @param const unsigned int Indentation of this value.
     * @return std::string String-coded float.
     * @since 1.0.0
     */
    std::string
    Generate( const unsigned int ) override;

  protected:
  private:
    float m_Value;

  };

} /* namespace GeekJSON */

#endif /* JSONFLOAT_HPP_ */
