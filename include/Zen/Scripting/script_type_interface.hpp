//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INTERFACE_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INTERFACE_INCLUDED

#include "Configuration.hpp"

#include <string>
#include <map>
#include <memory>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptMethod;
class I_ScriptModule;
class script_module;

/// Script Type interface.
/// This class is used as the base interface for script_type.
/// The primary purpose is to expose the common activate() method
/// and allow script_module to contain a collection of script_type.
class SCRIPTING_DLL_LINK script_type_interface
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, I_ScriptMethod*>      Methods_type;
    typedef std::shared_ptr<I_ScriptModule>             pScriptModule_type;
    /// @}

    /// @name script_type_interface interface
    /// @{
public:
    friend class script_module;

    /// Activate this script type.
    /// When a script_type is activated, it registers itself with
    /// the script engine.
    /// This method is called by script_module::activate().
    virtual void activate() = 0;

    /// Create the global objects.
    virtual void createGlobals() = 0;

public:
    /// Get the script_module<> for this type.
    virtual script_module& getModule() = 0;

    /// Get the methods that have been added so far.
    virtual Methods_type& getMethods() = 0;
    /// @}

    /// @name 'Structors
    /// @{
public:
             script_type_interface() = default;
    virtual ~script_type_interface() = default;
    /// @}

};  // interface script_type_interface

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INTERFACE_INCLUDED
