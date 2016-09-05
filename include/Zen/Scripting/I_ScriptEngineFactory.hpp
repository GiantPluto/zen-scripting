//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPT_ENGINE_FACTORY_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPT_ENGINE_FACTORY_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Plugin/I_ClassFactory.hpp>

#include <map>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptEngine;

class SCRIPTING_DLL_LINK I_ScriptEngineFactory
:   public Plugin::I_ClassFactory
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptEngine>        pScriptEngine_type;
    typedef std::weak_ptr<I_ScriptEngine>   wpScriptEngine_type;
    /// @}

    /// @name I_ScriptEngineFactory interface
    /// @{
public:
    /// Create a script engine
    /// Do not delete this object.  Call delete() instead.
    virtual pScriptEngine_type create(const std::string& _name) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptEngineFactory();
    virtual ~I_ScriptEngineFactory();
    /// @}

};  // interface I_ScriptEngineFactory

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting 
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPT_ENGINE_FACTORY_HPP_INCLUDED
