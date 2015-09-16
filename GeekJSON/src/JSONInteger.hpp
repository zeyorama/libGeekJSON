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

 \file JSONInteger.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONINTEGER_HPP_
#define JSONINTEGER_HPP_

#include "JSONValue.hpp"

#include <string>

namespace GeekJSON
{

  /*
   * GeekJSON::JSONInteger
   *
   *
   */
  class JSONInteger : public JSONValue
  {
  public:
    JSONInteger( const int& );
    virtual
    ~JSONInteger( void );

    void
    Set( const int& );

    const int&
    Get( void ) const;

    std::string
    Generate( void ) override;

  protected:
  private:
    int m_Value;

  };

} /* namespace GeekJSON */

#endif /* JSONINTEGER_HPP_ */
