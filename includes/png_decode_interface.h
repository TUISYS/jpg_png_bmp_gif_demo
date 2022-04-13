#ifndef __PNG_DECODE_INTERFACE_H__
#define __PNG_DECODE_INTERFACE_H__

unsigned char * tui_png_decode_pngfile_to_rgbabuf(char * pngfile, unsigned int *img_w, unsigned int *img_h);
void tui_png_decode_free_rgbabuf(unsigned char * rgbabuf);


#endif /* __PNG_DECODE_INTERFACE_H__ */

