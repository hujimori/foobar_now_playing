// foo_twitter.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

DECLARE_COMPONENT_VERSION(
	"now playing",
	"1.0",
	"tweet track"
);


class CPlayback : public play_callback_static
{
public:
	virtual unsigned int get_flags(void);
	virtual void on_playback_new_track(metadb_handle_ptr track);
	virtual void on_playback_stop(play_control::t_stop_reason p_reason) {};
	virtual void on_playback_time(double p_time) {};
	virtual void on_playback_seek(double time) {};
	virtual void on_playback_starting(play_control::t_track_command p_command, bool p_paused) {}
	virtual void on_playback_pause(bool p_state) {}
	virtual void on_playback_edited(metadb_handle_ptr track) {}
	virtual void on_playback_dynamic_info(const file_info & p_info) {};
	virtual void on_playback_dynamic_info_track(const file_info & p_info) {};
	virtual void on_volume_change(float p_new_val) {}
};

static play_callback_static_factory_t<CPlayback> pbsf;

unsigned int CPlayback::get_flags(void)
{
	return flag_on_playback_new_track;
}

void CPlayback::on_playback_new_track(metadb_handle_ptr track)
{
	// ファイルパス表示
	console::info(track->get_path());

	// メタデータ表示
	file_info_impl info;
	track->get_info(info);
	if (info.meta_exists("TITLE"))
	{
		console::info(info.meta_get("TITLE", 0));
	}
	if (info.meta_exists("ARTIST"))
	{
		console::info(info.meta_get("ARTIST", 0));
	}
}