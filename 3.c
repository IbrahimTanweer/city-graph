#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char city[20];
    int weight;
    struct Node* next;
}Node;

typedef struct{
    int num_vertices;
    Node** adj_lists;
}GraphList;

GraphList* create_graph_list(int vertices){
    GraphList* graph = malloc(sizeof(GraphList));
    if(graph == NULL){
        printf("Error allocating memory");
        return NULL;
    }
    graph->num_vertices = vertices;
    graph->adj_lists = malloc(sizeof(Node*) * vertices);
    if(graph->adj_lists == NULL){
        printf("Error allocating memory");
        return NULL;
    }
    for(int i = 0; i < vertices; i++){
        graph->adj_lists[i] = NULL;
        if(graph->adj_lists == NULL){
            printf("Error allocating memory");
            return NULL;
        }
    }
    return graph;
}

int add_graph_list(GraphList* graph, int src, int dest, int weight){
    char list_of_cities[6][20] = {"Delhi", "Mumbai", "Chennai", "Bihar", "Gujarat", "Rajasthan"};

    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->city, list_of_cities[dest]);
    new_node->weight = weight;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    new_node = malloc(sizeof(Node));
    strcpy(new_node->city, list_of_cities[dest]);
    new_node->weight = weight;
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
    return 0;
}

int print_graph_list(GraphList* graph){
    for(int i = 0; i < graph->num_vertices; i++){
        Node* temp = graph->adj_lists[i];
        printf("\n Adjacency list of vertex %d\n head", i);
        while(temp){
            printf(" -> %s(%d)", temp->city, temp->weight);
            temp = temp->next;
        }
    }
}

int main(){
    GraphList* graph;
    graph = create_graph_list(6);
    add_graph_list(graph,1,2,5);
    add_graph_list(graph,2,3,10);
    add_graph_list(graph,2,5,12);
    print_graph_list(graph);
    return 0;
}