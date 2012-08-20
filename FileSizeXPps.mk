
FileSizeXPps.dll: dlldata.obj FileSizeXP_p.obj FileSizeXP_i.obj
	link /dll /out:FileSizeXPps.dll /def:FileSizeXPps.def /entry:DllMain dlldata.obj FileSizeXP_p.obj FileSizeXP_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del FileSizeXPps.dll
	@del FileSizeXPps.lib
	@del FileSizeXPps.exp
	@del dlldata.obj
	@del FileSizeXP_p.obj
	@del FileSizeXP_i.obj
