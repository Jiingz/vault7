#pragma once
namespace Offsets
{
	enum Functions {
		HealthBarPosition = 0x5AFA80, // 83 EC 24 53 55 56 57 8B F9 6A // Function call :  E8 ? ? ? ? 8B 4E 08 8D 54 24 04 52 | I recreate that
		WorldToScreen = 0xA24C50, // 83 EC 10 56 E8 ? ? ? ? 8B 08  || FUNCTION CALL OF W2s: E8 ? ? ? ? F3 0F 10 4C 24 ? 83 C4 10 F3 0F 10
		GetBasicAttack = 0x1253D0, // E8 ? ? ? ? 83 38 00 74 4B recheck
		GetAttackDelay = 0x2848F0, // 8B 44 24 04 51 F3
		GetAttackCastDelay = 0x2847F0, // 83 EC 0C 53 8B 5C 24 14 8B CB 56
		GetSpellState = 0x4f2270, //unused | there are rumors this is unsafe, need to check
		GetBoundingRadius = 0x1254D0, // 83 EC 08 56 8B F1 83 BE ? ? ? ? ? 74
		BaseDrawPosition = 0x1720C0, // E8 ? ? ? ? EB 07 8B 01 8B call GetBaseDrawPos()
		IsNotWall = 0x9A78E0,	  // E8 ? ? ? ? 83 C4 10 80 BE ? ? ? ? ? 74 0A
		CompareObjectTypeFlags = 0x2360C0, // E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 87 ? ? ? ? 8D
		//IsValidObject = E8 ? ? ? ? 84 C0 75 ? 5E 83 C4 ? C2 ? ?
		onProcessSpell = 0x510740,				// 56 8B 74 24 08 8B 16 85
		OnCreateObject = 0x279D90, //UNUSED		// 56 8B F1 80 7E 28 00 75
		OnDeleteObject = 0x26AA60, //UNUSED		// 53 57 8B 7C 24 0C 8B D9 8B CF E8
		OnNewPath = 0x287EC0, //UNUSED			// 83 EC 18 56 8B 74 24 20 8B CE 57
		PrintChat = 0x590470,					// INSIDE PRINTCHAT FUNC: 8B 4D E0 42    ||  CALL OF PRINTCHAT: E8 ? ? ? ? B8 ? ? ? ? C7 04 
		//IsNotWall = 0x8e64f0,
		IssueClick = 0x6022C0, // inside function: 75 18 8B 0D ? ? ? ? 57
		IssueSpell = 0x5E9C50, // 53 8B 1D ?? ?? ?? ?? 55 56 57 8B F9 85

		//Healthbar pos
		v15a1 = 0xC,														//updated 11.22
		v15a2 = 0x268,														//updated 11.22
	};

	enum GameObject
	{
		Name = 0x6C,
		ChampionName = 0x2DA4,
	};

	//GameObject notes
	// CharacterData = 83 C0 C0 8D	// FF 74 24 64 8D 8E ? ? ? ?						go to fn xref to operand, go to 1 result, lea ecx, [esi+offseth] // follow instruction next line lea ecx, [esi+offseth]

	enum ActiveProcessSpell
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


	enum GameClient {
		GameTime = 0x31047C4, // F3 0F 5C 0D ? ? ? ? 0F 2F C1 F3	 subss   xmm1, dword_offset
		GameInfo = 0x30FFBB0, // A1 ? ? ? ? 68 ? ? ? ? 8B 70 08 // maybe +8?
		NetClient = 0x30cad38, //UNUSED OUTDATED
		ObjManager = 0x187015C, // 89 ? ? ? ? ? 57 C7 06 ? ? ? ? 66 C7 46 04 ? ?
		UnderMouseObject = 0x183F0D8, // A1 ? ? ? ? 8B 0D ? ? ? ? 3B 
		HudInstance = 0x1870198, // 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0
		LocalPlayer = 0x310D250, // A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
		BuffManager = 0x21B8, // 8D 8F ? ? ? ? E8 ? ? ? ? 6A 00 50								ecx, [edi + offseth]
	};

	enum Minimap {
		MinimapInstance = 0x30F88B8, // 8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7 // OUTDATED 11.19
		TacticalMap = 0x2,
	};

	enum ManagerTemplate {
		_ManagerTemplate_Func_ = 0x2f1180, //UNUSED, might be useful to find offsets but idk // OUTDATED 11.19
		AIMissileClient = 0x310D2D8,// 8B 0D ? ? ? ? 56 8B 01 FF		//UNUSED wont use that shit
		AIMinionClient = 0x18701F4, // A1 ? ? ? ? 53 55 8B 6C 24 1C		// 8B 35 ? ? ? ? 8B 56 
		AITurretClient = 0x3100990, // A1 ? ? ? ? 53 56 8B 70 04		// 8B 0D ? ? ? ? FF 74 24 14 FF 74 24 14 E8
		AIHeroClient = 0x186E030, 	// 8B 0D ? ? ? ? 8D 44 24 10 50 8D 44 24 10 50 53
		AIAttackableUnitClient = 0x1870160, // A1 ? ? ? ? FF B4 24 ? ? ? ? F3 0F 10 44 24 ? F3
		AIShopClient = 0x3100994, // 8B 0D ? ? ? ? E8 ? ? ? ? 84 C0 75 11 8B
		AIInhibitorClient = 0x310DAE0, // A1 ? ? ? ? 53 55 56 8B 70 04 8B 40
		AIBuildingClient = 0x186D888, // 8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 38
	};

	enum AIManager
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

	enum Chat {
		ChatInstance = 0x30FFBAC,  // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 84 
	};
}