# RTMGameplayDebuggerExample
This is a toy example for setting up a plugin module that contains a GameplayDebbugger categor

## Ratioale
The official documentation for Gameplay Debuggers in Unreal is several years out of date and references an old framework that no longer exists. 
While there are several Gameplay Debugger examples in the engine code (search `: public FGameplayDebuggerCategory`), these all take the approach of wrapping all code in `#if WITH_GAMEPLAY_DEBUGGER_MENU` which I personally find clunky and annoying
The reasoning for this is that the Gameplay Debugger framework does not exist in Shipping and Test Build configs, so needs excluding somehow. I just prefer to do that in a module that gets completely excluded for those builds. Benefits: 
* Gameplay Debugger code gets siloed away from gameplay code
* No need to wrap all Gameplay Debugger code in precompiler conditions
* Less chance of breaking the shipping build by accident

## Implementation
### Plugin Structure
In this plugin, there are 2 modules
* GameplayDebugEg - An empty Runtime module, named {PluginName}
* GameplayDebugEgDebugging - A debugging module, named {PluginName}Debugging, which is excluded from test and shipping builds

### Conditional Module Exclusion
Exclusion from test and shipping is donw in the UPlugin file, using an optional TargetConfigurationDenyList
```json
"Modules": [
		{
			"Name": "RTMDebugEg",
			"Type": "Runtime",
			"LoadingPhase": "Default"
		},
		{
			"Name": "RTMDebugEgDebugging",
			"Type": "Runtime",
			"LoadingPhase": "Default",
			"TargetConfigurationDenyList": [
				"Test",
				"Shipping"
			]
		}
	],
```

### Definition and Registration of the Gameplay Debugger
The definition/declaration of the gameplay debugger is [here](https://github.com/rtm223/RTMGameplayDebuggerExample/tree/main/Source/RTMDebugEgDebugging/Private/Debugging) and is registered in the Module's `StartupModule()` function [here](https://github.com/rtm223/RTMGameplayDebuggerExample/edit/main/Source/RTMDebugEgDebugging/Private/Module/RTMDebugEgDebugging.cpp)
```cpp
void FRTMDebugEgDebuggingModule::StartupModule()
{
	IModuleInterface::StartupModule();

	IGameplayDebugger& gameplayDebuggerModule = IGameplayDebugger::Get();
	gameplayDebuggerModule.RegisterCategory("Example", IGameplayDebugger::FOnGetCategory::CreateStatic(&FRTMDebugCategory_Example::MakeInstance), EGameplayDebuggerCategoryState::Disabled, 9);
}
```

## Usage in-Game
You can bring up the gameplay debugger view in PIE or in a debug/development build by pressing the ' key. Using Numpad numbers to toggle different categories on and off
The Project settings allow for customisation of the categories

The toy example in this plugin will just tell you what classes are being used for key gameplay framework actors in the current session

![image](https://github.com/user-attachments/assets/dfe76d33-18e2-4fc8-83e0-9678e4f70093)

It should be pretty trivial to adapt this setup to your own needs
