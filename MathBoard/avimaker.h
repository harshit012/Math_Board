#ifndef AVIMAKER_H
#define AVIMAKER_H
#include<stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

class AVIMaker
{
public:
    struct gwavi_header_t
    {
        unsigned int time_delay;	/* dwMicroSecPerFrame */
        unsigned int data_rate;		/* dwMaxBytesPerSec */
        unsigned int reserved;
        unsigned int flags;		/* dwFlags */
        unsigned int number_of_frames;	/* dwTotalFrames */
        unsigned int initial_frames;	/* dwInitialFrames */
        unsigned int data_streams;	/* dwStreams */
        unsigned int buffer_size;	/* dwSuggestedBufferSize */
        unsigned int width;		/* dwWidth */
        unsigned int height;		/* dwHeight */
        unsigned int time_scale;
        unsigned int playback_data_rate;
        unsigned int starting_time;
        unsigned int data_length;
    };

    struct gwavi_stream_header_t
    {
        char data_type[5];	    /* fccType */
        char codec[5];		    /* fccHandler */
        unsigned int flags;	    /* dwFlags */
        unsigned int priority;
        unsigned int initial_frames;/* dwInitialFrames */
        unsigned int time_scale;    /* dwScale */
        unsigned int data_rate;	    /* dwRate */
        unsigned int start_time;    /* dwStart */
        unsigned int data_length;   /* dwLength */
        unsigned int buffer_size;   /* dwSuggestedBufferSize */
        unsigned int video_quality; /* dwQuality */
        /**
         * Value between 0-10000. If set to -1, drivers use default quality
         * value.
         */
        int audio_quality;
        unsigned int sample_size;   /* dwSampleSize */
    };

    struct gwavi_stream_format_v_t
    {
        unsigned int header_size;
        unsigned int width;
        unsigned int height;
        unsigned short int num_planes;
        unsigned short int bits_per_pixel;
        unsigned int compression_type;
        unsigned int image_size;
        unsigned int x_pels_per_meter;
        unsigned int y_pels_per_meter;
        unsigned int colors_used;
        unsigned int colors_important;
        unsigned int *palette;
        unsigned int palette_count;
    };

    struct gwavi_stream_format_a_t
    {
        unsigned short format_type;
        unsigned int channels;
        unsigned int sample_rate;
        unsigned int bytes_per_second;
        unsigned int block_align;
        unsigned int bits_per_sample;
        unsigned short size;
    };

    struct gwavi_t
    {
        FILE *out;
        struct gwavi_header_t avi_header;
        struct gwavi_stream_header_t stream_header_v;
        struct gwavi_stream_format_v_t stream_format_v;
        struct gwavi_stream_header_t stream_header_a;
        struct gwavi_stream_format_a_t stream_format_a;
        long marker;
        int offsets_ptr;
        int offsets_len;
        long offsets_start;
        unsigned int *offsets;
        int offset_count;
    };

    struct gwavi_audio_t
    {
        unsigned int channels;
        unsigned int bits;
        unsigned int samples_per_second;
    };



    AVIMaker();
    int write_avi_header(FILE *out, struct gwavi_header_t *avi_header);
    int write_stream_header(FILE *out,
                struct gwavi_stream_header_t *stream_header);
    int write_stream_format_v(FILE *out,
                  struct gwavi_stream_format_v_t *stream_format_v);
    int write_stream_format_a(FILE *out,
                  struct gwavi_stream_format_a_t *stream_format_a);
    int write_avi_header_chunk(struct gwavi_t *gwavi);
    int write_index(FILE *out, int count, unsigned int *offsets);
    int check_fourcc(const char *fourcc);

    int write_int(FILE *out, unsigned int n);
    int write_short(FILE *out, unsigned int n);
    int write_chars(FILE *out, const char *s);
    int write_chars_bin(FILE *out, const char *s, int count);
    struct gwavi_t *gwavi_open(const char *filename, unsigned int width,
                   unsigned int height, const char *fourcc, unsigned int fps,
                   struct gwavi_audio_t *audio);
    int gwavi_add_frame(void* ptr, unsigned char *buffer, size_t len);
    int gwavi_add_audio(struct gwavi_t *gwavi, unsigned char *buffer, size_t len);
    int gwavi_close(void* ptr);

    int gwavi_set_framerate(struct gwavi_t *gwavi, unsigned int fps);
    int gwavi_set_codec(struct gwavi_t *gwavi, const char *fourcc);
    int gwavi_set_size(struct gwavi_t *gwavi, unsigned int width,
                unsigned int height);

};

#endif // AVIMAKER_H
