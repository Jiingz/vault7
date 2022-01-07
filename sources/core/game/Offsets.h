#pragma once
#include <d3d11.h>

#define oNtProtectVirtualMemory_Stub_1 0x3D9FF4
#define oNTQueryVirtualMemory_Stub 0x3DA1B0

#define DEFINE_RVA(address) ((DWORD)GetModuleHandle(NULL) + (DWORD)address)

#define STR_MERGE_IMPL(x, y)				x##y
#define STR_MERGE(x,y)						STR_MERGE_IMPL(x,y)
#define MAKE_PAD(size)						BYTE STR_MERGE(pad_, __COUNTER__) [ size ]
#define DEFINE_MEMBER_0(x, y)				x
#define DEFINE_MEMBER_N(x,offset)			struct { MAKE_PAD(offset); x; }

namespace Globals
{
	static HWND	LeagueWindow{ nullptr };
}


namespace Offsets
{
	enum Functions : DWORD {
		HealthBarPosition = 0x5ADDD0, // 83 EC 24 53 55 56 57 8B F9 6A // Function call :  E8 ? ? ? ? 8B 4E 08 8D 54 24 04 52 | I recreate that
		WorldToScreen = 0xA2B540, // 83 EC 10 56 E8 ? ? ? ? 8B 08  || FUNCTION CALL OF W2s: E8 ? ? ? ? F3 0F 10 4C 24 ? 83 C4 10 F3 0F 10
		GetBasicAttack = 0x123160, // E8 ? ? ? ? 83 38 00 74 4B 
		GetAttackDelay = 0x270810, // 8B 44 24 04 51 F3
		GetAttackCastDelay = 0x270710, // 83 EC 0C 53 8B 5C 24 14 8B CB 56
		GetBoundingRadius = 0x123260, // 83 EC 08 56 8B F1 83 BE ? ? ? ? ? 74
		BaseDrawPosition = 0x16FEE0, // E8 ? ? ? ? EB 07 8B 01 8B call GetBaseDrawPos()
		IsNotWall = 0x9AF1F0,	  // E8 ? ? ? ? 83 C4 10 80 BE ? ? ? ? ? 74 0A
		CompareObjectTypeFlags = 0x12BE60, //51 56 57 8B F9 33 D2 0F B6 47 Inside function, just Decompile (F5)
		//IsValidObject = E8 ? ? ? ? 84 C0 75 ? 5E 83 C4 ? C2 ? ?
		onProcessSpell = 0x50AF40,				// 56 8B 74 24 08 8B 16 85
		OnCreateObject = 0x27C740, //UNUSED		// 56 8B F1 80 7E 28 00 75
		OnDeleteObject = 0x2718C0, //UNUSED		// 53 57 8B 7C 24 0C 8B D9 8B CF E8
		OnNewPath = 0x277B80, //UNUSED			// 83 EC 18 56 8B 74 24 20 8B CE 57 OUTDATED
		PrintChat = 0x58C070,					// INSIDE PRINTCHAT FUNC: 8B 4D E0 42    ||  CALL OF PRINTCHAT: E8 ? ? ? ? B8 ? ? ? ? C7 04 
		//IsNotWall = 0x8e64f0,
		NewIssueOrder = 0x605950, // inside function: 75 18 8B 0D ? ? ? ? 57
		NewCastSpell = 0x5E8AA0, // 53 8B 1D ?? ?? ?? ?? 55 56 57 8B F9 85

		//Healthbar pos
		v15a1 = 0xC,														//updated 12.1
		v15a2 = 0x268,														//updated 12.1
	};

	enum GameObject
	{
		Name = 0x6C,
		ChampionName = 0x2DA4,
	};

	//GameObject notes
	// CharacterData = 83 C0 C0 8D	// FF 74 24 64 8D 8E ? ? ? ?						go to fn xref to operand, go to 1 result, lea ecx, [esi+offseth] // follow instruction next line lea ecx, [esi+offseth]

	enum ActiveProcessSpell : ULONG
	{
		/* NOTE
		ActiveSpell - difference offset = ActiveProcessSpell offset.

		*/

