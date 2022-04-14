<h1 align="center"> TUI 各种类型格式图片解析测试教程 </h1>

## 描述
TUI *V2.1* 以上版本支持各种类型格式图片解析（jpg、png、bmp、gif）
该仓库只提供了`.jpg`和`.png`头文件接口和测试demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件。
直接将头文件放进`TUISYS/tui_project/includes`，然后应用`#include`就可以调用相关函数了。

## jpg图片
支持`.jpg`文件的读取解析，和jpg buffer的解析，支持原图、1/2、1/4、1/8的尺寸缩小的解析。<br>
解析函数有两个，一个是`.jpg`文件解析（`tui_jpeg_decode_jpegfile_to_argbbuf`函数）和jpg buffer解析（`tui_jpeg_decode_jpegbuf_to_argbbuf`函数），这两个函数解析成功，会返回一个argb的buffer，然后通过image控件的函数`tui_image_set_image_argb_buf()`设置给控件，创建成功后需要释放这个内存，调用`tui_jpeg_decode_free_argbbuf`函数释放内存，否则会有内存泄漏。（参考test.c）<br>
简单创建jpg图片控件，适合不频繁刷新的场景，每次刷新会重新解码，代码如下：
``` c
void tui_image_test(void)
{
	tui_obj_t * obj;
	tui_image_attri_t attri = { 0 };//注意先清空结构体，避免随机值

	obj = tui_image_create(tui_layer_normal());

	/* 通用属性 */
	attri.obj.pt.x = 200;
	attri.obj.pt.y = 100;

	tui_image_set_attri(obj, &attri);
	tui_image_set_image_src(obj, 0, "E:\\image\\qq.jpg");
	tui_image_set_cur_img_index(obj, 0);
}
```

## png图片
支持`.png`文件的读取解析。<br>
解析函数对`.png`文件解析（`tui_png_decode_pngfile_to_rgbabuf`函数）这个函数解析成功，会返回一个rgba的buffer，然后通过image控件的函数`tui_image_set_image_rgba_buf()`设置给控件，创建成功后需要释放这个内存，需要调用`tui_png_decode_free_rgbabuf`函数释放内存，否则会有内存泄漏。（参考test.c）<br>
简单创建png图片控件，适合不频繁刷新的场景，每次刷新会重新解码，代码如下：
``` c
void tui_image_test(void)
{
	tui_obj_t * obj;
	tui_image_attri_t attri = { 0 };//注意先清空结构体，避免随机值

	obj = tui_image_create(tui_layer_normal());

	/* 通用属性 */
	attri.obj.pt.x = 200;
	attri.obj.pt.y = 100;

	tui_image_set_attri(obj, &attri);
	tui_image_set_image_src(obj, 0, "E:\\image\\cool.png");
	tui_image_set_cur_img_index(obj, 0);
}
```

## bmp图片
支持16、24、32位`.bmp`文件的读取解析，通过image控件的函数`tui_image_set_image_src()`设置给控件。<br>
创建bmp图片控件代码如下：
``` c
void tui_image_test(void)
{
	tui_obj_t * obj;
	tui_image_attri_t attri = { 0 };//注意先清空结构体，避免随机值

	obj = tui_image_create(tui_layer_normal());

	/* 通用属性 */
	attri.obj.pt.x = 200;
	attri.obj.pt.y = 100;

	tui_image_set_attri(obj, &attri);
	tui_image_set_image_src(obj, 0, "E:\\image\\fly_32bit.bmp");//支持fly_16bit.bmp，fly_4bit.bmp
	tui_image_set_cur_img_index(obj, 0);
}
```

## gif图片
支持`.gif`文件的读取解析和循环播放，通过gif控件的属性将路径设置给控件。gif动画图片支持纯绿色（0，255，0）关键颜色透明。<br>
创建gif图片控件代码如下：
``` c
void tui_gif_test(void)
{
	tui_obj_t * obj;
	tui_gif_attri_t attri = { 0 };//注意先清空结构体，避免随机值

	obj = tui_gif_create(tui_layer_normal());

	/* 通用属性 */
	attri.obj.pt.x = 200;
	attri.obj.pt.y = 100;
	attri.mode = TUI_IMAGE_LOOP;
	strcpy(attri.gif_path, "E:\\image\\led.gif");//绿色是关键颜色（透明色）

	tui_gif_set_attri(obj, &attri);
}
```
