#include "../SDK/foobar2000.h"
#include "../helpers/helpers.h"

class FileInfoData : public file_info_filter {
private:
	pfc::string8 m_tag; // É^ÉOñº
	pfc::string8 m_val; // íl
public:
	FileInfoData(const pfc::string8 tag, const pfc::string8 val) : m_tag(tag), m_val(val) {};
	virtual bool apply_filter(metadb_handle_ptr p_location, t_filestats p_stats, file_info & p_info);
};

