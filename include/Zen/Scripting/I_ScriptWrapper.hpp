//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_I_OBJECT_REFERENCE_HPP_INCLUDED
#define ZEN_SCRIPTING_I_OBJECT_REFERENCE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Event/Event.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ScriptObject;
class I_ScriptModule;
class I_ScriptType;

/// Helper for mapping C++ objects to the I_ScriptObject
class SCRIPTING_DLL_LINK I_ScriptWrapper
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_ScriptWrapper>         pScriptWrapper_type;
    typedef std::weak_ptr<I_ScriptWrapper>           wpScriptWrapper_type;
    typedef Zen::Event::Event<wpScriptWrapper_type>  ScriptWrapperEvent_type;

    typedef std::shared_ptr<I_ScriptObject>            pScriptObject_type;
    typedef std::shared_ptr<I_ScriptModule>            pScriptModule_type;
    typedef std::shared_ptr<I_ScriptType>              pScriptType_type;
    /// @}

    /// @name I_ScriptWrapper interface
    /// @{
public:
    virtual pScriptModule_type getModule() = 0;
    virtual pScriptType_type getType() = 0;

    virtual pScriptObject_type getScriptObject() = 0;
    virtual void setScriptObject(pScriptObject_type _pObject) = 0;

    /// @todo I think boost::any should be used instead of void*
    virtual void setScriptUserData(void* _pUserData) = 0;
    virtual void* getScriptUserData() const = 0;
    /// @}

    /// @name Events
    /// @{
public:
    ScriptWrapperEvent_type   onDestroyEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ScriptWrapper() = default;
    virtual ~I_ScriptWrapper() = default;
    /// @}
};  // interface I_ScriptWrapper

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_OBJECT_HEAP_HPP_INCLUDED
