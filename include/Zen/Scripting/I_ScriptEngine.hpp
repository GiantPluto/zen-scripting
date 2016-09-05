//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Event/Event.hpp>

#include <boost/any.hpp>

#include <memory>
#include <string>
#include <vector>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ObjectHeap;
class I_ScriptModule;

class SCRIPTING_DLL_LINK I_ScriptEngine
{
    /// @name Types
    /// @{
public:
    typedef std::string                            index_type;
    typedef std::shared_ptr<I_ScriptEngine>        pScriptEngine_type;
    typedef std::weak_ptr<I_ScriptEngine>          wpScriptEngine_type;
    typedef Zen::Event::Event<wpScriptEngine_type> scriptEngineEvent_type;

    typedef std::shared_ptr<I_ScriptModule>        pScriptModule_type;
    /// @}

    /// @name I_ScriptEngine interface
    /// @{
public:
    virtual I_ObjectHeap& heap() = 0;

    /// Execute a script
    /// @return true if the script was sucesfully executed, otherwise false
    virtual bool executeScript(const std::string& _fileName) = 0;

    /// Execute a method on an object
    /// @param _object An object passed from script
    /// @param _method A method passed from script
    /// @param _parms Parameters that will be passed to the method
    virtual void executeMethod(boost::any& _object, boost::any& _method, std::vector<boost::any>& _parms) = 0;

    /// Create a script module
    virtual pScriptModule_type createScriptModule(const std::string& _moduleName, const std::string& _docString) = 0;
    /// @}

    /// @name Static methods
    /// @{
    static const std::string& getNamespace();
    static const std::string& getExtensionPointName();
    /// @}

    /// @name Events
    /// @{
public:
    scriptEngineEvent_type  onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptEngine();
    virtual ~I_ScriptEngine();
    /// @}

};  // interface I_ScriptEngine

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED
