/**
 * This file is part of Oshiya, an XEP-0357 compatible XMPP component
 * Copyright (C) 2015 Christian Ulrich <christian@rechenwerk.net>
 * 
 * Oshiya is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Oshiya is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Oshiya.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "XmlElement.hpp"

using namespace Oshiya;

XmlElement::XmlElement()
    : mStanza {nullptr}
{

}

XmlElement::XmlElement(xmpp_stanza_t* stanza)
    : mStanza {xmpp_stanza_clone(stanza)}
{

}

XmlElement::XmlElement(const XmlElement& other)
    : mStanza {xmpp_stanza_copy(other.mStanza)}
{
    
}

XmlElement& XmlElement::operator=(const XmlElement& other)
{
    if(this != &other)
    {
        free();
        mStanza = xmpp_stanza_copy(other.mStanza);
    }

    return *this;
}

//XmlElement::XmlElement(XmlElement&& other)
//    : mStanza {other.mStanza}
//{
//    other.mStanza = nullptr;
//}

//XmlElement& XmlElement::operator=(XmlElement&& other)
//{
//    if(this != &other)
//    {
//        free();
//        mStanza = other.mStanza;
//        other.mStanza = nullptr;
//    }
//
//    return *this;
//}

XmlElement::~XmlElement()
{
    free();
}

void XmlElement::free()
{
    if(mStanza)
    {
        xmpp_stanza_release(mStanza);
    }
}