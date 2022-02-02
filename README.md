## Vault7 ##

I left gamehacking completely and I completely swapped to UNIX Systems , so I decided to publish my stuff.

Make sure to read the License! :)

## What is Vault7 ? ##

Vault7 was a upcoming scripting/cheating platform for the MOBA League of Legends. 
During development and testing time I can proudly say that not a single ban happened in 1.5-2 years.

## Hooking ##
[Hooking](https://github.com/Jiingz/vault7/blob/dev/sources/core/hooking/hooking_service.cpp) is done through abusing DEP (Data Execution Prevention) 
and some simple Detouring/JMP Hooks.

OnProcessSpell hook is being placed through DEP instead of Detouring, because League doesn't let you modify it's memory because of PAGE_READONLY access on it's memory.
However, with some effort you can still Detour on it.

DEP Hooking was easier because I basically had the code ready from older projects, and it is way safer.

## Some useful file links and info ##

The loader isn't really done, so I removed it.

You can use the [ServiceLocator](https://github.com/Jiingz/vault7/blob/dev/sources/core/locator.cpp) to access the most important components.

Same thing for the [Features](https://github.com/Jiingz/vault7/tree/dev/sources/core/features).


The [Tests](https://github.com/Jiingz/vault7/tree/dev/sources/core/tests) aren't finished, but most stuff work.
They can be executed through button presses on the DEBUG UI.

Everything script related is in the [SDK](https://github.com/Jiingz/vault7/tree/dev/sources/core/sdk).

[Prediction](https://github.com/Jiingz/vault7/tree/dev/sources/core/sdk/prediction) also isn't finished completely, but should be easy to improve and finalize for someone who know's what he's doing.

## Why am I publishing all my work? ##
As previously mentioned I left gamehacking and completely swapped to UNIX Systems. I focus on more future orientated work, which actually teaches me something useful
for programming in general, not just for hacking/the security sector.

## General information for Developer ##

I used a function which does clicks on given xy coordinates ingame. It's a internal league function and works almost the same as IssueOrder, but way more safe
and without the need of bypassing stupid checks.

For spell casting hooking GetCursorPos and feeding your values you want to cast on is enough.
You won't see the mouse moving or anything, it will look just like calling CastSpell.
