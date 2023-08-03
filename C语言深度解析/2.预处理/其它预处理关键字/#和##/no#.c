#define QDSP_MODULE_AUDPPTASK 	1
#define QDSP_MODULE_AUDRECTASK		2
#define QDSP_MODULE_UDPREPROCTASK 	3	

struct adsp_module_info 
{
	const char *name;
	const char *pdev_name;
	uint32_t id;
};

struct adsp_module_info module_info[] = 
{
		{.name="AUDPPTASK", .pdev_name=adsp_AUDPPTASK, .id=QDSP_MODULE_AUDPPTASK},
		{.name="AUDRECTASK", .pdev_name=adsp_AUDRECTASK, .id=QDSP_MODULE_AUDRECTASK},
		{.name="UDPREPROCTASK", .pdev_name=adsp_UDPREPROCTASK, .id=QDSP_MODULE_UDPREPROCTASK}
};