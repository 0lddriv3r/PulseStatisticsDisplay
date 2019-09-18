SET HRPS=%~dp0

rapidee -S -C -U HRPS %HRPS%

rapidee -I -C -E -U PATH %%HRPS%%;%%HRPS%%lib

@pause