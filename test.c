
#include "tui.h"
#include "jpeg_decode_interface.h"
#include "png_decode_interface.h"

void tui_png_decode_test(void)
{
	tui_image_attri_t attri = { 0 };
	tui_obj_t * image;
	unsigned int img_w, img_h;
	unsigned char *png_rgba_buf;
	
	/* 解析JPG */
	png_rgba_buf = tui_png_decode_pngfile_to_argbbuf("F:\\cool.png", &img_w, &img_h);
	if (jpeg_rgb_buf) {
		/* 创建image对象 */
		image = tui_image_create(tui_layer_top());
		/* 设置属性 */
		memset(&attri, 0, sizeof(tui_image_attri_t));
		attri.obj.pt.x = 50;
		attri.obj.pt.y = 50;
		tui_image_set_attri(image, &attri);
		tui_image_set_image_rgba_buf(image, 0, png_rgba_buf, img_w, img_h);
		tui_image_set_cur_img_index(image, 0);

		/* 释放解析JPG的buffer */
		tui_png_decode_free_rgbabuf(png_rgba_buf);
	}
}

void tui_jpeg_decode_test(void)
{
	tui_image_attri_t attri = { 0 };
	tui_obj_t * image;
	unsigned int img_w, img_h;
	unsigned char *jpeg_rgb_buf, *jpeg_file_buf = NULL;
	FILE *fjpg;
	int flen;
	
	/* 解析JPG */
	jpeg_rgb_buf = tui_jpeg_decode_jpegfile_to_argbbuf("F:\\qq.jpg", &img_w, &img_h, TUI_JPEG_SCALE_1_4);
	if (jpeg_rgb_buf) {
		/* 创建image对象 */
		image = tui_image_create(tui_layer_top());
		/* 设置属性 */
		memset(&attri, 0, sizeof(tui_image_attri_t));
		attri.obj.pt.x = 50;
		attri.obj.pt.y = 50;
		tui_image_set_attri(image, &attri);
		tui_image_set_image_argb_buf(image, 0, jpeg_rgb_buf, img_w, img_h);
		tui_image_set_cur_img_index(image, 0);

		/* 释放解析JPG的buffer */
		tui_jpeg_decode_free_argbbuf(jpeg_rgb_buf);
	}

	fjpg = fopen("F:\\qq.jpg", "rb");
	if (fjpg) {
		fseek(fjpg, 0, SEEK_END);
		flen = ftell(fjpg);
		fseek(fjpg, 0, SEEK_SET);

		jpeg_file_buf = malloc(flen);
		if (jpeg_file_buf)
			fread(jpeg_file_buf, 1, flen, fjpg);

		fclose(fjpg);

		if (jpeg_file_buf) {
			/* 解析JPG */
			jpeg_rgb_buf = tui_jpeg_decode_jpegbuf_to_argbbuf(jpeg_file_buf, flen, &img_w, &img_h, TUI_JPEG_SCALE_1_4);
			free(jpeg_file_buf);
			if (jpeg_rgb_buf) {
				/* 创建image对象 */
				image = tui_image_create(tui_layer_top());
				/* 设置属性 */
				memset(&attri, 0, sizeof(tui_image_attri_t));
				attri.obj.pt.x = 400;
				attri.obj.pt.y = 50;
				tui_image_set_attri(image, &attri);
				tui_image_set_image_argb_buf(image, 0, jpeg_rgb_buf, img_w, img_h);
				tui_image_set_cur_img_index(image, 0);

				/* 释放解析JPG的buffer */
				tui_jpeg_decode_free_argbbuf(jpeg_rgb_buf);
			}
		}
	}
}
