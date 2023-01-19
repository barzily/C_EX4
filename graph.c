#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"


node * creat_graph(int num_of_nodes)
{   
    node *head = NULL;
    pnode New_Node, tmp = NULL;
    int i;

    head = (pnode)malloc(sizeof(node));

    if(head == NULL)
    {
        exit(0);
    }   

    head->id = 0; 
    head->next = NULL;
    head->edges = NULL;

    tmp = head;

    for(i=1; i<num_of_nodes; i++)
    {
        New_Node = (pnode)malloc(sizeof(node));

        if(New_Node == NULL)
        {
            break;
        }
        New_Node->id = i;
        New_Node->next = NULL;
        New_Node->edges = NULL;

        tmp->next = New_Node;
        tmp = tmp->next;
    }
    return head;
}

pnode getNode(int id, pnode *head)
{
    pnode tmp = *head;

    while (tmp != NULL)
    {
        if (tmp->id == id)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return NULL;
}

void insert_node_cmd(pnode *head);


void add_adge(pnode *head,int src){

    int dst;
    int user_i;
    pnode tmp = getNode(src,head);
    while(scanf("%d",&dst)!=0 && scanf("%d",&user_i)!=0)
    {
        if(( (user_i >= 'A' && user_i <= 'Z') || dst >= 'A' && dst <= 'Z') )
        {
            break;
        }
        if((dst >= 'a' && dst <= 'z') || (user_i >= 'a' && user_i <= 'z'))
        {
            break;
        }
        insert_edge(tmp,dst,user_i,head);
    }
}

void insert_edge(pnode tmp,int dst,int user_i,pnode *head){

    if(tmp->edges == NULL)
    {
        tmp->edges = (pedge)malloc(sizeof(edge));
        if(tmp->edges == NULL)
        {
            exit(0);
        }
        tmp->edges->weight = user_i;
        tmp->edges->next =NULL;
        node *D = getNode(dst,head);
        tmp->edges->endpoint = &(*D);
    }
    else{
        pedge edg = tmp->edges;

        while(edg->next!=NULL)
        {
            edg = edg->next;
        }
        edg->next = (pedge)malloc(sizeof(edge));
        if(edg == NULL)
        {
            exit(0);
        }
        edg->next->next = NULL;
        edg->next->weight = user_i;
        node *D = getNode(dst,head);
        edg->next->endpoint = &(*D);
    }
}





void freeGraph(pnode *head)
{
     pnode tmpNode = *head;

    while (tmpNode != NULL)
    {
        pedge tmpEdge = tmpNode->edges;
        while (tmpEdge != NULL)
        {
            pedge tmpEdgefree = tmpEdge;
            tmpEdge = tmpEdge->next;
            free(tmpEdgefree);
        }
        node *tmpFree = tmpNode;
        tmpNode = tmpNode->next;
        free(tmpFree);
    }
}

void del_node(pnode *head)
{
    int D = 0;
    scanf("%d",&D);

    del_edge(head,D);

    pnode tmpNode = *head;
    node *p = NULL;
    if(tmpNode->id != D)
    {
        while (tmpNode->next->id!=D)
        {
        tmpNode = tmpNode->next;
        }
        p = tmpNode->next;
        tmpNode->next=tmpNode->next->next;
        free_edges(p);
        free(p);    
    }
    else
    {
    p = *head;
    *head = p->next;
    free_edges(p);
    free(p);
    }
}

void free_edges(pnode p)
{
    if(p->edges!=NULL)
    {
    pedge tmp = p->edges;

    while(tmp!=NULL)
    {
        pedge p1 = NULL;
        p1 = tmp;
        tmp = tmp->next;
        free(p1);
    }
    }
    else{
        free(p->edges);
    }
}

void del_edge(pnode *head,int n)
{
    pnode tmpNode = *head;

    while (tmpNode!= NULL)
    {
        if(tmpNode->id != n && tmpNode->edges!=NULL){

            if(tmpNode->edges->endpoint->id !=n)
            {
                pedge tmpEdge = tmpNode->edges;

                    while (tmpEdge->next!= NULL)
                    {   
                        if(tmpEdge->next->endpoint->id == n){
                            pedge p1 = tmpEdge->next;
                            tmpEdge->next=tmpEdge->next->next;
                            free(p1);
                            break;
                        }
                        tmpEdge = tmpEdge->next;
                    }           
            }
            else
            { 
                if(tmpNode->edges->next ==NULL)
                    {
                    pedge p1 = tmpNode->edges;
                    tmpNode->edges = NULL;
                    free(p1);
                    }
                else{
                    pedge p1 = tmpNode->edges;
                    tmpNode->edges = p1->next;
                    free(p1);
                    }
            }
        }
        tmpNode = tmpNode->next;
    }
}

void add_node(pnode *head){
    int src;
    scanf("%d", &src);
    int dst;
    int user_i;
    pnode tmp = getNode(src,head);
    if(tmp == NULL){
        pnode node_to_graph = *head;
        while (node_to_graph->next != NULL){
            node_to_graph = node_to_graph->next;
        }
        pnode New_Node = (pnode)(malloc(sizeof (node)));
        New_Node->id = src;
        New_Node->edges = NULL;
        New_Node->next = NULL;
        node_to_graph->next = New_Node;
        while (scanf("%d",&dst)!=0 && scanf("%d",&user_i)!=0){
            if((dst >= 'A' && dst <= 'Z') || (user_i >= 'A' && user_i <= 'Z'))
            {
                break;
            }
            if((dst >= 'a' && dst <= 'z') || (user_i >= 'a' && user_i <= 'z'))
            {
                break;
            }
            insert_edge(New_Node,dst,user_i,head);
        }
    } else{
        free_edges(tmp);

        tmp->edges = NULL;
        while (scanf("%d",&dst)!=0 && scanf("%d",&user_i)!=0){
            if((dst >= 'A' && dst <= 'Z') || (user_i >= 'A' && user_i <= 'Z'))
            {
                break;
            }
            if((dst >= 'a' && dst <= 'z') || (user_i >= 'a' && user_i <= 'z'))
            {
                break;
            }
            insert_edge(tmp,dst,user_i,head);
        }
    }
}
