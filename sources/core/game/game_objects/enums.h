#pragma once
#include <wtypes.h>
namespace game
{
	enum game_object_team
	{
		Order = 100,
		Chaos = 200,
		Neutral = 300
	};

	enum recall_state
	{
		twisted_fate_teleport = 4,
		recalling = 6,
		recall_yuumi_attached = 10,
		super_recall = 11,
		teleporting = 16,
		ShenStandUnitedState = 19
	};

	enum visible_type
	{
		visible = 0,
		local_visible = 1,
		force_visible = 8
	};

	enum combat_type
	{
		melee = 1,
		ranged = 2
	};

	enum buff_hash : ULONG
	{
		barontarget = 0xD7D32CF6,
		ConquerorEnrage = 0xD4515DC0,   // "ASSETS/Perks/Styles/Precision/Conqueror/ConquerorEnrage.lua"
		itemsmitechallenge = 0xD68F930B,
		SummonerExhaust = 0x6F2D5F3D,

		aatroxpassivereadyr = 0x4ED863B8,
		akalipweapon = 0x553CCB5D,
		alistareattack = 0xC9742FD2,
		BlessingoftheLizardElder = 0x3519F8B0,
		blessingofthelizardelderslow = 0x48208A75,
		bluecardpreattack = 0x8B0B9A1C,
		braumeshieldbuff = 0x7215EE81,
		braummarkcounter = 0xDF74BBED,
		cardmasterstackparticle = 0x4AED0CE1, // TwistedFate
		cursedtouch = 0x8C10C58A,   // Amumu
		deceive = 0x22C648A0, // Shaco
		GalioW = 0x22086614,
		goldcardpreattack = 0xA96339F2,
		kalistacoopstrikeally = 0x8A9646FD,
		kalistacoopstrikemarkbuff = 0xBE5519A3,
		LeonaSunlight = 0xE0C2FFB4,
		malzaharpassiveshield = 0x33DB7C71,
		Meditate = 0x50E753F4,  // Yi
		MoltenShield = 0x668C0F2F,  // Annie
		NamiE = 0xE503837D,
		nautiluspassivecheck = 0x5922A2FF,
		nautiluspiercinggazeshield = 0x24621017,
		neekowpassiveready = 0x7E98AA02,
		nocturneumbrablades = 0xD9A00D4D,
		redcardpreattack = 0x854C3BC3,
		rengarqasbuff = 0xD5BB5192,
		RengarQEmp = 0x162C88E7,
		sonapassivedebuff = 0xAF037A39,
		sonaqprocattacker = 0xF791AC5A,
		vaynesilvereddebuff = 0x4BAEFCCC,
		vaynetumblebonus = 0xBB89EA44,
		ViktorPowerTransfer = 0x5DDB178C,
		ViktorPowerTransferReturn = 0x98CB6192,
		viktorpowertransfer_haste = 0x3060A07C,
		VorpalSpikes = 0xB49346CA, // Cho
		wujustylesuperchargedvisual = 0x40DC9CE4,
		TaricR = 0x9AEAADC2,
		SennaPassiveStacks = 0xE88568F8,

		dreadnoughtmomentumbuff = 0xBB077487, // Dead Man's Plate
		itemangelhandbuff = 0x1D5D9677,
		itemphantomdancerdebuff = 0xD1F5085E,
		itemtitanichydracleavebuff = 0x9848DC51,
		zhonyasringshield = 0x3DC195A6,
		immortalShieldBow = 0xF0164916,
	};


	enum buff_type
	{
		BUFF_Internal = 0,
		BUFF_Aura = 1,
		BUFF_CombatEnhancer = 2,
		BUFF_CombatDehancer = 3,
		BUFF_SpellShield = 4,
		BUFF_Stun = 5,
		BUFF_Invisibility = 6,
		BUFF_Silence = 7,
		BUFF_Taunt = 8,
		BUFF_Berserk = 9,
		BUFF_Polymorph = 10,
		BUFF_Slow = 11,
		BUFF_Snare = 12,
		BUFF_Damage = 13,
		BUFF_Heal = 14,
		BUFF_Haste = 15,
		BUFF_SpellImmunity = 16,
		BUFF_PhysicalImmunity = 17,
		BUFF_Invulnerability = 18,
		BUFF_AttackSpeedSlow = 19,
		BUFF_NearSight = 20,
		BUFF_Fear = 22,
		BUFF_Charm = 23,
		BUFF_Poison = 24,
		BUFF_Suppression = 25,
		BUFF_Blind = 26,
		BUFF_Counter = 27,
		BUFF_Currency = 21,
		BUFF_Shred = 28,
		BUFF_Flee = 29,
		BUFF_Knockup = 30,
		BUFF_Knockback = 31,
		BUFF_Disarm = 32,
		BUFF_Grounded = 33,
		BUFF_Drowsy = 34,
		BUFF_Asleep = 35,
		BUFF_Obscured = 36,
		BUFF_ClickproofToEnemies = 37,
		BUFF_UnKillable = 38
	};
}