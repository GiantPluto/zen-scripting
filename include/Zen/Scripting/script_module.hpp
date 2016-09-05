//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_MODULE_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_MODULE_HPP_INCLUDED

#include <Zen/Scripting/forward_declarations.hpp>

#include <Zen/Scripting/I_ScriptEngine.hpp>
#include <Zen/Scripting/I_ScriptModule.hpp>

#include <boost/noncopyable.hpp>

#include <string>
#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

/// Helper class for defining script modules.
/// This class is exposed publicly so that you can derive additional
/// implementations from it or so you can use it as an example if
/// you want to implement it in a different way.
class script_module
:   public boost::noncopyable
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptEngine>                 pScriptEngine_type;
    typedef std::shared_ptr<I_ScriptModule>                 pScriptModule_type;

    typedef std::map<std::string, script_type_interface*>   ScriptTypes;
    /// @}

    /// @name script_module implementation
    /// @{
public:
    /// Add a script type to this module.
    /// A script type is a "type", "table" or "class" depending on the terminology
    /// used by the underlying scripting engine.
    template<typename ScriptableClass_type>
    script_type<ScriptableClass_type>&
    addType(const std::string& _typeName, const std::string& _typeDoc);

    template<typename ScriptableClass_type>
    derived_script_type<ScriptableClass_type>&
    addDerivedType(script_type_interface& _baseType, const std::string& _typeName, const std::string& _typeDoc);

    /// Activate this module.
    /// When a module is activated, all of the classes within the module are
    /// finalized and registered.  You cannot add more classes to the module and
    /// you cannot add more methods to existing classes after this method is called.
    void activate();

    /// Get the underlying I_ScriptModule class.
    pScriptModule_type getScriptModule();

    script_type_interface& getScriptType(const std::string& _typeName);
    /// @}

    /// @name 'Structors
    /// @{
public:
             script_module(pScriptEngine_type _pScriptEngine, const std::string& _name, const std::string& _documentation = "");
    virtual ~script_module();
    /// @}

private:
    pScriptEngine_type          m_pScriptEngine;
    std::string                 m_name;
    std::string                 m_documentation;

    /// true if this module has been activated.
    /// Should this be part of I_ScriptModule instead?
    bool                        m_activated;

    /// Script module that this script_module wraps.
    pScriptModule_type          m_pModule;

    ScriptTypes                 m_scriptTypes;
};  // class script_module

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_MODULE_HPP_INCLUDED
