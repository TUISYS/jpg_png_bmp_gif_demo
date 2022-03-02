#ifndef __JPEG_DECODE_INTERFACE_H__
#define __JPEG_DECODE_INTERFACE_H__


typedef enum tag_tui_jpeg_scale {
	TUI_JPEG_SCALE_1_1,                  /* 不缩放，原始大小 */
	TUI_JPEG_SCALE_1_2,                  /* 缩小2分之1 */
	TUI_JPEG_SCALE_1_4,                  /* 缩小4分之1 */
	TUI_JPEG_SCALE_1_8,                  /* 缩小8分之1 */
	TUI_JPEG_SCALE_NUM,
} tui_jpeg_scale_e;


unsigned char * tui_jpeg_decode_jpegfile_to_argbbuf(char * jpegfile, unsigned int *img_w, unsigned int *img_h, tui_jpeg_scale_e scale);
unsigned char * tui_jpeg_decode_jpegbuf_to_argbbuf(unsigned char * jpegbuf, unsigned int jpegbuf_size, unsigned int *img_w, unsigned int *img_h, tui_jpeg_scale_e scale);
void tui_jpeg_decode_free_argbbuf(unsigned char * argbbuf);


#endif /* __JPEG_DECODE_INTERFACE_H__ */

