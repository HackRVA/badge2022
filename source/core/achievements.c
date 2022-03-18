#include "achievements.h"
#include "key_value_storage.h"

static unsigned short achievements[ACHIEVEMENT_COUNT] = { 0 };

static void save_achievements_to_flash(void)
{
    flash_kv_store_binary("achievements", &achievements, sizeof(achievements));
}

void maybe_load_achievements_from_flash(void)
{
	static int loaded_achievements_from_flash = 0;

	if (loaded_achievements_from_flash)
		return;

    flash_kv_get_binary("achievements", &achievements, sizeof(achievements));

	loaded_achievements_from_flash = 1;
}

void add_achievement(enum achievement achievement, unsigned short achievement_increment)
{
	int new_value;

	if (achievement >= ACHIEVEMENT_COUNT)
		return;

	new_value = achievements[achievement] + achievement_increment;
	if (new_value >= 0 && new_value <= 0x0ffff)
		achievements[achievement] = new_value;
	save_achievements_to_flash();
}

int get_achievement_count(enum achievement achievement)
{

	maybe_load_achievements_from_flash();

	if (achievement >= ACHIEVEMENT_COUNT)
		return -1;
	return achievements[achievement];
}