		SpellSlot = 0x4,				//		- 0x8
		CastEndTime = 0x8,			//			- 0x134	
		SenderName = 0x18,			//			
		SenderNetworkID = 0x6C,
		SenderIndex = 0x64,			//			- 0x8
		StartPos = 0x7C,				//		- 0x8
		EndPos = 0x88,				//			- 0x8
		CastPos = 0x94,				//			- 0x8
		Direction = 0xAC,				//		- 0x8
		TargetArray = 0xB8,			//			- 0x8
		TargetArraySize = 0xBC,		//			- 0x8
		CastDelay = 0xC4,				//		- 0x8
		AnimationDelay = 0xD4,		//			- 0x8
		Cooldown = 0xD8,				//		- 0x8
		IsSpell = 0xE0,				//		    - 0x8
		IsBasicAttack = 0xE4,			//		- 0x1D0
		IsSpecialAttack = 0xE5,		//			- 0x1D2
		IsHeadshotAttack = 0xE6,		//		- 0x1D4
		SpellType = 0xEC,				// //OUTDATED
		ManaCost = 0xF4,				//		- 0x8
	};

	enum GameClient : DWORD {
		GameTime = 0x31034D4, // F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3	 subss   xmm1, dword_offset
		GameInfo = 0x30FE7FC, // A1 ? ? ? ? 68 ? ? ? ? 8B 70 08
		ObjManager = 0x186EE44, // 89 ? ? ? ? ? 57 C7 06 ? ? ? ? 66 C7 46 04 ? ?
		UnderMouseObject = 0x183EA70, // A1 ? ? ? ? 8B 0D ? ? ? ? 3B 
		HudInstance = 0x186EE7C, // 8B 2D ? ? ? ? 8B 75
		LocalPlayer = 0x310B984, // A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
		BuffManager = 0x21B8, // 8D 83 ? ? ? ? 50 8D AB ? ? ? ?								eax, [ebx + offset]
		StaticRenderer = 0x3137D08, // A1 ? ? ? ? F3 0F 10 60 ?		dword_offset
	};

	enum Chat : DWORD {
		ChatInstance = 0x30FE7F8,  // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 84 
	};

	enum ManagerTemplate : DWORD {
		_ManagerTemplate_Func_ = 0x2f1180, //UNUSED, might be useful to find offsets but idk // OUTDATED 11.19
		AIMissileClient = 0x310BF08,// 8B 0D ? ? ? ? 56 8B 01 FF		//UNUSED wont use that shit
		AIMinionClient = 0x186EEDC, // A1 ? ? ? ? 53 55 8B 6C 24 1C		// 8B 35 ? ? ? ? 8B 56 
		AITurretClient = 0x30FF5E0, // A1 ? ? ? ? 53 56 8B 70 04		// 8B 0D ? ? ? ? FF 74 24 14 FF 74 24 14 E8
		AIHeroClient = 0x186CC58, 	// 8B 15 ? ? ? ? 0F 44 C1
		AIAttackableUnitClient = 0x186EE84, // A1 ? ? ? ? FF B4 24 ? ? ? ? F3 0F 10 44 24 ? F3
		AIShopClient = 0x30FF5E4, // 8B 0D ? ? ? ? E8 ? ? ? ? 84 C0 75 11 8B
		AIInhibitorClient = 0x310C4E0, // A1 ? ? ? ? 53 55 56 8B 70 04 8B 40
		AIBuildingClient = 0x186C4A8, // 8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 38
	};

	enum AIManager : DWORD
	{
		WayPoint = 0x10,
		NavMesh = 0x1B0,
		MoveSpeed = 0x1BC,
		IsMoving = 0x1C0,
		PassedWayPoints = 0x1C4,
		NavBegin = 0x1CC,
		NavEnd = 0x1D8,
		WayPointVector = 0x1E4,
		DashSpeed = 0x1F8,
		IsDashing = 0x214,
		ServerPos = 0x2E4,
		Velocity = 0x2F0,
		IsDashingRaw = 0x3C0,
	};

	enum BuffManager
	{
		type = 0x4,
		name = 0x8,
		script = 0x8,
		hash_name = 0x88,
		start_time = 0xc,
		end_time = 0x10,
		entry_array = 0x10,
		count = 0x74,
		count_alt_one = 0x24,
		count_alt_two = 0x20,
		node_start = 0x20,
		node_current = 0x24,
	};

	enum SpellSlot
	{
		Instance = 0x27F8,
		Level = 0x20,
		ReadyTime = 0x28,
		CurrentCharges = 0x5C,
		MaxCharges = 0x64,
		GetNextChargeTime = 0x68,
		RechargeTimeSeconds = 0x70,
		CooldownTimeMax = 0x80,
		TrueDamage = 0xA0,
		SpellInfo = 0x144,
	};

	enum SpellData
	{
		ManaRequirement = 0x052C,
	};
}