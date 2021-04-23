#include "avimaker.h"

AVIMaker::AVIMaker()
{

}


int AVIMaker::write_int(FILE *out, unsigned int n)
{
    if (fputc((n & 255), out) == EOF)
        return -1;
    if (fputc(((n >> 8) & 255), out) == EOF)
        return -1;
    if (fputc(((n >> 16) & 255), out) == EOF)
        return -1;
    if (fputc(((n >> 24) & 255), out) == EOF)
        return -1;

    return 0;
}

int AVIMaker::write_short(FILE *out, unsigned int n)
{
    if (fputc((n & 255), out) == EOF)
        return -1;
    if (fputc(((n >> 8) & 255), out) == EOF)
        return -1;

    return 0;
}

int AVIMaker::write_chars(FILE *out, const char *s)
{
    int t = 0;

    while(s[t] != 0 && t < 255)
        if (fputc(s[t++], out) == EOF)
            return -1;

    return 0;
}

int AVIMaker::write_chars_bin(FILE *out, const char *s, int count)
{
    int t;

    for (t = 0; t < count; t++)
        if (fputc(s[t], out) == EOF)
            return -1;

    return 0;
}



// fileio.c finished

int AVIMaker::write_avi_header(FILE *out,gwavi_header_t *avi_header)
{
    long marker, t;
        if (write_chars_bin(out, "avih", 4) == -1) {
            (void)fprintf(stderr, "write_avi_header: write_chars_bin() "
                      "failed\n");
            return -1;
        }
        if ((marker = ftell(out)) == -1) {
            perror("write_avi_header (ftell)");
            return -1;
        }
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        if (write_int(out,avi_header->time_delay) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->data_rate) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->reserved) == -1)
            goto write_int_failed;
        /* dwFlags */
        if (write_int(out, avi_header->flags) == -1)
            goto write_int_failed;
        /* dwTotalFrames */
        if (write_int(out, avi_header->number_of_frames) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->initial_frames) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->data_streams) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->buffer_size) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->width) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->height) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->time_scale) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->playback_data_rate) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->starting_time) == -1)
            goto write_int_failed;
        if (write_int(out, avi_header->data_length) == -1)
            goto write_int_failed;

        if ((t = ftell(out)) == -1) {
            perror("write_avi_header (ftell)");
            return -1;
        }
        if (fseek(out, marker, SEEK_SET) == -1) {
            perror("write_avi_header (fseek)");
            return -1;
        }
        if (write_int(out, (unsigned int)(t - marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1) {
            perror("write_avi_header (fseek)");
            return -1;
        }

        return 0;

    write_int_failed:
        (void)fprintf(stderr, "write_avi_header: write_int() failed\n");
        return -1;
}

int AVIMaker::write_stream_header(FILE *out, AVIMaker::gwavi_stream_header_t *stream_header)
{
    long marker, t;

        if (write_chars_bin(out, "strh", 4) == -1)
            goto write_chars_bin_failed;
        if ((marker = ftell(out)) == -1) {
            perror("write_stream_header (ftell)");
            return -1;
        }
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        if (write_chars_bin(out, stream_header->data_type, 4) == -1)
            goto write_chars_bin_failed;
        if (write_chars_bin(out, stream_header->codec, 4) == -1)
            goto write_chars_bin_failed;
        if (write_int(out, stream_header->flags) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->priority) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->initial_frames) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->time_scale) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->data_rate) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->start_time) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->data_length) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->buffer_size) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->video_quality) == -1)
            goto write_int_failed;
        if (write_int(out, stream_header->sample_size) == -1)
            goto write_int_failed;
        if (write_int(out, 0) == -1)
            goto write_int_failed;
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        if ((t = ftell(out)) == -1) {
            perror("write_stream_header (ftell)");
            return -1;
        }
        if (fseek(out, marker, SEEK_SET) == -1) {
            perror("write_stream_header (fseek)");
            return -1;
        }
        write_int(out, (unsigned int)(t - marker - 4));
        if (fseek(out, t, SEEK_SET) == -1){
            perror("write_stream_header (fseek)");
            return -1;
        }

        return 0;

    write_int_failed:
        (void)fprintf(stderr, "write_stream_header: write_int() failed\n");
        return -1;

    write_chars_bin_failed:
        (void)fprintf(stderr, "write_stream_header: write_chars_bin() failed\n");
        return -1;
}

