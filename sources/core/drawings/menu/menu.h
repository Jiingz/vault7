#pragma once
#include <mutex>

namespace drawings
{
	static class MainMenu
	{
	private:

		enum active_menu
		{
			coreMenu,
			orbwalker,
			champion,
			name_changer
		};

	public:

		static void DrawMenu();

	private:

		static void CustomColor();

		static void CustomStyle();

		static bool open_;
		static int delay_;
		static active_menu active_menu_;
		static std::once_flag style_initialized_;
	};

}

using namespace drawings;