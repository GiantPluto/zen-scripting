# Zen C++ Scripting Framework

The Zen Scripting Framework is a framework for making it easier to add scripting language support for C++ applications and libraries.

Using this library and the Zen Plugin library, common facades can be created for different scripting engines, providing application developers with support for a variety of scripting languages.

Currently supported scripting languages include Lua and Python 2.7 (via the [ZLua](https://github.com/indie-zen-plugins/ZLua) and [ZPython](https://github.com/indie-zen-plugins/ZPython) plugins).  V8 JavaScript integration is the next on the list.

## Version 2.0

The main breaking change between Zen Scripting 1.x and 2.0 is the removal of dependencies on Zen Core.  Now that C++ includes implementations of threading and smart pointers, the Zen Core managed_ptr is no longer necessary.
