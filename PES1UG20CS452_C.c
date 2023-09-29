// client.c
#include "PES1UG20CS452_H.h"

int main()
{
    int choice;
    int vertices;
    int dfs_result = 0,bfs_result = 0;
    int start_point, end_point;

    FILE* fp = fopen("input.txt", "rw");
    if( fp == NULL ) 
        { printf("Error: %s\n", strerror(errno)); }

do{
    printf("\n-------------------------------------------------------------------------------------\n");
    printf("Welcome to the Robot Cafe :\n");
    printf("1. Read the floor plan.(input file)\n");
    printf("2. Export the BFS and DFS paths to respective files.\n");
    printf("Please Enter 3 to exit the program.");
    printf("Input your choice : ");
    scanf(" %d", &choice);

    switch (choice)
    {

    case 1:
        printf("\nReading the input file ...\n");
        coord start, end;
        getcord(&start, fp);
        getcord(&end, fp);
        printf("\nStart: (%d, %d)\nEnd: (%d, %d)\n", start.x, start.y, end.x, end.y);
        vertices = num_v(fp);
        vertex_node* adj_list = (vertex_node*)malloc((vertices + 1) * sizeof(vertex_node));
        read_map(fp, adj_list);
        printf("Input file has been read and adjacency list successfully created.\n");
        break;

    case 2:
        printf("\nThe Path :\n");
        int* d_path = (int*)calloc(vertices, sizeof(int));
        int* b_path = (int*)calloc(vertices, sizeof(int));

        start_point = find_vertex(adj_list, &start, vertices);
        end_point = find_vertex(adj_list, &end, vertices);

        find_path(adj_list, start_point, end_point, vertices, &dfs_result, &bfs_result, d_path, b_path);
        store_path(adj_list, start_point, end_point, vertices, dfs_result, bfs_result, d_path, b_path);

        free(adj_list);
        break;

    default:
        break;
    }

}while(choice!=3);

    return 0;
}
