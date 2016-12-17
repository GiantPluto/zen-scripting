//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Enterprise Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPTABLE_SERVICE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPTABLE_SERVICE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Scripting/I_ScriptEngine.hpp>
#include <Zen/Scripting/I_Scriptable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
;

/// Scriptable service.
/// A scriptable service is a top level service that can be exposed to a
/// scripting language.  This can be an extension style service using Zen::Plugin
/// plugin system, or it can be an application service using Zen::Enterprise
/// I_ApplicationService.
class SCRIPTING_DLL_LINK I_ScriptableService
:   public I_Scriptable
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<Scripting::I_ScriptEngine> pScriptEngine_type;
    typedef std::shared_ptr<Scripting::I_ScriptModule> pScriptModule_type;
    /// @}

    /// @name I_ScriptableService interface.
    /// @{
public:
    /// Register script engine.
    /// If the application service supports scripting, this method registers
    /// a script engine for the application service to use for exposing methods
    /// the script engine.
    virtual void registerScriptEngine(pScriptEngine_type _pScriptEngine) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptableService() = default;
    virtual ~I_ScriptableService() = default;
    /// @}

};  // interface I_ScriptableService

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPTABLE_SERVICE_HPP_INCLUDED
