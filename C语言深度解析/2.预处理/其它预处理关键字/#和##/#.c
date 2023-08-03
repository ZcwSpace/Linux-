#define QDSP_MODULE_AUDPPTASK_1 	1
#define QDSP_MODULE_AUDRECTASK_2	2
#define QDSP_MODULE_AUDRECTASK_3 	3	

#define QDSP_MODULE(n) { .name = #n, .pdev_name = "adsp_" #n, .id = QDSP_MODULE_##n }

struct adsp_module_info {
    const char *name;
    const char *pdev_name;
    uint32_t id;
};

struct adsp_module_info module_info[] = 
{
        QDSP_MODULE(AUDPPTASK),
        QDSP_MODULE(AUDRECTASK),
        QDSP_MODULE(UDPREPROCTASK)
};		