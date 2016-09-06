//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_OBJECT_HEAP_HPP_INCLUDED
#define ZEN_SCRIPTING_I_OBJECT_HEAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Event/Event.hpp>

#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ScriptWrapper;

/// @note RAR - I don't think we're actively using this anymore.
///		It was originally part of the implementation of the Java -> C++
///		JNI layer, but we have not been maintaining that and it doesn't
///		even exist in this repository (it's in the old "framework" repo).
class SCRIPTING_DLL_LINK I_ObjectHeap
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ObjectHeap>          pObjectHeap_type;
    typedef std::weak_ptr<I_ObjectHeap>     wpObjectHeap_type;
    typedef Zen::Event::Event<wpObjectHeap_type>            objectHeapEvent_type;

    typedef std::shared_ptr<I_ScriptWrapper>     pScriptWrapper_type;
    /// @}

    /// @name I_ObjectHeap interface
    /// @{
public:
    /// Create a new object based on the object reference.
    /// This really doesn't do anything except maintain the
    /// reference count of the C++ wrapped object.
    virtual void createObject(pScriptWrapper_type _pObject) = 0;

    /// Get the global reference object from the heap that is the same
    /// as the reference passed as a parameter.
    virtual pScriptWrapper_type getGlobalReference(I_ScriptWrapper& _object) = 0;
    /// @}

    /// @name Events
    /// @{
public:
    objectHeapEvent_type   onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ObjectHeap() = default;
    virtual ~I_ObjectHeap() = default;
    /// @}

};  // interface I_ObjectHeap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_OBJECT_HEAP_HPP_INCLUDED
