#pragma once
#include <d3d11.h>

#define oNtProtectVirtualMemory_Stub_1 0x3D9FF4
#define oNTQueryVirtualMemory_Stub 0x3DA1B0


namespace Globals
{
	static HWND	LeagueWindow{ nullptr };
}


namespace Offsets
{
	enum Functions : DWORD {
		HealthBarPosition = 0x5A9630, // 83 EC 24 53 55 56 57 8B F9 6A // Function call :  E8 ? ? ? ? 8B 4E 08 8D 54 24 04 52 | I recreate that
		WorldToScreen = 0xA25950, // 83 EC 10 56 E8 ? ? ? ? 8B 08  || FUNCTION CALL OF W2s: E8 ? ? ? ? F3 0F 10 4C 24 ? 83 C4 10 F3 0F 10
		GetBasicAttack = 0x121360, // E8 ? ? ? ? 83 38 00 74 4B 
		GetAttackDelay = 0x2809D0, // 8B 44 24 04 51 F3
		GetAttackCastDelay = 0x2808D0, // 83 EC 0C 53 8B 5C 24 14 8B CB 56
		GetBoundingRadius = 0x121460, // 83 EC 08 56 8B F1 83 BE ? ? ? ? ? 74
		BaseDrawPosition = 0x16E170, // E8 ? ? ? ? EB 07 8B 01 8B call GetBaseDrawPos()
		IsNotWall = 0x9A9570,	  // E8 ? ? ? ? 83 C4 10 80 BE ? ? ? ? ? 74 0A
		CompareObjectTypeFlags = 0x2367A0, // E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 87 ? ? ? ? 8D
		//IsValidObject = E8 ? ? ? ? 84 C0 75 ? 5E 83 C4 ? C2 ? ?
		onProcessSpell = 0x509BD0,				// 56 8B 74 24 08 8B 16 85
		OnCreateObject = 0x2778A0, //UNUSED		// 56 8B F1 80 7E 28 00 75
		OnDeleteObject = 0x267A80, //UNUSED		// 53 57 8B 7C 24 0C 8B D9 8B CF E8
		OnNewPath = 0x277B80, //UNUSED			// 83 EC 18 56 8B 74 24 20 8B CE 57
		PrintChat = 0x589770,					// INSIDE PRINTCHAT FUNC: 8B 4D E0 42    ||  CALL OF PRINTCHAT: E8 ? ? ? ? B8 ? ? ? ? C7 04 
		//IsNotWall = 0x8e64f0,
		IssueClick = 0x5FA0E0, // inside function: 75 18 8B 0D ? ? ? ? 57
		IssueSpell = 0x5E1C00, // 53 8B 1D ?? ?? ?? ?? 55 56 57 8B F9 85

		//Healthbar pos
		v15a1 = 0xC,														//updated 11.23
		v15a2 = 0x268,														//updated 11.23
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
		GameTime = 0x3101384, // F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3	 subss   xmm1, dword_offset
		GameInfo = 0x30FC794, // A1 ? ? ? ? 68 ? ? ? ? 8B 70 08 // maybe +8?
		ObjManager = 0x186CD20, // 89 ? ? ? ? ? 57 C7 06 ? ? ? ? 66 C7 46 04 ? ?
		UnderMouseObject = 0x30FC714, // A1 ? ? ? ? 8B 0D ? ? ? ? 3B 
		HudInstance = 0x186CD58, // 8B 2D ? ? ? ? 8B 75
		LocalPlayer = 0x310990C, // A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
		BuffManager = 0x21B8, // 8D 8F ? ? ? ? E8 ? ? ? ? 6A 00 50								ecx, [edi + offseth]
	};

	enum Minimap : DWORD {
		MinimapInstance = 0x30F88B8, // 8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7 // OUTDATED 11.19
		TacticalMap = 0x2,
	};

	enum ManagerTemplate : DWORD {
		_ManagerTemplate_Func_ = 0x2f1180, //UNUSED, might be useful to find offsets but idk // OUTDATED 11.19
		AIMissileClient = 0x3109E8C,// 8B 0D ? ? ? ? 56 8B 01 FF		//UNUSED wont use that shit
		AIMinionClient = 0x186CDB8, // A1 ? ? ? ? 53 55 8B 6C 24 1C		// 8B 35 ? ? ? ? 8B 56 
		AITurretClient = 0x30FD578, // A1 ? ? ? ? 53 56 8B 70 04		// 8B 0D ? ? ? ? FF 74 24 14 FF 74 24 14 E8
		AIHeroClient = 0x186ABF4, 	// 8B 15 ? ? ? ? 0F 44 C1
		AIAttackableUnitClient = 0x186CD60, // A1 ? ? ? ? FF B4 24 ? ? ? ? F3 0F 10 44 24 ? F3
		AIShopClient = 0x30FD57C, // 8B 0D ? ? ? ? E8 ? ? ? ? 84 C0 75 11 8B
		AIInhibitorClient = 0x310A640, // A1 ? ? ? ? 53 55 56 8B 70 04 8B 40
		AIBuildingClient = 0x186A4E0, // 8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 38
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
		BuffVectorStart = 0x10,
		BuffVectorEnd = 0x14,
		// from BuffEntry
		BuffType = 0x4,
		BuffScript = 0x8,
		BuffName = 0x8,
		BuffStartTime = 0xC,
		BuffEndTime = 0x10,
		BuffDuration = 0x14,
		BuffStacksAlt1 = 0x20,
		BuffStacksAlt2 = 0x24,
		BuffStacksFloat = 0x2C,
		BuffStacksInt = 0x74,
		BuffScriptHash = 0x88,
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

	enum Chat : DWORD {
		ChatInstance = 0x30FC790,  // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 84 
	};
}