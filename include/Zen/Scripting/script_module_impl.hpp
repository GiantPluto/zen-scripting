//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_MODULE_IMPL_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_MODULE_IMPL_HPP_INCLUDED

#include <Zen/Scripting/script_module.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
inline
script_module::script_module(pScriptEngine_type _pScriptEngine, const std::string& _name, const std::string& _documentation)
:   m_pScriptEngine(_pScriptEngine)
,   m_name(_name)
,   m_documentation(_documentation)
,   m_activated(false)
,   m_scriptTypes()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
inline
script_module::~script_module()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
inline
void
script_module::activate()
{
    // A module can only be activated once.
    assert(!m_activated);

    // Create the script module.
    m_pModule = m_pScriptEngine->createScriptModule(m_name, m_documentation);

    // Activate all of the script types.
    for(ScriptTypes::iterator iter = m_scriptTypes.begin(); iter != m_scriptTypes.end(); iter++)
    {
        iter->second->activate();
    }

    m_pModule->activate();

    // Create the globals for each script type.
    for(ScriptTypes::iterator iter = m_scriptTypes.begin(); iter != m_scriptTypes.end(); iter++)
    {
        iter->second->createGlobals();
    }

    // Mark this module as activated.
    m_activated = true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
template<typename ScriptableClass_type>
inline
script_type<ScriptableClass_type>&
script_module::addType(const std::string& _typeName, const std::string& _typeDoc)
{
    // Modules cannot add new types if the module has already been activated.
    assert(!m_activated);

    script_type<ScriptableClass_type>* const pScriptType =
        new script_type<ScriptableClass_type>(*this, _typeName, _typeDoc);

    m_scriptTypes[_typeName] = pScriptType;

    return *pScriptType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
template<typename ScriptableClass_type>
inline
derived_script_type<ScriptableClass_type>&
script_module::addDerivedType(script_type_interface& _baseType, const std::string& _typeName, const std::string& _typeDoc)
{
    // Modules cannot add new types if the module has already been activated.
    assert(!m_activated);

    derived_script_type<ScriptableClass_type>*
    const pScriptType =
        new derived_script_type<ScriptableClass_type>
            (_baseType, *this, _typeName, _typeDoc);

    m_scriptTypes[_typeName] = pScriptType;

    return *pScriptType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
inline
script_module::pScriptModule_type
script_module::getScriptModule()
{
    return m_pModule;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
inline
script_type_interface&
script_module::getScriptType(const std::string& _typeName)
{
    script_type_interface* pScriptType = m_scriptTypes[_typeName];

    assert(pScriptType != NULL);

    return *pScriptType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_MODULE_IMPL_HPP_INCLUDED
