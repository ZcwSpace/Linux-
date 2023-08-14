void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int parent[MAXVEX];/* 定义一数组用来判断边与边是否形成环路 */
	Edge edges[MAXEDGE];/* 定义边集数组,edge的结构为begin,end,weight,均为整型 */
	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;	/* 初始化数组值为0 */
	for (i = 0; i < G.numEdges; i++)	/* 循环每一条边 */
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m) /* 假如n与m不等，说明此边没有与现有的生成树形成环路 */
		{
			parent[n] = m;	/* 将此边的结尾顶点放入下标为起点的parent中。 */
							/* 表示此顶点已经在生成树集合中 */
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}