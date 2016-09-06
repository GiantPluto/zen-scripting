#include <Zen/Scripting/.hpp>

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

#include <Zen/Scripting/I_ScriptEngine.hpp>

#include <memory>
#include <functional>

class MockScriptEngine
: public I_ScriptEngine
{
public:
    virtual I_ObjectHeap& heap()
    {
        
    }

    /// Execute a script
    /// @return true if the script was sucesfully executed, otherwise false
    virtual bool executeScript(const std::string& _fileName)
    {
        // TODO Implement?
        return true;
    }

    /// Execute a method on an object
    /// @param _object An object passed from script
    /// @param _method A method passed from script
    /// @param _parms Parameters that will be passed to the method
    virtual void executeMethod(boost::any& _object, boost::any& _method, std::vector<boost::any>& _parms)
    {
        
    }

    /// Create a script module
    virtual pScriptModule_type createScriptModule(const std::string& _moduleName, const std::string& _docString)
    {
        return pScriptModule_type();
    }

    MockScriptEngine();
    ~MockScriptEngine();
};

class MockConsole
: public I_Scriptable
{
public:
    void print(const std::string& _value)
    {
        // TODO Implement?
    }
}

BOOST_AUTO_TEST_CASE( simple_script_example )
{
    auto pEngine = new MockScriptEngine();

    auto pModule = new Zen::Scripting::script_module(pEngine, "Simple", "Simple Script Module");
    
    pModule->addType<MockConsole>("Console", "Console")
        .addMethod("print", &MockConsole::print)
    ;
    
    pModule->activate();

    // TODO Implement stuff
    
    delete pModule;
    delete pEngine;
}
