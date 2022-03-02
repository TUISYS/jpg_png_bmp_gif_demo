<h1 align="center"> TUI JPEG图片解析测试教程 </h1>

## 描述
TUI *V2.1* 以上版本支持对所有`.jpg`文件的读取解析，和jpg buffer的解析，支持原图、1/2、1/4、1/8的尺寸缩小的解析。<br>
`TUISYS/jpeg_demo`仓库只提供了头文件接口和测试demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件。
直接将`jpeg_decode_interface.h`放进`TUISYS/tui_project/includes`，然后应用就可以调用相关函数了。

## 注意
解析函数有两个，一个是`.jpg`文件解析（`tui_jpeg_decode_jpegfile_to_argbbuf`函数）和jpg buffer解析（`tui_jpeg_decode_jpegbuf_to_argbbuf`函数），这两个函数解析成功，会返回一个argb的buffer，如果不需要这个内存，需要调用`tui_jpeg_decode_free_argbbuf`函数释放内存，否则会有内存泄漏。
