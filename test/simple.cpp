
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

// #include <Zen/Scripting/I_Scriptable.hpp>
// #include <Zen/Scripting/I_ScriptEngine.hpp>
// #include <Zen/Scripting/script_module.hpp>
// #include <Zen/Scripting/script_type.hpp>


// #include <Zen/Scripting/script_module_impl.hpp>
// #include <Zen/Scripting/script_type_impl.hpp>
// #include <Zen/Scripting/ScriptWrapper.hpp>

#include <Zen/Scripting/Scripting.hpp>

#include <functional>
#include <iostream>
#include <memory>

class MockScriptEngine
:   public Zen::Scripting::I_ScriptEngine
{
public:
    virtual void initialize(pConfiguration_type _pConfiguration = nullptr)
    {
        
    }

    virtual Zen::Scripting::I_ObjectHeap& heap()
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

    // Not copyable nor assignable
    MockScriptEngine(const MockScriptEngine&) = delete;
    void operator=(const MockScriptEngine&) = delete;
};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MockScriptEngine::MockScriptEngine()
{
}

MockScriptEngine::~MockScriptEngine()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class MockConsole
//:   public Zen::Scripting::I_Scriptable
{
public:
    typedef MockConsole*                                    pScriptObject_type;
    typedef Zen::Scripting::ScriptWrapper<MockConsole>      ScriptObjectReference_type;
    typedef ScriptObjectReference_type                      ScriptWrapper_type;
    typedef ScriptWrapper_type*                             pScriptWrapper_type;
    
public:
    void print(const std::string& _value)
    {
        std::cout << _value << std::endl;
    }

    // Not copyable nor assignable
    MockConsole(const MockConsole&) = delete;
    void operator=(const MockConsole&) = delete;
};

BOOST_AUTO_TEST_CASE( simple_script_example )
{
    std::shared_ptr<Zen::Scripting::I_ScriptEngine> pEngine(new MockScriptEngine());

    auto pModule = new Zen::Scripting::script_module(pEngine, "Simple", "Simple Script Module");

    pModule->addType<MockConsole>("Console", "Console")
        .addMethod("print", &MockConsole::print)
    ;

    pModule->activate();

    // TODO Implement stuff

    delete pModule;
    
    // pEngine will get destroyed when it goes out of scope
    //delete pEngine;
}