int AVIMaker::write_stream_format_v(FILE *out, AVIMaker::gwavi_stream_format_v_t *stream_format_v)
{
    long marker,t;
        unsigned int i;

        if (write_chars_bin(out, "strf", 4) == -1) {
            (void)fprintf(stderr, "write_stream_format_v: write_chars_bin()"
                      " failed\n");
            return -1;
        }
        if ((marker = ftell(out)) == -1) {
            perror("write_stream_format_v (ftell)");
            return -1;
        }
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        if (write_int(out, stream_format_v->header_size) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->width) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->height) == -1)
            goto write_int_failed;
        if (write_short(out, stream_format_v->num_planes) == -1) {
            (void)fprintf(stderr, "write_stream_format_v: write_short() "
                      "failed\n");
            return -1;
        }
        if (write_short(out, stream_format_v->bits_per_pixel) == -1) {
            (void)fprintf(stderr, "write_stream_format_v: write_short() "
                      "failed\n");
            return -1;
        }
        if (write_int(out, stream_format_v->compression_type) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->image_size) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->x_pels_per_meter) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->y_pels_per_meter) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->colors_used) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_v->colors_important) == -1)
            goto write_int_failed;

        if (stream_format_v->colors_used != 0)
            for (i = 0; i < stream_format_v->colors_used; i++) {
                if (fputc(stream_format_v->palette[i] & 255, out)
                        == EOF)
                    goto fputc_failed;
                if (fputc((stream_format_v->palette[i] >> 8) & 255, out)
                        == EOF)
                    goto fputc_failed;
                if (fputc((stream_format_v->palette[i] >> 16) & 255, out)
                        == EOF)
                    goto fputc_failed;
                if (fputc(0, out) == EOF)
                    goto fputc_failed;
            }

        if ((t = ftell(out)) == -1) {
            perror("write_stream_format_v (ftell)");
            return -1;
        }
        if (fseek(out,marker,SEEK_SET) == -1) {
            perror("write_stream_format_v (fseek)");
            return -1;
        }
        if (write_int(out, (unsigned int)(t - marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1) {
            perror("write_stream_format_v (fseek)");
            return -1;
        }
        return 0;
    write_int_failed:
        (void)fprintf(stderr, "write_stream_format_v: write_int() failed\n");
        return -1;
    fputc_failed:
        (void)fprintf(stderr, "write_stream_format_v: fputc() failed\n");
        return -1;
}

int AVIMaker::write_stream_format_a(FILE *out, AVIMaker::gwavi_stream_format_a_t *stream_format_a)
{
    long marker, t;

        if (write_chars_bin(out, "strf", 4) == -1) {
            (void)fprintf(stderr, "write_stream_format_a: write_chars_bin()"
                      " failed\n");
            return -1;
        }
        if ((marker = ftell(out)) == -1) {
            perror("write_stream_format_a (ftell)");
            return -1;
        }
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        if (write_short(out, stream_format_a->format_type) == -1)
            goto write_short_failed;
        if (write_short(out, stream_format_a->channels) == -1)
            goto write_short_failed;
        if (write_int(out, stream_format_a->sample_rate) == -1)
            goto write_int_failed;
        if (write_int(out, stream_format_a->bytes_per_second) == -1)
            goto write_int_failed;
        if (write_short(out, stream_format_a->block_align) == -1)
            goto write_short_failed;
        if (write_short(out, stream_format_a->bits_per_sample) == -1)
            goto write_short_failed;
        if (write_short(out, stream_format_a->size) == -1)
            goto write_short_failed;

        if ((t = ftell(out)) == -1) {
            perror("write_stream_format_a (ftell)");
            return -1;
        }
        if (fseek(out, marker, SEEK_SET) == -1) {
            perror("write_stream_format_a (fseek)");
            return -1;
        }
        if (write_int(out, (unsigned int)(t - marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1) {
            perror("write_stream_format_a (fseek)");
            return -1;
        }

        return 0;

    write_int_failed:
        (void)fprintf(stderr, "write_stream_format_a: write_int() failed\n");
        return -1;

    write_short_failed:
        (void)fprintf(stderr, "write_stream_format_a: write_short() failed\n");
        return -1;
}

int AVIMaker::write_avi_header_chunk(AVIMaker::gwavi_t *gwavi)
{
    long marker, t;
        long sub_marker;
        FILE *out = gwavi->out;

        if (write_chars_bin(out, "LIST", 4) == -1)
            goto write_chars_bin_failed;
        if ((marker = ftell(out)) == -1)
            goto ftell_failed;
        if (write_int(out, 0) == -1)
            goto write_int_failed;
        if (write_chars_bin(out, "hdrl", 4) == -1)
            goto write_chars_bin_failed;
        if (write_avi_header(out, &gwavi->avi_header) == -1) {
            (void)fprintf(stderr, "write_avi_header_chunk: "
                      "write_avi_header() failed\n");
            return -1;
        }

        if (write_chars_bin(out, "LIST", 4) == -1)
            goto write_chars_bin_failed;
        if ((sub_marker = ftell(out)) == -1)
            goto ftell_failed;
        if (write_int(out, 0) == -1)
            goto write_int_failed;
        if (write_chars_bin(out, "strl", 4) == -1)
            goto write_chars_bin_failed;
        if (write_stream_header(out, &gwavi->stream_header_v) == -1) {
            (void)fprintf(stderr, "write_avi_header_chunk: "
                      "write_stream_header failed\n");
            return -1;
        }
        if (write_stream_format_v(out, &gwavi->stream_format_v) == -1) {
            (void)fprintf(stderr, "write_avi_header_chunk: "
                      "write_stream_format_v failed\n");
            return -1;
        }

        if ((t = ftell(out)) == -1)
            goto ftell_failed;

        if (fseek(out, sub_marker, SEEK_SET) == -1)
            goto fseek_failed;
        if (write_int(out, (unsigned int)(t - sub_marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1)
            goto fseek_failed;

        if (gwavi->avi_header.data_streams == 2) {
            if (write_chars_bin(out, "LIST", 4) == -1)
                goto write_chars_bin_failed;
            if ((sub_marker = ftell(out)) == -1)
                goto ftell_failed;
            if (write_int(out, 0) == -1)
                goto write_int_failed;
            if (write_chars_bin(out, "strl", 4) == -1)
                goto write_chars_bin_failed;
            if (write_stream_header(out, &gwavi->stream_header_a) == -1) {
                (void)fprintf(stderr, "write_avi_header_chunk: "
                          "write_stream_header failed\n");
                return -1;
            }
            if (write_stream_format_a(out, &gwavi->stream_format_a) == -1) {
                (void)fprintf(stderr, "write_avi_header_chunk: "
                          "write_stream_format_a failed\n");
                return -1;
            }

            if ((t = ftell(out)) == -1)
                goto ftell_failed;
            if (fseek(out, sub_marker, SEEK_SET) == -1)
                goto fseek_failed;
            if (write_int(out, (unsigned int)(t - sub_marker - 4)) == -1)
                goto write_int_failed;
            if (fseek(out, t, SEEK_SET) == -1)
                goto fseek_failed;
        }

        if ((t = ftell(out)) == -1)
            goto ftell_failed;
        if (fseek(out, marker, SEEK_SET) == -1)
            goto fseek_failed;
        if (write_int(out, (unsigned int)(t - marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1)
            goto fseek_failed;

        return 0;

    ftell_failed:
        perror("write_avi_header_chunk (ftell)");
        return -1;

    fseek_failed:
        perror("write_avi_header_chunk (fseek)");
        return -1;

    write_int_failed:
        (void)fprintf(stderr, "write_avi_header_chunk: write_int() failed\n");
        return -1;

    write_chars_bin_failed:
        (void)fprintf(stderr, "write_avi_header_chunk: write_chars_bin() failed\n");
        return -1;
}

int AVIMaker::write_index(FILE *out, int count, unsigned int *offsets)
{
    long marker, t;
        unsigned int offset = 4;

        if (offsets == 0)
            return -1;

        if (write_chars_bin(out, "idx1", 4) == -1) {
            (void)fprintf(stderr, "write_index: write_chars_bin) failed\n");
            return -1;
        }
        if ((marker = ftell(out)) == -1) {
            perror("write_index (ftell)");
            return -1;
        }
        if (write_int(out, 0) == -1)
            goto write_int_failed;

        for (t = 0; t < count; t++) {
            if ((offsets[t] & 0x80000000) == 0)
                write_chars(out, "00dc");
            else {
                write_chars(out, "01wb");
                offsets[t] &= 0x7fffffff;
            }
            if (write_int(out, 0x10) == -1)
                goto write_int_failed;
            if (write_int(out, offset) == -1)
                goto write_int_failed;
            if (write_int(out, offsets[t]) == -1)
                goto write_int_failed;

            offset = offset + offsets[t] + 8;
        }

        if ((t = ftell(out)) == -1) {
            perror("write_index (ftell)");
            return -1;
        }
        if (fseek(out, marker, SEEK_SET) == -1) {
            perror("write_index (fseek)");
            return -1;
        }
        if (write_int(out, (unsigned int)(t - marker - 4)) == -1)
            goto write_int_failed;
        if (fseek(out, t, SEEK_SET) == -1) {
            perror("write_index (fseek)");
            return -1;
        }

        return 0;

    write_int_failed:
        (void)fprintf(stderr, "write_index: write_int() failed\n");
        return -1;
}

int AVIMaker::check_fourcc(const char *fourcc)
{
    int ret = 0;
    /* list of fourccs from http://fourcc.org/codecs.php */
    const char valid_fourcc[] =
        "3IV1 3IV2 8BPS"
        "AASC ABYR ADV1 ADVJ AEMI AFLC AFLI AJPG AMPG ANIM AP41 ASLC"
        "ASV1 ASV2 ASVX AUR2 AURA AVC1 AVRN"
        "BA81 BINK BLZ0 BT20 BTCV BW10 BYR1 BYR2"
        "CC12 CDVC CFCC CGDI CHAM CJPG CMYK CPLA CRAM CSCD CTRX CVID"
        "CWLT CXY1 CXY2 CYUV CYUY"
        "D261 D263 DAVC DCL1 DCL2 DCL3 DCL4 DCL5 DIV3 DIV4 DIV5 DIVX"
        "DM4V DMB1 DMB2 DMK2 DSVD DUCK DV25 DV50 DVAN DVCS DVE2 DVH1"
        "DVHD DVSD DVSL DVX1 DVX2 DVX3 DX50 DXGM DXTC DXTN"
        "EKQ0 ELK0 EM2V ES07 ESCP ETV1 ETV2 ETVC"
        "FFV1 FLJP FMP4 FMVC FPS1 FRWA FRWD FVF1"
        "GEOX GJPG GLZW GPEG GWLT"
        "H260 H261 H262 H263 H264 H265 H266 H267 H268 H269"
        "HDYC HFYU HMCR HMRR"
        "I263 ICLB IGOR IJPG ILVC ILVR IPDV IR21 IRAW ISME"
        "IV30 IV31 IV32 IV33 IV34 IV35 IV36 IV37 IV38 IV39 IV40 IV41"
        "IV41 IV43 IV44 IV45 IV46 IV47 IV48 IV49 IV50"
        "JBYR JPEG JPGL"
        "KMVC"
        "L261 L263 LBYR LCMW LCW2 LEAD LGRY LJ11 LJ22 LJ2K LJ44 LJPG"
        "LMP2 LMP4 LSVC LSVM LSVX LZO1"
        "M261 M263 M4CC M4S2 MC12 MCAM MJ2C MJPG MMES MP2A MP2T MP2V"
        "MP42 MP43 MP4A MP4S MP4T MP4V MPEG MPG4 MPGI MR16 MRCA MRLE"
        "MSVC MSZH"
        "MTX1 MTX2 MTX3 MTX4 MTX5 MTX6 MTX7 MTX8 MTX9"
        "MVI1 MVI2 MWV1"
        "NAVI NDSC NDSM NDSP NDSS NDXC NDXH NDXP NDXS NHVU NTN1 NTN2"
        "NVDS NVHS"
        "NVS0 NVS1 NVS2 NVS3 NVS4 NVS5"
        "NVT0 NVT1 NVT2 NVT3 NVT4 NVT5"
        "PDVC PGVV PHMO PIM1 PIM2 PIMJ PIXL PJPG PVEZ PVMM PVW2"
        "QPEG QPEQ"
        "RGBT RLE RLE4 RLE8 RMP4 RPZA RT21 RV20 RV30 RV40 S422 SAN3"
        "SDCC SEDG SFMC SMP4 SMSC SMSD SMSV SP40 SP44 SP54 SPIG SQZ2"
        "STVA STVB STVC STVX STVY SV10 SVQ1 SVQ3"
        "TLMS TLST TM20 TM2X TMIC TMOT TR20 TSCC TV10 TVJP TVMJ TY0N"
        "TY2C TY2N"
        "UCOD ULTI"
        "V210 V261 V655 VCR1 VCR2 VCR3 VCR4 VCR5 VCR6 VCR7 VCR8 VCR9"
        "VDCT VDOM VDTZ VGPX VIDS VIFP VIVO VIXL VLV1 VP30 VP31 VP40"
        "VP50 VP60 VP61 VP62 VP70 VP80 VQC1 VQC2 VQJC VSSV VUUU VX1K"
        "VX2K VXSP VYU9 VYUY"
        "WBVC WHAM WINX WJPG WMV1 WMV2 WMV3 WMVA WNV1 WVC1"
        "X263 X264 XLV0 XMPG XVID"
        "XWV0 XWV1 XWV2 XWV3 XWV4 XWV5 XWV6 XWV7 XWV8 XWV9"
        "XXAN"
        "Y16 Y411 Y41P Y444 Y8 YC12 YUV8 YUV9 YUVP YUY2 YUYV YV12 YV16"
        "YV92"
        "ZLIB ZMBV ZPEG ZYGO ZYYY";

    if (!fourcc) {
        (void)fputs("fourcc cannot be NULL", stderr);
        return -1;
    }
    if (strchr(fourcc, ' ') || !strstr(valid_fourcc, fourcc))
        ret = 1;

    return ret;
}



int AVIMaker::gwavi_add_frame(void *ptr, unsigned char *buffer, size_t len)
{
    struct gwavi_t *gwavi=(struct gwavi_t *)ptr;
    size_t maxi_pad;  /* if your frame is raggin, give it some paddin' */
    size_t t;

    if (!gwavi || !buffer) {
        (void)fputs("gwavi and/or buffer argument cannot be NULL",
                stderr);
        return -1;
    }
    if (len < 256)
        (void)fprintf(stderr, "WARNING: specified buffer len seems "
                  "rather small: %d. Are you sure about this?\n",
                  (int)len);

    gwavi->offset_count++;
    gwavi->stream_header_v.data_length++;

    maxi_pad = len % 4;
    if (maxi_pad > 0)
        maxi_pad = 4 - maxi_pad;

    if (gwavi->offset_count >= gwavi->offsets_len) {
        gwavi->offsets_len += 1024;
        gwavi->offsets = (unsigned int *)realloc(gwavi->offsets,
                    (size_t)gwavi->offsets_len *
                    sizeof(unsigned int));
    }

    gwavi->offsets[gwavi->offsets_ptr++] = (unsigned int)(len + maxi_pad);

    if (write_chars_bin(gwavi->out, "00dc", 4) == -1) {
        (void)fprintf(stderr, "gwavi_add_frame: write_chars_bin() "
                  "failed\n");
        return -1;
    }
    if (write_int(gwavi->out, (unsigned int)(len + maxi_pad)) == -1) {
        (void)fprintf(stderr, "gwavi_add_frame: write_int() failed\n");
        return -1;
    }

    if ((t = fwrite(buffer, 1, len, gwavi->out)) != len) {
        (void)fprintf(stderr, "gwavi_add_frame: fwrite() failed\n");
        return -1;
    }

    for (t = 0; t < maxi_pad; t++)
        if (fputc(0, gwavi->out) == EOF) {
            (void)fprintf(stderr, "gwavi_add_frame: fputc() failed\n");
            return -1;
        }

    return 0;
}


int AVIMaker::gwavi_add_audio(struct gwavi_t *gwavi, unsigned char *buffer, size_t len)
{
    size_t maxi_pad;  /* in case audio bleeds over the 4 byte boundary  */
    size_t t;

    if (!gwavi || !buffer) {
        (void)fputs("gwavi and/or buffer argument cannot be NULL",
                stderr);
        return -1;
    }
    gwavi->offset_count++;
    maxi_pad = len % 4;
    if (maxi_pad > 0)
        maxi_pad = 4 - maxi_pad;

    if (gwavi->offset_count >= gwavi->offsets_len) {
        gwavi->offsets_len += 1024;
        gwavi->offsets = (unsigned int *)realloc(gwavi->offsets,
                    (size_t)gwavi->offsets_len *
                    sizeof(unsigned int));
    }
    gwavi->offsets[gwavi->offsets_ptr++] =
        (unsigned int)((len + maxi_pad) | 0x80000000);

    if (write_chars_bin(gwavi->out,"01wb",4) == -1) {
        (void)fprintf(stderr, "gwavi_add_audio: write_chars_bin() "
                  "failed\n");
        return -1;
    }
    if (write_int(gwavi->out,(unsigned int)(len + maxi_pad)) == -1) {
        (void)fprintf(stderr, "gwavi_add_audio: write_int() failed\n");
        return -1;
    }

    if ((t = fwrite(buffer, 1, len, gwavi->out)) != len ) {
        (void)fprintf(stderr, "gwavi_add_audio: fwrite() failed\n");
        return -1;
    }

    for (t = 0; t < maxi_pad; t++)
        if (fputc(0,gwavi->out) == EOF) {
            (void)fprintf(stderr, "gwavi_add_audio: fputc() failed\n");
            return -1;
        }

    gwavi->stream_header_a.data_length += (unsigned int)(len + maxi_pad);

    return 0;
}






int AVIMaker::gwavi_close(void* ptr)
{
    struct gwavi_t *gwavi=(struct gwavi_t *)ptr;
    long t;

    if (!gwavi) {
        (void)fputs("gwavi argument cannot be NULL", stderr);
        return -1;
    }

    if ((t = ftell(gwavi->out)) == -1)
        goto ftell_failed;
    if (fseek(gwavi->out, gwavi->marker, SEEK_SET) == -1)
        goto fseek_failed;
    if (write_int(gwavi->out, (unsigned int)(t - gwavi->marker - 4)) == -1) {
        (void)fprintf(stderr, "gwavi_close: write_int() failed\n");
        return -1;
    }
    if (fseek(gwavi->out,t,SEEK_SET) == -1)
        goto fseek_failed;

    if (write_index(gwavi->out, gwavi->offset_count, gwavi->offsets) == -1) {
        (void)fprintf(stderr, "gwavi_close: write_index() failed\n");
        return -1;
    }

    free(gwavi->offsets);

    /* reset some avi header fields */
    gwavi->avi_header.number_of_frames = gwavi->stream_header_v.data_length;

    if ((t = ftell(gwavi->out)) == -1)
        goto ftell_failed;
    if (fseek(gwavi->out, 12, SEEK_SET) == -1)
        goto fseek_failed;
    if (write_avi_header_chunk(gwavi) == -1) {
        (void)fprintf(stderr, "gwavi_close: write_avi_header_chunk() "
                  "failed\n");
        return -1;
    }
    if (fseek(gwavi->out, t, SEEK_SET) == -1)
        goto fseek_failed;

    if ((t = ftell(gwavi->out)) == -1)
        goto ftell_failed;
    if (fseek(gwavi->out, 4, SEEK_SET) == -1)
        goto fseek_failed;
    if (write_int(gwavi->out, (unsigned int)(t - 8)) == -1) {
        (void)fprintf(stderr, "gwavi_close: write_int() failed\n");
        return -1;
    }
    if (fseek(gwavi->out, t, SEEK_SET) == -1)
        goto fseek_failed;

    if (gwavi->stream_format_v.palette != 0)
        free(gwavi->stream_format_v.palette);

    if (fclose(gwavi->out) == EOF) {
        perror("gwavi_close (fclose)");
        return -1;
    }
    free(gwavi);

    return 0;

ftell_failed:
    perror("gwavi_close: (ftell)");
    return -1;

fseek_failed:
    perror("gwavi_close (fseek)");
    return -1;
}



int AVIMaker::gwavi_set_framerate(struct gwavi_t *gwavi, unsigned int fps)
{
    if (!gwavi) {
        (void)fputs("gwavi argument cannot be NULL", stderr);
        return -1;
    }
    gwavi->stream_header_v.data_rate = fps;
    gwavi->avi_header.time_delay = (10000000 / fps);

    return 0;
}


int AVIMaker::gwavi_set_codec(struct gwavi_t *gwavi, const char *fourcc)
{
    if (!gwavi) {
        (void)fputs("gwavi argument cannot be NULL", stderr);
        return -1;
    }
    if (check_fourcc(fourcc) != 0)
        (void)fprintf(stderr, "WARNING: given fourcc does not seem to "
                  "be valid: %s\n", fourcc);

    memcpy(gwavi->stream_header_v.codec, fourcc, 4);
    gwavi->stream_format_v.compression_type =
        ((unsigned int)fourcc[3] << 24) +
        ((unsigned int)fourcc[2] << 16) +
        ((unsigned int)fourcc[1] << 8) +
        ((unsigned int)fourcc[0]);

    return 0;
}

int AVIMaker::gwavi_set_size(struct gwavi_t *gwavi, unsigned int width, unsigned int height)
{
    unsigned int size = (width * height * 3);

    if (!gwavi) {
        (void)fputs("gwavi argument cannot be NULL", stderr);
        return -1;
    }

    gwavi->avi_header.data_rate = size;
    gwavi->avi_header.width = width;
    gwavi->avi_header.height = height;
    gwavi->avi_header.buffer_size = size;
    gwavi->stream_header_v.buffer_size = size;
    gwavi->stream_format_v.width = width;
    gwavi->stream_format_v.height = height;
    gwavi->stream_format_v.image_size = size;

    return 0;
}





//gwavi.h starts

AVIMaker::gwavi_t *AVIMaker::gwavi_open(const char *filename, unsigned int width, unsigned int height, const char *fourcc, unsigned int fps, AVIMaker::gwavi_audio_t *audio)
{
    struct gwavi_t *gwavi;
        FILE *out;

        if (check_fourcc(fourcc) != 0)
            (void)fprintf(stderr, "WARNING: given fourcc does not seem to "
                      "be valid: %s\n", fourcc);
        if (fps < 1)
            return NULL;
        if ((out = fopen(filename, "wb+")) == NULL) {
            perror("gwavi_open: failed to open file for writing");
            return NULL;
        }

        if ((gwavi = (struct gwavi_t *)malloc(sizeof(struct gwavi_t))) == NULL) {
            (void)fprintf(stderr, "gwavi_open: could not allocate memoryi "
                      "for gwavi structure\n");
            return NULL;
        }
        memset(gwavi, 0, sizeof(struct gwavi_t));

        gwavi->out = out;

        /* set avi header */
        gwavi->avi_header.time_delay= 1000000 / fps;
        gwavi->avi_header.data_rate = width * height * 3;
        gwavi->avi_header.flags = 0x10;

        if (audio)
            gwavi->avi_header.data_streams = 2;
        else
            gwavi->avi_header.data_streams = 1;

        /* this field gets updated when calling gwavi_close() */
        gwavi->avi_header.number_of_frames = 0;
        gwavi->avi_header.width = width;
        gwavi->avi_header.height = height;
        gwavi->avi_header.buffer_size = (width * height * 3);

        /* set stream header */
        (void)strcpy(gwavi->stream_header_v.data_type, "vids");
        (void)memcpy(gwavi->stream_header_v.codec, fourcc, 4);
        gwavi->stream_header_v.time_scale = 1;
        gwavi->stream_header_v.data_rate = fps;
        gwavi->stream_header_v.buffer_size = (width * height * 3);
        gwavi->stream_header_v.data_length = 0;

        /* set stream format */
        gwavi->stream_format_v.header_size = 40;
        gwavi->stream_format_v.width = width;
        gwavi->stream_format_v.height = height;
        gwavi->stream_format_v.num_planes = 1;
        gwavi->stream_format_v.bits_per_pixel = 24;
        gwavi->stream_format_v.compression_type =
            ((unsigned int)fourcc[3] << 24) +
            ((unsigned int)fourcc[2] << 16) +
            ((unsigned int)fourcc[1] << 8) +
            ((unsigned int)fourcc[0]);
        gwavi->stream_format_v.image_size = width * height * 3;
        gwavi->stream_format_v.colors_used = 0;
        gwavi->stream_format_v.colors_important = 0;

        gwavi->stream_format_v.palette = 0;
        gwavi->stream_format_v.palette_count = 0;

        if (audio) {
            /* set stream header */
            memcpy(gwavi->stream_header_a.data_type, "auds", 4);
            gwavi->stream_header_a.codec[0] = 1;
            gwavi->stream_header_a.codec[1] = 0;
            gwavi->stream_header_a.codec[2] = 0;
            gwavi->stream_header_a.codec[3] = 0;
            gwavi->stream_header_a.time_scale = 1;
            gwavi->stream_header_a.data_rate = audio->samples_per_second;
            gwavi->stream_header_a.buffer_size =
                audio->channels * (audio->bits / 8) * audio->samples_per_second;
            /* when set to -1, drivers use default quality value */
            gwavi->stream_header_a.audio_quality = -1;
            gwavi->stream_header_a.sample_size =
                (audio->bits / 8) * audio->channels;

            /* set stream format */
            gwavi->stream_format_a.format_type = 1;
            gwavi->stream_format_a.channels = audio->channels;
            gwavi->stream_format_a.sample_rate = audio->samples_per_second;
            gwavi->stream_format_a.bytes_per_second =
                audio->channels * (audio->bits / 8) * audio->samples_per_second;
            gwavi->stream_format_a.block_align =
                audio->channels * (audio->bits / 8);
            gwavi->stream_format_a.bits_per_sample = audio->bits;
            gwavi->stream_format_a.size = 0;
        }

        if (write_chars_bin(out, "RIFF", 4) == -1)
            goto write_chars_bin_failed;
        if (write_int(out, 0) == -1) {
            (void)fprintf(stderr, "gwavi_info: write_int() failed\n");
            return NULL;
        }
        if (write_chars_bin(out, "AVI ", 4) == -1)
            goto write_chars_bin_failed;

        if (write_avi_header_chunk(gwavi) == -1) {
            (void)fprintf(stderr, "gwavi_info: write_avi_header_chunk "
                      "failed\n");
            return NULL;
        }

        if (write_chars_bin(out, "LIST", 4) == -1)
            goto write_chars_bin_failed;
        if ((gwavi->marker = ftell(out)) == -1) {
            perror("gwavi_info (ftell)");
            return NULL;
        }
        if (write_int(out, 0) == -1) {
            (void)fprintf(stderr, "gwavi_info: write_int() failed\n");
            return NULL;
        }
        if (write_chars_bin(out, "movi", 4) == -1)
            goto write_chars_bin_failed;

        gwavi->offsets_len = 1024;
        if ((gwavi->offsets = (unsigned int *)malloc((size_t)gwavi->offsets_len *
                          sizeof(unsigned int)))
                == NULL) {
            (void)fprintf(stderr, "gwavi_info: could not allocate memory "
                      "for gwavi offsets table\n");
            return NULL;
        }

        gwavi->offsets_ptr = 0;

        return gwavi;

    write_chars_bin_failed:
        (void)fprintf(stderr, "gwavi_open: write_chars_bin() failed\n");
        return NULL;
}

