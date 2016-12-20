//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED

#include "Configuration.hpp"

// Events aren't implemented in 2.0 yet
//#include <Zen/Core/Event/Event.hpp>

#include <boost/any.hpp>

#include <map>
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
    /// Required?  I think this has something to do with being an extension point.
    typedef std::string                             index_type;
    typedef std::shared_ptr<I_ScriptEngine>         pScriptEngine_type;
    typedef std::weak_ptr<I_ScriptEngine>           wpScriptEngine_type;
    // typedef Zen::Event::Event<wpScriptEngine_type> scriptEngineEvent_type;
    
    // TODO This should be I_Configuration
    typedef std::map<std::string, std::string>      Configuration_type;
    typedef Configuration_type*                     pConfiguration_type;        

    typedef std::shared_ptr<I_ScriptModule>         pScriptModule_type;
    /// @}

    /// @name I_ScriptEngine interface
    /// @{
public:
    /// Initialize the script engine
    /// @since 2.0
    virtual void initialize(pConfiguration_type _pConfiguration = nullptr) = 0;
    
    /// TODO Why is this here?  How is it used?
    virtual I_ObjectHeap& heap() = 0;

    /// Execute a script
    /// @return true if the script was successfully executed, otherwise false
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
    // TODO These assume a script engine is an extension point; is that valid?
    static const std::string& getNamespace();
    static const std::string& getExtensionPointName();
    /// @}

    /// @name Events
    /// @{
public:
    // scriptEngineEvent_type  onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptEngine() = default;
    virtual ~I_ScriptEngine() = default;
    /// @}

};  // interface I_ScriptEngine

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPT_ENGINE_HPP_INCLUDED
