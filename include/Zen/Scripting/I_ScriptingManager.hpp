//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPTING_MANAGER_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPTING_MANAGER_HPP_INCLUDED

#include "Configuration.hpp"

#include <memory>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptEngine;
class I_ScriptModule;

class SCRIPTING_DLL_LINK I_ScriptingManager
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptEngine>    pScriptEngine_type;
    typedef std::shared_ptr<I_ScriptModule>    pScriptModule_type;
    /// @}

    /// @name I_ScriptingManager interface
    /// @{
public:
    /// Create a script engine by name
    /// @param _name The name of a script engine.  Currently supported names
    ///             include "python" and "lua" but it's possible that other
    ///             scripting plugins can be created.
    /// @return NULL if the engine isn't found, otherwise the engine is returned
    ///             The engine must be destroyed by calling destroyScriptEngine
    virtual pScriptEngine_type createScriptEngine(const std::string& _name) = 0;
    /// @}

    /// @name Static Methods
    /// @{
public:
    static I_ScriptingManager& getSingleton();
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptingManager();
    virtual ~I_ScriptingManager();
    /// @}

};  // interface I_ScriptingManager

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPTING_MANAGER_HPP_INCLUDED
