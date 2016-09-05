//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPT_TYPE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPT_TYPE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Event/Event.hpp>

#include <boost/function.hpp>
#include <boost/any.hpp>

#include <vector>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ObjectReference;
class I_ScriptMethod;
class I_ScriptModule;

class SCRIPTING_DLL_LINK I_ScriptType
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptType>               pScriptType_type;
    typedef std::weak_ptr<I_ScriptType>                 wpScriptType_type;
    typedef Zen::Event::Event<wpScriptType_type>        scriptTypeEvent_type;
    typedef std::shared_ptr<I_ScriptModule>             pScriptModule_type;

    typedef I_ObjectReference*                          pObjectReference_type;

    typedef void(*void_function_no_args_type)(pObjectReference_type);
    typedef void(*void_function_args_type)(pObjectReference_type, std::vector<boost::any>);

    typedef pObjectReference_type(*object_function_no_args_type)(pObjectReference_type);
    typedef pObjectReference_type(*object_function_args_type)(pObjectReference_type, std::vector<boost::any>);

    typedef std::string(*string_function_no_args_type)(pObjectReference_type);
    typedef std::string(*string_function_args_type)(pObjectReference_type, std::vector<boost::any>);

    typedef bool(*bool_function_no_args_type)(pObjectReference_type);
    typedef bool(*bool_function_args_type)(pObjectReference_type, std::vector<boost::any>);

    typedef int(*int_function_no_args_type)(pObjectReference_type);
    typedef int(*int_function_args_type)(pObjectReference_type, std::vector<boost::any>);
    /// @}

    /// @name I_ScriptType interface
    /// @{
public:
    /// Get the module to which this type belongs.
    virtual pScriptModule_type getScriptModule() = 0;

    /// Get the name of this type.
    virtual const std::string& getTypeName() = 0;

    /// Get the documentation / short description of this type.
    virtual const std::string& getDocumentation() = 0;

    /// Add a method to this type that takes no arguments and returns void
    virtual void addMethod(const std::string& _name, const std::string& _docString, void_function_no_args_type _function) = 0;

    /// Add a method to this type that takes arguments and returns void
    virtual void addMethod(const std::string& _name, const std::string& _docString, void_function_args_type _function) = 0;

    /// Add a method to this type that takes no arguments and returns an I_ObjectReference
    virtual void addMethod(const std::string& _name, const std::string& _docString, object_function_no_args_type _function) = 0;

    /// Add a method to this type that takes arguments and returns an I_ObjectReference
    virtual void addMethod(const std::string& _name, const std::string& _docString, object_function_args_type _function) = 0;

    /// Add a method to this type that takes no arguments and returns a std::string
    virtual void addMethod(const std::string& _name, const std::string& _docString, string_function_no_args_type _function) = 0;

    /// Add a method to this type that takes arguments and returns a std::string
    virtual void addMethod(const std::string& _name, const std::string& _docString, string_function_args_type _function) = 0;

    /// Add a method to this type that takes no arguments and returns a bool
    virtual void addMethod(const std::string& _name, const std::string& _docString, bool_function_no_args_type _function) = 0;

    /// Add a method to this type that takes arguments and returns a bool
    virtual void addMethod(const std::string& _name, const std::string& _docString, bool_function_args_type _function) = 0;

    /// Add a method to this type that takes no arguments and returns a bool
    virtual void addMethod(const std::string& _name, const std::string& _docString, int_function_no_args_type _function) = 0;

    /// Add a method to this type that takes arguments and returns a bool
    virtual void addMethod(const std::string& _name, const std::string& _docString, int_function_args_type _function) = 0;

    /// Add a generic I_ScriptMethod.
    virtual void addMethod(const std::string& _name, const std::string& _docString, I_ScriptMethod* _pMethod) = 0;

    /// Activate the type.  No more methods or attributes can be modified
    /// once the type is activated.
    virtual void activate() = 0;
    /// @}

    /// @name Events
    /// @{
public:
    scriptTypeEvent_type    onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptType();
    virtual ~I_ScriptType();
    /// @}

};  // interface I_ScriptType

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPT_TYPE_HPP_INCLUDED
