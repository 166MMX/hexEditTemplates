#pragma pack(1)

struct c_chunk_header {
    char*           type;
    unsigned int    size;
    unsigned short  version;
} chunk_header;

struct c_realmedia_file_header {
    c_chunk_header  chunk_header;
    unsigned int    file_version;
    unsigned int    header_count;
} realmedia_file_header;

struct c_file_flags {
    unsigned short  saveable: 1;
    unsigned short  perfect_play: 1;
    unsigned short  live_breadcast: 1;
} file_flags;

struct c_file_property_header {
    c_chunk_header  chunk_header;
    unsigned int    max_bit_rate;
    unsigned int    avg_bit_rate;
    unsigned int    max_data_packet_size;
    unsigned int    avg_data_packet_size;
    unsigned int    data_packet_count;
    unsigned int    duration;
    unsigned int    pre_buffer;
    unsigned int    first_index_chunk_offset;
    unsigned int    first_data_chunk_offset;
    unsigned short  stream_count;
    c_file_flags    flags;
} file_property_header;

struct c_media_property_header {
    c_chunk_header  chunk_header;
    unsigned short  stream_number;
    unsigned int    max_bit_rate;
    unsigned int    avg_bit_rate;
    unsigned int    max_data_packet_size;
    unsigned int    avg_data_packet_size;
    unsigned int    stream_offset;
    unsigned int    stream_pre_roll;
    unsigned int    stream_duration;
    unsigned char   stream_description_length;
    char*           stream_description;
    unsigned char   stream_mime_type_length;
    char*           stream_mime_type;
    unsigned int    mime_type_header_size;
    char            mime_type_header; // TODO: continue
} media_property_header;

struct c_content_description_header {
    c_chunk_header  chunk_header;
    unsigned short  title_length;
    char*           title;
    unsigned short  author_length;
    char*           author;
    unsigned short  copyright_length;
    char*           copyright;
    unsigned short  comment_length;
    char*           comment;
} content_description_header;

struct c_data_packet_flags {
    unsigned char   reliable_packet: 1;
    unsigned char   keyframe: 1;
} data_packet_flags;

struct c_data_packet {
    unsigned short  version;
    unsigned short  size;
    unsigned short  stream_number;
    unsigned int    timestamp;
    unsigned char   group;
    c_data_packet_flags  flags;
    unsigned short  asm_rule;
    unsigned char   asm_flags;
    unsigned char   payload;
} data_packet;

struct c_data_header {
    c_chunk_header  chunk_header;
    unsigned int    packet_count;
    unsigned int    next_data_offset;
    c_data_packet   packets;
} data_header;

struct c_index_entry {
    unsigned short  version;
    unsigned int    timestamp;
    unsigned int    packet_offset;
    unsigned int    packet_number;
} index_entry;

struct c_index_chunk {
    c_chunk_header  header;
    unsigned int    entry_count;
    unsigned short  stream_number;
    unsigned int    next_index_offset;
    c_index_entry   entries;
} index_chunk;

