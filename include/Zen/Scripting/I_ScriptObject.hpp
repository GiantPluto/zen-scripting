//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPT_OBJECT_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPT_OBJECT_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Event/Event.hpp>

#include <memory>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

/// Wrapper for the script engine's native data types
class SCRIPTING_DLL_LINK I_ScriptObject
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptObject>         pScriptObject_type;
    typedef std::weak_ptr<I_ScriptObject>           wpScriptObject_type;
    typedef Zen::Event::Event<wpScriptObject_type>  scriptObjectEvent_type;
    /// @}

    /// @name I_ScriptObject interface
    /// @{
public:
    /// @}

    /// @name Events
    /// @{
public:
    scriptObjectEvent_type  onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptObject() = default;
    virtual ~I_ScriptObject() = default;
    /// @}
};  // interface I_ScriptObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPT_OBJECT_HPP_INCLUDED
