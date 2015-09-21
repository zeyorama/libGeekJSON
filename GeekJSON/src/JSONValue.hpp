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

 \file JSONValue.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONVALUE_HPP_
#define JSONVALUE_HPP_

#include <string>

namespace GeekJSON
{

  /**
   * \brief Base class for all values descripted in JSON.
   * @version 1.0.0
   */
  class JSONValue
  {
  public:
    JSONValue( void ) { return; }
    virtual ~JSONValue( void ) { return; }

    /**
     * @brief Generates the JSONValue as string and returns it.
     *
     * @param const unsigned int Indentation of this value.
     * @return std::string String-coded value in JSON style.
     * @since 1.0.0
     */
    virtual std::string Generate( const unsigned int ) = 0;

  protected:
  private:
  };

} /* namespace GeekJSON */

#endif /* JSONVALUE_HPP_ */
