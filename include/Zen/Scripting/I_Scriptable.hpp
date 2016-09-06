//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPTABLE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPTABLE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Scripting/I_ScriptModule.hpp>

#include <memory>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptWrapper;

/// @brief Implement this in classes that are scriptable
class SCRIPTING_DLL_LINK I_Scriptable
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptModule>     pScriptModule_type;
    /// @}

    /// @name I_Scriptable interface
    /// @{
public:
    /// Get the name that the Script system uses for this class
    /// The base framework interfaces implement this, but if you
    /// want to create a derived class, override this method.
    virtual const std::string& getScriptTypeName() = 0;

    /// @brief Get the script object associated with this object
    /// @return The script object associated with this object, but possibly NULL if this object
    ///         was created before a script engine was registered.
    virtual I_ScriptWrapper* getScriptObject() = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_Scriptable() = default;
public:
    virtual ~I_Scriptable() = default;
    /// @}

};  // interface I_Scriptable

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPTABLE_HPP_INCLUDED
