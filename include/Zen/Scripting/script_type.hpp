//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Scripting/I_ScriptType.hpp>
#include <Zen/Scripting/I_ScriptMethod.hpp>
#include <Zen/Scripting/I_Scriptable.hpp>

#include <Zen/Scripting/forward_declarations.hpp>
#include <Zen/Scripting/script_type_interface.hpp>

#include <boost/typeof/typeof.hpp>

#include <string>
#include <map>
#include <memory>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
;

/// Helper template for defining scriptable types.
template<typename ScriptableClass_type>
class script_type
:   public script_type_interface
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptType>               pScriptType_type;
    typedef std::weak_ptr<I_ScriptModule>               wpScriptModule_type;
    typedef std::map<std::string, I_Scriptable*>        GlobalObjects_type;
    /// @}

    /// @name script_type_interface implementation.
    /// @{
public:
    /// Activate the class.
    /// @note ONLY script_module<> should call this method unless
    ///		this object was constructed using an existing
    ///		pScriptType_type.
    /// @see script_type::script_type(pScriptType_type)
    virtual void activate();

    /// Get the methods that have been added so far.
    virtual Methods_type& getMethods();

    /// Get the script_module<> for this type.
    virtual script_module& getModule();

private:
    virtual void createGlobals();
    /// @}

    /// @name script_type implementation
    /// @{
public:
    /// Add a method to this script type.
    template<class Method_type>
    script_type<ScriptableClass_type>&
    addMethod(const std::string& _methodName, Method_type _pFunction);

    /// Add a const method to this script type.
    template<class Method_type>
    script_type<ScriptableClass_type>&
    addConstMethod(const std::string& _methodName, Method_type _pFunction);

    /// Expose the specified object to the global name space.
    void createGlobalObject(const std::string& _objectName, I_Scriptable* _pScriptableObject);

    /// Get the script module for this type.
    /// This will not always return a valid script module depending
    /// upon the state of this script_type.
    /// Look at the documentation of the constructors of this class for more information.
    pScriptModule_type getScriptModule();
    /// @}

    /// @name 'Structors.
    ///
    /// @{
public:
    /// Construct a script type that adds to an existing script type whose
    /// module has not yet been activated.  After adding methods to this script_type,
    /// invoke the script_type::activate() method to register the methods.
    /// getScriptModule() will return a valid script module if this constructor
    /// is used.
    script_type(pScriptType_type pScriptType_type);
protected:
    friend class script_module;
    /// Create a script type.
    /// This constructor is invoked by script_module.
    /// getScriptModule() will return a valid script module if this constructor
    /// is used only after _module::activate() has been invoked.
    script_type(script_module& _module, const std::string& _typeName, const std::string& _documentation);
    /// @}

    /// @name Member Variables
    /// @{
protected:
    /// Script module that contains this script type.
    /// This is the template version.  Either m_pModule or m_pScriptModule
    /// are valid, but generally not both.
    /// @see m_pScriptModule
    script_module*      m_pModule;

    /// Script module that contains this script type.
    /// This is the interface version.
    /// @see m_pModule
    wpScriptModule_type m_pScriptModule;

    /// Name of this script_type.
    /// This name is the name that is exposed to the script engine.
    std::string         m_typeName;

    /// Documentation for this script type.
    /// This is generally a very short description of the type.
    std::string         m_documentation;

    Methods_type        m_methods;

    bool                m_activated;

    pScriptType_type    m_pScriptType;

    GlobalObjects_type  m_globalObjects;
    /// @}

};  // class script_type

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

/// Extend script_type to handle derived types.
template<typename ScriptableClass_type>
class derived_script_type
:   public script_type<ScriptableClass_type>
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, I_ScriptMethod*>  Methods_type;
    typedef std::shared_ptr<I_ScriptType>           pScriptType_type;
    typedef std::shared_ptr<I_ScriptModule>         pScriptModule_type;
    typedef std::weak_ptr<I_ScriptModule>           wpScriptModule_type;
    typedef std::map<std::string, I_Scriptable*>    GlobalObjects_type;
    /// @}

    /// @name script_type overrides
    /// @{
public:
    virtual void activate();
    /// @}

    /// @name 'Structors
    /// @{
public:
    derived_script_type(script_type_interface& _baseType, script_module& _module, const std::string& _typeName, const std::string& _documentation);
    /// @}

    /// @name Member Variables
    /// @{
private:
    script_type_interface&  m_baseType;
    /// @}

};  // class derived_script_type

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED
