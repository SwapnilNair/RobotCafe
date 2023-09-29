#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
typedef struct coord
{  int x;
    int y;
} coord;

typedef struct vertex
{  int vid;
    coord loc;
    struct vertex* next;
} vertex_node;

int num_v(FILE*);
int qisempty(int*);
void getcord(coord*, FILE*);
int qdelete(int*, int*, int*);
void read_map(FILE*, vertex_node*);
void qinsert(int*, int*, int*, int);
void create_adj_list(vertex_node*, int);
void insert_vnode(vertex_node*, int, int);
int find_vertex(vertex_node*, coord*, int);
int dfs(vertex_node*, int, int, int*, int, int*);
void bfs(vertex_node*, int, int, int*, int, int*);
int reconstruct_from_bfs(vertex_node*, int, int, int*, int*);
void store_path(vertex_node*, int, int, int, int, int, int*, int*);
void find_path(vertex_node*, int, int, int, int*, int*, int*, int*);
