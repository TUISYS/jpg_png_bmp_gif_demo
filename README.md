<h1 align="center"> TUI 各种类型格式图片解析测试教程 </h1>

## 描述
TUI *V2.1* 以上版本支持各种类型格式图片解析（jpg、png、bmp、gif）
该仓库只提供了`.jpg`和`.png`头文件接口和测试demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件。
直接将头文件放进`TUISYS/tui_project/includes`，然后应用`#include`就可以调用相关函数了。

## jpg图片
支持`.jpg`文件的读取解析，和jpg buffer的解析，支持原图、1/2、1/4、1/8的尺寸缩小的解析。<br>
解析函数有两个，一个是`.jpg`文件解析（`tui_jpeg_decode_jpegfile_to_argbbuf`函数）和jpg buffer解析（`tui_jpeg_decode_jpegbuf_to_argbbuf`函数），这两个函数解析成功，会返回一个argb的buffer，然后通过image控件的函数`tui_image_set_image_argb_buf()`设置给控件，如果不需要这个内存，需要调用`tui_jpeg_decode_free_argbbuf`函数释放内存，否则会有内存泄漏。

## png图片
支持`.png`文件的读取解析。<br>
解析函数是`.png`文件解析（`tui_png_decode_pngfile_to_rgbabuf`函数）这个函数解析成功，会返回一个rgba的buffer，然后通过image控件的函数`tui_image_set_image_rgba_buf()`设置给控件，如果不需要这个内存，需要调用`tui_png_decode_free_rgbabuf`函数释放内存，否则会有内存泄漏。


## bmp图片
支持16、24、32位`.bmp`文件的读取解析，通过image控件的函数`tui_image_set_image_src()`设置给控件。<br>

## gif图片
支持`.gif`文件的读取解析和循环播放，通过gif控件的属性将路径设置给控件。<br>
