//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_METHOD_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_METHOD_HPP_INCLUDED

#include <Zen/Scripting/forward_declarations.hpp>
#include <Zen/Scripting/I_ScriptMethod.hpp>

#include <stdexcept>
#include <sstream>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
;

template<typename ScriptableClass_type, class Method_type, typename Return_type, class DispatchHelper_type>
class script_method
:   public I_ScriptMethod
{
    /// @name I_ScriptMethod implementation
    /// @{
public:
    virtual boost::any dispatch(pScriptWrapper_type _pScriptWrapper, std::vector<boost::any>& _arguments);
    /// @}

    /// @name 'Structors
    /// @{
public:
    script_method(Method_type _pFunction, DispatchHelper_type& _signature, const std::string& _typeName, const std::string& _methodName);
    /// @}

    /// @name Member Variables
    /// @{
public:
    Method_type             m_pFunction;
    DispatchHelper_type&    m_dispatchHelper;
    std::string             m_typeName;
    std::string             m_methodName;
    /// @}

};  // class script_method

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
template<class ScriptableClass_type, class Method_type, typename Return_type, class DispatchHelper_type>
inline
script_method<ScriptableClass_type, Method_type, Return_type, DispatchHelper_type>::script_method(Method_type _pFunction, DispatchHelper_type& _signature, const std::string& _typeName, const std::string& _methodName)
:   m_pFunction(_pFunction)
,   m_dispatchHelper(_signature)
,   m_typeName(_typeName)
,   m_methodName(_methodName)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
template<typename ScriptableClass_type, class Method_type, typename Return_type, class DispatchHelper_type>
inline
boost::any
script_method<ScriptableClass_type, Method_type, Return_type, DispatchHelper_type>::dispatch(I_ScriptWrapper* _pObject, std::vector<boost::any>& _parms)
{
    assert(_pObject != NULL);

    if (m_dispatchHelper.getParameterCount() > _parms.size())
    {
        std::stringstream errorMessage;
        errorMessage << "Error calling C++ method " << m_typeName << "::" << m_methodName << ": Not enough arguments.  Expected " 
            <<  m_dispatchHelper.getParameterCount() << ", but got " << _parms.size();
        throw std::runtime_error(errorMessage.str());
    }

    try
    {
        return m_dispatchHelper.dispatch(m_pFunction, _pObject, _parms);
    }
    catch(std::runtime_error& _ex)
    {
        std::stringstream errorMessage;
        errorMessage << "Caught an exception in C++ method " << m_typeName << "::" << m_methodName << ": "
            << _ex.what();
        throw std::runtime_error(errorMessage.str());
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_METHOD_HPP_INCLUDED
