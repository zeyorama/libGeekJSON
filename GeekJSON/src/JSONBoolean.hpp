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

 \file JSONBoolean.hpp

 Created on: Sep 16, 2015
 \author     fkzey
 */

#ifndef JSONBOOLEAN_HPP_
#define JSONBOOLEAN_HPP_

#include "JSONValue.hpp"

#include <string>

namespace GeekJSON
{

  class JSONBoolean : public JSONValue
  {
  public:
    JSONBoolean( const bool& );
    virtual
    ~JSONBoolean( void );

    void
    Set( const bool& );

    const bool&
    Get( void ) const;

    std::string
    Generate( const unsigned int ) override;

  protected:
  private:
    bool  m_Value;

  };

} /* namespace GeekJSON */

#endif /* JSONBOOLEAN_HPP_ */
