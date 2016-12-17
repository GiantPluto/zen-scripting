//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Scripting Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#pragma once


#include <Zen/Scripting/forward_declarations.hpp>

// C++ framework API
#include <Zen/Scripting/I_ScriptEngine.hpp>
#include <Zen/Scripting/I_ScriptingManager.hpp>
#include <Zen/Scripting/I_ScriptModule.hpp>
#include <Zen/Scripting/I_ScriptMethod.hpp>
#include <Zen/Scripting/I_ScriptType.hpp>
#include <Zen/Scripting/I_Scriptable.hpp>
#include <Zen/Scripting/I_ScriptableService.hpp>
#include <Zen/Scripting/ScriptWrapper.hpp>

// template declarations and some template implementation
#include <Zen/Scripting/script_module.hpp>
#include <Zen/Scripting/script_method.hpp>
#include <Zen/Scripting/script_type_interface.hpp>
#include <Zen/Scripting/script_type.hpp>
#include <Zen/Scripting/script_convert_argument.hpp>
#include <Zen/Scripting/script_dispatch_helper.hpp>

// template implementation
#include <Zen/Scripting/script_module_impl.hpp>
#include <Zen/Scripting/script_type_impl.hpp>
