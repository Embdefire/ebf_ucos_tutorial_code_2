
set dir="%cd%"

for /R %dir% %%i in (*.uvprojx) do (ren %%i Fire_uCOS.uvprojx)
for /R %dir% %%i in (*.uvoptx) do (ren %%i Fire_uCOS.uvoptx)

del *.bak /s
del *.ddk /s
del *.edk /s
del *.lst /s
del *.lnp /s
del *.mpf /s
del *.mpj /s
del *.obj /s
del *.omf /s
::del *.opt /s  
del *.plg /s
del *.rpt /s
del *.tmp /s
del *.__i /s
del *.crf /s
del *.o /s
del *.d /s
del *.axf /s
del *.tra /s
del *.dep /s           
del JLinkLog.txt /s
 
del *.uvguix.Administrator /s  
del *.scvd /s  

del *.iex /s
del *.htm /s
::del *.sct /s
del *.map /s

exit
