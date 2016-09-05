//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Core Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPTING_MANAGER_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPTING_MANAGER_HPP_INCLUDED

#include "../I_ScriptingManager.hpp"

#include "../I_ScriptEngineFactory.hpp"
#include "../I_ScriptEngine.hpp"

#include <Zen/Core/Plugins/ServiceCache.hpp>

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptEngine;
class I_ScriptEngineFactory;

class ScriptingManager
:   public I_ScriptingManager
{
    /// @name Types
    /// @{
public:
    typedef Zen::Plugins::ServiceCache<I_ScriptEngine, I_ScriptEngineFactory>   scriptEngineCache_type;
    /// @}

    /// @name I_ScriptingManager interface
    /// @{
public:
    virtual pScriptEngine_type createScriptEngine(const std::string& _name);
    /// @}

    /// @name 'Structors
    /// @{
public:
             ScriptingManager();
    virtual ~ScriptingManager();
    /// @}

    /// @name Member Variables
    /// @{
private:
    scriptEngineCache_type  m_scriptEngineCache;
    pScriptEngine_type m_pDefaultEngine;
    /// @}

};  // class I_ScriptingManager

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_I_SCRIPTING_MANAGER_HPP_INCLUDED
